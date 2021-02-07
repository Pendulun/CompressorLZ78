#include "TrieEncoder.hpp"

namespace compressor{
	
	TrieEncoder::TrieEncoder(){
		this->maxIndex = 0;
		this->setRaiz(new Node(0,""));
	}

	TrieEncoder::~TrieEncoder(){
	}

	/**
	* Retorna o maior índice na Trie atual
	*/
	int TrieEncoder::getMaxIndex(){
		return this->maxIndex;
	}

	/**
	* Insere um nó na lista de filhos do nó pai
	*/
	void TrieEncoder::inserirNo(Node* filho, Node* pai){	
		pai->addChild(filho,false);
		maxIndex++;
	}

	/**
	* Pesquisa um padrão dentro da Trie
	* Retorna NULL caso encontre o padrão
	* Retorna o Node* onde não foi possível continuar a pesquisa caso na ache
	*/
	Retorno* TrieEncoder::pesquisar(std::string padrao){
		int indexPadrao = 0;
		Node* noAtual = this->getRaiz();
		bool temTransicao = false;
		bool ehFolha = false;
		do{
			temTransicao = false;
			ehFolha = false;
			if(noAtual->possuiFilhos()){
				//É nó interno
				bool encontrouNosFilhos = false; 
				for(Node* filho : *(noAtual->getChildren())){
					std::string letraPadrao = "";
					std::string letraNo = "";
					letraNo += filho->getLetter();
					letraPadrao += padrao[indexPadrao];
					if(letraPadrao.compare(letraNo) == 0){
						if(indexPadrao==(padrao.length()-1)){
							//Foi o último caractere do padrão, logo encontrei
							return new Retorno(filho, true);
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
			}else{
				//Nó atual é nó folha
				ehFolha = true;
				break;
			}
		}while(temTransicao);

		//Não foi encontrado uma transição (nó folha ou nó interno sem transição)
		if(indexPadrao==(padrao.length()-1) && temTransicao){
			//Se atingimos o final do padrão,
			//Achamos o padrão 
			return new Retorno(noAtual, true);
		}else{
			return new Retorno(noAtual,false);
		}
	}

}