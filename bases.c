#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 30
#include "bases.h"
#include <locale.h>


int fraci[max],inteiro[max];

void decimalparabinario()
{

    float numero,f;
    int i,cnum,t;
    char termo;

    printf("Digite um numero Decimal: ");
    if(scanf("%f%c", &numero, &termo) != 2)
    {
        printf("ERRO!\nEste número não é decimal!\n");
        fflush(stdin);
        return("ERRO");
    }
    printf("\n");

    //Conversao de decimal para binario


    f=numero-(int)numero;

    //Parte fracionaria <- alocando no vetor "fraci"
    for(i=0; i<max; i++)
    {
        f=f-(int)f;
        fraci[i]=(int)(f*2);
        f*=2;
    }


    cnum=(int)numero;
    for(i=max-1; i>=0; i--)
    {
        if(cnum%2==0)
        {
            inteiro[i]=0;
        }
        else
            inteiro[i]=1;
        cnum/=2;
    }
       //parte inteira
    printf("%f(10) = ",numero);
    t=0;

    for(i=0; i<max; i++)
    {
        if(inteiro[i]||t)
        {
            t=1;
            printf("%d",inteiro[i]);
        }
    }
    printf(".");

    //parte fracionaria
    for(i=0; i<7; i++)
        printf("%d",fraci[i]);

    printf("(2)\n");
}


void binarioparadecimal()
{
    char num[50];
    int antesDec[50], depoisDec[50];
    int antesDecnum, depoisDecnum, tint=0, l, j=0, k=0, i, len;
    float fract=0, floatValue;
    char p = 'd';

    //


    printf("Digite o numero binario: ");
    scanf("%s",&num);
    len = strlen(num);

    for (i=0;i<len; i++) {
        if (num[i]!='1' && num[i]!='0' && num[i]!='.') {
            printf("\nERRO!\nEste número não é binario!\n");
            return("ERRO");
        }
    }

    //Separa o inteiro do fracionado

    for(l=0; l<strlen(num); l++)
    {
        if(num[l]=='.')
        {
            p='u';
        }
        else if(p=='d')
        {

            antesDec[l] = (int)num[l]-48;
            k++;
        }
        else
        {
            depoisDec[j] = (int)num[l]-48;
            j++;

        }
    }


    // Armazena o tamanho do inteiro e do fracionario
    antesDecnum = k;
    depoisDecnum= j;


    //Converter parte inteira para decimal
    j=0;
    for(l = antesDecnum-1; l>=0; l--)
    {
        tint = tint + (antesDec[l] *(int) pow(2,j));
        j++;
    }

    //Converter parte fracionaria para decimal
    j = -1;
    for(l = 0; l<depoisDecnum; l++)
    {
        fract = fract + (depoisDec[l]*pow(2,j));
        j--;
    }


    //Juntando as duas partes
    floatValue = tint + fract;
    printf("\n%s(2) = %f(10)\n",num,floatValue);
}
//Funcao "pow"
float pou(int c, int d)
{
    float pow=1;
    if (d >= 0)
    {
        int i = 1;
        while (i <= d)
        {
            pow = pow * c;
            i++;
        }
    }
    else
    {
        int i = 0;
        while (i > d)
        {
            pow = pow/c;
            i--;
        }
    }
    return pow;
}

// intnum = numero inteiro.
// fracnume = numero fracionario



float octal_inteiro(int n)
{
    int octal, elevado, separador, div, tam, dec;
    tam = log10(n)+ 1;
    octal=0;
    div=1;
    separador=n%10;
    octal=separador;
    for(elevado=1; elevado<tam; elevado++)
    {
        div=div*10;
        separador=n/div;
        separador=separador%10;
        dec=separador*pow(8,elevado);
        octal=octal+dec;
    }
    return octal;
}

float octal_real(float n)
{
    int elevado, separador, div, aux;
    float dec, octal;
    octal=0;
    div=10;
    for(elevado=-1; elevado>-5; elevado--)/*Limite de digitos após a virgula é de 5 casas antes da virgula*/
    {
        separador=n*div;
        dec=separador*pow(8,elevado);
        octal=octal+dec;
        div=div*10;
        n=n*10;
        aux=n;
        n=n-aux;
    }
    return octal;
    return 0;
}

int octdec()
{
    float menor_0, num, dec, parte_inteira, parte_real, verificador_octal, verificador_octal_real;
    int maior_0;
    printf("Digite um numero octal: ");
    scanf("%f", &num);
    maior_0=num;
    verificador_octal_real=num-maior_0;
    verificador_octal = maior_0 % 10;
    while(verificador_octal > 7 && verificador_octal > 0 || verificador_octal_real*10 > 7)/*verificar se o digito é valido*/
    {
        system("cls");
        printf("ERRO>>>>>>Numero invalido<<<<<<<\n\ndigite um valor de base octal ");
        scanf("%f", &num);
        maior_0=num;
        verificador_octal= maior_0%10;
        verificador_octal_real=num-maior_0;
    }
    menor_0=num-maior_0;
    parte_inteira=octal_inteiro(maior_0);
    parte_real=octal_real(menor_0);
    dec = parte_inteira+parte_real;
    system("cls");
    printf("\n\n %f em octal -> %f em decimal \n\n", num, dec);
    system("pause");
    system("cls");
    return main();
}

float dec_real(float n){
    float octal, pega_numero_real,digito,expoente;
    int pega_numero_inteiro, i;
    octal=0;
    expoente=1;
    for(i=0; i<5; i++)
    {
        pega_numero_real=n*8;
        pega_numero_inteiro=pega_numero_real;
        n=pega_numero_real-pega_numero_inteiro;
        expoente=expoente*10;
        digito=(pega_numero_inteiro/expoente);
        octal=octal+digito;
    }
    return octal;
}
int dec_inteiro(int n)
{
    int octal,quocnt, resto,mult;
    octal=0;
    quocnt=n/8;
    resto=n%8;
    mult=1;
    octal=resto;
    while(quocnt!=0)
    {
        mult*=10;
        resto=quocnt%8;
        quocnt=quocnt/8;
        octal=octal+resto*mult;
    }
    return octal;
}

int decoct()
{
    int maior_0;
    float num, menor_0, resp_octal, part_inteira, part_fracionaria;
    printf("Digite um numero decimal: ");
    scanf("%f", &num);
    maior_0=num;
    menor_0=num-maior_0;
    part_inteira=dec_inteiro(maior_0);
    part_fracionaria=dec_real(menor_0);
    resp_octal=part_inteira+part_fracionaria;
    printf(" %5.2f  em decimal --->  %f em octal \n", num, resp_octal);
    system("pause");
    system("cls");
    return 0;
}

int hexdec()
{
    //definição das variaveis
    char hex[20];
    long long dec=0;
    int len, pot, count, i, n_dec;
    //obtenção do valor hexadecimal
    printf("Digite um número hexadecimal: ");
    gets(hex); //Obtem o valor da variavel
    len = strlen(hex); //tamanho da string
    i=0;
    pot = len-1;
    //correçao do valor de cada caracter + teste se numero é hexadecimal
    for(count=len; count!=0; count--)
    {
        if(hex[i]>='0' && hex[i]<='9')
        {
            n_dec = hex[i] - 48; //correção pela tabela ASCII
        }
        else if(hex[i]>='a' && hex[i]<='f')
        {
            n_dec = hex[i] - 87; //correção pela tabela ASCII
        }
        else if(hex[i]>='A' && hex[i]<='F')
        {
            n_dec = hex[i] - 55; //correção pela tabela ASCII
        }
        else if(hex[i]='.')
        {
            n_dec = hex[i] - 46;
        }
        else
        {
            printf("ERRO!\nEste número não é hexadecimal!\n");
            fflush(stdin);
            return("ERRO");
        }
        dec += n_dec * pow(16,pot); //soma dos caracteres em string
        i++;
        pot--;
    }
    //resultado
    system("cls");
    printf("Número hexadecimal: %s\n", hex);
    printf("Número decimal: %lld\n", dec);
    fflush(stdin);
    return(0);
}

int dechex()
{
    //definição das variaveis
    long long dec, quociente, resto=17;
    char hex[20], termo;
    int i=0, j;
    //obtenção do valor decimal
    printf("Digite um número decimal: ");
    //teste para ver se numero é decimal
    if(scanf("%lld%c", &dec, &termo) != 2 || termo != '\n')
    {
        printf("ERRO!\nEste número não é decimal!\n");
        fflush(stdin);
        return("ERRO");
    }
    quociente = dec;
    while (quociente!=0)
    {
        //definiçao dos valores das variaveis
        resto = 0;
        resto = quociente%16;
        quociente /= 16;
        printf("%lld \n", resto);
        //correção dos valores de cada caracter
        if (resto<10)
        {
            hex[i] = resto + 48; //correção pela tabela ASCII
        }
        else
        {
            hex[i] = resto + 55; //correção pela tabela ASCII
        }
        i++;
    }
    system("cls");
    printf("Número decimal: %lld\n", dec);
    printf("Número hexadecimal: ");
    //escrita de cada caracter na tela, formando o numero final


    for (j=i-1; j>=0; j--)
    {
        printf("%c", hex[j]);
    }
    printf("\n");
    fflush(stdin);
    return(0);
}
