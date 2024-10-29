#include <iostream>
#include <vector>
#include <optional>
#include <iterator>
#include <algorithm>
#include "Produto.hpp"

class GerenciadorProdutos
{
public:
    std::vector<Produto *> produtos{};

    // Função para cadastrar produtos (passando ponteiro para Produto)
    void cadastrarProduto(Produto *produto)
    {
        std::cout << "Inserindo produto: "; produto->print();
        produtos.push_back(produto);
    }

    // Função para mostrar informações dos produtos cadastrados
    void mostrarProdutos() noexcept
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
        // Dica: substituir por std::find passando uma função que retorna
        // se o nome do produto atual é igual ao nomeProduto passado por
        // parâmetro

        // https://en.cppreference.com/w/cpp/algorithm/find
        auto it = std::find_if(produtos.begin(), produtos.end(),
                               // [&nomeProduto](const Produto &x)
                               [&nomeProduto](const Produto *x)
                               { return x->getNomeProduto() == nomeProduto; });

        if (it != produtos.end())
        {
            return *it;
        }
        
        // std::cout << "Produto não encontrado" << std::endl;;
        return nullptr;

    }

    /*Produto *pesquisar(const std::string &nomeProduto)
    {
        for (auto &prod : produtos)
        {
            if (prod->getNomeProduto() == nomeProduto)
            {
                return prod; // Retorna ponteiro para o produto encontrado
            }
        }
        return new ProdutoDigital("", "", -1, -1);
    }*/

    // [BUG]
     void deletarProduto(const std::string &nomeProduto)
     {
         auto produto = std::remove_if(produtos.begin(), produtos.end(), [&nomeProduto](const Produto *x)
                                       { return x->getNomeProduto() == nomeProduto; });
         if (produto == produtos.end())
         {
             std::cout << "Produto não encontrado" << std::endl;
         }

        return;
     }

    void atualizarProduto(Produto *produto,
                          const std::string &novoNome = "",
                          const std::string &novaDescricao = "",
                          double novoPreco = -1,
                          int novoEstoque = -1)
    {
        if (novoNome != "")
        {
            produto->setNomeProduto(novoNome);
        }

        if (novaDescricao != "")
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
    };

    // Destrutor para liberar memória
    ~GerenciadorProdutos()
    {
        // Usar smart pointer faria com que gerenciássemos automaticamente a liberação da memória alocada
        for (auto &produto : produtos)
        {
            delete produto;
        }
    }
};
