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
						arquivoSaida<<"("<<retorno->getLastFound()->getIndex()<<","<<proxLetra<<")";
						this->myTrie->inserirNo(novoPadrao, retorno->getLastFound());
						padraoLido = "";
					}
					delete retorno;
    			}
    			if(padraoLido.compare("") != 0){
    				arquivoSaida<<"("<<ultimoLido->getIndex()<<","<<(char)4<<")";
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
    			char par1 = ' ', par2 = ' ', virgula = ' ', letra = ' ';
    			int index = 0;
    			std::string vazio = "";
    			this->decoder->push_back(std::make_pair(0,vazio));
    			while(!arquivoEntrada.eof()){
    				while(arquivoEntrada.get(par1)){
	    				std::string letraLida = "";
	   					std::string acumulador = "";
	    				arquivoEntrada>>index;
	    				arquivoEntrada>>virgula;
	    				arquivoEntrada>>letra;
	    				arquivoEntrada>>par2;
	    				if(letra != (char)4){
	    					letraLida += letra;
	    					this->decoder->push_back(std::make_pair(index,letraLida));
	    				}
	    				acumulador = this->getAcumulado(index);
	    				arquivoSaida<<acumulador;
	    				if(letra != (char)4){
	    					arquivoSaida<<letraLida;
	    				}
	    			}
    			}
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