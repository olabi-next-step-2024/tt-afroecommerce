#include <iostream>
#include "Produto.hpp"
#include "Cliente.hpp"

class Adm : public Cliente
{

public:
    Adm(std::string nome, std::string email, std::string senha) : Cliente(nome, email, senha) {}
    void adicionarEstoque(Produto produto)
    {
        std::cout<<"Adicionado ao estoque"<< produto.getNome() << std::endl;

    }
};