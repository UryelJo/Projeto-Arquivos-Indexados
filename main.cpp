//Inclusão de bibliotecas
#include <iostream>
#include <cstring>
#include <clocale>
#include <vector>

//Definição das Estruturas
struct Paises {
    int codigoPais;
    char nome[50];
};

struct indexPaises {
    int codigoPais;
    int index;
};

struct Cidades {
    int codigoCidade;
    char nome[50];
    char uf[3];
    int codigoPais;
};

struct indexCidades {
    int codigoCidade;
    int index;
};

struct Guias {
    int codigoGuia;
    char nome[50];
    char endereco[100];
    char telefone[15];
    int codigoCidade;
};

struct indexGuias {
    int codigoGuia;
    int index;
};

struct Clientes {
    int codigoCliente;
    char nome[50];
    char endereco[100];
    int codigoCidade;
};

struct indexClientes {
    int codigoCliente;
    int index;
};

struct Pacotes {
    int codigoPacote;
    char descricao[150];
    int codigoGuia;
    double valorPorPessoa;
    int totalPessoas;
    int quantidadeMaximaSuportada;
};

struct indexPacotes {
    int codigoPacote;
    int index;
};

struct Vendas {
    int codigoVenda;
    int codigoCliente;
    int codigoPacote;
    int quantidadePessoas;
    double valorTotal;
};

struct indexVendas {
    int codigoVenda;
    int index;
};


int main() {

}