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

struct Cidades {
    int codigoCidade;
    char nome[50];
    char uf[3];
    int codigoPais;
};

struct Guias {
    int codigoGuia;
    char nome[50];
    char endereco[100];
    char telefone[15];
    int codigoCidade;
};

struct Clientes {
    int codigoCliente;
    char nome[50];
    char endereco[100];
    int codigoCidade;
};

struct Pacotes {
    int codigoPacote;
    char descricao[150];
    int codigoGuia;
    double valorPorPessoa;
    int totalPessoas;
    int quantidadeMaximaSuportada;
};

struct Vendas {
    int codigoVenda;
    int codigoCliente;
    int codigoPacote;
    int quantidadePessoas;
    double valorTotal;
};


using namespace std;

int main() {

}