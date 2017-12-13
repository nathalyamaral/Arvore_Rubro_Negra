#include <sstream>
#include <iomanip>

#include "indice.h"

Indice::Indice() {
}

Indice::~Indice() {
}

void Indice::inserir(int linha, const std::string& palavra) {
	ItemIndice *novo = new ItemIndice(palavra);
	ItemIndice *existente = dynamic_cast<ItemIndice*>(buscar(novo));

	if (existente) {
		existente->add_linha(linha);
		delete novo;
	} else {
		novo->add_linha(linha);
		ArvoreRN::inserir(novo);
	}
}

std::string Indice::str() {
	std::string r = "";
	std::stringstream ss(r);

	for (int i = 0; i <= altura(raiz()); i++) {
		ss << str(raiz(), i) << std::endl;
	}

	return ss.str();
}

std::string Indice::str(No *no, int altura) {
	std::string r = "";
	std::stringstream ss(r);

	if (no) {
		if (altura > 0) {
			ss << str(no->esq(), altura - 1);
			ss << str(no->dir(), altura - 1);
		} else {
			ss << no->str() << " ";
		}
	}

	return ss.str();
}


std::string Indice::stridx() {
	return stridx(dynamic_cast<ItemIndice*>(raiz()));
}

std::string Indice::stridx(ItemIndice *item) {
	std::string s("");
	std::stringstream ss(s);

	if (item) {
		ss << item->slinhas()
		   << stridx(dynamic_cast<ItemIndice*>(item->esq()))
		   << stridx(dynamic_cast<ItemIndice*>(item->dir()));
	}

	return ss.str();
}
