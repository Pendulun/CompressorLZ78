#ifndef RETORNO_H
#define RETORNO_H
#include "Node.hpp"
namespace compressor{
	class Retorno{
	private:
		Node* lastFound;
		bool completeFound;
	public:
		Node* getLastFound();
		bool getCompleteFound();
		Retorno(Node*,bool);
		~Retorno();
	};
}
#endif