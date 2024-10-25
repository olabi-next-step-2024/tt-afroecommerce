#include <iostream>
#include "Produto.hpp"
#include "ProdutoDigital.hpp"
#include "ProdutoFisico.hpp"
#include "GerenciadorProdutos.hpp"
#include <vector>

int main()
{

    GerenciadorProdutos gerenciador;
    
    Produto* dvd = new ProdutoFisico("DVD", "DVD virgem", 1.50, 1);
    Produto* filme = new ProdutoDigital("Matrix", "Filme dublado",5,1);

    gerenciador.cadastrarProduto(dvd);
    gerenciador.cadastrarProduto(filme);

    gerenciador.mostrarProdutos();

    gerenciador.buscaProduto("Matrix")->print();
    gerenciador.buscaProduto("DVD")->print();
    //gerenciador.buscaProduto("Tenis")->print();

    gerenciador.atualizarProduto(dvd,"DVD Aurora Blueray","",-1,-1);

    gerenciador.mostrarProdutos();


    return 0;
}
