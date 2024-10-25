classDiagram
     ItemCarrinho -- Carrinho
    Cliente -- Carrinho    
    Produto <|-- ProdutoFisico
    Produto <|-- ProdutoDigital
    Cliente --o SistemaEcommerce
    Produto --o SistemaEcommerce
   

    class Produto{
    <<Interface>>
    
        - int id
        - string nome
        - double preco
        - string descricao
        - int estoque
        
    
    }
    class SistemaEcommerce{
    
    - List<Produto> produtos
    - List<Cliente> clientes
    +exibirProdutos()
    +logarCliente()
    + adicionarCliente(Cliente cliente)
    + adicionarProduto(Produto produto)
    + realizarCompra(int idCliente, List<ItemCarrinho> itens)


    }
    class Carrinho{
    
    - List<ItemCarrinho> itens
    + adicionarItem(Produto produto, int quantidade)
    + removerItem(Produto produto)
    + calcularTotal()  double

    }
    class ProdutoFisico{
      
    
    + double calcularFrete(double distancia)  double
    }
    class ProdutoDigital{
        - String tipoArquivo
    }

    class Cliente{

    - string nome
    - string email
    - Carrinho carrinho
    
    }
    class ItemCarrinho {
        - Produto produto
        - int quantidade
    }
    
    
    