#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conta.h"

struct conta{

    int numero, especial;
    float saldo;
    char cliente[51];

};

void inicializar(p_conta pConta[], int tamanho){

    for(int i = 0; i < tamanho; i++){

       pConta[i] = NULL;

    }

}

void inserir(p_conta pConta[], int posicao){

    pConta[posicao] = (p_conta) malloc(sizeof(struct conta));

    pConta[posicao]->numero = posicao + 1;

    fflush(stdin);

    printf("Nome do cliente: ");
    gets(pConta[posicao]->cliente);

    fflush(stdin);

    while(1){

        printf("Cliente especial?? SIM(1) NAO(0): ");
        scanf("%i", &pConta[posicao]->especial);

        if(pConta[posicao]->especial == 1 || pConta[posicao]->especial == 0)break;

        printf("Valor Invalido, digite 1 ou 0 porfavor.\n\n");

    }

    pConta[posicao]->saldo = 0;

    printf("Cadastro realizado com sucesso\n\n");

}

void alterar(p_conta pConta[], int tamanho){

    alt:

    system("cls || clear");

    int alte = 0;
    printf("Qual conta deseja alterar: ");
    scanf("%d", &alte);
    int achou = 0;
    int menu = 0;

    for(int i = 0; i < tamanho; i++){

        if(alte == pConta[i]->numero){

            while(menu != 4){

                printf("O que deseja alterar:\n\n");
                printf("1- Nome do cliente: \n");
                printf("2- Saldo do cliente: \n");
                printf("3- Status do cliente: \n");
                printf("4- Voltar \n");
                scanf("%d", &menu);

                switch(menu){

                case 1:

                    system("cls || clear");

                    fflush(stdin);

                    printf("Insira o novo nome do cliente: ");
                    scanf("%s", &pConta[i]->cliente);

                    break;

                case 2:

                    system("cls || clear");

                    fflush(stdin);

                    printf("Insira o novo saldo do cliente: ");
                    scanf("%f", &pConta[i]->saldo);

                    break;

                case 3:

                    system("cls || clear");

                    while(1){

                        fflush(stdin);

                        printf("Insira o novo status do cliente, sabendo que\n ESPECIAL(1) NAO ESPECIAL(0)");
                        scanf("%d", &pConta[i]->especial);

                        if(pConta[i]->especial == 0 || pConta[i]->especial == 1)break;

                        printf("Numero invalido, insira novamente");

                    }

                    break;

                case 4:
                    break;

                default:

                    system("cls || clear");

                    printf("Opcao invalida, digite novamente...");

                    break;

                }

            }

            achou = 1;

        }

    }

    if(achou == 0){

        printf("Conta nao encontrada");


        int resp = 0;

        while(1){

            system("cls || clear");

            printf("Deseja procurar novamente: SIM(1) NAO(0)");
            scanf("%d", &resp);

            if(resp == 0 || resp == 1) break;

            printf("\n\nDigite 1 ou 0 porfavor");

        }

        if(resp == 1){

            system("pause");
            goto alt;

        }

    }


}

void procurar(p_conta pConta[], int tamanho){

    search:

    system("cls || clear");

    int proc;
    printf("Qual o numero da conta que deseja procurar: ");
    scanf("%d", &proc);
    int achou = 0;

    for(int i = 0; i < tamanho; i++){

        if(proc == pConta[i]->numero){

            printf("Sua conta esta na %d posicao", i);
            achou = 1;
            break;
        }

    }

    if(achou == 0){

        printf("Conta nao encontrada");


        int resp = 0;

        while(1){

            system("cls || clear");

            printf("Deseja procurar novamente: SIM(1) NAO(0)");
            scanf("%d", &resp);

            if(resp == 0 || resp == 1) break;

            printf("\n\nDigite 1 ou 0 porfavor");

        }

        if(resp == 1){

            system("pause");
            goto search;

        }

    }


}

void listar(p_conta pConta[], int tamanho){

    //for para passar em todas as posição do vetor da struct

    printf("\tCONTAS REGISTRADAS");

    for(int i = 0; i < tamanho; i++){

        printf("\n");
        printf("Numero da conta -> %d\n", pConta[i]->numero);
        printf("Nome do cliente -> %s\n", pConta[i]->cliente);

        if(pConta[i]->especial == 1){

            printf("Cliente Especial\n");

        }else{

            printf("Cliente Regular\n");

        }

        printf("Saldo da conta -> %.2lf\n\n\n", pConta[i]->saldo);

    }

}

void depositar(p_conta pConta[], int tamanho){

    impr:

    system("cls || clear");

    int conta;
    printf("Qual o numero da conta procurada: ");
    scanf("%d", &conta);
    int achou = 0;
    float valor;

    for(int i = 0; i < tamanho; i++){

        if(conta == pConta[i]->numero){

            system("cls || clear");

            printf("Qual o valor do deposito: ");
            scanf("%f", &valor);

            printf("\nDeposito bem sucedido!!!\n\n");

            printf("Saldo Antes: %.2lf\n", pConta[i]->saldo);

            pConta[i]->saldo += valor;

            printf("Saldo Depois: %.2lf\n\n", pConta[i]->saldo);

            achou = 1;
            break;
        }

    }

    if(achou == 0){

                printf("Conta nao encontrada");

                system("pause");

                int resp = 0;

                while(1){

                    system("cls || clear");

                    printf("Deseja procurar novamente: SIM(1) NAO(0)");
                    scanf("%d", &resp);

                    if(resp == 0 || resp == 1) break;

                        printf("\n\nDigite 1 ou 0 porfavor");

                    }

                if(resp == 1){

                goto impr;

                }

            }

}

void sacar(p_conta pConta[], int tamanho){

    saq:

    system("cls || clear");

    int conta;
    printf("Qual o numero da conta procurada: ");
    scanf("%d", &conta);
    int achou = 0;
    float valor;

    for(int i = 0; i < tamanho; i++){

        if(conta == pConta[i]->numero){

            system("cls || clear");

            printf("Qual o valor do saque que deseja realizar: ");
            scanf("%f", &valor);

            if(pConta[i]->saldo >= valor){

                system("cls || clear");

                printf("\nSaque bem sucedido!!!\n\n");
                printf("Saldo Antes: %.2lf\n",pConta[i]->saldo);
                pConta[i]->saldo -= valor;
                printf("Saldo Depois: %.2lf\n\n",pConta[i]->saldo);

            }else{

                printf("\nSaldo insuficiente...");

            }

            achou = 1;
            break;

        }

    }

    if(achou == 0){

        printf("Conta nao encontrada");

        int resp = 0;

        while(1){

            system("cls || clear");

            printf("Deseja procurar novamente: SIM(1) NAO(0)");
            scanf("%d", &resp);

            if(resp == 0 || resp == 1) break;

                system("cls || clear");

                printf("\n\nDigite 1 ou 0 porfavor");

                sleep(2);

            }

            if(resp == 1){

            system("pause");
            goto saq;

            }

        }

}

void imprimir(p_conta pConta[], int tamanho){

    impr:

    system("cls || clear");

    int codigo;

    printf("Qual o numero da conta procurada: ");
    scanf("%d", &codigo);

    int achou = 0;

    for(int i = 0; i < tamanho; i++){

        if(codigo == pConta[i]->numero){

            printf("Numero -> %d\n", pConta[i]->numero);
            printf("Nome do cliente -> %s\n", pConta[i]->cliente);

            if(pConta[i]->especial == 1){

                printf("Conta Especial\n");

            }else{

                printf("Conta Regular\n");

            }

            printf("Saldo da conta -> %.2lf\n\n", pConta[i]->saldo);

            achou = 1;

        }

    }

    if(achou == 0){

        printf("Conta nao encontrada");

        int resp = 0;

        while(1){

            system("cls || clear");

            printf("Deseja procurar novamente: SIM(1) NAO(0)");
            scanf("%d", &resp);

            if(resp == 0 || resp == 1) break;

            printf("\n\nDigite 1 ou 0 porfavor");

        }

        if(resp == 1){

        system("pause");
        goto impr;

        }

    }

}

void saldoGeral(p_conta pConta[], int tamanho){

    float geral;

    for(int i = 0; i < tamanho; i++){

        geral += pConta[i]->saldo;

    }

    printf("O saldo de todas as contas somadas e: %.2lf", geral);

}
