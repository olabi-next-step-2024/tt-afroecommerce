#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <vector>
#include "src/Produto/Produto.hpp"

class Carrinho
{
protected:
    std::vector<Produto *> produtos;

public:
    Carrinho(std::vector<Produto *> produtos) : produtos(produtos) {}

     Carrinho() : produtos() {}

    void esvaziarCarrinho()
    {
        if (!produtos.empty())
            produtos.clear();
    }

    void adicionarProduto(Produto *produto)
    {
        std::cout << "Produto adicionado com sucesso dentro do carrinho";
        produtos.push_back(produto);
    }

    Produto *buscaProduto(const std::string &nomeProduto)
    {
        auto it = std::find_if(produtos.begin(), produtos.end(),
                               [&nomeProduto](Produto *x)
                               { return x->getNomeProduto() == nomeProduto; });

        return (it != produtos.end()) ? *it : nullptr;
    }

    // Função para deletar produto pelo nome
    void deletarProduto(const std::string &nomeProduto)
    {
        auto it = std::find_if(produtos.begin(), produtos.end(),
                               [&nomeProduto](Produto *x)
                               { return x->getNomeProduto() == nomeProduto; });

        if (it == produtos.end())
        {
            std::cout << "Produto não encontrado" << std::endl;
            return;
        }

        delete *it;         // Libera a memória do produto
        produtos.erase(it); // Remove o ponteiro do vetor
        std::cout << "Produto deletado com sucesso!" << std::endl;
    }
};