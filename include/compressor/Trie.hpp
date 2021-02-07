#ifndef TRIE_H
#define TRIE_H
#include <iostream>
#include <string>
#include "Node.hpp"
#include "Retorno.hpp"
namespace compressor{
	class Trie{
	public:
		Node* getRaiz();
		virtual int getMaxIndex() = 0;
		virtual void inserirNo(Node* filho,Node* pai) = 0;
		virtual Retorno* pesquisar(std::string padrao) = 0;
		virtual ~Trie();
		Trie();
	private:
		Node* raiz;
	protected:
		void setRaiz(Node* raiz);
	};
}

#endif