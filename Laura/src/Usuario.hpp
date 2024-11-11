#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <iostream>
#include "Carrinho.hpp"
#include "Cliente.hpp"


class Usuario : public Cliente
{
private:


public:
    std::unique_ptr<Carrinho> carrinho;

    Usuario(std::string nome, std::string email, std::string senha)
        : Cliente(nome, email, senha) {}
    void comprar()
    {
        std::cout<<"Compra realizada" << std::endl;
    }
};

#endif