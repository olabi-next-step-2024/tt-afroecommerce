#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Produto.hpp"

class GerenciadorProdutos
{
public:
    std::vector<Produto *> produtos;

    // Função para cadastrar produtos (passando ponteiro para Produto)
    void cadastrarProduto(Produto *produto)
    {
        std::cout << "Inserindo produto: ";
        produto->print();
        produtos.push_back(produto);
    }

    // Função para mostrar informações dos produtos cadastrados
    void mostrarProdutos() const noexcept
    {
        std::cout << "\nMostrando todos os produtos: \n\n";
        for (const auto &produto : produtos)
        {
            produto->print();
        }
        putchar('\n');
    }

    // Função para buscar produto pelo nome
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

    void atualizarProduto(Produto *produto,
                          const std::string &novoNome = "",
                          const std::string &novaDescricao = "",
                          double novoPreco = -1,
                          int novoEstoque = -1)
    {
        if (!produto)
        {
            std::cout << "Produto não encontrado para atualizar." << std::endl;
            return;
        }

        if (!novoNome.empty())
        {
            produto->setNomeProduto(novoNome);
        }

        if (!novaDescricao.empty())
        {
            produto->setDescricao(novaDescricao);
        }

        if (novoPreco != -1)
        {
            produto->setPrecoProduto(novoPreco);
        }

        if (novoEstoque != -1)
        {
            produto->setQuantidadeEstoque(novoEstoque);
        }
    }

    // Destrutor para liberar memória
    ~GerenciadorProdutos()
    {
        for (auto &produto : produtos)
        {
            delete produto;
        }
    }
};
