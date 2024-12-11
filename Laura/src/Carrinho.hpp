#ifndef CARRINHO_HPP
#define CARRINHO_HPP

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "ItemCarrinho.hpp"
#include "Produto.hpp"

class Carrinho
{
private:
    std::vector<std::shared_ptr<ItemCarrinho>> itens;

public:
    void adicionarItem(const Produto produto, int quantidade)
    // Se for usar Produto como instância, ñ como ponteiro, o ideal é receber por referência
    // mas para usar polimorfismo, determinando em tempo de execução se o Produto é físico ou Digital, o ideal seria usar ponteiro (smart pointer)
    {
        for (auto item : itens)
        {
            if (item->getProduto().getNome() == produto.getNome())
            {
                item->setQtd(quantidade); // setQtd ainda não foi implementado
                return;
            }
        }
        itens.emplace_back(produto, quantidade);
    }

    /*void removerItem(const Produto &produto)
    {
        itens.erase(std::remove_if(itens.begin(), itens.end(), [&produto](const ItemCarrinho &item) // adicionar <algorithm> para remove_if
                                   { item->getProduto().getNome() == produto->getNome(); }),        // item aqui é instância e não ponteiro, seria no caso `.` em vez de `->`
                    itens.end());
    }*/
};

#endif