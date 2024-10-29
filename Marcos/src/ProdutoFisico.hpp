#include "Produto.hpp"
#include <iostream>

// Classe derivada de Produto
class ProdutoFisico : public Produto
{
public:
    const double frete = 8; // a constante não está sendo utilizada? se não, remover

    ProdutoFisico(std::string nome, std::string descricao, double valor, int quantidade)
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

    double calcularFrete(int distancia)
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
    ~ProdutoFisico() override {} 
    // como o destrutor da classe base é virtual, o destrutor da classe derivada já o substitui, 
    // não é necessário o uso de `override`. Mas pode ser usado, caso queira deixar explícito
};
