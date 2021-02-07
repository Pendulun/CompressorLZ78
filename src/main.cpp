#include <string>
#include <iostream>
#include "Validador.hpp"
#include "Compressor.hpp"
#include "CompressorLZ78.hpp"
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
	compressor::Compressor* compressor = new compressor::CompressorLZ78();
	bool passouComandoDois = true;
	bool temSaida = false;
	validacao::Validador validador;


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
				if(validador.confereExtensaoArquivo(arquivoEntrada, EXTENSAOZ78)){
					if(temSaida){
						if(validador.confereExtensaoArquivo(arquivoSaida, EXTENSAOTXT)){
						compressor->decode(arquivoEntrada,arquivoSaida);
						}else{
							std::cout<<"Extensao do Arquivo de saida nao esta correto"<<std::endl;
						}
					}else{
						arquivoSaida = arquivoEntrada.substr(0,arquivoEntrada.length() - 3)+"txt";
						compressor->decode(arquivoEntrada,arquivoSaida);
					}
				}else{
					std::cout<<"Extensao do Arquivo de entrada nao reconhecida"<<std::endl;
				}
			}else if(validador.confereComando(encode,comandoUm)){
				if(validador.confereExtensaoArquivo(arquivoEntrada, EXTENSAOTXT)){
					if(temSaida){
						if(validador.confereExtensaoArquivo(arquivoSaida, EXTENSAOZ78)){
						compressor->encode(arquivoEntrada,arquivoSaida);
						}else{
							std::cout<<"Extensao do Arquivo de saida nao reconhecida"<<std::endl;
						}
					}else{
						arquivoSaida = arquivoEntrada.substr(0,arquivoEntrada.length() - 3)+"z78";
						compressor->encode(arquivoEntrada,arquivoSaida);
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
	delete compressor;
}