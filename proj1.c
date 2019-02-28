#include<stdio.h>
#include<string.h>
//#include"func.h"
	//structs, tipos e etc..
	
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
		int idade;
		char raca;
		char classe;
		status status;
	}personagem;
	
	//funçôes
char funCriacao(){
	FILE *fp
	personagem a;
	int v;
	char gen;
	fp=&a
	do{
	//nome
	printf("Insira o nome do seu personagem.\n");	
	scanf("%s", &a.nome);
	setbuf(stdin,NULL);
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

//main
int main() {
	
	char escolhamenu;
	
	printf("Introdução\n");
	do{
		scanf("%c", &escolhamenu);
		switch(escolhamenu) {
			case 'c':
			CharCreator(escolhamenu);
			break;
			case 's':
			//CharSelector(escolhamenu);
			break;
			case 'a':
			//Adventure(escolhamenu);
			break;
			default:
			printf("Alternativa invalida\n Digite uma alternativa valida\n");
		}
	}while(!(escolhamenu=='c'||escolhamenu=='s'||escolhamenu=='a'));
}
 
