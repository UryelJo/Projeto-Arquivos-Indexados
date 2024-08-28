//Inclusão de bibliotecas
#include <iostream>
#include <cstring>
#include <clocale>
#include <vector>

using namespace std;

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

void textoInicial();
void textoFinal();
void incluirNovoPais();
void incluirNovaCidade();

int main() {
    int opcao = 0;

    setlocale(LC_ALL, "Portuguese");
    textoInicial();

    vector<Paises> paises = {
        {8, "Brasil"},
        {12, "Argentina"},
        {3, "Uruguai"},
        {7, "Paraguai"},
        {9, "Chile"}
    };
    vector<indexPaises> indexPaises = {
        {3, 2},
        {7, 3},
        {8, 0},
        {9, 4},
        {12, 1}
    };

    vector<Cidades> cidades = {
        {103, "Rio de Janeiro", "RJ", 8},
        {7, "São Paulo", "SP", 8},
        {89, "Buenos Aires", "BA", 12},
        {4, "Montevidéu", "MT", 3},
        {97, "Assunção", "AS", 7},
        {1, "Santiago", "ST", 9}
    };
    vector<indexCidades> indexCidades = {
        {1, 5},
        {4, 3},
        {7, 1},
        {89, 2},
        {97, 4},
        {103, 0}
    };

    vector<Guias> guias = {
        {6, "Francisco Alfredo", "Rua Almirzinho", "1111-1111", 4},
        {34, "Daniel Moscou Perdeu", "Rua Dieguinho", "2222-2222", 1},
        {52, "Elma Maria Pinto", "Rua Vitaozin", "3333-3333", 7},
        {16, "Jacinto Cabeça latras", "Rua Giovaninha", "4444-4444", 89},
        {90, "Tisugiro kimikoma", "Rua Guigazinho", "5555-5555", 103}
    };
    vector<indexGuias> indexGuias = {
        {6, 0},
        {16, 3},
        {34, 1},
        {52, 2},
        {90, 4}
    };

    vector<Clientes> clientes = {
        {12, "João da Silva", "Rua das Flores", 7},
        {90, "Maria de Souza", "Rua das Pedras", 1},
        {5, "José da Costa", "Rua das Árvores", 89},
        {8, "Ana Paula", "Rua das Rosas", 4},
        {27, "Carlos Alberto", "Rua das Margaridas", 103}
    };
    vector<indexClientes> indexClientes = {
        {5, 2},
        {8, 3},
        {12, 0},
        {27, 4},
        {90, 1}
    };

    vector<Pacotes> pacotes = {
        {5, "Viagem para a China, durante o tempo que o governo deixar, com direito a trabalho escravo e vigilancia indesejada 24 horas por dia", 52, 1000.00, 5, 10},
        {1, "Viagem para o Oriente Médio, durante 1 mês, com visita a faixa de gaza", 6, 800.00, 7, 10},
        {90, "Viagem para o Brasil, durante 3 dias, com visitas a favelas do Rio de Janeiro", 16, 600.00, 13, 15},
        {78, "Viagem para a Antartida, durante 5 meses, com visitas recorrentes de pinguins", 90, 1200.00, 10, 20},
        {12, "Viagem para a Russia, durante tempo indeterminado, com direito a 8 litros de vodka", 34, 1500.00, 9, 15}
    };
    vector<indexPacotes> indexPacotes = {
        {1, 1},
        {5, 0},
        {12, 4},
        {78, 3},
        {90, 2}
    };

    do {
        cout<<"\n\n\tInforme a opcao desejada{ \n" << "\t\t[1] - incluir um novo Pais \n" << "\t\t[2] - incluir uma nova cidade \n" << "\n\n\t\t[0] - Sair \n" << "\t}";
        cout << "[>] ";
        cin >> opcao;
    }while(opcao != 0);

    textoFinal();
    cout<<"\n";

    system("pause");

}

void textoInicial() {
    vector<char> textoBemVindo = { '=' ,'=' ,'=' ,'=' ,'[' ,'B', 'e', 'm', ' ', 'V', 'i', 'n', 'd', 'o', ' ', 'a', ' ', 'A', 'g', 'e', 'n', 'c', 'i', 'a', ' ', 'd', 'e', ' ', 'T', 'u', 'r', 'i', 's', 'm', 'o', ' ', 'U', 'R', 'Y', 'F', 'L','Y' , ']' , '=' ,'=' ,'=' ,'='};
    for (int i = 0; i < textoBemVindo.size(); i++) {
        for (int j = 0; j <= i; j++) {
            if(j == 0) {
                std::cout<< "\t\t\t\t" << textoBemVindo[j];
            } else {
                std::cout<< textoBemVindo[j];
            }
        }
        if (i < textoBemVindo.size() - 1) {
            system("cls");
        }
    }
}
void textoFinal() {
    vector<char> textoAdeus = { '=' ,'=' ,'=' ,'=' ,'[' ,'A', 't', 'e', ' ', 'a', ' ', 'P', 'r', 'o', 'x', 'i', 'm', 'a', ' ', 'V', 'i', 's', 'i', 't', 'a', ' ', ']' , '=' ,'=' ,'=' ,'='};
    for (int i = 0; i < textoAdeus.size(); i++) {
        for (int j = 0; j <= i; j++) {
            if(j == 0) {
                std::cout<< "\t\t\t\t" << textoAdeus[j];
            } else {
                std::cout<< textoAdeus[j];
            }
        }
        if (i < textoAdeus.size() - 1) {
            system("cls");
        }
    }
}
