#ifndef NO_H
#define NO_H

#include <string>

#define ARVRN_NO_PRETO    0
#define ARVRN_NO_VERMELHO 1

// Implementação da Arvore Rubro Negra

typedef enum _Cor {
	PRETO = 0,
	VERMELHO
} Cor;

/*
 * Classe abstrata que representa um nó de uma árvore rubro negra.
 *
 * O método compara(...) deve ser implementado e será utilizado pela árvore
 * durante a inserção para decidir se o nó será armazenado à esq ou à
 * dir do nó pai. 
 * */

class No {
	public:
		No(Cor cor);
		No();
		~No();

		/*
		 * método abstrato que deve retornar:
		 * -> -1  se menor que outro
		 * ->  0  se igual ao outro
		 * ->  1  se maior que outro
		 * */

		virtual int compara(No* outro) = 0; 

		virtual std::string str() = 0; // deve representar o objeto através de uma string

		static bool V(No *no);
		static bool P(No *no);

		void mudaCor();
		void cor(Cor cor);
		Cor cor() const;

		void pai(No* n);
		No* pai();

		No* tio();
		No* avo();

		void esq(No *n);
		No* esq();

		void dir(No *n);
		No* dir();

		bool vermelho();
		bool preto();

	private:
		Cor m_cor; // cor do nó

		No *m_p; // nó pai
		No *m_e; // nó filho à esq
		No *m_d; // nó filho à dir
};


#endif // NO_H
