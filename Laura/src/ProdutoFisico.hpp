#include <iostream>
#include "Produto.hpp"

class ProdutoFisico : public Produto
{
public:
    
    ProdutoFisico(int id, std::string descricao, std::string nome, double preco)
        : Produto(id, descricao, nome, preco){}

    double calcularFrete(double distancia)
    {
        double frete;
        frete = distancia * (1.2); 
        return frete;
    }
};