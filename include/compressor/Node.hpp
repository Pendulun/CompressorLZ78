#ifndef NODE_H
#define NODE_H
#include <forward_list>
#include <iterator>
#include <string>
#include <iostream>
namespace compressor{
	class Node{
	private:
		int index;
		std::string letter;
		std::forward_list<Node*> *children;
	public:
		Node(int index, std::string letter);
		~Node();
		int getIndex();
		std::string getLetter();
		void setIndex(int index);
		void setLetter(std::string letter);
		void addChild(Node* child, bool ehRaiz);
		bool possuiFilhos();
		std::forward_list<Node*>* getChildren();
	};
}
#endif