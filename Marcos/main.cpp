#include <memory>
#include <iostream>
#include <vector>
#include "src/Produto/Produto.hpp"
#include "src/Usuario/Cliente.hpp"
#include "src/Usuario/Usuario.hpp"
#include "src/Produto/ProdutoFisico.hpp"
#include "src/Produto/ProdutoDigital.hpp"
#include "src/Produto/GerenciadorProdutos.hpp"
#include "src/Sistema.hpp"
#include "src/Menu.hpp"

enum return_status
{
    PRODUCT_FOUND,
    PRODUCT_NOT_FOUND,
};

int mostrar(std::shared_ptr<Produto> produto)
{
    if (produto == nullptr)
    {
        std::cout << "Produto não encontrado" << std::endl;
        return PRODUCT_NOT_FOUND;
    }
    else
    {
        produto->print();
        return PRODUCT_FOUND;
    }
}

void test1()
{
    GerenciadorProdutos gerenciador;

    std::cout << "Teste para ver se os produtos DVD e Filme estão sendo inseridos" << std::endl;
    std::cout << "******************************************************************************" << std::endl;
    // Teste para ver se os produtos DVD e Filme estão sendo inseridos
    // ****************************************************************************** //
    std::shared_ptr<Produto> dvd = std::make_shared<ProdutoFisico>(12, "DVD", "DVD virgem", 1.50, 1);
    std::shared_ptr<Produto> filme = std::make_shared<ProdutoDigital>(27, "Matrix", "Filme dublado", 5, 1);

    gerenciador.cadastrarProduto(dvd);
    gerenciador.cadastrarProduto(filme);

    gerenciador.mostrarProdutos();
    // ****************************************************************************** //

    // Teste de alteração do valor de produto
    // ****************************************************************************** //
    gerenciador.buscaProduto(27)->print();
    std::shared_ptr<Produto> ret = gerenciador.buscaProduto(12);
    if (ret != nullptr)
    {
        ret->print();
    }
    gerenciador.atualizarProduto(dvd, 12, "DVD Aurora Blueray", "", -1, -1);

    gerenciador.mostrarProdutos();
    // ****************************************************************************** //
}

// }

void test2()
{
    GerenciadorProdutos gerenciador{};

    std::shared_ptr<Produto> dvd = std::make_shared<ProdutoFisico>(12, "DVD", "DVD virgem", 1.50, 1);
    std::shared_ptr<Produto> filme = std::make_shared<ProdutoDigital>(27, "Matrix", "Filme dublado", 5, 1);

    gerenciador.cadastrarProduto(dvd);
    gerenciador.cadastrarProduto(filme);

    gerenciador.mostrarProdutos();
    // ****************************************************************************** //
    // Verificar produtos não encontrados
    // ****************************************************************************** //
    std::shared_ptr<Produto> produto = gerenciador.buscaProduto(12);
    std::shared_ptr<Produto> produto1 = gerenciador.buscaProduto(26);
    mostrar(produto);
    mostrar(produto1);
}

void test3()
{
    GerenciadorProdutos gerenciador{};

    std::shared_ptr<Produto> dvd = std::make_shared<ProdutoFisico>(12, "DVD", "DVD virgem", 1.50, 1);
    std::shared_ptr<Produto> filme = std::make_shared<ProdutoDigital>(27, "Matrix", "Filme dublado", 5, 1);
    std::shared_ptr<Produto> tenis = std::make_shared<ProdutoFisico>(32, "Tenis", "Tenis de corrida Nike", 357.35, 2);

    gerenciador.cadastrarProduto(dvd);
    gerenciador.cadastrarProduto(filme);
    gerenciador.cadastrarProduto(tenis);

    gerenciador.deletarProduto(27);
    std::cout << "Estou passando por aqui";

    gerenciador.mostrarProdutos();
}

void test4()
{
    GerenciadorProdutos gerenciador;
    std::shared_ptr<Produto> dvd = std::make_shared<ProdutoFisico>(12, "DVD", "DVD virgem", 1.50, 1);
    std::shared_ptr<Produto> filme = std::make_shared<ProdutoDigital>(27, "Matrix", "Filme dublado", 5, 1);
    std::shared_ptr<Produto> tenis = std::make_shared<ProdutoFisico>(32, "Tenis", "Tenis de corrida Nike", 357.35, 2);

    gerenciador.cadastrarProduto(dvd);
    gerenciador.cadastrarProduto(filme);
    gerenciador.cadastrarProduto(tenis);

    Usuario *cliente = new Cliente("Marcos Paulo", "teste@gmail.com");
    cliente->print();
    delete cliente;
}
void test5()
{
    GerenciadorProdutos gerenciador;
    std::shared_ptr<Produto> dvd = std::make_shared<ProdutoFisico>(12, "DVD", "DVD virgem", 1.50, 3);
    std::shared_ptr<Produto> filme = std::make_shared<ProdutoDigital>(27, "Matrix", "Filme dublado", 5, 2);
    std::shared_ptr<Produto> tenis = std::make_shared<ProdutoFisico>(32, "Tenis", "Tenis de corrida Nike", 357.35, 2);

    gerenciador.cadastrarProduto(dvd);
    gerenciador.cadastrarProduto(filme);
    gerenciador.cadastrarProduto(tenis);

    Sistema sistema;
    Cliente cliente1("Marcos Paulo", "teste@gmail.com");
    sistema.cadastrarCliente(cliente1);
    Carrinho carrinho;
    carrinho.adicionarProduto(dvd,2);
    carrinho.adicionarProduto(filme,1);
    //carrinho.calcular_total();
    //std::cout << carrinho.getTotal();
    // sistema.cadastrarCliente(cliente);

}

int main()
{
    Menu menu;
    menu.menu();
    // test5();
    return 0;
}
