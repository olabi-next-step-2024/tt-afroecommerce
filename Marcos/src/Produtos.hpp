#include <iostream>

class Produto
{
protected:
    std::string nomeProduto, descricaoProduto;
    double valorProduto;
    int estoqueProduto;
    enum tipoProduto
    {
        Fisico,
        Digital
    };

public:
    Produto(std::string nome, std::string descricao, double valor, int quantidade) : nomeProduto(nome), descricaoProduto(descricao), valorProduto(valor), estoqueProduto(quantidade) {}

    Produto(std::string nome, double valor);

    // Getter e Setters
    virtual std::string getNomeProduto() const = 0;

    void setNomeProduto(std::string nome)
    {
        this->nomeProduto = nome;
    };

    std::string getDescricao() const
    {
        return descricaoProduto;
    }

    void setDescricao(std::string descricao)
    {
        this->descricaoProduto = descricao;
    }

    double getValorProduto() // é interessante manter os getters como const
    {
        return valorProduto;
    }

    void setValorProduto(double valor)
    {
        this->valorProduto = valor;
    }

    int getEstoqueProduto()
    {
        return estoqueProduto;
    }

    void setEstoqueProduto(int quantidadeProduto)
    {
        this->estoqueProduto = quantidadeProduto;
    }
};

class ProdutoFisico : public Produto
{
public:
    ProdutoFisico(std::string nome, std::string descricao, double valor, int quantidade)
        : Produto(nome, descricao, valor, quantidade) {}
};

// E produto digital?