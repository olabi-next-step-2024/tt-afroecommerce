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

    void adicionarProduto(std::shared_ptr<Produto> produto, int quantidade)
    {
        if (produto->getQuantidadeEstoque() >= quantidade)
        {
            produtos[produto->getId_produto()] += quantidade;
            produto->atualizar_estoque(-quantidade);
            std::cout << "Produto adicionado com sucesso dentro do carrinho";
        }
        else
        {
            std::cout << "Estoque insuficiente para o produto" << std::endl;
        }
    }
    // Função para deletar produto pelo nome
    void remover_produto(std::shared_ptr<Produto> produto, int quantidade)
    {
        if (produtos.find(produto->getId_produto()) != produtos.end())
        {
            if (quantidade >= produtos[produto->getId_produto()])
            {
                produto->atualizar_estoque(produtos[produto->getId_produto()]);
                produtos.erase(produto->getId_produto());
            }
            else
            {
                produtos[produto->getId_produto()] -= quantidade;
                produto->atualizar_estoque(quantidade);
            }
            calcular_total();
        }
    }

    void calcular_total()
    {
        for (const auto &[nome, quantidade] : produtos)
        {
            auto p = gerenciador.buscaProduto(nome);
            total += p->getPrecoProduto() * quantidade;
        }
    }

    

    // void efetuar_compra() {

    // }

    // Produto *buscaProduto(const std::string &nomeProduto)
    // {
    //     for (auto &produto : produtos)
    //     {
    //         auto it = std::find_if(produtos.begin(), produtos.end(),
    //                                [&nomeProduto](Produto *x)
    //                                { return x->getNomeProduto() == nomeProduto; });
    //     }

    //     return (it != produtos.end()) ? *it : nullptr;
    // }
};