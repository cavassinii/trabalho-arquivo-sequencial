#include <iostream>
#include <conio.h>
#include <cstring>
#include <cstdlib>

using namespace std;

#define TAMAX 10

struct cidade {
    int codigo;
    string nome;
    string uf;
};

struct curso {
    int codigo;
    string descricao;
    float valorAula;
};

struct instrutor {
    int codigo;
    string nome;
    string endereco;
    int codigoCidade;
};

struct aluno {
    int codigo;
    string nome;
    string endereco;
    int codigoCidade;
};

struct turma {
    int codigo;
    int codigoCurso;
    int codigoInstrutor;
    int totalParticipantes;
    int quantMaxParticipantes;
};

struct matricula {
    int codigo;
    int codigoAluno;
    int codigoTurma;
    int quantidadeAulas;
    float valorTotal;
};

void leituraCidade(struct cidade v[], int &qtdRegistros);
int buscaBinariaCidade(cidade vetorCidade[], int cod);

void leituraInstrutor(struct instrutor v[], int &qtdRegistros, struct instrutor vetorInstrutores[], int qtdRegistrosInstrutor, struct cidade vetorCidades[], int qtdRegistrosCidade);
int buscaBinariaInstrutor(instrutor vetorInstrutor[], int cod);
void inclusaoInstrutor(struct instrutor S[], int contS, struct instrutor T[], int contT, struct instrutor A[], int &contA);

int main() {
    int opcao;

    cidade cidades[TAMAX];
    int qtdRegistrosCidade;

    instrutor instrutores[TAMAX];
    int qtdRegistrosInstrutor = 0;

    instrutor T[TAMAX];
    int contT;

    instrutor S[TAMAX];
    int contS;

    do {
        system("cls");

        cout << "____M_E_N_U____" << endl;
        cout << "\n1. Cidades" << endl;
        cout << "2. Cursos" << endl;
        cout << "3. Instrutores" << endl;
        cout << "4. Alunos" << endl;
        cout << "5. Turmas" << endl;
        cout << "6. Matriculas" << endl;
        cout << "7. Sair" << endl;
        cout << "\nEscolha uma opcao: ";
        cin >> opcao;

        // Processa a escolha do usuário
        switch (opcao) {
        case 1:
            int operacaoCidade;
            system("cls");
            do {

                cout << "1. Leitura de Cidades" << endl;
                cout << "2. Voltar" << endl;
                cout << "\nEscolha uma operacao: ";
                cin >> operacaoCidade;

                switch (operacaoCidade) {
                case 1:
                    leituraCidade(cidades, qtdRegistrosCidade);

                    system("cls");

                    break;
                case 2:
                    break;
                default:
                    cout << "Opcao invalida, tente novamente." << endl;
                    break;
                }
            } while (operacaoCidade != 2);
            break;
        case 2:
            cout << "Voce selecionou a opcao 2." << endl;
            break;
        case 3:
            int operacaoInstrutor;

            if (qtdRegistrosInstrutor != 0) {
            }
            system("cls");
            do {

                cout << "1. Incluir de Instrutores" << endl;
                cout << "2. Voltar" << endl;
                cout << "\nEscolha uma operacao: ";
                cin >> operacaoInstrutor;

                switch (operacaoInstrutor) {
                case 1:
                    cout << "\n\n" << qtdRegistrosCidade << "\n\n";
                    cout << "Digite os cadastros a serem incluidos" << endl;
                    leituraInstrutor(T, contT, instrutores, qtdRegistrosInstrutor, cidades, qtdRegistrosCidade);
                    inclusaoInstrutor(S, contS, T, contT, instrutores, qtdRegistrosInstrutor);

                    for (int i = 0; i < qtdRegistrosInstrutor; i++) {
                        S[i].codigo = instrutores[i].codigo;
                        S[i].nome = instrutores[i].nome;
                        S[i].endereco = instrutores[i].endereco;
                        S[i].codigoCidade = instrutores[i].codigoCidade;
                    }

                    contS = qtdRegistrosInstrutor;

                    system("cls");

                    break;
                case 2:

                    break;
                default:
                    cout << "Opcao invalida, tente novamente." << endl;

                    break;
                }
            } while (operacaoInstrutor != 2);

            break;
        case 4:
            cout << "Saindo do programa..." << endl;
            break;
        case 5:
            cout << "Saindo do programa..." << endl;
            break;
        case 6:
            cout << "Saindo do programa..." << endl;
            break;
        case 7:
            cout << "Saindo do programa..." << endl;
            break;
        default:
            cout << "Opcao invalida. Por favor, escolha uma opcao valida." << endl;
            break;
        }
    } while (opcao != 7);

    for (int i = 0; i < qtdRegistrosInstrutor; i++) {
        cout << "\n\n**Registro " << i + 1 << "**" << endl;
        cout << "Codigo: " << instrutores[i].codigo << endl;
        cout << "Nome: " << instrutores[i].nome << endl;
        cout << "Endereco: " << instrutores[i].endereco << endl;
        cout << "Codigo_cidade: " << instrutores[i].codigoCidade << endl;
    }

    return 0;
}

int buscaBinariaCidade(cidade vetorCidade[], int cod, int qtdCidades) {
    int i = 0;
    for (; i < qtdCidades; i++) {
        if (cod == vetorCidade[i].codigo) {
            return i;
        }
    }
    return -1;
}

bool buscaSerialInstrutor(instrutor vetorInstrutor[], int cod, int cont) {
    int i = 0;
    for (; i < cont; i++) {
        if (cod == vetorInstrutor[i].codigo) {
            return false;
        }
    }
    return true;
}

void leituraCidade(struct cidade v[], int &qtdRegistros) {
    int i = 0;

    cout << "\nLeitura de Cidades\n";
    for (int saida = 1; i < TAMAX && saida == 1; i++) {
        cout << "Codigo: ";
        cin >> v[i].codigo;
        cin.ignore();
        if (v[i].codigo != 0) {
            cout << "Nome: ";
            getline(cin, v[i].nome);
            cout << "UF: ";
            getline(cin, v[i].uf);
        } else
            saida = 0;
    }
    if (i == TAMAX) {
        qtdRegistros = i;
    } else
        qtdRegistros = i - 1;
    cout << "\n\n" << qtdRegistros << "\n\n";
}

void leituraCurso(struct curso v[], int &qtdRegistros) {
    int i = 0;

    cout << "\nCadastro de Cursos\n";
    for (int saida = 1; i < TAMAX && saida == 1; i++) {
        cout << "Codigo: ";
        cin >> v[i].codigo;
        cin.ignore();
        if (v[i].codigo != 0) {
            cout << "Descricao: ";
            getline(cin, v[i].descricao);
            cout << "Valor por aula: ";
            cin >> v[i].valorAula;
            cin.ignore();
        } else
            saida = 0;
        if (i == TAMAX) {
            qtdRegistros = i;
        } else
            qtdRegistros = i - 1;
    }
}

void leituraInstrutor(struct instrutor v[], int &qtdRegistros, struct instrutor vetorInstrutores[], int qtdRegistrosInstrutor, struct cidade vetorCidades[], int qtdRegistrosCidade) {
    int i = 0;

    cout << "\nCadastro de Instrutores\n";
    for (int saida = 1; i < TAMAX && saida == 1; i++) {
        for (int y = 1; y != -1;) {
            cout << "Codigo: ";
            cin >> v[i].codigo;
            cin.ignore();

            if (buscaSerialInstrutor(v, v[i].codigo, i) && buscaSerialInstrutor(vetorInstrutores, v[i].codigo, qtdRegistrosInstrutor)) {
                if (v[i].codigo > 0) {
                    cout << "Nome: ";
                    getline(cin, v[i].nome);
                    cout << "Endereco: ";
                    getline(cin, v[i].endereco);
                    for (; y != -1;) {
                        cout << "Codigo da Cidade: ";
                        cin >> v[i].codigoCidade;
                        int resultBusca = buscaBinariaCidade(vetorCidades, v[i].codigoCidade, qtdRegistrosCidade);
                        if (resultBusca != -1) {
                            cout << "Cidade: " << vetorCidades[resultBusca].nome << " " << vetorCidades[resultBusca].uf << "\n\n";
                            y = -1;

                        } else
                            cout << "\nCidade invalida!\n";
                    }

                } else
                    saida = -1;
                y = -1;

            } else
                cout << "\nCodigo repetido. Tente digitar outro codigo\n";

        }
    }

    if (i == TAMAX) {
        qtdRegistros = i;
    } else
        qtdRegistros = i - 1;
}

void inclusaoInstrutor(struct instrutor S[], int contS, struct instrutor T[], int contT, struct instrutor A[], int &contA) {
    int i = 0, j = 0, k = 0; // i (contador de S) j (contador de T) k (contador de A)
    for (; i < contS && j < contT; k++) {
        if (S[i].codigo < T[j].codigo) {
            A[k].codigo = S[i].codigo;
            A[k].nome = S[i].nome;
            A[k].endereco = S[i].endereco;
            A[k].codigoCidade = S[i].codigoCidade;
            i++;
        } else {
            A[k].codigo = T[j].codigo;
            A[k].nome = T[j].nome;
            A[k].endereco = T[j].endereco;
            A[k].codigoCidade = T[j].codigoCidade;
            j++;
        }
    }
    while (i < contS) {
        A[k].codigo = S[i].codigo;
        A[k].nome = S[i].nome;
        A[k].endereco = S[i].endereco;
        A[k].codigoCidade = S[i].codigoCidade;
        i++;
        k++;
    }
    while (j < contT) {
        A[k].codigo = T[j].codigo;
        A[k].nome = T[j].nome;
        A[k].endereco = T[j].endereco;
        A[k].codigoCidade = T[j].codigoCidade;
        j++;
        k++;
    }
    contA = k;

}

