#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include "Sistema.hpp"
// #include "src/Produto/"
#include "Usuario/Cliente.hpp"
// #include "src/Produto/Produto.hpp"
#include "Produto/ProdutoFisico.hpp"
#include "Produto/GerenciadorProdutos.hpp"

class Menu
{
public:
    int menu_admin()
    {
        int opt;
        Sistema sistema;
        GerenciadorProdutos gerenciador;
        Cliente cliente1("John Doe", "johndoe@anon.com");
        std::shared_ptr<Produto> dvd = std::make_shared<ProdutoFisico>(12, "DVD", "DVD virgem", 1.50, 1);

        puts("[1] Cadastrar cliente");
        puts("[2] Cadastrar produto");
        // Atualização de quantidade é uma extensão de atualizar produto
        puts("[3] Atualizar produto");
        puts("[4] Excluir produto");
        puts("[5] Mostrar todos os clientes cadastrados");
        puts("[0] Voltar");

        while (std::cin >> opt)
        {
            switch (opt)
            {
            case 0:
                return 0;
            case 1:
            {
                std::string nome, email;
                printf("Insira o nome do cliente: "); std::cin >> nome;
                printf("Agora insira o e-mail: "); std::cin >> email;
                sistema.cadastrarCliente(Cliente(nome, email));
                printf("Cliente %s (%s) cadastrado com sucesso!", nome.c_str(), email.c_str());
            }
                return 1;
            case 2:
                gerenciador.cadastrarProduto(dvd);
                // dvd->print(); std::cout << " adicionado com sucesso!" << '\n';
                return 1;
            case 3:
                std::cout << "Produto anterior: "; dvd->print(); 
                gerenciador.atualizarProduto(dvd, 12, "DVD Aurora Blueray", "", -1, -1);
                std::cout << "Produto atualizado: "; gerenciador.buscaProduto(dvd->getId_produto())->print();
                return 1;
            case 4:
                gerenciador.deletarProduto(dvd->getId_produto());
                puts("Produto bobba excluído com sucesso!");
                return 1;
            default:
                printf("Opção inválida! Insira novamente: ");
                break;
            }
        }
        return 1;
    }

    bool menu_user()
    {
        int opt;
        puts("[1] Adicionar produto ao carrinho");
        puts("[2] Remover item do carrinho");
        puts("[3] Remover todos os itens do carrinho");
        puts("[4] Total do carrinho");
        puts("[5] Efetuar compra");
        puts("[0] Voltar");
        while (std::cin >> opt)
        {
            switch (opt)
            {
            case 0:
                return 0;
            case 1:
                puts("Produto adicionado ao carrinho.");
                return 1;
            case 2:
                puts("Produto removido ao carrinho.");
                return 1;
            case 3:
                puts("Carrinho limpo.");
                return 1;
            case 4:
                puts("Total do carrinho: R$ 0,00");
                return 1;
            case 5:
                puts("Compra efetuada com sucesso!");
                return 1;
            default:
                printf("Opção inválida! Insira novamente: ");
                break;
            }
        }
        return 1;
    }

    int menu()
    {
        int opt;
        do
        {
            puts("[1] Menu de admin");
            puts("[2] Menu de usuário");
            puts("[0] Sair");
            std::cin >> opt;
            switch (opt)
            {
            case 1:
                while (menu_admin())
                {
                }
                break;
            case 2:
                while (menu_user())
                {
                }
                break;
            case 0:
                // return 0
                break;
            default:
                printf("Opção inválida! Insira novamente: ");
            }
        } while (true);
        return 0;
    }
};

#endif