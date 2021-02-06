#ifndef VALIDADOR_H
#define VALIDADOR_H
#include <string>
namespace validacao{
	class Validador{
	public:
		bool confereExtensaoArquivo(std::string arquivo, std::string extensao);
		bool confereComando(std::string comandoEsperado, std::string comandoRecebido);
	};
}
#endif