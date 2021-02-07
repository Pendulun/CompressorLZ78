#include "CompressorLZ78.hpp"
namespace compressor{
	void CompressorLZ78::encode(std::string entrada, std::string saida){
		std::ifstream arquivoEntrada;
		arquivoEntrada.open(entrada, std::ifstream::binary);
		std::ofstream arquivoSaida;
		arquivoSaida.open(saida,std::ofstream::out);

    	if(arquivoEntrada.is_open()){
    		if(arquivoSaida.is_open()){
    			Retorno* retorno;
    			Node* ultimoLido;
    			char letra;
    			std::string padraoLido = "";
    			while(arquivoEntrada.get(letra)){
    				std::string proxLetra = "";
					proxLetra+=letra;
					retorno = this->myTrie->pesquisar(padraoLido+proxLetra);
					ultimoLido = retorno->getLastFound();
					if(retorno->getCompleteFound()){
						padraoLido+=proxLetra;
					}else{
						int novoIndice = this->myTrie->getMaxIndex() + 1;
						Node* novoPadrao = new Node(novoIndice,proxLetra);
						std::string saida = "("+std::to_string(retorno->getLastFound()->getIndex())+","+proxLetra+")";
						//arquivoSaida<<saida;
						int index = retorno->getLastFound()->getIndex();
						arquivoSaida.write((char*)(&index),sizeof(int));
						arquivoSaida.write(&letra,sizeof(char));

						this->myTrie->inserirNo(novoPadrao, retorno->getLastFound());
						padraoLido = "";
					}
					delete retorno;
    			}
    			if(padraoLido.compare("") != 0){
    				std::string saida = "("+std::to_string(ultimoLido->getIndex())+","+(char)4+")";
    				//arquivoSaida<<saida;
    				char eof = (char)4;
    				int index = ultimoLido->getIndex();
    				arquivoSaida.write((char*)(&index),sizeof(int));
    				arquivoSaida.write((char*)(&eof),sizeof(char));
    			}
    		//	arquivoSaida<<(char)4;
    		}else{
    			std::cout<<"Nao foi possivel abrir o arquivo de saida"<<std::endl;
    		}
    	}else{
    		std::cout<<"Nao foi possivel abrir o arquivo de entrada"<<std::endl;
    	}

		arquivoEntrada.close();
		arquivoSaida.close();
	}

	void CompressorLZ78::decode(std::string entrada, std::string saida){
		std::ifstream arquivoEntrada;
		arquivoEntrada.open(entrada, std::ifstream::binary);
		arquivoEntrada.unsetf(std::ios_base::skipws);
		std::ofstream arquivoSaida;
		arquivoSaida.open(saida,std::ofstream::out);

		if(arquivoEntrada.is_open()){
    		if(arquivoSaida.is_open()){
    			int* indexNovo = (int*) malloc(sizeof(int));
    			char* letraNova = (char*) malloc(sizeof(char));
    			std::string vazio = "";
    			this->decoder->push_back(std::make_pair(0,vazio));
    			while(arquivoEntrada.read((char*)indexNovo,sizeof(int)) && arquivoEntrada.read(letraNova,sizeof(char))){
    				std::string letraLida = "";
	   				std::string acumulador = "";
    				if(*letraNova != (char)4){
	    				letraLida += *letraNova;
	    				this->decoder->push_back(std::make_pair(*indexNovo,letraLida));
	    			}
	    			acumulador = this->getAcumulado(*indexNovo);
	    			arquivoSaida<<acumulador;
	    			if(*letraNova != (char)4){
	    				arquivoSaida<<letraLida;
	    			}
    			}

    			free(indexNovo);
    			free(letraNova);
    		}else{
    			std::cout<<"Nao foi possivel abrir o arquivo de saida"<<std::endl;
    		}
    	}else{
    		std::cout<<"Nao foi possivel abrir o arquivo de entrada"<<std::endl;
    	}

    	arquivoEntrada.close();
    	arquivoSaida.close();
    	this->decoder->clear();
	}

	std::string CompressorLZ78::getAcumulado(int index){
		std::string acumulador = "";
		while(index != 0){
		    acumulador = this->decoder->at(index).second + acumulador;
		    index = this->decoder->at(index).first;
	    }
	    return acumulador;
	}

	CompressorLZ78::CompressorLZ78(){
		this->myTrie = new TrieEncoder();
		this->decoder = new std::vector<std::pair<int,std::string>>();
	};
	CompressorLZ78::~CompressorLZ78(){
		delete this->myTrie;
		delete this->decoder;
	};
}