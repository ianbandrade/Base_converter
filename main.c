#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 30
#include "bases.h"
#include <locale.h>

//Funcoes
void decimalparabinario();
void binarioparadecimal();
float pou();
//Fim Funcoes


int main()
{
    setlocale(LC_ALL, "portuguese");
    //set_locale(LC_ALL, "portuguese");
    int op;
    float aux,num,f;
    int i,cnum,ch;
    do
    {
        printf("\n--------- Menu --------- \n");
        printf("\n1. Binario para Decimal\n");
        printf("2. Decimal para Binario\n");
        printf("3. Octal para Decimal\n");
        printf("4. Decimal para Octal\n");
        printf("5. Hexadecimal para Decimal\n");
        printf("6. Decimal para Hexadecimal\n");
        printf("7. Sair\n");
        printf("\nDigite uma opção: ");
        scanf("%d",&op); //
        system("\nCLS\n"); //Comando utilizado para limpar tela
        fflush(stdin);

        switch(op)
        {
        case 1:

            binarioparadecimal();
            system("PAUSE");


            break;
        case 2:
            decimalparabinario();

            system("PAUSE");


            break;
        case 3:
            octdec();

            system("PAUSE");


            break;
        case 4:
            decoct();

            system("PAUSE");


            break;
        case 5:
            hexdec();

            system("PAUSE");


            break;
        case 6:
            dechex();

            system("PAUSE");


            break;
        case 7://Sair do programa
            printf("Saindo...\n");
            return 0;
        default://Caso não seja nenhuma das anteriores...
            printf("Opção Inválida!\n");
            break;
        }
    }
    while(op != 7);
    system("PAUSE");
    return 0;
}


