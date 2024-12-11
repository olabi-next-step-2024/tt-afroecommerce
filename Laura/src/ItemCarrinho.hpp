#ifndef ITEMCARRINHO_HPP
#define ITEMCARRINHO_HPP

#include <iostream>
#include <memory>
#include <vector>
#include "Produto.hpp"

class ItemCarrinho
{

private:
    Produto produto; // Algo como: std::shared_ptr<Produto> produto;
    int quantidade;

public:
    
    ItemCarrinho(const Produto &produto, int quanridade) : produto(produto), quantidade(quantidade) {}

    Produto getProduto()
    {
        return produto;
    }

    int getQtd() const {
        return quantidade;
    }

    int setQtd(int quantidade){
        return quantidade;
    }

};

#endiftQtd()int quantidade{}
        this.quantidade=quantidade;
    