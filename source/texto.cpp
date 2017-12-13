#include <iostream>

#include "texto.h"

Texto::Texto() {
    m_linhas = 1;
    m_buf = "";
}

Texto::~Texto() {
}

Texto& Texto::operator<<(char chr) {

   m_conteudo += chr;

   switch (chr) {
      case ':':
      case ',':
      case ';':
      case '.':
      case '?':
      case '!':
      case ' ':
      case '\r':
      case '\n':
      case '\t': {
         if (!m_buf.empty())
            m_indice.inserir(m_linhas, m_buf);

         m_buf = "";

         if (chr == '\n')
            m_linhas++;
      } break;

      default: {
         m_buf += chr;
      }
   }

   return *this;
}

void Texto::imprimir_indice() {
   std::cout << "--------------------------------------------" << std::endl
           	 << m_indice.str()
             << "--------------------------------------------" << std::endl 
			 << m_indice.stridx()
             << "--------------------------------------------" << std::endl 
             << std::flush;
}

void Texto::imprimir_conteudo() {
   std::cout << m_conteudo << std::endl;
}
