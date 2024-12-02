#ifndef PRODUTODIGITAL_HPP
#define PRODUTODIGITAL_HPP

#include <string>
#include <iostream>
#include "Produto.hpp"

class ProdutoDigital : public Produto
{
public:
    ProdutoDigital(int id_produto, std::string nome, std::string descricao, double valor, int quantidade)
        : Produto(id_produto, nome, descricao, valor, quantidade) {}

    // getters
    std::string getNomeProduto() const override
    {
        return nomeProduto;
    }
    std::string getDescricao() const override
    {
        return descricaoProduto;
    }

    double getPrecoProduto() const override
    {
        return precoProduto;
    }
    int getQuantidadeEstoque() const override
    {
        return quantidadeEstoque;
    }
    int getId_produto() const override{
        return id_produto;
    }
    // setters
    void setDescricao(const std::string &novaDescricao) override
    {
        descricaoProduto = novaDescricao;
    }
    void setNomeProduto(const std::string &novoNomeProduto) override
    {
        nomeProduto = novoNomeProduto;
    }
    void setPrecoProduto(double novoPreco) override
    {
        precoProduto = novoPreco;
    }
    void setQuantidadeEstoque(int novoEstoque) override
    {
        quantidadeEstoque = novoEstoque;
    }

    void print() override
    {
        std::cout << "Produto("
                  << "nome=" << getNomeProduto() << ", "
                  << "descr=" << getDescricao() << ", "
                  << "preço=" << getPrecoProduto() << ", "
                  << "qtd.=" << getQuantidadeEstoque() << ")\n";

    }

    // Destrutor
    //virtual ~ProdutoDigital() = default;
};

#endif