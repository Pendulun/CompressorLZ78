#include "CompressorZL78.hpp"

namespace compressor{
	void CompressorZL78::encode(std::string entrada, std::string saida){
		std::cout<<"Encode CompressorZL78"<<std::endl;
		std::ifstream arquivoEntrada;
		arquivoEntrada.open(entrada, std::ifstream::binary);
		std::ofstream arquivoSaida;
		arquivoSaida.open(saida,std::ofstream::out);
		arquivoEntrada.seekg (0, arquivoEntrada.end);
    	int length = arquivoEntrada.tellg();
    	arquivoEntrada.seekg (0, arquivoEntrada.beg);

		char * buffer = new char [length];
		arquivoEntrada.read(buffer,length);

		std::string padraoLido = "";
		for(int i =0; i<length;i++){
			std::cout<<"Letra lida: "<<buffer[i]<<std::endl;
		}

		arquivoEntrada.close();
		arquivoSaida.close();
		delete[] buffer;
	}

	void CompressorZL78::decode(std::string entrada, std::string saida){
		std::cout<<"Decode CompressorZL78"<<std::endl;
	}

	CompressorZL78::CompressorZL78(){
		std::cout<<"CompressorZL78 CONSTRUTOR"<<std::endl;
		this->myTrie = new TrieEncoder();
	};
	CompressorZL78::~CompressorZL78(){
		std::cout<<"CompressorZL78 DESTRUTOR"<<std::endl;
		delete this->myTrie;
	};
}