#include<stdio.h>
#include<string.h>
//#include"func.h"
	//structs, tipos e etc..

	typedef struct{
		int vida_max ;//1-30
		int energia_max;//1-30
		int pt_forca;//1-20
		int pt_destreza;//1-20 e daqui pra baixo
		int pt_const;//costituição
		int pt_sab;
		int pt_int;//inteligencia
		int pt_cas;//carisma
	}status;


	typedef struct{
		char nome[100];
		char genero[9];
		int idade;
		char raca[5];
		char classe[10];
		status status;
	}personagem;

	//funçôes
int funCriacao(){
	personagem a;
	int v,choice,gen;

	do{
	//nome
	setbuf(stdin,NULL);
	printf("\n\tInsira o nome do seu personagem.\n>> ");
	scanf("%99[^\n]", &a.nome);
	setbuf(stdin,NULL);
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

	scanf("%d",&v);
	setbuf(stdin,NULL);
	} while(v);
}

//main
int main() {

	char escolhamenu;

	printf("Introducao\n");
	do{
		scanf("%c", &escolhamenu);
		switch(escolhamenu) {
			case 'c':
			funCriacao(escolhamenu);
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