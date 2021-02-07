#ifndef TRIEENCODER_H
#define TRIEENCODER_H
#include <iostream>
#include <string>
#include <forward_list>
#include "Trie.hpp"
#include "Retorno.hpp"
namespace compressor{
	class TrieEncoder : public Trie{
	public:
		void inserirNo(Node* filho,Node* pai) override;
		Retorno* pesquisar(std::string padrao) override;
		TrieEncoder();
		~TrieEncoder();
		int getMaxIndex() override;
	private:
		int maxIndex;
	};
}

#endif