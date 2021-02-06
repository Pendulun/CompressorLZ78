#include <string>
#include <iostream>
#include "Validador.hpp"
#define EXTENSAOZ78 ".z78"
#define EXTENSAOTXT ".txt"

int main(int argc, char *argv[]){
	std::string const decode = "-x";
	std::string const encode = "-c";
	std::string const output = "-o";
	std::string arquivoSaida = "";
	std::string arquivoEntrada = "";
	std::string comandoUm = "";
	std::string comandoDois = "";
	bool passouComandoDois = true;
	bool temSaida = false;
	Validacao::Validador validador;


	if(argc == 5){
		comandoDois += argv[3];
		if(!validador.confereComando(output,comandoDois)){
			std::cout<<"Segundo comando so pode ser o de output \'-o\'"<<std::endl;
			passouComandoDois = false;
		}else{
			temSaida = true;
			arquivoSaida = argv[4];
		}
	}

	if(passouComandoDois){
		if(argc >= 3){
			comandoUm = argv[1];
			arquivoEntrada += argv[2];
			if(validador.confereComando(decode,comandoUm)){
				std::cout<<"eh para descomprimir"<<std::endl;
				if(validador.confereExtensaoArquivo(arquivoEntrada, EXTENSAOZ78)){
					std::cout<<"Aceitou o arquivo"<<std::endl;
					if(temSaida){
						if(validador.confereExtensaoArquivo(arquivoSaida, EXTENSAOTXT)){
						// Descomprime arquivo com nome de saida passado
						}else{
							std::cout<<"Extensao do Arquivo de saida nao esta correto"<<std::endl;
						}
					}else{
						// Descomprime arquivo com nome de saida igual entrada
					}
				}else{
					std::cout<<"Extensao do Arquivo de entrada nao reconhecida"<<std::endl;
				}
			}else if(validador.confereComando(encode,comandoUm)){
				std::cout<<"eh para descomprimir"<<std::endl;
				if(validador.confereExtensaoArquivo(arquivoEntrada, EXTENSAOTXT)){
					std::cout<<"Aceitou o arquivo"<<std::endl;
					if(temSaida){
						if(validador.confereExtensaoArquivo(arquivoSaida, EXTENSAOZ78)){
						// Comprime arquivo com nome de saida passado
						}else{
							std::cout<<"Extensao do Arquivo de saida nao reconhecida"<<std::endl;
						}
					}else{
						// Comprime arquivo com nome de saida igual entrada
					}
				}else{
					std::cout<<"Extensao do Arquivo de entrada nao esta correto"<<std::endl;
				}
			}else{
					std::cout<<"Erro! Comando nao aceito. O primeiro comando deve ser ";
					std::cout<<"\'-c\' ou \'-x\'"<<std::endl;
			}
		}else{
			std::cout<<"Nao foram passados comandos suficientes"<<std::endl;
		}
	}
}