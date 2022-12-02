#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conta.h"
#define MAX 1000

int main()
{

   p_conta vtrContas[MAX];

   //posição
   int p = 0;

   inicializar(vtrContas, MAX);

   // Mostrar menu
    int menu = 0;

    while(menu != 9){

        system("cls");
        printf("Gerenciador de contas \n\n");
        printf("1. Cadastrar conta\n");
        printf("2. Alterar conta\n");
        printf("3. Procurar conta\n");
        printf("4. Listar contas\n");
        printf("5. Depositar\n");
        printf("6. Sacar\n");
        printf("7. Imprimir conta\n");
        printf("8. Mostrar saldo geral\n");
        printf("9. Sair\n\n");
        printf("Digite sua opcao: ");
        scanf("%d", &menu);
        printf("\n");

        switch(menu){

        case 1:

            system("cls || clear");

            inserir(vtrContas, p);
            p++;

            system("pause");

            break;

        case 2:

            system("cls || clear");

            alterar(vtrContas, p);

            break;

        case 3:

            system("cls || clear");

            procurar(vtrContas, p);

            system("pause");

            break;

        case 4:

            system("cls || clear");

            listar(vtrContas, p);

            system("pause");

            break;

        case 5:



            depositar(vtrContas, p);

            system("pause");

            break;

        case 6:

            system("cls || clear");

            sacar(vtrContas, p);

            system("pause");

            break;

        case 7:

            system("cls || clear");

            imprimir(vtrContas, p);

            system("pause");

            break;

        case 8:

            system("cls || clear");

            saldoGeral(vtrContas, p);

            system("pause");

            break;

        case 9:

            system("cls || clear");

            break;

        default:

            system("cls || clear");

            printf("Opcao invalida, digite novamente");

        break;

        }

    }

}
