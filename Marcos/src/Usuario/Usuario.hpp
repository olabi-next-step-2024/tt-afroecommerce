#ifndef USUARIO_HPP
#define USUARIO_HPP
#include <string>

class Usuario
{
protected:
    std::string email, nome;
    int id;

public:
    Usuario(std::string nome, std::string email) : nome(nome), email(email) {}

    virtual ~Usuario() {}
    virtual void print() = 0;

    // Getters
    virtual std::string getNomeCliente() const = 0;
    virtual std::string getEmailCliente() const = 0;
    virtual int getIdCliente() const = 0;
    // Setters

    virtual void setEmailCliente(std::string &email) = 0;
    virtual void setNomeCliente(std::string &nome) = 0;
};

#endif