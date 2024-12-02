#ifndef PRODUTOFISICO_HPP
#define PRODUTOFISICO_HPP

#include <iostream>
#include "Produto.hpp"

// Classe derivada de Produto
class ProdutoFisico : public Produto
{
public:

    ProdutoFisico(int id_produto, std::string nome, std::string descricao, double valor, int quantidade)
        : Produto(id_produto,nome, descricao, valor, quantidade) {}

    // getters
    double getPrecoProduto() const override
    {
        return precoProduto;
    }
    std::string getNomeProduto() const override
    {
        return nomeProduto;
    }
    std::string getDescricao() const override
    {
        return descricaoProduto;
    }
    int getQuantidadeEstoque() const override
    {
        return quantidadeEstoque;
    }
    int getId_produto() const override{
        return id_produto;
    }
    // setters
    void setNomeProduto(const std::string &novoNomeProduto) override
    {
        nomeProduto = novoNomeProduto;
    }

    void setDescricao(const std::string &novaDescricao) override
    {
        descricaoProduto = novaDescricao;
    }

    void setPrecoProduto(double novoPreco) override
    {
        precoProduto = novoPreco;
    }

    void setQuantidadeEstoque(int novoEstoque) override
    {
        quantidadeEstoque = novoEstoque;
    }

    double calcularFrete(float distancia)
    {
        double valorFrete = 0;
        if (distancia > 15 && distancia <= 30)
        {
            return distancia * (valorFrete + 2);
        }
        else if (distancia > 30)
        {
            return distancia * (valorFrete + 5);
        }
        return valorFrete * distancia;
    }

    // Converter para ser printável via ostream com cout;
    void print() override
    {
        std::cout << "Produto("
                  << "nome=" << getNomeProduto() << ", "
                  << "descr.=" << getDescricao() << ", "
                  << "preço=" << getPrecoProduto() << ", "
                  << "qtd.=" << getQuantidadeEstoque() << ")\n";
    }

    // Destrutor se necessário
    //virtual ~ProdutoFisico() = default;
    // como o destrutor da classe base é virtual, o destrutor da classe derivada já o substitui,
    // não é necessário o uso de `override`. Mas pode ser usado, caso queira deixar explícito
};

#endif