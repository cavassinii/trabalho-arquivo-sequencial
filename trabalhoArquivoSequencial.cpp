#include <iostream>
#include <conio.h>
#include <cstring>
#include <cstdlib>

using namespace std;

#define TMCidades 10
#define TMCursos 10
#define TMInstrutores 10
#define TMAlunos 10
#define TMTurmas 10
#define TMMatriculas 10

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

//FUNÇÕES TABELA CIDADE
void leituraCidade(struct cidade v[], int &qtdRegistros);
int buscaBinariaCidade(cidade vetor[], int cod, int qtdRegistros);
void mostrarCidades(cidade vetor[], int qtdRegistros);

//FUNÇÕES TABELA CURSO
void leituraCurso(struct curso v[], int &qtdRegistros);
void mostrarCursos(curso vetor[], int qtdRegistros);

//FUNÇÕES TABELA INSTRUTOR
void leituraInstrutor(struct instrutor v[], int &qtdRegistros, struct instrutor vetorInstrutores[], int qtdRegistrosInstrutor, struct cidade vetorCidades[], int qtdRegistrosCidade);
int buscaBinariaInstrutor(instrutor vetor[], int cod, int qtdRegistros);
void inclusaoInstrutor(struct instrutor S[], int contS, struct instrutor T[], int contT, struct instrutor A[], int &contA);
void mostrarInstrutores(instrutor vetor[], int qtdRegistros);


//FUNÇÕES TABELA ALUNO
void leituraAluno(struct aluno v[], int &qtdRegistros, struct aluno vetorAlunos[], int qtdRegistrosAluno, struct cidade vetorCidades[], int qtdRegistrosCidade);
int buscaBinariaAluno(aluno vetor[], int cod, int qtdRegistros);
void inclusaoAluno(struct aluno S[], int contS, struct aluno T[], int contT, struct aluno A[], int &contA);
void leituraExclusaoAluno(int TExclusao[], int &contTExclusao);
void exclusaoAluno (struct aluno S[], int contS, int T[], int contT, struct aluno A[], int &contA);
void mostrarAlunos(aluno vetor[], int qtdRegistros);

//FUNÇÕES TABELA TURMA
void leituraTurma(struct turma v[], int &qtdRegistros, struct turma vetorTurmas[], int qtdRegistrosTurma, struct curso vetorCursos[], int qtdRegistrosCurso, struct instrutor vetorInstrutores[], int qtdRegistrosInstrutor, struct cidade vetorCidades[], int qtdRegistrosCidade);
void inclusaoTurma(struct turma S[], int contS, struct turma T[], int contT, struct turma A[], int &contA);
void mostrarTurmas(turma vetor[], int qtdRegistros);
int buscaBinariaTurma(turma vetor[], int cod, int qtdRegistros);

//FUNÇÕES TABELA MATRICULAS
void leituraMatricula(struct matricula v[], int &qtdRegistros, struct matricula vetorMatriculas[], int qtdRegistrosMatricula, struct cidade vetorCidades[], int qtdRegistrosCidade, struct instrutor vetorInstrutores[], int qtdRegistrosInstrutor, struct curso vetorCursos[], int qtdRegistrosCurso, struct aluno vetorAlunos[], int qtdRegistrosAluno, struct turma vetorTurmas[], int qtdRegistrosTurma);
int buscaBinariaMatricula(matricula vetor[], int cod, int qtdRegistros);
bool buscaSerialMatricula(matricula vetor[], int cod, int cont);


int main() {
    int opcao;
	//VARIAVEIS CIDADE
    cidade cidades[TMCidades];
    int qtdRegistrosCidade = 0;
    
    //VARIAVEIS CURSO
    curso cursos[TMCursos];
    int qtdRegistrosCurso = 0;
	
	//VARIAVEIS INSTRUTOR
    instrutor instrutores[TMInstrutores];
    int qtdRegistrosInstrutor = 0;
    instrutor TInstrutor[TMInstrutores];
    int contTInstrutor = 0;
    instrutor SInstrutor[TMInstrutores];
    int contSInstrutor = 0;
       
    //VARIAVEIS ALUNO
    aluno alunos[TMAlunos];
    int qtdRegistrosAluno = 0;
    aluno TAluno[TMAlunos];
    int contTAluno = 0;
    aluno SAluno[TMAlunos];
    int contSAluno = 0;
    int TExclusao[TMAlunos], contTExclusao = 0;   
	
	//VARIAVEIS TURMA
	 turma turmas[TMTurmas];
	 int qtdRegistrosTurma = 0;
	 turma TTurma[TMTurmas];
	 int contTTurma = 0;
	 turma STurma[TMTurmas];
	 int contSTurma = 0;
	 
	 //VARIAVEIS MATRICULA
	 matricula matriculas[TMMatriculas] ;
	 int qtdRegistrosMatricula = 0;
	 matricula TMatricula[TMMatriculas];
	 int contTMatricula = 0;
	 matricula SMatricula[TMMatriculas];
	 int contSTmatricula = 0;
    
    
    
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
                cout << "2. Mostrar Cidades" << endl;
                cout << "3. Voltar" << endl;
                cout << "\nEscolha uma operacao: ";
                cin >> operacaoCidade;

                switch (operacaoCidade) {
                case 1:
                    leituraCidade(cidades, qtdRegistrosCidade);

                    system("cls");

                    break;
                case 2:
                	mostrarCidades(cidades, qtdRegistrosCidade);
                	
                	cout << "Precione enter para continuar";
                	getch();
                	system("cls");
                    break;
                case 3:
                	break;
                default:
                	system("cls");
                    cout << "Opcao invalida, tente novamente.\n" << endl;
                    
                    break;
                }
            } while (operacaoCidade != 3);
            break;
        case 2:
            int operacaoCurso;  	
            system("cls");
            do{
            	cout << "1. Leitura de Cursos" << endl;
            	cout << "2. Mostrar Cursos" << endl;
            	cout << "3. Voltar" << endl;
            	cout << "\nEscolha uma operacao: ";
            	cin >> (operacaoCurso);
            	
            	switch (operacaoCurso) {
            	case 1:
            		leituraCurso(cursos, qtdRegistrosCurso);
            		
            		system("cls");
            		
            		break;
            	case 2:
            		mostrarCursos(cursos, qtdRegistrosCurso);
                	
                	cout << "Precione enter para continuar";
                	getch();
                	system("cls");
            
            		break;
            	case 3:
            		break;
            	default:
            		system("cls");
            		cout << "Opcao invalida, tente novamente.\n" << endl;
            		
            		break;
				}
			} while (operacaoCurso != 3);
            break;
        case 3:
            int operacaoInstrutor;

            system("cls");
            do {

                cout << "1. Incluir Instrutores" << endl;
                cout << "2. Mostrar Instrutores" << endl;
                cout << "3. Voltar" << endl;
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
                	mostrarInstrutores(instrutores, qtdRegistrosInstrutor);
                	
                	cout << "Precione enter para continuar";
                	getch();
                	system("cls");

                    break;
                case 3:
                	break;
                default:
                	system("cls");
                    cout << "Opcao invalida, tente novamente.\n" << endl;

                    break;
                }
            } while (operacaoInstrutor != 3);

            break;
        case 4:
            int operacaoAluno;

            system("cls");
            do {

                cout << "1. Incluir Alunos" << endl;
                cout << "2. Excluir Alunos" << endl;
                cout << "3. Mostrar Alunos" << endl;
                cout << "4. Voltar" << endl;
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
                	
                	cout << "\nDigite os codigos dos cadastros a serem excluidos" << endl;
                	leituraExclusaoAluno(TExclusao, contTExclusao);
                	exclusaoAluno(SAluno, contSAluno, TExclusao, contTExclusao, alunos, qtdRegistrosAluno);
                	
                	 for (int i = 0; i < qtdRegistrosAluno; i++) {
                        SAluno[i].codigo = alunos[i].codigo;
                        SAluno[i].nome = alunos[i].nome;
                        SAluno[i].endereco = alunos[i].endereco;
                        SAluno[i].codigoCidade = alunos[i].codigoCidade;
                    }
                	
                	contSAluno = qtdRegistrosAluno;
                	
                	system("cls");
        
                    break;
                case 3:
                	
                	mostrarAlunos(alunos, qtdRegistrosAluno);
                	
                	cout << "Precione enter para continuar";
                	getch();
                	system("cls");
                	
                	break;
                case 4:
                	break;
                default:
                	system("cls");
                    cout << "Opcao invalida, tente novamente.\n" << endl;

                    break;
                }
            } while (operacaoAluno != 4);
            
            break;
        case 5:
            int operacaoTurma;
            
            system("cls");
            
			do {
				cout << "1. Incluir Turmas" << endl;
				cout << "2. Mostrar Turmas" << endl;
				cout << "3. Voltar" << endl;
				cout << "\nEscolha uma operacao: ";
				cin >> operacaoTurma;
				
				switch(operacaoTurma){
				case 1:
					
					leituraTurma(TTurma, contTTurma, turmas, qtdRegistrosTurma, cursos, qtdRegistrosCurso, instrutores, qtdRegistrosInstrutor, cidades, qtdRegistrosCidade);
					inclusaoTurma(STurma, contSTurma, TTurma, contTTurma, turmas, qtdRegistrosTurma);
					
					for(int i = 0; i < qtdRegistrosTurma; i++){
            			STurma[i].codigo = turmas[i].codigo;
            			STurma[i].codigoCurso = turmas[i].codigoCurso;
            			STurma[i].codigoInstrutor = turmas[i].codigoInstrutor;
            			STurma[i].totalParticipantes = turmas[i].totalParticipantes;
            			STurma[i].quantMaxParticipantes = turmas[i].quantMaxParticipantes;
					}
					
					contSTurma = qtdRegistrosTurma;

					system("cls");
					
					break;
				
				case 2:
					
                	mostrarTurmas(turmas, qtdRegistrosTurma);
                	
                	cout << "Precione enter para continuar";
                	getch();
                	system("cls");
					
					break;
				case 3:
					break;
				default:
					system("cls");
					cout << "Opcao invalida, tente novamente.\n" << endl;
					
				}
			} while (operacaoTurma != 3);
            
            break;
        case 6:
            int operacaoTurma;
            
            system("cls");
            
			do {
				cout << "1. Incluir Matriculas" << endl;
				cout << "2. Mostrar Matriculas" << endl;
				cout << "3. Voltar" << endl;
				cout << "\nEscolha uma operacao: ";
				cin >> operacaoMatricula;
				
				switch(operacaoMatricula){
				case 1:
					
					leituraMatricula(TMatricula, contTMatricula, matriculas, qtdRegistrosMatricula, cidades, qtdRegistrosCidade, instrutores, qtdRegistrosInstrutor, cursos, qtdRegistrosCurso,  );
					inclusaoMatricula(STurma, contSTurma, TTurma, contTTurma, turmas, qtdRegistrosTurma);
					
					for(int i = 0; i < qtdRegistrosTurma; i++){
            			STurma[i].codigo = turmas[i].codigo;
            			STurma[i].codigoCurso = turmas[i].codigoCurso;
            			STurma[i].codigoInstrutor = turmas[i].codigoInstrutor;
            			STurma[i].totalParticipantes = turmas[i].totalParticipantes;
            			STurma[i].quantMaxParticipantes = turmas[i].quantMaxParticipantes;
					}
					
					contSTurma = qtdRegistrosTurma;

					system("cls");
					
					break;
				
				case 2:
					
                	mostrarTurmas(turmas, qtdRegistrosTurma);
                	
                	cout << "Precione enter para continuar";
                	getch();
                	system("cls");
					
					break;
				case 3:
					break;
				default:
					system("cls");
					cout << "Opcao invalida, tente novamente.\n" << endl;
           		
        case 7:
            cout << "Saindo do programa..." << endl;
            break;
        default:
            cout << "Opcao invalida. Por favor, escolha uma opcao valida." << endl;
            break;
        }
    } while (opcao != 7);

	
	
    for (int i = 0; i < qtdRegistrosTurma; i++) {
        cout << "\n\n**Registro " << i + 1 << "**" << endl;
        cout << "Codigo: " << turmas[i].codigo << endl;
        cout << "Codigo Curso: " << turmas[i].codigoCurso << endl;
        cout << "Codigo Instrutor : " << turmas[i].codigoInstrutor << endl;
        cout << "Total de Participantes : " << turmas[i].totalParticipantes << endl;
        cout << "Maximo de Participantes : " << turmas[i].quantMaxParticipantes << endl;
 
 
    }

    return 0;
}

int buscaBinariaCidade(cidade vetor[], int cod, int qtdRegistros) {
    
    int i = 0, f = qtdRegistros - 1;
    int m = (i + f) / 2;
    for (; f >= i && cod != vetor[m].codigo; m = (i + f) / 2){
        if (cod > vetor[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == vetor[m].codigo){
      return m;
    }
    else
       return -1;

}

int buscaBinariaCurso(curso vetorCurso[], int cod, int qtdCursos) {

 
    int i = 0, f = qtdCursos - 1;
    
    
    int m = (i + f) / 2;
    for (; f >= i && cod != vetorCurso[m].codigo; m = (i + f) / 2){
        if (cod > vetorCurso[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    	
    	
    	if (cod == vetorCurso[m].codigo){
      		return m;
	}

    
    else
       return -1;

}

int buscaBinariaAluno(aluno vetor[], int cod, int qtdRegistros){
	
	if(qtdRegistros == 0){
		return -1;
	}
	
    int i = 0, f = qtdRegistros - 1;
    int m = (i + f) / 2;
    for (; f >= i && cod != vetor[m].codigo; m = (i + f) / 2){
        if (cod > vetor[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }

    	if (cod == vetor[m].codigo){
    	
      	return m;
    }

    
    else
       return -1;

}


int buscaBinariaInstrutor(instrutor vetor[], int cod, int qtdRegistros){
	
	if(qtdRegistros == 0){
		return -1;
	}
	
    int i = 0, f = qtdRegistros - 1;
    int m = (i + f) / 2;
    for (; f >= i && cod != vetor[m].codigo; m = (i + f) / 2){
        if (cod > vetor[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }

    	if (cod == vetor[m].codigo){
    	
      	return m;
    }

    
    else
       return -1;

}

int buscaBinariaTurma(turma vetor[], int cod, int qtdRegistros){
	
	if(qtdRegistros == 0){
		return -1;
	}
	
    int i = 0, f = qtdRegistros - 1;
    int m = (i + f) / 2;
    for (; f >= i && cod != vetor[m].codigo; m = (i + f) / 2){
        if (cod > vetor[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }

    	if (cod == vetor[m].codigo){
    	
      	return m;
    }

    
    else
       return -1;

}

int buscaBinariaMatricula(matricula vetor[], int cod, int qtdRegistros){
	
	if(qtdRegistros == 0){
		return true;
	}
	
    int i = 0, f = qtdRegistros - 1;
    int m = (i + f) / 2;
    for (; f >= i && cod != vetor[m].codigo; m = (i + f) / 2){
        if (cod > vetor[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }

    	if (cod == vetor[m].codigo){
    	
      	return m;
    }

    
    else
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

bool buscaSerialMatricula(matricula vetor[], int cod, int cont) {
    int i = 0;
    for (; i < cont; i++) {
        if (cod == vetor[i].codigo) {
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

bool buscaSerialTurma(turma vetorTurma[], int cod, int cont) {
    int i = 0;
    for (; i < cont; i++) {
        if (cod == vetorTurma[i].codigo) {
            return false;
        }
    }
    return true;
}

bool buscaSerialExclusaoAluno(int TExclusao[], int cod, int cont) {
    int i = 0;
    for (; i < cont; i++) {
        if (cod == TExclusao[i]) {
            return false;
        }
    }
    return true;
}

void leituraCidade(struct cidade v[], int &qtdRegistros) {
    int i = 0;

    cout << "\nLeitura de Cidades";
    for (int saida = 1; i < TMCidades && saida == 1; i++) {
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
	if(v[TMCidades -1].codigo != 0){
		if (i == TMCidades) {
        qtdRegistros = i;
    	}else
        	qtdRegistros = i - 1;	
	}else
		qtdRegistros = i - 1;
}

void leituraCurso(struct curso v[], int &qtdRegistros) {
    int i = 0;

    cout << "\nCadastro de Cursos";
    for (int saida = 1; i < TMCursos && saida == 1; i++) {
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
    }
    
	if(v[TMCursos-1].codigo != 0){
		if (i == TMCursos) {
        qtdRegistros = i;
    	}else
        	qtdRegistros = i - 1;	
	}else
		qtdRegistros = i - 1;
    
}

void leituraInstrutor(struct instrutor v[], int &qtdRegistros, struct instrutor vetorInstrutores[], int qtdRegistrosInstrutor, struct cidade vetorCidades[], int qtdRegistrosCidade) {
    int i = 0;

    cout << "\nCadastro de Instrutores\n";
    for (int saida = 1; i < TMInstrutores && saida == 1; i++) {
        for (int y = 1; y != -1;) {
            cout << "Codigo: ";
            cin >> v[i].codigo;
            cin.ignore();

            if (buscaSerialInstrutor(v, v[i].codigo, i) && buscaBinariaInstrutor(vetorInstrutores, v[i].codigo, qtdRegistrosInstrutor) == -1) {
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
                cout << "\nCodigo repetido. Tente digitar outro codigo\n" << endl;

        }
    }

	if(v[TMInstrutores -1].codigo != 0){
		if (i == TMInstrutores) {
        qtdRegistros = i;
    	}else
        	qtdRegistros = i - 1;	
	}else
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
    for (int saida = 1; i < TMAlunos && saida == 1; i++) {
        for (int y = 1; y != -1;) {
            cout << "Codigo: ";
            cin >> v[i].codigo;
            cin.ignore();

            if (buscaSerialAluno(v, v[i].codigo, i) && buscaBinariaAluno(vetorAlunos, v[i].codigo, qtdRegistrosAluno) == -1) {
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
                cout << "\nCodigo repetido. Tente digitar outro codigo\n" << endl;

        }
    }
	
	if(v[TMAlunos-1].codigo != 0){
		if (i == TMAlunos) {
        qtdRegistros = i;
    	}else
        	qtdRegistros = i - 1;	
	}else
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

void leituraExclusaoAluno(int TExclusao[], int &contTExclusao){
	int i = 0;

    for (int saida = 1; i < TMAlunos && saida == 1; i++) {
            cout << "Codigo para exclusao: ";
            cin >> TExclusao[i];
            cin.ignore();
            if(TExclusao[i] == 0){
            	saida = -1;
			}

    }

	if(TExclusao[TMAlunos-1] != 0){
		if (i == TMAlunos) {
        contTExclusao = i;
    	}else
        	contTExclusao = i - 1;	
	}else
		contTExclusao = i - 1;
}

void exclusaoAluno (struct aluno S[], int contS, int T[], int contT, struct aluno A[], int &contA){
    int i = 0, j = 0, k = 0; // i (contador de S) j (contador de T) k (contador de A)
    for (;j < contT; i++){
        if (S[i].codigo != T[j]){
            A[k].codigo = S[i].codigo;
            A[k].nome = S[i].nome;
            A[k].endereco = S[i].endereco;
            A[k].codigoCidade = S[i].codigoCidade;
            k++;
            }
        else {
            j++;
        }
    }
    while (i < contS){
        A[k].codigo = S[i].codigo;
        A[k].nome = S[i].nome;
        A[k].endereco = S[i].endereco;
        A[k].codigoCidade = S[i].codigoCidade;
        i++;
        k++;
    }
    contA = k;
}

void leituraTurma(struct turma v[], int &qtdRegistros, struct turma vetorTurmas[], int qtdRegistrosTurma, struct curso vetorCursos[], int qtdRegistrosCurso, struct instrutor vetorInstrutores[], int qtdRegistrosInstrutor, struct cidade vetorCidades[], int qtdRegistrosCidade) {
    int i = 0;

    cout << "\nCadastro de Turmas\n";
    for (int saida = 1; i < TMTurmas && saida == 1; i++) {
        for (int y = 1; y != -1;) {
            cout << "Codigo: ";
            cin >> v[i].codigo;
            

            if (buscaSerialTurma(v, v[i].codigo, i) && buscaBinariaTurma(vetorTurmas, v[i].codigo, qtdRegistrosTurma) == -1) {
                if (v[i].codigo != 0) {
                	for(; y != -1;){
					
                    cout << "Codigo do curso: ";
                    cin >> v[i].codigoCurso;
                    
                    
                    int resultBusca = buscaBinariaCurso(vetorCursos, v[i].codigoCurso, qtdRegistrosCurso);
                    if(resultBusca != -1){
                    	cout << " -Curso: " << vetorCursos[resultBusca].descricao << "\n  -Valor Aula: R$" << vetorCursos[resultBusca].valorAula << endl;
                    	y = -1;
					}else cout << "\nCodigo do curso nao encontrado, tente novamente." << endl;
                } 
                	
                	for(y = 1; y != -1;){
                		cout << "Codigo do instrutor: ";
                    	cin >> v[i].codigoInstrutor;
                    	
                    	
                    	int resultBusca = buscaBinariaInstrutor(vetorInstrutores, v[i].codigoInstrutor, qtdRegistrosInstrutor);
                    	if(resultBusca != -1){
    	
                    		cout << " -Instrutor: " << vetorInstrutores[resultBusca].nome;
                    		resultBusca = buscaBinariaCidade(vetorCidades, vetorInstrutores[resultBusca].codigoCidade, qtdRegistrosCidade);
                    		cout << "\n  -Cidade: " << vetorCidades[resultBusca].nome << endl;
                    		y = -1;
						}else cout << "\nCodigo do instrutor nao encontrado, tente novamente." << endl;
					}

                    cout << "Total de participantes: ";
                    cin >> v[i].totalParticipantes;
                    
                    cout << "Quantidade maxima de participantes: ";
                    cin >> v[i].quantMaxParticipantes;
                    cout << "\n\n";
                    

                } else
                    saida = -1;
                y = -1;

            } else
                cout << "\nCodigo repetido. Tente digitar outro codigo\n" << endl;

        }
    }

	if(v[TMTurmas -1].codigo != 0){
		if (i == TMTurmas) {
        qtdRegistros = i;
    	}else
        	qtdRegistros = i - 1;	
	}else
		qtdRegistros = i - 1;
        
}

void inclusaoTurma(struct turma S[], int contS, struct turma T[], int contT, struct turma A[], int &contA) {
    int i = 0, j = 0, k = 0; // i (contador de S) j (contador de T) k (contador de A)
    for (; i < contS && j < contT; k++) {
        if (S[i].codigo < T[j].codigo) {
            A[k].codigo = S[i].codigo;
            A[k].codigoCurso = S[i].codigoCurso;
            A[k].codigoInstrutor = S[i].codigoInstrutor;
            A[k].totalParticipantes = S[i].totalParticipantes;
            A[k].quantMaxParticipantes = S[i].quantMaxParticipantes;
            i++;
        } else {
            A[k].codigo = T[j].codigo;
            A[k].codigoCurso = T[j].codigoCurso;
            A[k].codigoInstrutor = T[j].codigoInstrutor;
            A[k].totalParticipantes = T[j].totalParticipantes;
            A[k].quantMaxParticipantes = T[j].quantMaxParticipantes;
            j++;
        }
    }
    while (i < contS) {
        A[k].codigo = S[i].codigo;
        A[k].codigoCurso = S[i].codigoCurso;
        A[k].codigoInstrutor = S[i].codigoInstrutor;
        A[k].totalParticipantes = S[i].totalParticipantes;
        A[k].quantMaxParticipantes = S[i].quantMaxParticipantes;
        i++;
        k++;
    }
    while (j < contT) {
        A[k].codigo = T[j].codigo;
        A[k].codigoCurso = T[j].codigoCurso;
        A[k].codigoInstrutor = T[j].codigoInstrutor;
        A[k].totalParticipantes = T[j].totalParticipantes;
        A[k].quantMaxParticipantes = T[j].quantMaxParticipantes;
        j++;
        k++;
    }
    contA = k;
    
}

//FUNÇÕES MOSTRAR

void mostrarCidades(cidade vetorCidades[], int qtdCidades) {
    cout << "=== CIDADES ===" << endl;
    for (int i = 0; i < qtdCidades; i++) {
        cout << "**Registro " << i + 1 << "**" << endl;
        cout << "Codigo: " << vetorCidades[i].codigo << endl;
        cout << "Nome: " << vetorCidades[i].nome << endl;
        cout << "UF: " << vetorCidades[i].uf << endl;
        cout << endl;
    }
}

void mostrarCursos(curso vetorCursos[], int qtdCursos) {
    cout << "=== CURSOS ===" << endl;
    for (int i = 0; i < qtdCursos; i++) {
        cout << "**Registro " << i + 1 << "**" << endl;
        cout << "Codigo: " << vetorCursos[i].codigo << endl;
        cout << "Descricao: " << vetorCursos[i].descricao << endl;
        cout << "Valor por aula: R$" << vetorCursos[i].valorAula << endl;
        cout << endl;
    }
}

void mostrarInstrutores(instrutor vetorInstrutores[], int qtdInstrutores) {
    cout << "=== INSTRUTORES ===" << endl;
    for (int i = 0; i < qtdInstrutores; i++) {
        cout << "**Registro " << i + 1 << "**" << endl;
        cout << "Codigo: " << vetorInstrutores[i].codigo << endl;
        cout << "Nome: " << vetorInstrutores[i].nome << endl;
        cout << "Endereco: " << vetorInstrutores[i].endereco << endl;
        cout << "Codigo da Cidade: " << vetorInstrutores[i].codigoCidade << endl;
        cout << endl;
    }
}

void mostrarAlunos(aluno vetorAlunos[], int qtdAlunos) {
    cout << "=== ALUNOS ===" << endl;
    for (int i = 0; i < qtdAlunos; i++) {
        cout << "**Registro " << i + 1 << "**" << endl;
        cout << "Codigo: " << vetorAlunos[i].codigo << endl;
        cout << "Nome: " << vetorAlunos[i].nome << endl;
        cout << "Endereco: " << vetorAlunos[i].endereco << endl;
        cout << "Codigo da Cidade: " << vetorAlunos[i].codigoCidade << endl;
        cout << endl;
    }
}

void mostrarTurmas(turma vetorTurmas[], int qtdTurmas) {
    cout << "=== TURMAS ===" << endl;
    for (int i = 0; i < qtdTurmas; i++) {
        cout << "**Registro " << i + 1 << "**" << endl;
        cout << "Codigo: " << vetorTurmas[i].codigo << endl;
        cout << "Codigo do Curso: " << vetorTurmas[i].codigoCurso << endl;
        cout << "Codigo do Instrutor: " << vetorTurmas[i].codigoInstrutor << endl;
        cout << "Total de Participantes: " << vetorTurmas[i].totalParticipantes << endl;
        cout << "Quantidade Maxima de Participantes: " << vetorTurmas[i].quantMaxParticipantes << endl;
        cout << endl;
    }
}

void leituraMatricula(struct matricula v[], int &qtdRegistros, struct matricula vetorMatriculas[], int qtdRegistrosMatricula, struct cidade vetorCidades[], int qtdRegistrosCidade, struct instrutor vetorInstrutores[], int qtdRegistrosInstrutor, struct curso vetorCursos[], int qtdRegistrosCurso, struct aluno vetorAlunos[], int qtdRegistrosAluno, struct turma vetorTurmas[], int qtdRegistrosTurma) {
    int i = 0;
    int resultBusca = 0;

    cout << "\nCadastro de Matriculas\n";
    for (int saida = 1; i < TMMatriculas && saida == 1; i++) {
        for (int y = 1; y != -1;) {
            cout << "Codigo: ";
            cin >> v[i].codigo;
            

            if (buscaSerialMatricula(v, v[i].codigo, i) && buscaBinariaMatricula(vetorMatriculas, v[i].codigo, qtdRegistrosMatricula) != -1) {
                if (v[i].codigo != 0) {
                	for(; y != -1;){
										
                    cout << "Codigo do aluno: ";
                    cin >> v[i].codigoAluno;
            		resultBusca = buscaBinariaAluno(vetorAlunos, v[i].codigoAluno, qtdRegistrosAluno);
            		
                    if(resultBusca != -1){
                    	cout << " -Aluno: " << vetorAlunos[resultBusca].nome;
                    	resultBusca == buscaBinariaCidade(vetorCidades, vetorAlunos[resultBusca].codigoCidade, qtdRegistrosCidade);
                    	cout << "\n -Cidade: " << vetorCidades[resultBusca].nome;
                    	y = -1;
                    	
					}else cout << "\nCodigo do aluno nao encontrado, tente novamente." << endl;
                } 
                	
                	for(y = 1; y != -1;){
                		cout << "Codigo da Turma: ";
                    	cin >> v[i].codigoTurma;                  	                    	
                    	int resultBusca = buscaBinariaTurma(vetorTurmas, v[i].codigoTurma, qtdRegistrosTurma);
                    	
                    	if(resultBusca != -1){
                    		
                    		resultBusca = buscaBinariaInstrutor(vetorInstrutores, vetorTurmas[resultBusca].codigoInstrutor, qtdRegistrosInstrutor);
                    		cout << "\n -Cidade: " << vetorInstrutores[resultBusca].nome;
                    		
                    		resultBusca = buscaBinariaCurso(vetorCursos, vetorTurmas[resultBusca].codigoCurso, qtdRegistrosCurso);
                    		cout << " -Instrutor: " << vetorCursos[resultBusca].descricao;
                    		cout << "\n -Valor por aula: R$" << vetorCursos[resultBusca].valorAula;
                    		
                    		y = -1;
						}else cout << "\nCodigo da turma nao encontrado, tente novamente." << endl;
					}

                    cout << "Quantidade de aulas: ";
                    cin >> v[i].quantidadeAulas;
                    
                    cout << " -Total a pagar: R$" << v[i].quantidadeAulas * vetorCursos[resultBusca].valorAula;
                    
					resultBusca = buscaBinariaTurma(vetorTurmas, v[i].codigoTurma, qtdRegistrosTurma);
					if(vetorTurmas[resultBusca].totalParticipantes + 1 <= vetorTurmas[resultBusca].quantMaxParticipantes){
						vetorTurmas[resultBusca].totalParticipantes++;
					}
						else cout << "\nMatricula nao concluida, turma cheia." << endl;
                    

                } else
                    saida = -1;
                	y = -1;

            } else
                cout << "\nCodigo repetido. Tente digitar outro codigo\n" << endl;

        }
        
        cout << "\nMatricula incluida com sucesso, precione alguma tecla para continuar";
        getch();
    }

	if(v[TMMatriculas -1].codigo != 0){
		if (i == TMTurmas) {
        qtdRegistros = i;
    	}else
        	qtdRegistros = i - 1;	
	}else
		qtdRegistros = i - 1;
        
}

