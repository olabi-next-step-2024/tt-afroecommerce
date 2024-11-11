// Produto.hpp
#ifndef PRODUTO_HPP // Se PRODUTO_HPP não foi definido ainda
#define PRODUTO_HPP // Define PRODUTO_HPP para evitar inclusões futuras

#include <string>

class Produto
{
protected:
    std::string nomeProduto, descricaoProduto;
    double precoProduto;
    int quantidadeEstoque;
    enum tipoProduto
    {
        Fisico,
        Digital
    };

    // Se não sabe exatamente quantas categorias 
    enum categoria
    {
        Categoria1,
        Categoria2,
        Categoria3,
        Categoria4
    };

public:
    Produto(std::string nome, std::string descricao, double valor, int quantidade)
        : nomeProduto(nome), descricaoProduto(descricao), precoProduto(valor), quantidadeEstoque(quantidade) {}

    virtual ~Produto() {} // *** é preferível usar ~Produto() = default; a usar chaves vazias

    virtual void print() = 0;

    // Getters
    virtual std::string getNomeProduto() const = 0;
    virtual std::string getDescricao() const = 0;
    virtual double getPrecoProduto() const = 0;
    virtual int getQuantidadeEstoque() const = 0;

    // Setters
    virtual void setNomeProduto(const std::string &nome) = 0;
    virtual void setDescricao(const std::string &descricao) = 0;
    virtual void setPrecoProduto(double preco) = 0;
    virtual void setQuantidadeEstoque(int quantidade) = 0;
};

#endif // PRODUTO_HPP
