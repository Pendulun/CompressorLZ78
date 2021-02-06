#include "Validador.hpp"


namespace validacao{
	bool Validador::confereExtensaoArquivo(std::string arquivo, std::string extensao){
		if(arquivo.length()>=5){
			if(extensao.compare(0,extensao.length(),arquivo,arquivo.length()-4,4) == 0){
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}
	}

	bool Validador::confereComando(std::string comandoEsperado, std::string comandoRecebido){
		if(comandoEsperado.compare(comandoRecebido) == 0){
			return true;
		}else{
			return false;
		}
	}
}