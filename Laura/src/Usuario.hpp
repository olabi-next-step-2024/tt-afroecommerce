#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <iostream>
#include "Carrinho.hpp"
#include "Cliente.hpp"


class Usuario : public Cliente
{
private:

    Carrinho carrinho;


public:

    Usuario(std::string nome, std::string email, std::string senha, Carrinho& carrinho)
        : Cliente(nome, email, senha), carrinho(carrinho) {}
    void comprar()
    {
        std::cout<<"Compra realizada" << std::endl;
    }
};

#endif