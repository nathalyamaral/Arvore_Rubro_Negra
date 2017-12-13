#ifndef ITEM_INDICE_H
#define ITEM_INDICE_H

#include <string>
#include <list>

#include "arvrn.h"

class ItemIndice : public No {
	public:
		ItemIndice(const std::string& palavra);
		virtual ~ItemIndice();

		int compara(No* outro);

		std::string str();
		std::string slinhas();

		void palavra( const std::string& palavra);
		std::string palavra() const;

		void add_linha(int linha);
	private:
		std::string m_palavra;
		std::list<int> m_linhas;
};

#endif // ITEM_INDICE_H
