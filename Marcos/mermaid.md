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




    classDiagram
    class Produto {
        -id_produto: int
        -nome: str
        -preco: float
        -descricao: str
        -estoque: int
        +atualizar_estoque(quantidade: int)
    }

    class ProdutoFisico {
        +calcular_frete(distancia: float): float
    }

    class ProdutoDigital {
    }

    class Cliente {
        -id_cliente: int
        -nome: str
        -email: str
    }

    class Carrinho {
        -itens: Dict[int, int]
        -total: float
        +adicionar_produto(produto: Produto, quantidade: int)
        +remover_produto(produto: Produto, quantidade: int)
        +limpar_carrinho()
        +calcular_total()
    }

    class ProdutoManager {
        +produtos: List[Produto]
        +cadastrar_produto(produto: Produto)
        +buscar_produto_por_id(id_produto: int): Produto
        +atualizar_produto(id_produto: int, **dados)
        +excluir_produto(id_produto: int)
    }

    class Sistema {
        -clientes: List[Cliente]
        -carrinhos: Dict[int, Carrinho]
        +cadastrar_cliente(cliente: Cliente)
        +finalizar_compra(id_cliente: int)
    }

    Produto <|-- ProdutoFisico
    Produto <|-- ProdutoDigital
    ProdutoManager --> Produto
    Sistema --> Cliente
    Sistema --> Carrinho
    Carrinho --> Produto
