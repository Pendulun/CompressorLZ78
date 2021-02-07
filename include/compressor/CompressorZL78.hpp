#ifndef COMPRESSORZL78_H
#define COMPRESSORZL78_H
#include <iostream>
#include <fstream>
#include "Compressor.hpp"
#include "Trie.hpp"
#include "TrieEncoder.hpp"

namespace compressor{
	class CompressorZL78: public Compressor{
	public:
		void encode(std::string, std::string) override;
		void decode(std::string, std::string) override;
		CompressorZL78();
		~CompressorZL78();
	private:
		Trie* myTrie;
	};
}

#endif