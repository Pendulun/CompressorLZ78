#ifndef TRIEENCODER_H
#define TRIEENCODER_H
#include <iostream>
#include <string>
#include <forward_list>
#include "Trie.hpp"
namespace compressor{
	class TrieEncoder : public Trie{
	public:
		void inserirNo(Node* filho,Node* pai) override;
		Node* pesquisar(std::string padrao) override;
		TrieEncoder();
		~TrieEncoder();
		int getMaxIndex();
	private:
		int maxIndex;
	};
}

#endif