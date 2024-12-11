#include <iostream>
#include <memory>
// #include "src/ProdutoFisico.hpp"
// #include "src/Usuario.hpp"
#include "src/Menu.hpp"

void test_adicionar_produto()
{
    // std::shared_ptr<Produto> banana_da_terra = std::make_shared<ProdutoFisico>(0, "Fruta", "Banana", 2.5);
    // std::shared_ptr<Produto> banana_nanica = std::make_shared<ProdutoFisico>(1, "Fruta", "Banana Nanica", 1);
    // std::shared_ptr<Usuario> user = std::make_shared<Usuario>("romildo", "romildoj@jsk.com", "12345", std::make_unique<Carrinho>());
    // user->carrinho->produtos.push_back(banana_da_terra);
    // user->carrinho->produtos.push_back(banana_nanica);
}


int main(int argc, char const *argv[])
{
    Menu menu;
    menu.menu();
    // test_adicionar_produto();
    return 0;
}
