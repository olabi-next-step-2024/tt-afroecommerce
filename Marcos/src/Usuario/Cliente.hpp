#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>
#include <string>
#include "Usuario.hpp"
#include "../Carrinho/Carrinho.hpp"

class Cliente : public Usuario
{

private:
    std::shared_ptr<Carrinho> carrinho;

public:
    Cliente(std::string nome, std::string email)
        : Usuario(nome, email), carrinho(std::make_unique<Carrinho>()) {}

    ~Cliente() override = default;    

    std::string getNomeCliente() const override
    {
        return nome;
    }

    void setNomeCliente(std::string &nomeCliente) override
    {
        nome = nomeCliente;
    }

    std::string getEmailCliente() const override
    {
        return email;
    }

    void setCarrinho(std::unique_ptr<Carrinho> &carrinho)
    {
        this->carrinho = std::move(carrinho);
    }


    void setEmailCliente(std::string &emailCliente) override
    {
        email = emailCliente;
    }

    int getIdCliente() const override
    {
        return id;
    }

    void print() override
    {
        std::cout << "Cliente: "
                  << getNomeCliente()
                  << " email: "
                  << getEmailCliente()
                  << ")\n";
    }
};

#endif