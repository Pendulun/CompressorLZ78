#include "TrieEncoder.hpp"

namespace compressor{
	
	TrieEncoder::TrieEncoder(){
		this->maxIndex = 0;
		this->setRaiz(new Node(0,""));
		//Node* novoNo = new Node(0,"");
		//(this->getRaiz())->addChild(novoNo,true);
		//delete novoNo;
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
		bool ehFolha = false;
		do{
			temTransicao = false;
			ehFolha = false;
			std::cout<<"Procurando no no: "<<noAtual->getLetter();
			std::cout<<" de indice: "<<noAtual->getIndex()<<std::endl;
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
							std::cout<<"Encontramos o padrão, nao retornamos nada 1"<<std::endl;
							return nullptr;
						}else{
							noAtual = filho;
							indexPadrao++;
							temTransicao = true;
							break;	
						}
					}
				}
				
				if(!temTransicao){ //Não achou uma transição dado o nó atual
					std::cout<<"Nao tem transicao"<<std::endl;
					break;
				}else{
					std::cout<<"Tem transicao"<<std::endl;
				}
			}else{
				std::cout<<"No atual e folha"<<std::endl; //Nó atual é nó folha
				ehFolha = true;
				break;
			}
		}while(temTransicao);

		//Não foi encontrado uma transição (nó folha ou nó interno sem transição)
		if(indexPadrao==(padrao.length()-1) && temTransicao){
			//Se atingimos o final do padrão,
			//Achamos o padrão 
			std::cout<<"Encontramos o padrão, nao retornamos nada 2"<<std::endl;
			return nullptr;
		}else{
			//Se não encontramos o padrão ainda, aqui deveria passar a ser adicionado o padrão
			//Se for um nó folha, existe um valor associado a ele
			// Se for interno, devemos achar o nó filho que contém o valor associado a esse interno
			/*if(!ehFolha){ 
				std::cout<<"No atual nao eh folha"<<std::endl;
				for(auto it = noAtual->getChildren()->begin();it != noAtual->getChildren()->end();it++){
					if((*it)->getLetter().compare("") == 0){
						noAtual = (*it);
						break;
					}
				}
			}*/

			std::cout<<"Nao encontramos o padrao"<<std::endl;
			std::cout<<"Deve ser adicionado em:"<<noAtual->getLetter();
			std::cout<<" Index: "<<noAtual->getIndex()<<std::endl;
			return noAtual;
		}
	}

}