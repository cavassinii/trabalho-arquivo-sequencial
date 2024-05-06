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
int buscaSerialCidade(cidade vetorCidade[], int cod, int qtdCidades);

void leituraCurso(struct curso v[], int &qtdRegistros);

void leituraInstrutor(struct instrutor v[], int &qtdRegistros, struct instrutor vetorInstrutores[], int qtdRegistrosInstrutor, struct cidade vetorCidades[], int qtdRegistrosCidade);
int buscaBinariaInstrutor(instrutor vetorInstrutor[], int cod);
void inclusaoInstrutor(struct instrutor S[], int contS, struct instrutor T[], int contT, struct instrutor A[], int &contA);

void leituraAluno(struct aluno v[], int &qtdRegistros, struct aluno vetorAlunos[], int qtdRegistrosAluno, struct cidade vetorCidades[], int qtdRegistrosCidade);
bool buscaSerialAluno(aluno vetorAluno[], int cod, int cont);
void inclusaoAluno(struct aluno S[], int contS, struct aluno T[], int contT, struct aluno A[], int &contA);

int main() {
    int opcao;
	//VARIAVEIS CIDADE
    cidade cidades[TAMAX];
    int qtdRegistrosCidade = 0;
    
    //VARIAVEIS CURSO
    curso cursos[TAMAX];
    int qtdRegistrosCurso = 0;
	
	//VARIAVEIS INSTRUTOR
    instrutor instrutores[TAMAX];
    int qtdRegistrosInstrutor = 0;
    instrutor TInstrutor[TAMAX];
    int contTInstrutor = 0;
    instrutor SInstrutor[TAMAX];
    int contSInstrutor = 0;
       
    //VARIAVEIS ALUNO
    aluno alunos[TAMAX];
    int qtdRegistrosAluno = 0;
    aluno TAluno[TAMAX];
    int contTAluno = 0;
    aluno SAluno[TAMAX];
    int contSAluno = 0;
    
    
    
    
    /*CIDADES: leitura

	CURSOS: leitura

	INSTRUTORES: inclusão
	
	ALUNOS: inclusão, exclusão

	TURMAS: inclusão, mostrarUm, mostrarCompletas

	MATRICULAS: inclusão*/

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
                	system("cls");
                    cout << "Opcao invalida, tente novamente.\n" << endl;
                    
                    break;
                }
            } while (operacaoCidade != 2);
            break;
        case 2:
            int operacaoCurso;  	
            system("cls");
            do{
            	cout << "1. Leitura de Cursos" << endl;
            	cout << "2. Voltar" << endl;
            	cout << "\nEscolha uma operacao: ";
            	cin >> (operacaoCurso);
            	
            	switch (operacaoCurso) {
            	case 1:
            		leituraCurso(cursos, qtdRegistrosCurso);
            		
            		system("cls");
            		
            		break;
            	case 2:
            		break;
            	default:
            		system("cls");
            		cout << "Opcao invalida, tente novamente.\n" << endl;
            		
            		break;
				}
			} while (operacaoCurso != 2);
            break;
        case 3:
            int operacaoInstrutor;

            system("cls");
            do {

                cout << "1. Incluir Instrutores" << endl;
                cout << "2. Voltar" << endl;
                cout << "\nEscolha uma operacao: ";
                cin >> operacaoInstrutor;

                switch (operacaoInstrutor) {
                case 1:
                	
                    cout << "\nDigite os cadastros a serem incluidos" << endl;
                    leituraInstrutor(TInstrutor, contTInstrutor, instrutores, qtdRegistrosInstrutor, cidades, qtdRegistrosCidade);
                    inclusaoInstrutor(SInstrutor, contSInstrutor, TInstrutor, contTInstrutor, instrutores, qtdRegistrosInstrutor);

                    for (int i = 0; i < qtdRegistrosInstrutor; i++) {
                        SInstrutor[i].codigo = instrutores[i].codigo;
                        SInstrutor[i].nome = instrutores[i].nome;
                        SInstrutor[i].endereco = instrutores[i].endereco;
                        SInstrutor[i].codigoCidade = instrutores[i].codigoCidade;
                    }

                    contSInstrutor = qtdRegistrosInstrutor;

                    system("cls");

                    break;
                case 2:

                    break;
                default:
                	system("cls");
                    cout << "Opcao invalida, tente novamente.\n" << endl;

                    break;
                }
            } while (operacaoInstrutor != 2);

            break;
        case 4:
            int operacaoAluno;

            system("cls");
            do {

                cout << "1. Incluir Alunos" << endl;
                cout << "2. Voltar" << endl;
                cout << "\nEscolha uma operacao: ";
                cin >> operacaoAluno;

                switch (operacaoAluno) {
                case 1:
                	
                    cout << "\nDigite os cadastros a serem incluidos" << endl;
                    leituraAluno(TAluno, contTAluno, alunos, qtdRegistrosAluno, cidades, qtdRegistrosCidade);
                    inclusaoAluno(SAluno, contSAluno, TAluno, contTAluno, alunos, qtdRegistrosAluno);

                    for (int i = 0; i < qtdRegistrosAluno; i++) {
                        SAluno[i].codigo = alunos[i].codigo;
                        SAluno[i].nome = alunos[i].nome;
                        SAluno[i].endereco = alunos[i].endereco;
                        SAluno[i].codigoCidade = alunos[i].codigoCidade;
                    }

                    contSAluno = qtdRegistrosAluno;

                    system("cls");

                    break;
                case 2:

                    break;
                default:
                	system("cls");
                    cout << "Opcao invalida, tente novamente.\n" << endl;

                    break;
                }
            } while (operacaoAluno != 2);
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

    for (int i = 0; i < qtdRegistrosAluno; i++) {
        cout << "\n\n**Registro " << i + 1 << "**" << endl;
        cout << "Codigo: " << alunos[i].codigo << endl;
        cout << "Nome: " << alunos[i].nome << endl;
        cout << "Endereco: " << alunos[i].endereco << endl;
        cout << "Codigo_cidade: " << alunos[i].codigoCidade << endl;
    }

    return 0;
}

int buscaSerialCidade(cidade vetorCidade[], int cod, int qtdCidades) {
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

bool buscaSerialAluno(aluno vetorAluno[], int cod, int cont) {
    int i = 0;
    for (; i < cont; i++) {
        if (cod == vetorAluno[i].codigo) {
            return false;
        }
    }
    return true;
}

void leituraCidade(struct cidade v[], int &qtdRegistros) {
    int i = 0;

    cout << "\nLeitura de Cidades";
    for (int saida = 1; i < TAMAX && saida == 1; i++) {
        cout << "\nCodigo: ";
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
}

void leituraCurso(struct curso v[], int &qtdRegistros) {
    int i = 0;

    cout << "\nCadastro de Cursos";
    for (int saida = 1; i < TAMAX && saida == 1; i++) {
        cout << "\nCodigo: ";
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
                        int resultBusca = buscaSerialCidade(vetorCidades, v[i].codigoCidade, qtdRegistrosCidade);
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

void leituraAluno(struct aluno v[], int &qtdRegistros, struct aluno vetorAlunos[], int qtdRegistrosAluno, struct cidade vetorCidades[], int qtdRegistrosCidade){
	int i = 0;

    cout << "\nCadastro de Alunos\n";
    for (int saida = 1; i < TAMAX && saida == 1; i++) {
        for (int y = 1; y != -1;) {
            cout << "Codigo: ";
            cin >> v[i].codigo;
            cin.ignore();

            if (buscaSerialAluno(v, v[i].codigo, i) && buscaSerialAluno(vetorAlunos, v[i].codigo, qtdRegistrosAluno)) {
                if (v[i].codigo > 0) {
                    cout << "Nome: ";
                    getline(cin, v[i].nome);
                    cout << "Endereco: ";
                    getline(cin, v[i].endereco);
                    for (; y != -1;) {
                        cout << "Codigo da Cidade: ";
                        cin >> v[i].codigoCidade;
                        int resultBusca = buscaSerialCidade(vetorCidades, v[i].codigoCidade, qtdRegistrosCidade);
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

void inclusaoAluno(struct aluno S[], int contS, struct aluno T[], int contT, struct aluno A[], int &contA){
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
