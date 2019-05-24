#include "Board.hpp"
#include "Trie_tree.h"
#include "fileReader.hpp"
#include "Json.hpp"
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <iostream>
#include <cstring>

int max(int v1, int v2)
{
	return v1 > v2 ? v1 : v2;
}

struct Config
{
	int rows;
	int columns;
	int crossings;
	std::string words_filename;
};

size_t read_file_to_dictionary(const std::string &filename, Tree &tree)
{
    size_t count = 0;
	const std::vector<std::string> words_string = FileUtils::FileReader::read_file_as_lines(filename);

	for (const auto &w : words_string)
	{
		tree.add_word(w);
	}

	for (const auto &w : words_string)
	{
		bool ch = tree.check_if_word_exists(w);
		if (!ch)
		{
			std::cout << ch <<  ": " << w << std::endl;
		}
		else
        {
		    count++;
        }
	}
	return count;
}

void read_config(const std::string &filename, Config &config)
{
	const std::string name_of_file = "nazwa_pliku";
	const std::string name_of_rows = "wiersze";
	const std::string name_of_columns = "kolumny";
	const std::string name_of_crossings = "liczba_skrzyzowan";

	std::string config_file = FileUtils::FileReader::read_file(filename);
	Json::Json json = Json::Json::parse_from_string(config_file);
	
	if (json.check_if_key_exists(name_of_file))
	{
		config.words_filename = json[name_of_file].get_value_as_string();
	}
	else
	{
		std::cout << "Couldn't find \"" << name_of_file << "\" key in JSON object" << std::endl;
	}

	if (json.check_if_key_exists(name_of_rows))
	{
		config.rows = json[name_of_rows].get_value_as_int();
	}
	else
	{
		std::cout << "Couldn't find \"" << name_of_rows << "\" key in JSON object" << std::endl;
	}

	if (json.check_if_key_exists(name_of_columns))
	{
		config.columns = json[name_of_columns].get_value_as_int();
	}
	else
	{
		std::cout << "Couldn't find \"" << name_of_columns << "\" key in JSON object" << std::endl;
	}

	if (json.check_if_key_exists(name_of_crossings))
	{
		config.crossings = json[name_of_crossings].get_value_as_int();
	}
	else
	{
		std::cout << "Couldn't find \"" << name_of_crossings << "\" key in JSON object" << std::endl;
	}


}

int main()
{
	std::srand(std::time(nullptr));
	const std::string config_filename = "config.json";
	Config config;

	Tree dictionary;
	
	read_config(config_filename, config);


	const size_t count = read_file_to_dictionary(config.words_filename, dictionary);

	std::cout << "Added: " << count << " words" << std::endl;

	Board board(config.rows, config.columns);


	const std::string text = "kora krowa kora kura katafalk kora kultura kijanka krzywa";
	const std::string _wzorzec = "kora";
	int i, j, t, m, n;

	const char* tekst = text.data();
	const char *wzorzec = _wzorzec.data();
	
	int P[100];

	m = _wzorzec.size();
	n = text.size();

	P[0]=0; P[1]=0; t=0;
	for (j=2; j<=m; j++)
	{
		while ((t>0)&&(wzorzec[t]!=wzorzec[j-1]))
		{
			t=P[t];
		}

		if (wzorzec[t]==wzorzec[j-1]) t++;
		P[j]=t;
	}
	 
	//algorytm KMP
	i = 1; j = 0;
	while (i<=n-m+1)
	{
		j = P[j];
		while((j<m)&&(wzorzec[j]==tekst[i+j-1])) j++;

		if (j==m) printf("%d\n",i);

		i=i+max(1,j-P[j]);
	}

	return 0;
}
