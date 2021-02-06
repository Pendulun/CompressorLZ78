#ifndef TRIE_H
#define TRIE_H
#include <iostream>
#include <string>
#include "Node.hpp"
namespace compressor{
	class Trie{
	public:
		Node* getRaiz();
		virtual void inserirNo(Node* filho,Node* pai) = 0;
		virtual Node* pesquisar(std::string padrao) = 0;
		~Trie() virtual;
		Trie();
	private:
		Node* raiz;
	protected:
		void setRaiz(Node* raiz);
	};
}

#endif