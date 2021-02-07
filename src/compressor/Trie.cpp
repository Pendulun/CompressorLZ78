#include "Trie.hpp"

namespace compressor{
	
	Node* Trie::getRaiz(){
		return this->raiz;
	}

	void Trie::setRaiz(Node* novaRaiz){
		this->raiz = novaRaiz;
	}

	void Trie::inserirNo(Node* filho,Node* pai){}

	Retorno* Trie::pesquisar(std::string padrao){}

	Trie::Trie(){}

	Trie::~Trie(){
		delete this->raiz;
	}
}