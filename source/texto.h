#ifndef TEXTO_H
#define TEXTO_H

#include <string>
#include <list>

#include "indice.h"

class Texto {
	public:
		Texto();
		~Texto();

		static Texto fromFile(const std::string& file);

		void imprimir_indice();
		void imprimir_conteudo();

		Texto& operator<<(char chr);

	protected:
		void add_palavra(const std::string& palavra);

	private:
		int m_linhas;
		Indice m_indice;
		std::string m_buf;
		std::string m_conteudo;
};

#endif // TEXTO_H
