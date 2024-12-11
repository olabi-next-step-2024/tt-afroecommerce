#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>

class Menu
{
public:
    int menu_admin()
    {
        int opt;
        puts("[1] Cadastrar cliente");
        puts("[2] Cadastrar produto");
        // Atualização de quantidade é uma extensão de atualizar produto
        puts("[3] Atualizar produto");
        puts("[4] Excluir produto");
        puts("[0] Voltar");
        while (std::cin >> opt)
        {
            switch (opt)
            {
            case 0:
                return 0;
            case 1:
                puts("Cliente John Doe (johndoe@anon.com) cadastrado com sucesso!");
                return 1;
            case 2:
                puts("Produto bobba cadastrado com sucesso!");
                return 1;
            case 3:
                puts("Produto bobba atualizado com sucesso!");
                return 1;
            case 4:
                puts("Produto bobba excluído com sucesso!");
                return 1;
            default:
                printf("Opção inválida! Insira novamente: ");
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
                return 0;
            default:
                printf("Opção inválida! Insira novamente: ");
            }
        } while (opt);
        return 0;
    }
};

#endif