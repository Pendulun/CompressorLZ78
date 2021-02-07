#include "Trie.hpp"

namespace compressor{
	
	Node* Trie::getRaiz(){
		std::cout<<"4"<<std::endl;
		return this->raiz;
	}

	void Trie::setRaiz(Node* novaRaiz){
		this->raiz = novaRaiz;
	}

	void Trie::inserirNo(Node* filho,Node* pai){}

	Node* Trie::pesquisar(std::string padrao){}

	Trie::Trie(){}

	Trie::~Trie(){
		std::cout<<"Destrutor Trie"<<std::endl;
		std::cout<<"Deletando raiz"<<std::endl;
		delete this->raiz;
	}
}