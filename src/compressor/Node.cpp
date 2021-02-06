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

	int Node::getIndex(){
		return this->index;
	}

	std::string Node::getLetter(){
		return this->letter;
	}

	void Node::setIndex(int index){
		this->index = index;
	}

	void Node::setLetter(std::string letter){
		this->letter = letter;
	}

	void Node::addChild(Node* child){
		//Se o nó não tem filhos, devemos criar um novo nó filho que contém o index atual
		//Para que apenas nós folha tenham valores nos index
		if(this->children->empty()){
			Node* noValor = new Node(this->index,"");
			this->children->push_front(noValor);
			this->index = -1;
		}
		this->children->insert_after(this->children->end(),child);
	}
}