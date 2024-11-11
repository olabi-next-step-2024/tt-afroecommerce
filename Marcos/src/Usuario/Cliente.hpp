#include <iostream>
#include <string>
#include "Usuario.hpp"
#include "src/Carrinho/Carrinho.hpp"

class Cliente : public Usuario
{

private:
    Carrinho *carrinho;

public:
    Cliente(const std::string &nome, const std::string &email)
        : Usuario(nome, email), carrinho(new Carrinho()) {}

    ~Cliente()
    {
        delete carrinho;
    }

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

    void setEmailCliente(std::string &emailCliente) override
    {
        email = emailCliente;
    }

    int getIdCliente() const override
    {
        return id;
    }
};