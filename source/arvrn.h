#ifndef ARVRN_H
#define ARVRN_H

#include <string>

#include "no.h"

class ArvoreRN {
	public:
		ArvoreRN();
		virtual ~ArvoreRN();

		/*
		 * Método virtual/abstrato que deve representar a árvore em uma string
		 **/

		virtual std::string str() = 0;

		/* 
		 * Método de inserção de um novo nó na árvore
		 **/

		void inserir(No *no);

		/* 
		 * Método de busca na árvore
		 * Condição utilizada é o método compara() da classe nó (Ex. no->compara(outro_no) == 0)
		 **/ 

		No* buscar(No *no);

		/*
		 * retorna a raiz da árvore
		 **/

		No* raiz();

		/*
		 * Calcula a altura da árvore (distância entre a raiz e a folha mais distante)
		 **/

		int altura();

		/*
		 * Calcula a distância entre um nó e sua folha mais distante
		 **/

		int altura(No* no);
	private:
		/*
		 * Métodos de Balanceamento
		 * A partir de um nó de referência, efetua a operação e retorna um novo nó de referência (pai)
		 **/

		No* balancear(No *no);
		No* rotacionarEsquerda(No *no);
		No* rotacionarDireita(No *no);
	private:
		No *m_raiz;
};

#endif // ARVRN_H
