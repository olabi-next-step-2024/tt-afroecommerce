#include <iostream>
#include "Produto.hpp"

class ProdutoDigital : public Produto
{
    private:
    std::string tipoArquivo;

    public:

    std::string getTipoArquivo(){
        return tipoArquivo;
    }
    

}