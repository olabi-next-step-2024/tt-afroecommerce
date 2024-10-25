#include <iostream>
#include <string>
#include "Produto.hpp"

class ProdutoDigital : public Produto
{
public:
    ProdutoDigital(std::string nome, std::string descricao, double valor, int quantidade)
        : Produto(nome, descricao, valor, quantidade) {}

    std::string getNomeProduto() const override
    {
        return nomeProduto;
    }

    void setNomeProduto(const std::string &novoNomeProduto) override
    {
        nomeProduto = novoNomeProduto;
    }

    std::string getDescricao() const override
    {
        return descricaoProduto;
    }

    void setDescricao(const std::string &novaDescricao) override
    {
        descricaoProduto = novaDescricao;
    }

    double getPrecoProduto() const override
    {
        return precoProduto;
    }

    void setPrecoProduto(double novoPreco) override
    {
        precoProduto = novoPreco;
    }

    int getQuantidadeEstoque() const override
    {
        return quantidadeEstoque;
    }

    void setQuantidadeEstoque(int novoEstoque) override
    {
        quantidadeEstoque = novoEstoque;
    }

    void print() override
    {
        std::cout << "Nome: " << getNomeProduto() << std::endl;
        std::cout << "Descrição: " << getDescricao() << std::endl;
        std::cout << "Preço: " << getPrecoProduto() << std::endl;
        std::cout << "Estoque: " << getQuantidadeEstoque() << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }

    // Destrutor
    ~ProdutoDigital() override {}
};