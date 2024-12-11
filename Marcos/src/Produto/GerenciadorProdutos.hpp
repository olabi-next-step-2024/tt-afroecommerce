#ifndef GERENCIADORPRODUTOS_HPP
#define GERENCIADORPRODUTOS_HPP

#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include "Produto.hpp"

// typedef std::vector<std::shared_ptr<Produto>> ListaProdutos;

class GerenciadorProdutos
{
    std::map<int, std::shared_ptr<Produto>> produtos{};

public:
    // Função para cadastrar produtos (passando ponteiro para Produto)
    void cadastrarProduto(std::shared_ptr<Produto> produto)
    {
        int idProduto = produto->getId_produto();
        if (produtos.find(idProduto) != produtos.end())
        {
            std::cout << "Produto com o id '" << idProduto << "' já existe!" << std::endl;
            return;
        }
        produtos[idProduto] = produto;
        std::cout << "Inserindo produto: "; produto->print();
    }

    // Função para mostrar informações dos produtos cadastrados
    void mostrarProdutos() noexcept
    {
        std::cout << "\nMostrando todos os produtos: \n\n";
        for (const auto &[idProduto, produto] : produtos)
        {
            produto->print();
        }
        putchar('\n');
    }

    // Função para buscar produto pelo nome
    std::shared_ptr<Produto> buscaProduto(int idProduto)
    {
        auto it = produtos.find(idProduto);
        return (it != produtos.end()) ? it->second : nullptr;
    }

    // std::shared_ptr<Produto> buscaProduto(int id_produto) // Tipos primitivos por referência: https://stackoverflow.com/questions/14013139/is-it-counter-productive-to-pass-primitive-types-by-reference
    // {
    // 	auto it = produtos.find(id_produto);
    //     return (it != produtos.end()) ? it->second : nullptr;
    // }

    // Função para deletar produto pelo nome
    void deletarProduto(int idProduto)
    {
        auto it = produtos.find(idProduto);
        if (it == produtos.end())
        {
            std::cout << "Produto não encontrado" << std::endl;
            return;
        }
        produtos.erase(it); // Remove o produto do map
        std::cout << "Produto deletado com sucesso!" << std::endl;
    }

    // Função para atualizar produto
    void atualizarProduto(std::shared_ptr<Produto> produto,
                          int idProduto,
                          const std::string &novoNome = "",
                          const std::string &novaDescricao = "",
                          double novoPreco = -1,
                          int novoEstoque = -1)
    {


		// produto_novo(produto_old.getName(), "DESCRICAO_NOVA", produto_old.getPrice(), )
		// if (produto_novo.getId() == idProduto) {
		// 	produtos[idProduto] = produto;
		// }

        if (!produto)
        {
            std::cout << "Produto não encontrado para atualizar." << std::endl;
            return;
        }

        if (!novoNome.empty())
        {
            const std::string antigoNome = produto->getNomeProduto();
            produto->setNomeProduto(novoNome);

            if (antigoNome != novoNome)
            {
                // Renomeia o produto no mapa
                produtos[idProduto] = produto;
                //produtos.erase(antigoNome);
            }
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
};

#endif