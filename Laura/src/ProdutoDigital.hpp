#ifndef PRODUTODIGITAL_HPP
#define PRODUTODIGITAL_HPP

#include <iostream>
#include "Produto.hpp"

class ProdutoDigital : public Produto
{
    private:
    std::string tipoArquivo;

    public:

    ProdutoDigital(int id, std::string descricao, std::string nome, double preco, std::string tipoArquivo)
        : Produto(id, descricao, nome, preco), tipoArquivo(tipoArquivo) {}

    std::string getTipoArquivo(){
        return tipoArquivo;
    }
    

};

#endif