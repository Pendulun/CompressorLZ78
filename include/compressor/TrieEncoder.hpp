#ifndef TRIEENCODER_H
#define TRIEENCODER_H
#include <iostream>
#include <string>
#include <forward_list>
#include "Trie.hpp"
namespace compressor{
	class TrieEncoder : public Trie{
	public:
		TrieEncoder();
		~TrieEncoder();
		int getMaxIndex();
	private:
		int maxIndex;
	};
}

#endif