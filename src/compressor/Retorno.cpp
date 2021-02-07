#include "Retorno.hpp"
namespace compressor{
	Retorno::Retorno(Node* no, bool completeFound){
		this->lastFound = no;
		this->completeFound = completeFound;
	}

	Retorno::~Retorno(){
		/*Como o lastFound aponta para um no na TrieEncoder
		* nao precisamos deletá-lo aqui e deixamos a sua delecao
		* para o Trie
		*/
	}

	Node* Retorno::getLastFound(){
		return this->lastFound;
	}

	bool Retorno::getCompleteFound(){
		return this->completeFound;
	}
}