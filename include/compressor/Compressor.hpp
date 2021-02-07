#ifndef COMPRESSOR_H
#define COMPRESSOR_H
#include <string>
#include <iostream>
namespace compressor{
	class Compressor{
	public:
		virtual void encode(std::string, std::string) = 0;
		virtual void decode(std::string, std::string) = 0;
		virtual ~Compressor();
	};
}

#endif