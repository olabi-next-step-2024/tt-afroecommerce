classDiagram
    Produto <|-- ProdutoFisico
    Produto <|-- ProdutoDigital
    Produto o-- Estoque
    Cliente -- Carrinho
    Carrinho o-- Produto
    Produto -- TipoProduto
    Ecommerce -- Cliente
    class Produto {
        <<Abstract>>
     #String nomeProduto
     #String descricaoProduto
     #Double estoqueProduto
     #Int valorProduto
     #TipoProduto tipo
    }

    class Estoque {
     +Dictionary Produtos
     +cadastrarProduto()
     +buscaProduto()
     +atualizaProduto()
     +excluirProduto()
    }

    class ProdutoFisico {
      +calcularFrete()
    }

    class ProdutoDigital {
    }

    class TipoProduto {
    <<enumeration>>
    Fisico
    Virtual
    }

    class Cliente {
     #String nomeCliente
     #String Email
     #String numero
     #String senha
    }

    class Ecommerce {
    +logarCliente()
    +logOut()
    }

    class Carrinho {
    -Cliente cliente
    -List Produtos
    +adicionarCarrinho()
    +removerCarrinho()
    }