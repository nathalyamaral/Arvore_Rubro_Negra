#ifndef INDICE_H
#define INDICE_H

#include "arvrn.h"
#include "item_indice.h"

class Indice : ArvoreRN {
	public:
		Indice();
		virtual ~Indice();

		void inserir(int linha, const std::string& palavra);

		std::string str();
		std::string stridx();

	private:
		std::string str(No *no, int altura);
		std::string stridx(ItemIndice *item);
};

#endif // INDICE_H
