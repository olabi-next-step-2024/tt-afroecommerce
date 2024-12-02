#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>
// #include "Carrinho.hpp"

class Cliente
{
private:
    std::string nome;
    std::string email;
    std::string senha;

public:
    Cliente(std::string nome, std::string email, std::string senha)
        : nome(nome), email(email), senha(senha) {}

    void logar(std::string email, std::string senha)
    {
        if (this->senha == senha & this->email == email)
        {
            std::cout << "Logado com sucesso" << std::endl;
        }
    }
};

#endif