#ifndef SISTEMA_HPP
#define SISTEMA_HPP
#include <iostream>
#include <map>
#include <vector>
#include "Produto/GerenciadorProdutos.hpp"
#include "Carrinho/Carrinho.hpp"
#include "Usuario/Cliente.hpp"
#include "Produto/Produto.hpp"

class Sistema{
private:
    std::vector<Cliente> clientes {};
    std::map<int, Carrinho> carrinhos {};
    GerenciadorProdutos gerenciador = {};

public:
    void cadastrarCliente(const Cliente& cliente){
        clientes.push_back(cliente);
    }

    void realizarCompra(int id_cliente){
        if(carrinhos.find(id_cliente) == carrinhos.end()){
            throw std::invalid_argument("Carrinho vazio ou inexistente");
        }

        Carrinho& carrinho = carrinhos[id_cliente];
        for(const auto& item : carrinho.getProdutos()){
            std::shared_ptr<Produto> produto = gerenciador.buscaProduto(item.first);
            
            if(produto->getQuantidadeEstoque() < item.second){
                throw std::invalid_argument("Quantidade no estoque insuficiente para produto" + produto ->getNomeProduto());
            }

            carrinho.esvaziarCarrinho();
            std::cout << "Compra finalizada com sucesso" << std::endl;
        }
    }
};



#endif