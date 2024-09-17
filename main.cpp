//Inclusão de bibliotecas
#include <iostream>
#include <clocale>
#include <vector>
#include <cstring>

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
    bool excluido;
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
    bool excluido;
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
void menuDeInclusao(vector<Paises>&, vector<IndexPaises>&, vector<Cidades>&, vector<IndexCidades>&, vector<Guias>&, vector<IndexGuias>&, vector<Clientes>&, vector<IndexClientes>&, vector<Pacotes>&, vector<IndexPacotes>&, vector<Vendas>&, vector<IndexVendas>&);

//Funções de inclusão de novos registros
void incluirNovoPais(vector<Paises>&, vector<IndexPaises>&);
void incluirNovaCidade(vector<Cidades>&, vector<IndexCidades>&, vector<Paises>&, vector<IndexPaises>&);
void incluirNovoGuia(vector<Guias>&, vector<IndexGuias>&, vector<Cidades>&, vector<IndexCidades>&, vector<Paises>&, vector<IndexPaises>& );
void incluirNovoCliente(vector<Clientes>&, vector<IndexClientes>&, vector<Cidades>&, vector<IndexCidades>&, vector<Paises>&, vector<IndexPaises>&);
void incluirNovoPacote(vector<Pacotes>&, vector<IndexPacotes>&, vector<Guias>&, vector<IndexGuias>&, vector<Cidades>&, vector<IndexCidades>&, vector<Paises>&, vector<IndexPaises>&);
void incluirNovaVenda(vector<Vendas>&, vector<IndexVendas>&, vector<Clientes>&, vector<IndexClientes>&,  vector<Pacotes>&, vector<IndexPacotes>&, vector<Guias>&, vector<IndexGuias>&,  vector<Cidades>&, vector<IndexCidades>&,  vector<Paises>&, vector<IndexPaises>&);

//Funções de exclusão de registros
void excluirCliente(vector<Clientes>&, vector<IndexClientes>&, vector<Cidades>&, vector<IndexCidades>&,  vector<Vendas>&, vector<IndexVendas>&);
void excluirGuia(vector<Guias>&, vector<IndexGuias>&, vector<Cidades>&, vector<IndexCidades>&, vector<Paises>&, vector<IndexPaises>&, vector<Pacotes>&, vector<IndexPacotes>&);

//Funções de exibição de códigos
void exibirCodigosPaises(vector<IndexPaises>&, vector<Paises>&);
void exibirCodigosCidades(vector<IndexCidades>&, vector<Cidades>&, vector<Paises>&, vector<IndexPaises>&);
void exibirCodigosGuias(vector<IndexGuias>&, vector<Guias>&, vector<Cidades>&, vector<IndexCidades>&,  vector<Paises>&, vector<IndexPaises>&);
void exibirCodigosClientes(vector<IndexClientes>&, vector<Clientes>&,  vector<Cidades>&, vector<IndexCidades>&);
void exibirCodigosPacotes(vector<IndexPacotes>&, vector<Pacotes>&,  vector<IndexGuias>&,  vector<Guias>&,  vector<Cidades>&, vector<IndexCidades>&,  vector<Paises>&, vector<IndexPaises>&);
void exibirCodigosVendas(vector<IndexVendas>&, vector<Vendas>&,  vector<Clientes>&, vector<IndexClientes>&,  vector<Pacotes>&, vector<IndexPacotes>&);

void consultarDadosPacoteCompletamenteVendidos(vector<Pacotes>&, vector<IndexPacotes>&, vector<Guias>&, vector<IndexGuias>&, vector<Cidades>&, vector<IndexCidades>&, vector<Paises>&, vector<IndexPaises>&);
void consultarDadosDeterminadoPacote(vector<Pacotes>&, vector<IndexPacotes>&, vector<Guias>&, vector<IndexGuias>&, vector<Cidades>&, vector<IndexCidades>&, vector<Paises>&, vector<IndexPaises>&);
void consultarDadosVendas(vector<Vendas>&, vector<IndexVendas>&, vector<Clientes>&, vector<IndexClientes>&, vector<Pacotes>&, vector<IndexPacotes>&);

void organizarDadosTabelaClientes(vector<Clientes>&, vector<IndexClientes>&);

//Funções de busca genéricos que retornam Boolean para verificar se o código já existe
bool buscarPaisPorCodigo( vector<IndexPaises>&, int);
bool buscarCidadePorCodigo( vector<IndexCidades>&, int);
bool buscarGuiaPorCodigo( vector<IndexGuias>&, int);
bool buscarClientePorCodigo( vector<IndexClientes>&, int);
bool buscarPacotePorCodigo( vector<IndexPacotes>&, int);
bool buscarVendaPorCodigo( vector<IndexVendas>&, int);

int main() {
    int opcao = 0;

    setlocale(LC_ALL, "Portuguese");

    vector<Paises> paises = {{8, "Brasil"},{12, "Argentina"},{3, "Uruguai"},{7, "Paraguai"},{9, "Chile"}};
    vector<IndexPaises> indexPaises = {{3, 2},{7, 3},{8, 0},{9, 4},{12, 1}};

    vector<Cidades> cidades = {{103, "Rio de Janeiro", "RJ", 8},{7, "Sao Paulo", "SP", 8},{89, "Buenos Aires", "BA", 12},{4, "Montevideu", "MT", 3},{97, "Assuncao", "AS", 7},{1, "Santiago", "ST", 9}};
    vector<IndexCidades> indexCidades = {{1, 5},{4, 3},{7, 1},{89, 2},{97, 4},{103, 0}};

    vector<Guias> guias = {{6, "Francisco Alfredo", "Rua Almirzinho", "1111-1111", 4, false},{34, "Daniel Moscou Perdeu", "Rua Dieguinho", "2222-2222", 1, false},{52, "Elma Maria Pinto", "Rua Vitaozin", "3333-3333", 7, false},{16, "Jacinto Cabeca latras", "Rua Giovaninha", "4444-4444", 89, false},{90, "Tisugiro kimikoma", "Rua Guigazinho", "5555-5555", 103, false},{12, "Joaquim Fenix", "Rua das Flores", "6666-6666", 7, false}};
    vector<IndexGuias> indexGuias = {{6, 0},{16, 3},{34, 1},{52, 2},{90, 4},{12, 5}};

    vector<Clientes> clientes = {{12, "Joao da Silva", "Rua das Flores", 7, false},{90, "Maria de Souza", "Rua das Pedras", 1, false},{5, "Jose da Costa", "Rua das Arvores", 89, false},{8, "Ana Paula", "Rua das Rosas", 4, false},{27, "Carlos Alberto", "Rua das Margaridas", 103, false}};
    vector<IndexClientes> indexClientes = {{5, 2},{8, 3},{12, 0},{27, 4},{90, 1}};

    vector<Pacotes> pacotes = {{5, "Viagem para a China com direito a trabalho escravo e vigilancia indesejada 24 horas por dia", 52, 1000.00, 5, 10},{1, "Viagem para o Oriente Medio, durante 1 mes, com visita a faixa de gaza", 6, 800.00, 7, 10},{90, "Viagem para o Brasil, durante 3 dias, com visitas a favelas do Rio de Janeiro", 16, 600.00, 13, 15},{78, "Viagem para a Antartida, durante 5 meses, com visitas recorrentes de pinguins", 90, 1200.00, 10, 20},{12, "Viagem para a Russia, durante tempo indeterminado, com direito a 8 litros de vodka", 34, 1500.00, 9, 15}};
    vector<IndexPacotes> indexPacotes = {{1, 1},{5, 0},{12, 4},{78, 3},{90, 2}};

    vector<Vendas> vendas = {{67, 12, 5, 5, 5000.00},{2, 90, 1, 7, 5600.00},{12, 5, 90, 13, 7800.00}};
    vector <IndexVendas> indexVendas = {{2, 1},{12, 2},{67, 0}};

    do {
        textoInicial();
        cout<<"\tInforme a opcao desejada{ \n" << "\t\t[1] - Inclusoes \n" << "\t\t[2] - Excluir Determinado Cliente \n"<<"\t\t[3] - Excluir Determinado Guia \n"<< "\t\t[4] - Consultar Pacotes que foram completamente Vendidos \n"<<"\t\t[5] - Consultar Dados de Determinado Pacote\n" << "\t\t[6] - Consultar Todas as Vendas Feitas \n" << "\t\t[7] - Organizar Tabela de Clientes\n" <<"\n\n\t\t[0] - Sair \n" << "\t}";
        cout << "[>] ";
        cin >> opcao;
        cin.ignore();

        if(opcao == 1) {
            menuDeInclusao(paises, indexPaises, cidades, indexCidades, guias, indexGuias, clientes, indexClientes, pacotes, indexPacotes, vendas, indexVendas);
        } else if(opcao == 2) {
            excluirCliente(clientes, indexClientes, cidades, indexCidades, vendas, indexVendas);
        } else if(opcao == 3) {
            excluirGuia(guias, indexGuias, cidades, indexCidades, paises, indexPaises, pacotes, indexPacotes);
        } else if(opcao == 4) {
            consultarDadosPacoteCompletamenteVendidos(pacotes, indexPacotes, guias, indexGuias, cidades, indexCidades, paises, indexPaises);
        } else if(opcao == 5) {
            consultarDadosDeterminadoPacote(pacotes, indexPacotes, guias, indexGuias, cidades, indexCidades, paises, indexPaises);
        } else if(opcao == 6) {
            consultarDadosVendas(vendas, indexVendas, clientes, indexClientes, pacotes, indexPacotes);
        } else if(opcao == 7) {
            organizarDadosTabelaClientes(clientes, indexClientes);
        } else if(opcao == 8) {
            for(auto & cliente : clientes) {
                cout<<cliente.codigoCliente<<" - "<<cliente.nome<<endl;
            }
            system("pause");
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
void menuDeInclusao(vector<Paises> & paises, vector<IndexPaises> & indexPaises, vector<Cidades> & cidades, vector<IndexCidades> & indexCidades, vector<Guias> & guias, vector<IndexGuias> & indexGuias, vector<Clientes> & clientes, vector<IndexClientes> & indexClientes, vector<Pacotes> & pacotes, vector<IndexPacotes> & indexPacotes, vector<Vendas> & vendas, vector<IndexVendas> & indexVendas) {
    int opcao = 0;
    system("cls");
    do {
        cout<<"\tInforme em qual tabela deseja incluir{ \n" << "\t\t[1] - Incluir Novo Pais \n" << "\t\t[2] - Incluir Nova Cidade \n"<<"\t\t[3] - Incluir Novo Guia \n"<< "\t\t[4] - Incluir Novo Cliente \n"<<"\t\t[5] - Incluir Novo Pacote \n" << "\t\t[6] - Incluir Nova Venda \n" << "\n\n\t\t[0] - Voltar para o Menu \n" << "\t}";
        cout << "[>] ";
        cin >> opcao;
        cin.ignore();

        if(opcao == 1) {
            incluirNovoPais(paises, indexPaises);
        } else if(opcao == 2) {
            incluirNovaCidade(cidades, indexCidades, paises, indexPaises);
        } else if(opcao == 3) {
            incluirNovoGuia(guias, indexGuias, cidades, indexCidades, paises, indexPaises);
        } else if(opcao == 4) {
            incluirNovoCliente(clientes, indexClientes, cidades, indexCidades, paises, indexPaises);
        } else if (opcao == 5) {
            incluirNovoPacote(pacotes, indexPacotes, guias, indexGuias, cidades, indexCidades, paises, indexPaises);
        } else if (opcao == 6) {
            incluirNovaVenda(vendas, indexVendas, clientes, indexClientes, pacotes, indexPacotes, guias, indexGuias, cidades, indexCidades, paises, indexPaises);
        } else {
            opcao = 0;
        }
    } while (opcao != 0);
    system("cls");
}

void incluirNovoPais(vector<Paises>& paises, vector<IndexPaises>& indexPaises) {
    bool inseriu = false;
    Paises novoPais{};
    IndexPaises novoIndexPais{};
    system("cls");
    do {
        exibirCodigosPaises(indexPaises, paises);
        cout<<"\tInforme o codigo do novo pais \n\t[>] ";
        do {
            cin>>novoPais.codigoPais;
            cin.ignore();
        } while(novoPais.codigoPais < 0);
    }while(buscarPaisPorCodigo(indexPaises, novoPais.codigoPais));
    novoIndexPais.codigoPais = novoPais.codigoPais;
    cout<<"\n\tInforme o nome do novo pais \n\t[>] ";
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
void incluirNovaCidade(vector<Cidades> & cidades, vector<IndexCidades> & indexCidades, vector<Paises> & paises, vector<IndexPaises> & indexPaises) {
    bool inseriu = false;
    Cidades novaCidade{};
    IndexCidades novoIndexCidade{};
    system("cls");
    do {
        exibirCodigosCidades(indexCidades, cidades, paises, indexPaises);
        cout<<"\tInforme o codigo da nova cidade \n\t[>] ";
        do {
            cin>>novaCidade.codigoCidade;
            cin.ignore();
        } while(novaCidade.codigoCidade < 0);
    }while (buscarCidadePorCodigo(indexCidades, novaCidade.codigoCidade));
    novoIndexCidade.codigoCidade = novaCidade.codigoCidade;
    cout<<"\n\tInforme o nome da nova cidade \n\t[>] ";
    gets(novaCidade.nome);
    cout<<"\n\tInforme a UF da nova cidade \n\t[>] ";
    gets(novaCidade.uf);
    cidades.push_back(novaCidade);
    // cout<<endl;
    // do {
    //     exibirCodigosPaises(indexPaises, paises);
    //     cout<<"\tInforme o codigo do pais da nova cidade \n\t[>] ";
    //     do {
    //         cin>>novaCidade.codigoPais;
    //         cin.ignore();
    //     }while (novaCidade.codigoPais < 0);
    // }while(buscarPaisPorCodigo(indexPaises, novaCidade.codigoPais));

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
        exibirCodigosGuias(indexGuias, guias, cidades, indexCidades, paises, indexPaises);
        do {
            cout<<"\tInforme o codigo do novo guia \n\t[>] ";
            cin >> novoGuia.codigoGuia;
            cin.ignore();
        }while(novoGuia.codigoGuia < 0);
    } while (buscarGuiaPorCodigo(indexGuias, novoGuia.codigoGuia));
    novoIndexGuia.codigoGuia = novoGuia.codigoGuia;
    cout<<"\n\tInforme o nome do novo guia \n\t[>] ";
    gets(novoGuia.nome);
    cout<<"\n\tInforme o endereco do novo guia \n\t[>] ";
    gets(novoGuia.endereco);
    cout<<"\n\tInforme o telefone do novo guia \n\t[>] ";
    gets(novoGuia.telefone);
    cout<< endl;
    exibirCodigosCidades(indexCidades, cidades, paises, indexPaises);
    bool aux = false;
    do {
        cout<<"\tInforme o codigo da cidade do novo guia \n\t[>] ";
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
void incluirNovoCliente(vector<Clientes> & clientes, vector<IndexClientes> & indexClientes, vector<Cidades> & cidades, vector<IndexCidades> & indexCidades, vector<Paises> & paises, vector<IndexPaises> & indexPaises) {
    bool inseriu = false;
    int resposta = 0;
    Clientes novoCliente{};
    IndexClientes novoIndexCliente{};
    system("cls");
    do {
        exibirCodigosClientes(indexClientes, clientes, cidades, indexCidades);
        do {
            cout<<"\tInforme o codigo do novo cliente \n\t[>] ";
            cin >> novoCliente.codigoCliente;
            cin.ignore();
        }while(novoCliente.codigoCliente < 0);
    } while(buscarClientePorCodigo(indexClientes, novoCliente.codigoCliente));
    novoIndexCliente.codigoCliente = novoCliente.codigoCliente;
    cout<<"\n\tInforme o nome do novo cliente \n\t[>] ";
    gets(novoCliente.nome);
    cout<<"\n\tInforme o endereco do novo cliente \n\t[>] ";
    gets(novoCliente.endereco);
    cout<< endl;
    exibirCodigosCidades(indexCidades, cidades, paises, indexPaises);
    bool aux = false;
    do {
        cout<<"\tInforme o codigo da cidade do novo cliente \n\t[>] ";
        cin>>novoCliente.codigoCidade;
        cin.ignore();
        for(auto & indexCidade : indexCidades) {
            if(indexCidade.codigoCidade == novoCliente.codigoCidade && !aux) {
                aux = true;
            }
        }
        if(aux == false) {
            cout<<"\n\t\t[==Cidade nao encontrada==] \n\n\tDeseja cadastrar uma nova cidade?? [1 - Sim | 0 - Nao] \n\t[>] ";
            cin>>resposta;
            cin.ignore();
            if(resposta == 1) {
                incluirNovaCidade(cidades, indexCidades, paises, indexPaises);
            }
        }
    }while (aux == false);
    clientes.push_back(novoCliente);
    novoIndexCliente.index = static_cast<int>(clientes.size()-1);
    int position = 0;
    for(auto & indexCliente : indexClientes) {
        if(novoIndexCliente.codigoCliente < indexCliente.codigoCliente && !inseriu) {
            indexClientes.insert(indexClientes.begin() + position, novoIndexCliente);
            inseriu = true;
        }
        if(position == indexClientes.size() - 1 && !inseriu) {
            indexClientes.push_back(novoIndexCliente);
            inseriu = true;
        }
        position++;
    }
    system("cls");
}
void incluirNovoPacote(vector<Pacotes> & pacotes, vector<IndexPacotes> & indexPacotes, vector<Guias> & guias, vector<IndexGuias> & indexGuias, vector<Cidades> & cidades, vector<IndexCidades> & indexCidades, vector<Paises> & paises, vector<IndexPaises> & indexPaises) {
    bool inseriu = false;
    Pacotes novoPacote{};
    IndexPacotes novoIndexPacote{};
    system("cls");
    do {
        exibirCodigosPacotes(indexPacotes, pacotes, indexGuias, guias, cidades, indexCidades, paises, indexPaises);
        do {
            cout<<"\tInforme o codigo do novo pacote \n\t[>] ";
            cin >> novoPacote.codigoPacote;
            cin.ignore();
        }while(novoPacote.codigoPacote < 0);
    } while(buscarPacotePorCodigo(indexPacotes, novoPacote.codigoPacote));
    novoIndexPacote.codigoPacote = novoPacote.codigoPacote;
    cout<<"\n\tInforme a descricao do novo pacote \n\t[>] ";
    gets(novoPacote.descricao);
    cout<<"\n\tInforme o valor por pessoa do novo pacote \n\t[>] ";
    cin>>novoPacote.valorPorPessoa;
    cin.ignore();
    cout<<"\n\tInforme o total de pessoas do novo pacote \n\t [>] ";
    cin>>novoPacote.totalPessoas;
    cin.ignore();
    cout<<"\n\tInforme a quantidade maxima suportada do novo pacote \n\t[>] ";
    cin>>novoPacote.quantidadeMaximaSuportada;
    cin.ignore();
    cout<< endl;
    exibirCodigosGuias(indexGuias, guias, cidades, indexCidades, paises, indexPaises);
    bool aux = false;
    do {
        cout<<"\tInforme o codigo do guia do novo pacote \n\t[>] ";
        cin>>novoPacote.codigoGuia;
        cin.ignore();
        for(auto & indexGuia : indexGuias) {
            if(indexGuia.codigoGuia == novoPacote.codigoGuia && !aux) {
                aux = true;
            }
        }
        if(aux == false) {
            cout<<"\t[==Guia nao encontrado==]" <<endl;
        }
    } while(aux == false);
    pacotes.push_back(novoPacote);
    novoIndexPacote.index = static_cast<int>(pacotes.size()-1);
    int position = 0;
    for(auto & indexPacote : indexPacotes) {
        if(novoIndexPacote.codigoPacote < indexPacote.codigoPacote && !inseriu) {
            indexPacotes.insert(indexPacotes.begin() + position, novoIndexPacote);
            inseriu = true;
        }
        if(position == indexPacotes.size() - 1 && !inseriu) {
            indexPacotes.push_back(novoIndexPacote);
            inseriu = true;
        }
        position++;
    }
    system("cls");
}
void incluirNovaVenda(vector<Vendas> & vendas, vector<IndexVendas> & indexVendas, vector<Clientes> & clientes, vector<IndexClientes> & indexClientes, vector<Pacotes> & pacotes, vector<IndexPacotes> & indexPacotes,  vector<Guias> & guias, vector<IndexGuias> & indexGuias,  vector<Cidades> & cidades, vector<IndexCidades> & indexCidades,  vector<Paises> & paises, vector<IndexPaises> & indexPaises) {
    bool inseriu = false;
    int indexDoPacote = 0;
    Vendas novaVenda{};
    IndexVendas novoIndexVenda{};
    Pacotes pacoteSelecionado{};
    system("cls");
    do {
        exibirCodigosVendas(indexVendas, vendas, clientes, indexClientes, pacotes, indexPacotes);
        do {
            cout<<"\tInforme o codigo da nova venda \n\t[>] ";
            cin >> novaVenda.codigoVenda;
            cin.ignore();
        }while(novaVenda.codigoVenda < 0);
    } while(buscarVendaPorCodigo(indexVendas, novaVenda.codigoVenda));
    novoIndexVenda.codigoVenda = novaVenda.codigoVenda;
    bool aux = false;
    cout<<endl;
    system("cls");
    do {
        exibirCodigosClientes(indexClientes, clientes, cidades, indexCidades);
        cout<<"\tInforme o codigo do cliente da nova venda \n\t[>] ";
        cin>>novaVenda.codigoCliente;
        cin.ignore();

        for(auto & indexCliente : indexClientes) {
            if(indexCliente.codigoCliente == novaVenda.codigoCliente && !aux) {
                aux = true;
            }
        }
        if(aux == false) {
            cout<<"\t[==Cliente nao encontrado==]" <<endl;
        }
    } while(aux == false);
    aux = false;
    system("cls");
    do {
        exibirCodigosPacotes(indexPacotes, pacotes, indexGuias, guias, cidades, indexCidades, paises, indexPaises);
        cout<<"\n\tInforme o codigo do pacote da nova venda \n\t[>] ";
        cin>>novaVenda.codigoPacote;
        cin.ignore();
        for(auto & indexPacote : indexPacotes) {
            if(indexPacote.codigoPacote == novaVenda.codigoPacote && !aux) {
                aux = true;
                pacoteSelecionado = pacotes[indexPacote.index];
                indexDoPacote = indexPacote.index;
            }
        }
        if(aux == false) {
            cout<<"\t[==Pacote nao encontrado==]" <<endl;
        }
    } while(aux == false);
    do {
        cout<<"\n\tInforme para quantas pessoas deseja compra o pacote\n\t[>]  ";
        cin>>novaVenda.quantidadePessoas;
        cin.ignore();
    }while (novaVenda.quantidadePessoas < 0);
    if(novaVenda.quantidadePessoas > pacoteSelecionado.quantidadeMaximaSuportada - pacoteSelecionado.totalPessoas) {
        do {
            cout<< "\n\t[==Quantidade de pessoas excede a quantidade de vagas restantes para o pacote==]\n";
            cout<< "\n\t[==Quantidade de vagas restantes: "<< pacoteSelecionado.quantidadeMaximaSuportada - pacoteSelecionado.totalPessoas << "]==\n";
            do {
                cout<<"\n\tInforme para quantas pessoas deseja compra o pacote\n\t[>] ";
                cin>>novaVenda.quantidadePessoas;
                cin.ignore();
            }while (novaVenda.quantidadePessoas < 0);
            cout<<novaVenda.quantidadePessoas;
        }while(novaVenda.quantidadePessoas > pacoteSelecionado.quantidadeMaximaSuportada - pacoteSelecionado.totalPessoas);
    }
    pacotes[indexDoPacote].totalPessoas += novaVenda.quantidadePessoas;
    novaVenda.valorTotal = novaVenda.quantidadePessoas * pacoteSelecionado.valorPorPessoa;
    vendas.push_back(novaVenda);
    novoIndexVenda.index = static_cast<int>(vendas.size()-1);
    int position = 0;
    for(auto & indexVenda : indexVendas) {
        if(novoIndexVenda.codigoVenda < indexVenda.codigoVenda && !inseriu) {
            indexVendas.insert(indexVendas.begin() + position, novoIndexVenda);
            inseriu = true;
        }
        if(position == indexVendas.size() - 1 && !inseriu) {
            indexVendas.push_back(novoIndexVenda);
            inseriu = true;
        }
        position++;
    }

    system("cls");
}
void consultarDadosPacoteCompletamenteVendidos(vector<Pacotes> & pacotes, vector<IndexPacotes> & indexPacotes, vector<Guias> & guias, vector<IndexGuias> & indexGuias, vector<Cidades> & cidades, vector<IndexCidades> & indexCidades, vector<Paises> & paises, vector<IndexPaises> & indexPaises) {
    system("cls");
    cout<<"\tPacotes completamente vendidos: "<<endl;
    bool aux = false;
    for(auto & indexPacote : indexPacotes) {
        Pacotes pacoteSelecionado = pacotes[indexPacote.index];
        if(pacoteSelecionado.quantidadeMaximaSuportada == pacoteSelecionado.totalPessoas) {
            cout<< "\t\t[Codigo: "<< pacoteSelecionado.codigoPacote << "] Descricao: " << pacoteSelecionado.descricao;
            for(auto & indexGuia : indexGuias) {
                if(indexGuia.codigoGuia == pacoteSelecionado.codigoGuia) {
                    Guias guiaSelecionado = guias[indexGuia.index];
                    cout<<"\n\t\t\t\t Guia: "<< guiaSelecionado.nome;
                    for(auto & indexCidade : indexCidades) {
                        if(indexCidade.codigoCidade == guiaSelecionado.codigoCidade) {
                            Cidades cidadeSelecionada = cidades[indexCidade.index];
                            cout<<"\n\t\t\t\t Cidade: "<< cidadeSelecionada.nome;
                            for(auto & indexPais : indexPaises) {
                                if(indexPais.codigoPais == cidadeSelecionada.codigoPais) {
                                    Paises paisSelecionado = paises[indexPais.index];
                                    cout<<"\n\t\t\t\t Pais: "<< paisSelecionado.nome;
                                }
                            }
                        }
                    }
                }
            }
            cout<<"\n\t\t\t\t Total arrecadado: R$ "<< pacoteSelecionado.valorPorPessoa * pacoteSelecionado.totalPessoas << endl;
            aux = true;
        }
    }
    if(aux == false) {
        cout<<"\t[==Nenhum pacote foi completamente vendido==]\n";
    }
    system("pause");
}
void consultarDadosDeterminadoPacote(vector<Pacotes> & pacotes, vector<IndexPacotes> & indexPacotes, vector<Guias> & guias, vector<IndexGuias> & indexGuias, vector<Cidades> & cidades, vector<IndexCidades> & indexCidades, vector<Paises> & paises, vector<IndexPaises> & indexPaises) {
    system("cls");
    int codigoPacote = 0;
    bool achou = false;
    cout<< "\tPacotes disponiveis: "<<endl;
    for(auto & indexPacote : indexPacotes) {
        Pacotes pacoteSelecionado = pacotes[indexPacote.index];
        cout<< "\t\t[Codigo: "<< pacoteSelecionado.codigoPacote << "] Descricao: " << pacoteSelecionado.descricao << endl;
    }
    do {
        cout<< "\n\tInforme qual pacote deseja consultar \n\t[>] ";
        cin >> codigoPacote;
        cin.ignore();
    }while(codigoPacote < 0);
    for(auto & indexPacote : indexPacotes) {
        Pacotes pacoteSelecionado = pacotes[indexPacote.index];
        if(pacoteSelecionado.codigoPacote == codigoPacote) {
            achou = true;
            cout<< "\t\t[Codigo: "<< pacoteSelecionado.codigoPacote << "] Descricao: " << pacoteSelecionado.descricao;
            for(auto & indexGuia : indexGuias) {
                if(indexGuia.codigoGuia == pacoteSelecionado.codigoGuia) {
                    Guias guiaSelecionado = guias[indexGuia.index];
                    cout<<"\n\t\t\t\t Guia: "<< guiaSelecionado.nome;
                    for(auto & indexCidade : indexCidades) {
                        if(indexCidade.codigoCidade == guiaSelecionado.codigoCidade) {
                            Cidades cidadeSelecionada = cidades[indexCidade.index];
                            cout<<"\n\t\t\t\t Cidade: "<< cidadeSelecionada.nome;
                            for(auto & indexPais : indexPaises) {
                                if(indexPais.codigoPais == cidadeSelecionada.codigoPais) {
                                    Paises paisSelecionado = paises[indexPais.index];
                                    cout<<"\n\t\t\t\t Pais: "<< paisSelecionado.nome;
                                }
                            }
                        }
                    }
                }
            }
            cout<<"\n\t\t\t\t Total arrecadado: R$ "<< pacoteSelecionado.valorPorPessoa * pacoteSelecionado.totalPessoas << endl;
        }
    }
    if(achou == false) {
        cout<<"\t[==Pacote nao encontrado==]\n";
    }
    system("pause");
}
void consultarDadosVendas(vector<Vendas> & vendas, vector<IndexVendas> & indexVendas, vector<Clientes> & clientes, vector<IndexClientes> & indexClientes, vector<Pacotes> & pacotes, vector<IndexPacotes> & indexPacotes) {
    system("cls");
    double totalVendas = 0;
    cout<<"\tTodas as vendas realizadas: "<<endl;
    for(auto & indexVenda : indexVendas) {
        Vendas vendaSelecionada = vendas[indexVenda.index];
        cout<<"\t\t[Codigo: "<<vendaSelecionada.codigoVenda<<"] Cliente: ";
        for(auto & indexCliente : indexClientes) {
            if(indexCliente.codigoCliente == vendaSelecionada.codigoCliente) {
                Clientes clienteSelecionado = clientes[indexCliente.index];
                cout<<clienteSelecionado.nome;
            }
        }
        cout<<"\n\t\t\tPacote: ";
        for(auto & indexPacote : indexPacotes) {
            if(indexPacote.codigoPacote == vendaSelecionada.codigoPacote) {
                Pacotes pacoteSelecionado = pacotes[indexPacote.index];
                cout<<""<<pacoteSelecionado.descricao;
            }
        }
        cout<< "\n\t\t\tQuantidade de pessoas: "<<vendaSelecionada.quantidadePessoas;
        cout<< "\n\t\t\tValor total vendido: R$ "<<vendaSelecionada.valorTotal<<"\n"<<endl;
        totalVendas+= vendaSelecionada.valorTotal;
    }

    cout<<"\t\t[Total de todas as vendas]: R$ "<<totalVendas<<endl;

    system("pause");
}

void organizarDadosTabelaClientes(vector<Clientes> & clientes, vector<IndexClientes> & indexClientes) {
    system("cls");
    vector<IndexClientes> auxIndex = indexClientes;
    vector<Clientes> aux = clientes;
    indexClientes.clear();
    clientes.clear();
    for(auto & indexCliente : auxIndex) {
        if(!aux[indexCliente.index].excluido) {
            indexClientes.push_back(indexCliente);
            clientes.push_back(aux[indexCliente.index]);
        }
    }
    cout<<"\t[==Clientes organizados com sucesso==]\n";
    system("cls");
}

void excluirCliente(vector<Clientes> & clientes, vector<IndexClientes> & indexClientes, vector<Cidades> & cidades, vector<IndexCidades> & indexCidades,  vector<Vendas> & vendas, vector<IndexVendas> & indexVendas) {
    system("cls");
    exibirCodigosClientes(indexClientes, clientes, cidades, indexCidades);
    int codigoCliente = 0;
    bool vendaCadastradaParaOCliente = false;
    do {
        cout<< "\tInforme o codigo do cliente que deseja excluir \n\t[>] ";
        cin>>codigoCliente;
        cin.ignore();
    } while (codigoCliente < 0);
    for(auto & indexCliente : indexClientes) {
        if(indexCliente.codigoCliente == codigoCliente && !clientes[indexCliente.index].excluido) {
            for(auto & indexVenda : indexVendas) {
                if(vendas[indexVenda.index].codigoCliente == codigoCliente) {
                    vendaCadastradaParaOCliente = true;
                }
            }
            if(vendaCadastradaParaOCliente == true) {
                cout<<"\t[==Cliente possui venda cadastrada, nao pode ser excluido==]\n\n";
            } else {
                clientes[indexCliente.index].excluido = true;
                //indexClientes.erase( indexClientes.begin() + indexCliente.index -1);
                cout<<"\n\t\t[==Cliente excluido com sucesso==]\n\n";
            }
        }
    }
    system("pause");
}
void excluirGuia(vector<Guias> & guias, vector<IndexGuias> & indexGuias, vector<Cidades> & cidades, vector<IndexCidades> & indexCidade,  vector<Paises> & paises, vector<IndexPaises> & indexPaises,  vector<Pacotes> & pacotes, vector<IndexPacotes> & indexPacotes) {
    system("cls");
    exibirCodigosGuias(indexGuias, guias, cidades, indexCidade, paises, indexPaises);
    int codigoGuia = 0;
    bool pacoteCadastradoParaOGuia = false;
    do {
        cout<< "\tInforme o codigo do guia que deseja excluir \n\t[>] ";
        cin>>codigoGuia;
        cin.ignore();
    } while (codigoGuia < 0);
    for(auto & indexGuia : indexGuias) {
        if(indexGuia.codigoGuia == codigoGuia && !guias[indexGuia.index].excluido) {
            for(auto & indexPacote : indexPacotes) {
                if(pacotes[indexPacote.index].codigoGuia == codigoGuia) {
                    pacoteCadastradoParaOGuia = true;
                }
            }
            if(pacoteCadastradoParaOGuia == true) {
                cout<<"\t[==Guia possui pacote cadastrado, nao pode ser excluido==]\n\n";
            } else {
                guias[indexGuia.index].excluido = true;
                //indexGuias.erase( indexGuias.begin() + indexGuia.index -1);
                cout<<"\n\t\t[==Guia excluido com sucesso==]\n\n";
            }
        }
    }
    system("pause");
}

void exibirCodigosPaises(vector<IndexPaises> & indexPaises, vector<Paises> & paises) {
    cout<<"\tPaises Cadastrados: "<<endl;
    for(auto & indexPais : indexPaises) {
        Paises paisSelecionado = paises[indexPais.index];
        cout<<"\t\t [Codigo: "<<indexPais.codigoPais<<"] Nome do Pais: " << paisSelecionado.nome<<endl;
    }
    cout<<"\n";
}
void exibirCodigosCidades(vector<IndexCidades> & indexCidades, vector<Cidades> & cidades, vector<Paises> & paises, vector<IndexPaises> & indexPaises) {
    cout<<"\tCidades Cadastradas: "<<endl;
    for(auto & indexCidade : indexCidades) {
        Cidades cidadeSelecionada = cidades[indexCidade.index];
        cout<<"\t\t [Codigo: "<<indexCidade.codigoCidade<<"] Nome: " << cidadeSelecionada.nome<<"\n\t\t\t\t UF: "<< cidadeSelecionada.uf <<endl;
        for(auto & indexPais : indexPaises) {
            if(indexPais.codigoPais == cidadeSelecionada.codigoPais) {
                Paises paisSelecionado = paises[indexPais.index];
                cout<<"\t\t\t\t Pais: "<<paisSelecionado.nome<<"\n"<< endl;
            }
        }
    }
    cout<<"\n";
}
void exibirCodigosGuias(vector<IndexGuias> & indexGuias, vector<Guias> & guias, vector<Cidades> & cidades, vector<IndexCidades> & indexCidades, vector<Paises> & paises, vector<IndexPaises> & indexPaises) {
    cout<< "\tGuias Cadastrados: "<<endl;
    for(auto & indexGuia : indexGuias) {
        Guias guiaSelecionado = guias[indexGuia.index];
        if(!guiaSelecionado.excluido) {
            cout<<"\t\t [Codigo: "<<indexGuia.codigoGuia<<"] Nome: "<<guiaSelecionado.nome<<"\n\t\t\t\t Endereco: " << guiaSelecionado.endereco << "\n\t\t\t\t Telefone: "  << guiaSelecionado.telefone <<  endl;
            for(auto & indexCidade : indexCidades) {
                if(indexCidade.codigoCidade == guiaSelecionado.codigoCidade) {
                    Cidades cidadeSelecionada = cidades[indexCidade.index];
                    cout<<"\t\t\t\t\t Cidade: "<<cidadeSelecionada.nome<<"\n";
                    for(auto & indexPais : indexPaises) {
                        if(indexPais.codigoPais == cidadeSelecionada.codigoPais) {
                            Paises paisSelecionado = paises[indexPais.index];
                            cout<<"\t\t\t\t\t Pais: "<<paisSelecionado.nome<<"\n"<<endl;
                        }
                    }
                }
            }
        }
    }
}
void exibirCodigosClientes(vector<IndexClientes> & indexClientes, vector<Clientes> & clientes, vector<Cidades> & cidades, vector<IndexCidades> & indexCidades) {
    cout<<"\tClientes Cadastrados: "<<endl;
    for(auto & indexCliente : indexClientes) {
        Clientes clienteSelecionado = clientes[indexCliente.index];
        if(!clienteSelecionado.excluido) {
            cout<<"\t\t [Codigo: "<<indexCliente.codigoCliente<<"] Nome: " <<clienteSelecionado.nome<<"\n\t\t\t\t Endereco: "<< clienteSelecionado.endereco << endl;
            for(auto & indexCidade : indexCidades) {
                if(indexCidade.codigoCidade == clienteSelecionado.codigoCidade) {
                    Cidades cidadeSelecionada = cidades[indexCidade.index];
                    cout<<"\t\t\t\t\t Cidade: "<<cidadeSelecionada.nome<<"\n"<<endl;
                }
            }
        }
    }
    cout<<"\n";
}
void exibirCodigosPacotes(vector<IndexPacotes> & indexPacotes, vector<Pacotes> & pacotes, vector<IndexGuias> & indexGuias, vector<Guias> & guias, vector<Cidades> & cidades, vector<IndexCidades> & indexCidades,  vector<Paises> & paises, vector<IndexPaises> & indexPaises) {
    cout<< "\tPacotes Disponiveis: "<<endl;
    for(auto & indexPacote : indexPacotes) {
        Pacotes pacoteSelecionado = pacotes[indexPacote.index];
        cout<<"\t\t[Codigo: "<<indexPacote.codigoPacote<<"] Descricao: "<<pacoteSelecionado.descricao<<"\n\t\t\t\t Valor por Pessoa: "<< pacoteSelecionado.valorPorPessoa << "\n\t\t\t\t Total de Pessoas: " << pacoteSelecionado.totalPessoas << "\n\t\t\t\t Quantidade Maxima Suportada: " << pacoteSelecionado.quantidadeMaximaSuportada << endl;
        for(auto & indexGuia : indexGuias) {
            if(indexGuia.codigoGuia == pacoteSelecionado.codigoGuia) {
                Guias guiaSelecionado = guias[indexGuia.index];
                cout<<"\t\t\t\t\t Guia: "<<guiaSelecionado.nome<<"\n";
                for(auto & indexCidade : indexCidades) {
                    if(indexCidade.codigoCidade == guiaSelecionado.codigoCidade) {
                        Cidades cidadeSelecionada = cidades[indexCidade.index];
                        cout<<"\t\t\t\t\t Cidade: "<<cidadeSelecionada.nome<<"\n";
                        for(auto & indexPais : indexPaises) {
                            if(indexPais.codigoPais == cidadeSelecionada.codigoPais) {
                                Paises paisSelecionado = paises[indexPais.index];
                                cout<<"\t\t\t\t\t Pais: "<<paisSelecionado.nome<<"\n"<<endl;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<< "\n";
}
void exibirCodigosVendas(vector<IndexVendas> & indexVendas, vector<Vendas> & vendas, vector<Clientes> & clientes, vector<IndexClientes> & indexClientes, vector<Pacotes> & pacotes, vector<IndexPacotes> & indexPacotes) {
    cout<<"\tVendas Realizadas: "<<endl;
    for(auto & indexVenda : indexVendas) {
        Vendas vendaSelecionada = vendas[indexVenda.index];
        cout<<"\t\t[Codigo: "<<indexVenda.codigoVenda<<"] Valor Total: "<<vendaSelecionada.valorTotal<<"\n\t\t\t\t Quantidade de Pessoas: "<< vendaSelecionada.quantidadePessoas << endl;
        for(auto & indexCliente : indexClientes) {
            if(indexCliente.codigoCliente == vendaSelecionada.codigoCliente) {
                Clientes clienteSelecionado = clientes[indexCliente.index];
                cout<<"\t\t\t\t\t Cliente: "<<clienteSelecionado.nome<<endl;
            }
        }
        for(auto & indexPacote : indexPacotes) {
            if(indexPacote.codigoPacote == vendaSelecionada.codigoPacote) {
                Pacotes pacoteSelecionado = pacotes[indexPacote.index];
                cout<<"\t\t\t\t\t Pacote: "<<pacoteSelecionado.descricao<<"\n"<<endl;
            }
        }
    }
    cout<<"\n";
}

//Funções de busca genéricos que retornam Boolean para verificar se o código já existe
bool buscarPaisPorCodigo(vector<IndexPaises>& indexPaises,int codigo) {
    for (auto & index : indexPaises) {
        if(index.codigoPais == codigo) {
            system("cls");
            cout<<"\t[==Pais ja cadastrado==]\n \n";
            return true;
        }
    }
    return false;
}
bool buscarCidadePorCodigo(vector<IndexCidades>& indexCidades,int codigo) {
    for (auto & index : indexCidades) {
        if(index.codigoCidade == codigo) {
            system("cls");
            cout<<"\t[==Cidade ja cadastrada==]\n\n ";
            return true;
        }
    }
    return false;
}
bool buscarGuiaPorCodigo(vector<IndexGuias>& indexGuias,int codigo) {
    for (auto & index : indexGuias) {
        if(index.codigoGuia == codigo) {
            system("cls");
            cout<<"\t[==Guia ja cadastrado==]\n\n";
            return true;
        }
    }
    return false;
}
bool buscarClientePorCodigo(vector<IndexClientes>& indexClientes,int codigo) {
    for (auto & index : indexClientes) {
        if(index.codigoCliente == codigo) {
            system("cls");
            cout<<"\t[==Cliente ja cadastrado==]\n\n";
            return true;
        }
    }
    return false;
}
bool buscarPacotePorCodigo(vector<IndexPacotes>& indexPacotes,int codigo) {
    for (auto & index : indexPacotes) {
        if(index.codigoPacote == codigo) {
            system("cls");
            cout<<"\t[==Pacote ja cadastrado==]\n\n";
            return true;
        }
    }
    return false;
}
bool buscarVendaPorCodigo(vector<IndexVendas>& indexVendas,int codigo) {
    for (auto & index : indexVendas) {
        if(index.codigoVenda == codigo) {
            system("cls");
            cout<<"\t[==Venda ja cadastrada==]\n\n";
            return true;
        }
    }
    return false;
}