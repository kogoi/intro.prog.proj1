/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Ismael Cleiton
 *
 * Created on 28 de Fevereiro de 2019, 21:16
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
/*
 * 
 */
//structs, tipos e etc..
int i=0;
typedef struct{
		int vida_max ;
		int energia_max;
		int pt_forca;
		int pt_destreza;
		int pt_const;
		int pt_sab;
		int pt_int;
		int pt_cas;
	}status;
typedef struct{
		char nome[100];
		char genero[9];
		int idade[3];
		char raca;
		char classe;
		status status;
	}personagem;
personagem A;
	
//funçôes
personagem funCriacao(char *b);
void FunSave(void);
void FunMudarTudo(void);
void FunDEL(void);
void FunMostrar(void);
	
	//main
int main(int argc, char** argv) {
    char escolhamenu,nomeA[100];
	
    printf("BEM VINDO AO CRIADOR DE PERSONAGEM C&C(C&C)\n");
    printf("Vamos começar pelo nome.\nInsira o nome do seu personagem.\n");	
		scanf("%s", &nomeA);
		setbuf(stdin,NULL);
		A=funCriacao(&nomeA[0]);
	
    do{
        printf("o que você deseja fazer agora podemos\n*Salvar seu personagem para isso digite '1'\n*Modificar um personagem já salvo para isso digite '2'\n*exibir ficha de um personagem salvo, para isso digite '3'");
	scanf("%c", &escolhamenu);
        setbuf(stdin,NULL);
    }while(!(escolhamenu=='1'||escolhamenu=='2'||escolhamenu=='3'||escolhamenu=='4'));
    
	switch(escolhamenu) {
		case 'c':
		break;
		case 's':
		FunSave();
                FunMostrar();
		break;
		case 'd':
		//FunDEl();
		case 'v':
		FunMostrar();
		break;
		default:
		printf("Alternativa invalida\n Digite uma alternativa valida\n");
		}
    return (EXIT_SUCCESS);
}

personagem funCriacao(char *b){
		FILE *fp;
		personagem a;
		int choice,v;
		char gen;
		//do{
	//nome
			strcpy(a.nome,b);
	//genero
			printf("\n\tSelecione um genero:\n\n1. Feminino\n2. Masculino\n3. Outros\nNUMBER >> ");
	do{
		scanf("%i",&gen);
			switch(gen){
				case 1:
				strcpy(a.genero,"Feminino");
				break;
				case 2:
				strcpy(a.genero,"Masculino");
				break;
				case 3:
				strcpy(a.genero,"Outros");
				break;
				default:
				printf("Insira um caractere valido.\n>> ");
			}
		 }while(gen!=1&&gen!=2&&gen!=3&&gen!=4);
	//idade
	printf("\n\n\tInsira sua idade.\n>> ");
        do{
        scanf("%d",&a.idade);
        setbuf(stdin,NULL);
	}while(a.idade<0);
	//raça
	printf ("\n\tSelecione a sua raca. \n\n");
        printf ("1. HUMANO\n2. ELFO\n3. ANAO\n4. HALFLINGS\n5. GNOMOS\n6. MEIO-ORC\nNUMBER >> ");
        do{
        scanf ("%i",&choice);
        switch(choice){
         case 1:strcpy(a.raca,"HUMANO");
                break;
         case 2:strcpy(a.raca,"ELFO");
                break;
         case 3:strcpy(a.raca,"ANAO");
                break;
         case 4:strcpy(a.raca,"HALFLINGS");
                break;
         case 5:strcpy(a.raca,"GNOMOS");
                break;
         case 6:strcpy(a.raca,"MEIO-ORC");
                break;
         default: printf ("\nOpcao invalida. \nNUMBER >> ");
        }
        }while (choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5&&choice!=6);
	//classe
	printf ("\n\tSelecione a sua classe. \n\n");
        printf ("1. GUERREIRO\n2. MAGO\n3. FEITICEIRO\n4. BARBARO\n5. ASSASSINO\n6. DRUIDA\n7. CLERIGO\n8. CACADOR\n9. PALADINO\nNUMBER >> ");
        do{
        scanf ("%i",&choice);
        switch(choice){
         case 1:strcpy(a.classe,"GUERREIRO");
                break;
         case 2:strcpy(a.classe,"MAGO");
                break;
         case 3:strcpy(a.classe,"FEITICEIRO");
                break;
         case 4:strcpy(a.classe,"BARBARO");
                break;
         case 5:strcpy(a.classe,"ASSASSINO");
                break;
         case 6:strcpy(a.classe,"DRUIDA");
                break;
         case 7:strcpy(a.classe,"CLERIGO");
                break;
         case 8:strcpy(a.classe,"CACADOR");
                break;
         case 9:strcpy(a.classe,"PALADINO");
                break;
         default: printf ("\nOpcao invalida. \nNUMBER >> ");
        }
    }while (choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5&&choice!=6&&choice!=7&&choice!=8&&choice!=9);
    
    
                return(a);
	}
void FunSave(void){
	FILE *fp;
	
	if((fp=fopen(A.nome,"wb"))==NULL){
            printf("arquivo nulo.\n");
            return;
		}
	fwrite(&A,sizeof(personagem), 1,fp);
        fclose(fp);
	}	
void FunMostrar(void){
    FILE *fp;
    if((fp=fopen(A.nome,"r"))==NULL){
            printf("arquivo nulo.\n");
            return;
    }else{
        printf("%s\n",A.nome);
        printf("%s\n",A.genero);
        printf("%s\n",A.idade);
         }
            
    fclose(fp);
    return;        
}


