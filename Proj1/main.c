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
#define MAX 100
/*
 * 
 */
//structs, tipos e etc..
        personagem A[MAX];
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
		char idade;
		char raca;
		char classe;
		status status;
	}personagem;
	
	//funçôes
	void funCriacao(void);
	void FunSave(void);
	void FunMudarTudo(void);
	void FunDEL(void);
	void FunMostrar(void);
	
	//main
int main(int argc, char** argv) {
    char escolhamenu,nomeA[100];
	
    printf("Introdução\n");
    do{
	scanf("%c", &escolhamenu);
	switch(escolhamenu) {
		case 'c':
		printf("Insira o nome do seu personagem.\n");	
		scanf("%s", &nomeA);
		setbuf(stdin,NULL);
		A[i]=funCriacao(nomeA);
		i++;
		break;
		case 's':
		//Charmod(escolhamenu);
		break;
		case 'd':
		//FunDEl();
		case 'v':
		//FunMostrar(escolhamenu);
		break;
		default:
		printf("Alternativa invalida\n Digite uma alternativa valida\n");
		}
	}while(!(escolhamenu=='c'||escolhamenu=='s'||escolhamenu=='v'||escolhamenu=='d'));
    return (EXIT_SUCCESS);
}

void funCriacao(void){
		FILE *fp;
		personagem a;
		int v;
		char gen;
		do{
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
			scanf("%d",&a.idade);
			setbuf(stdin,NULL);
		}while(a.idade<0);
	//raça
		printf("Selecione sua raça.\n");
	
	//classe
		printf("Selecione sua classe.\n");
	
		scanf("%d",&v);
		setbuf(stdin,NULL);
		} while(v);
	}
void FunSave(void){
	FILE *fp;
	personagem j;
	
	if((fp=fopen(A[i].nome,"wb"))==NULL){
            printf("arquivo nulo.\n");
            return;
		}
	for(j=0;j=MAX;j++)
            if(*A[j].nome)
                if(fwrite(&A[j],sizeof(personagem), 1,fp)!=1)
        fclose(fp);
	}	



