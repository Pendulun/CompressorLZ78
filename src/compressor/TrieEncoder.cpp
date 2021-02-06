#include "TrieEncoder.hpp"

namespace compressor{
	
	TrieEncoder::TrieEncoder(){
		this->maxIndex = 0;
		this->setRaiz(new Node(0,""));
		this->getRaiz()->addChild(new Node(0,""),true);
	}

	TrieEncoder::~TrieEncoder(){
		std::cout<<"Destrutor TrieEncoder"<<std::endl;
	}

	/**
	* Retorna o maior índice na Trie atual
	*/
	int TrieEncoder::getMaxIndex(){
		return this->maxIndex();
	}

	/**
	* Insere um nó na lista de filhos do nó pai
	*/
	void TrieEncoder::inserirNo(Node* filho, Node* pai){	
		pai->addChild(filho);
		maxIndex++;
	}

	/**
	* Pesquisa um padrão dentro da Trie
	* Retorna NULL caso encontre o padrão
	* Retorna o Node* onde não foi possível continuar a pesquisa caso na ache
	*/
	Node* TrieEncoder::pesquisar(std::string padrao){
		int indexPadrao = 0;
		Node* noAtual = this->getRaiz();
		bool temTransicao = false;
		do{
			temTransicao = false;
			if(noAtual->possuiFilhos()){ //É nó interno
				bool encontrouNosFilhos = false; 
				for(Node* filho : *(noAtual->getChildren())){
					if(padrao[indexPadrao].compare(filho->getLetter())){
						if(indexPadrao==(padrao.length()-1)){
							//Foi o último caractere do padrão, logo encontrei
							std::cout<<"Encontramos o padrão, nao retornamos nada"<<std::endl;
							return NULL;
						}else{
							noAtual = filho;
							indexPadrao++;
							temTransicao = true;
							break;	
						}
					}
				}

				if(!temTransicao){ //Não achou uma transição dado o nó atual
					break;
				}
			}else{ //Nó atual é nó folha
				break;
			}
		}while(temTransicao);

		//Não foi encontrado uma transição (nó folha ou nó interno sem transição)
		if(indexPadrao==(padrao.length()-1)){
			//Se atingimos o final do padrão,
			//Achamos o padrão 
			std::cout<<"Encontramos o padrão, nao retornamos nada"<<std::endl;
			return NULL;
		}else{
			//Se não encontramos o padrão ainda, aqui deveria passar a ser adicionado o padrão
			std::cout<<"Nao encontramos o padrao"<<std::endl;
			std::cout<<"Deve ser adicionado em:"<<noAtual->getLetter();
			std::cout<<"Index: "<<noAtual->getIndex()<<std::endl;
			return noAtual;
		}
	}

}