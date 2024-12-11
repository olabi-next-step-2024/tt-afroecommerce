#ifndef CARRINHO_HPP
#define CARRINHO_HPP

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <map>
#include <vector>
#include "../Produto/Produto.hpp"
#include "../Produto/GerenciadorProdutos.hpp"

class Carrinho
{
protected:
    std::map<int, int> produtos{}; // usar id_produto
    float total = 0;
    GerenciadorProdutos gerenciador{};

public:
    Carrinho(std::map<int, int> produtos) : produtos(produtos) {}

    Carrinho() : produtos() {}

    void esvaziarCarrinho()
    {
        if (!produtos.empty())
            produtos.clear();
    }

   void adicionarProduto(std::shared_ptr<Produto> produto, int quantidade) {
        if (produto->getQuantidadeEstoque() >= quantidade) {
            produtos[produto->getId_produto()] += quantidade;
            produto->atualizar_estoque(-quantidade);
            std::cout << "Produto adicionado ao carrinho com sucesso.\n";
            calcular_total();
        } else {
            std::cout << "Estoque insuficiente para o produto.\n";
        }
    }
    // Função para deletar produto pelo nome
    void removerProduto(std::shared_ptr<Produto> produto, int quantidade) {
        auto it = produtos.find(produto->getId_produto());
        if (it != produtos.end()) {
            if (quantidade >= it->second) {
                // Remove completamente o produto do carrinho
                produto->atualizar_estoque(it->second);
                produtos.erase(it);
            } else {
                // Remove apenas a quantidade especificada
                it->second -= quantidade;
                produto->atualizar_estoque(quantidade);
            }
            std::cout << "Produto removido do carrinho com sucesso.\n";
            calcular_total();
        } else {
            std::cout << "Produto não encontrado no carrinho.\n";
        }
    }

    void calcular_total() {
        total = 0;  // Reinicializa o total
        for (const auto& [idProduto, quantidade] : produtos) {
            auto produto = gerenciador.buscaProduto(idProduto);
            if (produto) {
                total += produto->getPrecoProduto() * quantidade;
            } else {
                std::cout << "Erro: Produto com ID " << idProduto << " não encontrado.\n";
            }
        }
    }

    float getTotal(){
        return total;
    }

    const std::map<int, int>& getProdutos() const {
        return produtos;
    }

};

#endif