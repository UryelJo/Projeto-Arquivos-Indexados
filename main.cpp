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

struct IndexPaises {
    int codigoPais;
    int index;
};

struct Cidades {
    int codigoCidade;
    char nome[50];
    char uf[3];
    int codigoPais;
};

struct IndexCidades {
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

struct IndexGuias {
    int codigoGuia;
    int index;
};

struct Clientes {
    int codigoCliente;
    char nome[50];
    char endereco[100];
    int codigoCidade;
};

struct IndexClientes {
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

struct IndexPacotes {
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

struct IndexVendas {
    int codigoVenda;
    int index;
};

void textoInicial();
void textoFinal();

void incluirNovoPais(vector<Paises>&, vector<IndexPaises>&);
void incluirNovaCidade(vector<Cidades>&, vector<IndexCidades>&);
void incluirNovoGuia(vector<Guias>&, vector<IndexGuias>&, vector<Cidades>&, vector<IndexCidades>&, vector<Paises>&, vector<IndexPaises>&);

//Funções de exibição de códigos
void exibirCodigosPaises(vector<IndexPaises>&, vector<Paises>&);
void exibirCodigosCidades(vector<IndexCidades>&, vector<Cidades>&);
void exibirCodigosGuias(vector<IndexGuias>&, vector<Guias>&);
void exibirCodigosClientes(vector<IndexClientes>&, vector<Clientes>&);
void exibirCodigosPacotes(vector<IndexPacotes>&, vector<Pacotes>&);

//Funções de busca genéricos que retornam Boolean para verificar se o código já existe
bool buscarPaisPorCodigo(vector<IndexPaises>&, int);
bool buscarCidadePorCodigo(vector<IndexCidades>&, int);
bool buscarGuiaPorCodigo(vector<IndexGuias>&, int);
bool buscarClientePorCodigo(vector<IndexClientes>&, int);
bool buscarPacotePorCodigo(vector<IndexPacotes>&, int);
bool buscarVendaPorCodigo(vector<IndexVendas>&, int);

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
    vector<IndexPaises> indexPaises = {
        {3, 2},
        {7, 3},
        {8, 0},
        {9, 4},
        {12, 1}
    };
    vector<Cidades> cidades = {
        {103, "Rio de Janeiro", "RJ", 8},
        {7, "Sao Paulo", "SP", 8},
        {89, "Buenos Aires", "BA", 12},
        {4, "Montevideu", "MT", 3},
        {97, "Assuncao", "AS", 7},
        {1, "Santiago", "ST", 9}
    };
    vector<IndexCidades> indexCidades = {
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
        {16, "Jacinto Cabeca latras", "Rua Giovaninha", "4444-4444", 89},
        {90, "Tisugiro kimikoma", "Rua Guigazinho", "5555-5555", 103}
    };
    vector<IndexGuias> indexGuias = {
        {6, 0},
        {16, 3},
        {34, 1},
        {52, 2},
        {90, 4}
    };
    vector<Clientes> clientes = {
        {12, "Joao da Silva", "Rua das Flores", 7},
        {90, "Maria de Souza", "Rua das Pedras", 1},
        {5, "Jose da Costa", "Rua das Árvores", 89},
        {8, "Ana Paula", "Rua das Rosas", 4},
        {27, "Carlos Alberto", "Rua das Margaridas", 103}
    };
    vector<IndexClientes> indexClientes = {
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
    vector<IndexPacotes> indexPacotes = {
        {1, 1},
        {5, 0},
        {12, 4},
        {78, 3},
        {90, 2}
    };

    do {
        cout<<"\tInforme a opcao desejada{ \n" << "\t\t[1] - Incluir um novo Pais \n" << "\t\t[2] - Incluir uma nova cidade \n"<<"\t\t[3] - Incluir novo Guia \n" << "\n\n\t\t[0] - Sair \n" << "\t}";
        cout << "[>] ";
        cin >> opcao;
        cin.ignore();
        if(opcao == 1) {
            incluirNovoPais(paises, indexPaises);
        } else if (opcao == 2) {
            incluirNovaCidade(cidades, indexCidades);
        } else if(opcao == 3) {
            incluirNovoGuia(guias, indexGuias, cidades, indexCidades, paises, indexPaises);
        }
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
    cout<<"\n\n";
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

void incluirNovoPais(vector<Paises>& paises, vector<IndexPaises>& indexPaises) {
    bool inseriu = false;
    Paises novoPais{};
    IndexPaises novoIndexPais{};
    system("cls");
    do {
        exibirCodigosPaises(indexPaises, paises);
        cout<<"\t Informe o codigo do novo pais \n\t [>]  ";
        do {
            cin>>novoPais.codigoPais;
            cin.ignore();
        } while(novoPais.codigoPais < 0);
    }while(buscarPaisPorCodigo(indexPaises, novoPais.codigoPais));
    novoIndexPais.codigoPais = novoPais.codigoPais;
    cout<<"\t Informe o nome do novo pais \n\t [>]  ";
    gets(novoPais.nome);
    paises.push_back(novoPais);

    novoIndexPais.index = static_cast<int>(paises.size()-1);

    int position = 0;
    for(auto & indexPais : indexPaises) {
        if(novoIndexPais.codigoPais < indexPais.codigoPais && !inseriu) {
            indexPaises.insert(indexPaises.begin() + position, novoIndexPais);
            inseriu = true;
        }
        if(position == indexPaises.size() - 1 && !inseriu) {
            indexPaises.push_back(novoIndexPais);
            inseriu = true;
        }
        position++;
    }
    system("cls");
}
void incluirNovaCidade(vector<Cidades> & cidades, vector<IndexCidades> & indexCidades) {
    bool inseriu = false;
    Cidades novaCidade{};
    IndexCidades novoIndexCidade{};
    system("cls");
    do {
        exibirCodigosCidades(indexCidades, cidades);
        cout<<"\t Informe o codigo da nova cidade \n\t [>]  ";
        do {
            cin>>novaCidade.codigoCidade;
            cin.ignore();
        } while(novaCidade.codigoCidade < 0);
    }while (buscarCidadePorCodigo(indexCidades, novaCidade.codigoCidade));
    novoIndexCidade.codigoCidade = novaCidade.codigoCidade;
    cout<<"\t Informe o nome da nova cidade \n\t [>]  ";
    gets(novaCidade.nome);
    cout<<"\t Informe a UF da nova cidade \n\t [>]  ";
    gets(novaCidade.uf);
    cidades.push_back(novaCidade);

    novoIndexCidade.index = static_cast<int>(cidades.size()-1);

    int position = 0;
    for(auto & indexCidade : indexCidades) {
        if(novoIndexCidade.codigoCidade < indexCidade.codigoCidade && !inseriu) {
            indexCidades.insert(indexCidades.begin() + position, novoIndexCidade);
            inseriu = true;
        }
        if(position == indexCidades.size() - 1 && !inseriu) {
            indexCidades.push_back(novoIndexCidade);
            inseriu = true;
        }
        position++;
    }

    system("cls");
}
void incluirNovoGuia(vector<Guias> & guias, vector<IndexGuias> & indexGuias, vector<Cidades> & cidades, vector<IndexCidades> & indexCidades, vector<Paises> & paises, vector<IndexPaises> & indexPaises) {
    bool inseriu = false;
    Guias novoGuia{};
    IndexGuias novoIndexGuia{};
    system("cls");
    do {
        exibirCodigosGuias(indexGuias, guias);
        do {
            cout<<"\n\t Informe o codigo do novo guia \n\t [>]  ";
            cin >> novoGuia.codigoGuia;
            cin.ignore();
        }while(novoGuia.codigoGuia < 0);
    } while (buscarGuiaPorCodigo(indexGuias, novoGuia.codigoGuia));
    novoIndexGuia.codigoGuia = novoGuia.codigoGuia;
    cout<<"\n\t Informe o nome do novo guia \n\t [>]  ";
    gets(novoGuia.nome);
    cout<<"\n\t Informe o endereco do novo guia \n\t [>]  ";
    gets(novoGuia.endereco);
    cout<<"\n\t Informe o telefone do novo guia \n\t [>]  ";
    gets(novoGuia.telefone);
    cout<< endl;
    exibirCodigosCidades(indexCidades, cidades);
    bool aux = false;
    do {
        cout<<"\t Informe o codigo da cidade do novo guia \n\t [>]  ";
        cin>>novoGuia.codigoCidade;
        cin.ignore();
        for(auto & indexCidade : indexCidades) {
            if(indexCidade.codigoCidade == novoGuia.codigoCidade && !aux) {
                aux = true;
            }
        }
        if(aux == false) {
            cout<<"\t[==Cidade nao encontrada==]" <<endl;
        }
    }while(aux == false);
    guias.push_back(novoGuia);
    novoIndexGuia.index = static_cast<int>(guias.size()-1);
    int position = 0;
    for(auto & indexGuia : indexGuias) {
        if(novoIndexGuia.codigoGuia < indexGuia.codigoGuia && !inseriu) {
            indexGuias.insert(indexGuias.begin() + position, novoIndexGuia);
            inseriu = true;
        }
        if(position == indexGuias.size() - 1 && !inseriu) {
            indexGuias.push_back(novoIndexGuia);
            inseriu = true;
        }
        position++;
    }
    system("cls");
}

void exibirCodigosCidades(vector<IndexCidades> & indexCidades, vector<Cidades> & cidades) {
    cout<<"\tCidades Cadastradas: "<<endl;
    for(auto & indexCidade : indexCidades) {
        cout<<"\t\t [Codigo: "<<indexCidade.codigoCidade<<"] "<< cidades[indexCidade.index].nome<<" - "<< cidades[indexCidade.index].uf <<endl;
    }
    cout<<"\n";
}
void exibirCodigosPaises(vector<IndexPaises> & indexPaises, vector<Paises> & paises) {
    cout<<"\tPaises Cadastrados: "<<endl;
    for(auto & indexPais : indexPaises) {
        cout<<"\t\t [Codigo: "<<indexPais.codigoPais<<"] "<< paises[indexPais.index].nome<<endl;
    }
    cout<<"\n";
}
void exibirCodigosGuias(vector<IndexGuias> & indexGuias, vector<Guias> & guias) {
    cout<< "\tGuias Cadastrados: "<<endl;
    for(auto & indexGuia : indexGuias) {
        cout<<"\t\t [Codigo: "<<indexGuia.codigoGuia<<"] "<< guias[indexGuia.index].nome<<endl;
    }
}

//Funções de busca genéricos que retornam Boolean para verificar se o código já existe
bool buscarPaisPorCodigo(vector<IndexPaises>& indexPaises, int codigo ) {
    for (auto & index : indexPaises) {
        if(index.codigoPais == codigo) {
            system("cls");
            cout<<"\t[==Pais ja cadastrado==]\n \n";
            return true;
        }
    }
    return false;
}
bool buscarCidadePorCodigo(vector<IndexCidades>& indexCidades, int codigo ) {
    for (auto & index : indexCidades) {
        if(index.codigoCidade == codigo) {
            system("cls");
            cout<<"\t[==Cidade ja cadastrada==]\n\n ";
            return true;
        }
    }
    return false;
}
bool buscarGuiaPorCodigo(vector<IndexGuias>& indexGuias, int codigo ) {
    for (auto & index : indexGuias) {
        if(index.codigoGuia == codigo) {
            system("cls");
            cout<<"\t[==Guia ja cadastrado==]\n\n";
            return true;
        }
    }
    return false;
}
bool buscarClientePorCodigo(vector<IndexClientes>& indexClientes, int codigo ) {
    for (auto & index : indexClientes) {
        if(index.codigoCliente == codigo) {
            system("cls");
            cout<<"\t[==Cliente ja cadastrado==]\n\n";
            return true;
        }
    }
    return false;
}
bool buscarPacotePorCodigo(vector<IndexPacotes>& indexPacotes, int codigo ) {
    for (auto & index : indexPacotes) {
        if(index.codigoPacote == codigo) {
            system("cls");
            cout<<"\t[==Pacote ja cadastrado==]\n\n";
            return true;
        }
    }
    return false;
}
bool buscarVendaPorCodigo(vector<IndexVendas>& indexVendas, int codigo ) {
    for (auto & index : indexVendas) {
        if(index.codigoVenda == codigo) {
            system("cls");
            cout<<"\t[==Venda ja cadastrada==]\n\n";
            return true;
        }
    }
    return false;
}