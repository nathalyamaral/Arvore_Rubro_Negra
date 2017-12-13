#include <sstream>
#include <algorithm>

#include "indice.h"

ItemIndice::ItemIndice(const std::string& palavra)
  : No(), m_linhas(){
	m_palavra = palavra;
}

ItemIndice::~ItemIndice() {
}

int ItemIndice::compara(No* outro) {
	int result = 0;
	ItemIndice *po = dynamic_cast<ItemIndice*>(outro);

	if (po && m_palavra > po->palavra())
		result = 1;
	else if (po && m_palavra < po->palavra())
		result = -1;

	return result;
}

std::string ItemIndice::str() {
	std::string result = "";
	std::stringstream ss(result);

	ss << ((esq() != NULL) ? "/" : "*")
	   << "(" << palavra()
	   << " [" << ((cor() == PRETO) ? "N" : "R") << "]"
	   << ")"
	   << ((dir() != NULL) ? "\\" : "* ");

	return ss.str();
}

std::string ItemIndice::slinhas() {
	std::string s("");
	std::stringstream ss(s);
	std::list<int>::iterator it;

	ss << m_palavra << ": ";

	for (it = m_linhas.begin(); it != m_linhas.end(); ++it) {
		if (it != m_linhas.begin()) ss << ",";
		ss << *it;	
	}

	ss << std::endl;

	return ss.str();
}

void ItemIndice::palavra(const std::string& palavra) {
	m_palavra = palavra;
}

std::string ItemIndice::palavra() const {
	return m_palavra;
}

void ItemIndice::add_linha(int linha) {
	std::list<int>::iterator it = std::find(m_linhas.begin(), m_linhas.end(), linha);

	if (it == m_linhas.end())
		m_linhas.push_back(linha);
}
