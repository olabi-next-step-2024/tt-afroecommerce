#include <iostream>
#include <vector>
#include "Produto.hpp"

class GerenciadorProdutos
{
public:
    std::vector<Produto*> produtos; 

    // Função para cadastrar produtos (passando ponteiro para Produto)
    void cadastrarProduto(Produto* produto)
    {
        produtos.push_back(produto);
    }

    // Função para mostrar informações dos produtos cadastrados
    void mostrarProdutos()
    {
        for (const auto &produto : produtos)
        {
            produto->print();
        }
    }

    // Função para buscar produto pelo nome
    Produto* buscaProduto(const std::string& nomeProduto)
    {
        for (auto &prod : produtos)
        {
            if (prod->getNomeProduto() == nomeProduto)
            {
                return prod; // Retorna ponteiro para o produto encontrado
            }
        }
        return nullptr; // Retorna nullptr se não encontrar
    }

    void atualizarProduto(Produto* produto, 
                          const std::string& novoNome = "", 
                          const std::string& novaDescricao = "", 
                          double novoPreco = -1, 
                          int novoEstoque = -1)
    {
        if (novoNome != "") {
            produto->setNomeProduto(novoNome);
        }

        if (novaDescricao != "") {
            produto->setDescricao(novaDescricao);
        }

        if (novoPreco != -1) {
            produto->setPrecoProduto(novoPreco);
        }

        if (novoEstoque != -1) {
            produto->setQuantidadeEstoque(novoEstoque);
        }
    };

    // Destrutor para liberar memória
    ~GerenciadorProdutos()
    {
        
        for (auto &produto : produtos)
        {
            delete produto;
        }
    }
};
