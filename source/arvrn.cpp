#include "arvrn.h"

ArvoreRN::ArvoreRN() {
	this->m_raiz = NULL;
}

ArvoreRN::~ArvoreRN() {
}

int ArvoreRN::altura() {
	return altura(m_raiz);
}

int ArvoreRN::altura(No* no) {
	int hl = 0, hr = 0;

	if (no) {
		hl = (no->esq()) ? altura(no->esq()) + 1 : hl;
		hr = (no->dir()) ? altura(no->dir()) + 1 : hl;
	}

	return (hl >= hr) ? hl : hr;
}

No* ArvoreRN::raiz() {
	return m_raiz;
}

void ArvoreRN::inserir(No *no) {

	if (!this->m_raiz) {
		this->m_raiz = no;
		this->m_raiz->cor(PRETO);
	} else {
		No *p = this->m_raiz;

		while (p) {
			int r = no->compara(p);

			if (r >= 0) {
				if (p->dir()) 
					p = p->dir();
				else {
					no->pai(p);
					p->dir(no);
					break;
				}
			} else if (r < 0) {
				if (p->esq())
					p = p->esq();
				else {
					no->pai(p);
					p->esq(no);
					break;
				}
			} else {
				p = NULL;
			}
		} // while

		while (p != NULL) {
			p = balancear(p);
			p = p->pai();
		}

		if (m_raiz->vermelho())
			m_raiz->mudaCor();
	} // if
}

No* ArvoreRN::buscar(No* no) {
	No *p = this->m_raiz;

	while (p) {
		if (no->compara(p) > 0)  {
			p = p->dir();
		} else if (no->compara(p) < 0) {
			p = p->esq();
		} else {
			break; // encontrado
		}
	}

	return p;
}

No* ArvoreRN::balancear(No *no) {
	No *aux = no;

	/* Condição 1: se no à direita for vermelho, rotaciona à esquerda */

	if (No::V(no->dir()) && No::P(no->esq()))  {
		aux = rotacionarEsquerda(aux);
	}

	No *ee = (aux->esq()) ? aux->esq()->esq() : NULL;

	/* Condição 2: se o filho à esquerda não for nulo, o filho da direita for vermelho e o neto da esquerda for vermelho, rotaciona à Direita */

	if (No::V(aux->esq()) && No::V(ee)) {
		aux = rotacionarDireita(aux);
	}

	/* Condição 3: se o filho à esquerda for vermelho e o filho da direita for vermelho, troca a cor dos nós envolvidos */

	if (No::V(aux->esq()) && No::V(aux->dir())) {
		aux->mudaCor();
		
		if (aux->esq()) aux->esq()->mudaCor();
		if (aux->dir()) aux->dir()->mudaCor();
	}

	return aux;
}

No* ArvoreRN::rotacionarEsquerda(No *no) {
	No *pai = no->pai();
	No *dir = no->dir();

	if (dir) {
		no->dir(dir->esq());
		dir->esq(no);

		if (pai && pai->esq() == no) {
			pai->esq(dir);
		} else if (pai && pai->dir() == no) {
			pai->dir(dir);
		} else  {
			m_raiz = dir;
			m_raiz->pai(NULL);
		}
	}
	
	dir->cor(no->cor());
	no->cor(VERMELHO);

	return (dir);
}

No* ArvoreRN::rotacionarDireita(No *no) {
	No *pai = no->pai();
	No *esq = no->esq();

	if (esq) {
		no->esq(esq->dir());
		esq->dir(no);

		if (pai && pai->esq() == no) {
			pai->esq(esq);
		} else if (pai && pai->dir() == no) {
			pai->dir(esq);
		} else  {
			m_raiz = esq;
			m_raiz->pai(NULL);
		}
	}

	esq->cor(no->cor());
	no->cor(VERMELHO);

	return esq;
}

