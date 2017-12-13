#include "no.h"

No::No(Cor cor) {
	this->m_cor = cor;
	this->m_p = NULL;
	this->m_e = NULL;
	this->m_d = NULL;
}

No::No() :
 No(VERMELHO) {
}

No::~No() {
}

bool No::V(No *no) {
	return (no && no->vermelho());
}

bool No::P(No *no) {
	return (!no || no->preto());
}

void No::cor(Cor cor) {
	this->m_cor = cor;
}

Cor No::cor() const {
	return this->m_cor;
}

void No::mudaCor() {
	if (vermelho())
		cor(PRETO);
	else
		cor(VERMELHO);
}

void No::pai(No* n) {
	this->m_p = n;
}

No* No::pai() {
	return this->m_p;
}

No* No::avo() {
	return (this->m_p) ? this->m_p->pai() : NULL;
}

No* No::tio() {
	No *a = this->avo();
	No *t = NULL;

	if (a)
		t = (pai() == a->m_d) ? a->m_e : a->m_d;

	return t;
}

void No::esq(No *n) {
	this->m_e = n;

	if (n)
		n->pai(this);
}

No* No::esq() {
	return this->m_e;
}

void No::dir(No *n) {
	this->m_d = n;

	if (n)
		n->pai(this);
}

No* No::dir() {
	return this->m_d;
}

bool No::vermelho() {
	return (m_cor == VERMELHO);
}

bool No::preto() {
	return (m_cor == PRETO);
}

