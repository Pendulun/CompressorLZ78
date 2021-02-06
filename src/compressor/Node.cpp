#include "Node.hpp"

namespace compressor{
	Node::Node(int index, std::string letter){
		this->index = index;
		this->letter = letter;
		this->children = nullptr;
	}

	Node::~Node(){
		auto it = this->children->begin();
		for(it;it != this->children->end();it++){
			delete *it;
		}
	}

	/**
	* Retorna o índice associado ao nó
	* -1 se for um nó interno, e não negativo caso seja folha
	*/
	int Node::getIndex(){
		return this->index;
	}

	/**
	* Retorna a letra associada ao nó atual.
	*/
	std::string Node::getLetter(){
		return this->letter;
	}

	void Node::setIndex(int index){
		this->index = index;
	}

	void Node::setLetter(std::string letter){
		this->letter = letter;
	}

	/**
	* Retorna true caso o nó possua filhos, logo, pode ser usado para
	* descobrir se o nó é folha ou não
	*/
	bool Node::possuiFilhos(){
		if(this->children != NULL){
			return this->children->empty();
		}else{
			return false;
		}
	}

	/**
	* Adiciona um filho na lista de filhos do nó
	* Node* child: O nó filho a ser adicionado
	* bool ehRaiz: Flag usada para indicar se o nó atual é raiz
	*/
	void Node::addChild(Node* child, bool ehRaiz){
		//Se o nó não tem filhos, devemos criar um novo nó filho que contém o index atual
		//Para que apenas nós folha tenham valores nos index
		if(this->children->empty()){
			std::cout<<"Nao possuo filhos, criando no com valor"<<std::endl;
			Node* noValor = new Node(this->index,"");
			this->children->push_front(noValor);
			this->index = -1;
		}
		if(!ehRaiz){
			std::cout<<"Adicionando na lista de filhos"<<std::endl;
			this->children->insert_after(this->children->end(),child);
		}
	}

	/**
	* Retorna a lista filhos do nó. Será NULL caso não tenha filhos
	*/
	std::forward_list<Node*>* Node::getChildren(){
		if(this->children->empty()){
			return NULL;
		}else{
			return this->children;	
		}
	}
}