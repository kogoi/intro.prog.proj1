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
		char idade[3];
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
	
    printf("Introdução\n");
    printf("Insira o nome do seu personagem.\n");	
		scanf("%s", &nomeA);
		setbuf(stdin,NULL);
		A=funCriacao(&nomeA[0]);
	
    do{
	scanf("%c", &escolhamenu);
        setbuf(stdin,NULL);
    }while(!(escolhamenu=='c'||escolhamenu=='s'||escolhamenu=='v'||escolhamenu=='d'));
    
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
		int v;
		char gen;
		//do{
	//nome
			strcpy(a.nome,b);
	//genero
			printf("Selecione um genero:\n*F para Feminino\n*M para Masculino\n*O para Outros\n");
			do{
				scanf("%c",&gen);
				setbuf(stdin,NULL);
					switch(gen){
						case 'F':
						case 'f':
						strcpy(a.genero,"Feminino");
						break;
						case 'M':
						case 'm':
						strcpy(a.genero,"Masculino");
						break;
						case 'O':
						case 'o':
						strcpy(a.genero,"Outros");
						break;
						default:
						printf("Insira um caractere valido.\n");
					}
			}while(gen!='F'&&gen!='f'&&gen!='M'&&gen!='m'&&gen!='O'&&gen!='o');
	//idade
		printf("Insira sua idade.\n");
		do{
			scanf("%s",&a.idade);
			setbuf(stdin,NULL);
		}while(a.idade<0);
	//raça
		printf("Selecione sua raça.\n");
	
	//classe
		printf("Selecione sua classe.\n");
	
		//scanf("%d",&v);
		//setbuf(stdin,NULL);
		//} while(v);
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
