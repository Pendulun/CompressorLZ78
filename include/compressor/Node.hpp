#ifndef NODE_H
#define NODE_H
#include <forward_list>
#include <iterator>
#include <string>
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
		char getLetter();
		void setIndex(int index);
		void setLetter(char letter);
		void addChild(Node* child);
	};
}
#endif