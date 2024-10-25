#include <iostream>
#include <set>
#include "Produtos.hpp"

class GerenciadorProdutos
{
public:
    std::set<Produto> produtos;

    void cadastrarProduto(Produto produto)
    {
        produtos.insert(produto);
    }

    // Produto *buscaProduto(std::string nomeProduto)
    // {
    //     for (auto &prod : produtos)
    //     {
    //         if (prod.getNomeProduto() == nomeProduto)
    //         {
    //             return ;
    //         }
    //     }

    //     // produtos.find(produto.nome.equals(NomeProduto));
    //     // Caso não encontre, vai retornar
    //     // this->produtos.end();
    //     // Sugestão: usar std::optional
    // }
    // void atualizarProduto(Produto Produto, )
};