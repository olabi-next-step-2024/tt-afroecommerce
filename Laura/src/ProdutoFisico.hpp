#include <iostream>
#include "Produto.hpp"

class ProdutoFisico : public Produto
{
public:
    
    double calcularFrete(double distancia)
    {
        double frete;
        frete = distancia * (1.2); // interessante armazenar valor em uma variável
        return frete;
    }
};