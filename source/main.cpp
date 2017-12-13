#include <iostream>
#include <fstream>
#include <string>

#include "texto.h"

int main(int argc, const char *argv[]) {

	Texto texto;

	/*if (argc != 2) {
		std::cout << "Erro: Parâmetros insuficientes.\nTente:\n\tarvrn <arquivo>" << std::endl << std::flush;
		exit(1);
	}*/

	std::ifstream is("entrada.txt");

	if (is.is_open()) {
		while (!is.eof()) {
			char chr;

			is.get(chr);
			texto << std::tolower(chr);
		}

		is.close();
	} else {
		std::cerr << "Não foi possível ler o arquivo \"" << argv[1] << std::endl;
	}

	texto.imprimir_indice();

	return 0;
}
