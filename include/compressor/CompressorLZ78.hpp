#ifndef COMPRESSORLZ78_H
#define COMPRESSORLZ78_H
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include "Compressor.hpp"
#include "Trie.hpp"
#include "TrieEncoder.hpp"
#include "Retorno.hpp"

namespace compressor{
	class CompressorLZ78: public Compressor{
	public:
		void encode(std::string, std::string) override;
		void decode(std::string, std::string) override;
		CompressorLZ78();
		~CompressorLZ78();
	private:
		Trie* myTrie;
		std::vector<std::pair<int,std::string>>* decoder;
		std::string getAcumulado(int index);
	};
}

#endif