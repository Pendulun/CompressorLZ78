#include "TrieEncoder.hpp"

namespace compressor{
	
	TrieEncoder::TrieEncoder(){
		this->maxIndex = 0;
		std::cout<<"1"<<std::endl;
		this->setRaiz(new Node(0,""));
		std::cout<<"2"<<std::endl;
		Node* novoNo = new Node(0,"");
		(this->getRaiz())->addChild(novoNo,true);
		std::cout<<"3"<<std::endl;
		delete novoNo;
	}

	TrieEncoder::~TrieEncoder(){
		std::cout<<"Destrutor TrieEncoder"<<std::endl;
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
	Node* TrieEncoder::pesquisar(std::string padrao){
		int indexPadrao = 0;
		Node* noAtual = this->getRaiz();
		bool temTransicao = false;
		do{
			temTransicao = false;
			if(noAtual->possuiFilhos()){ //É nó interno
				bool encontrouNosFilhos = false; 
				for(Node* filho : *(noAtual->getChildren())){
					std::string letraPadrao = "";
					std::string letraNo = "";
					letraNo += filho->getLetter();
					letraPadrao += padrao[indexPadrao];
					if(letraPadrao.compare(letraNo) == 0){
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