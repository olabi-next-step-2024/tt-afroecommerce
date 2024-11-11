#ifndef CARRINHO_HPP
#define CARRINHO_HPP

#include <iostream>
#include <memory>
#include <vector>

class Carrinho
{
private:
    std::vector<std::shared_ptr<Produto>> produtos;
    Carrinho() {};

public:
    Carrinho c1();
};

#endif