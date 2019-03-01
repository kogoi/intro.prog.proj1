#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

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
void FunCriacao();
void FunMudarTudo(void);
void FunDEL(void);
void FunMostrar(void);
	
//main
int main(int argc, char* argv) {
    int escolhamenu;
	
    printf("BEM VINDO AO CRIADOR DE PERSONAGEM C&C(C&C)\n");
    printf("Vamos começar pelo nome.\n");
    FunCriacao();
    do{
        do{
            printf("o que você deseja fazer agora podemos\n*Criar um novo personagem para isso digite '1'\n*Modificar um personagem já salvo para isso digite '2'\n*exibir ficha de um personagem salvo, para isso digite '3'.\n*Deletar personagem Salvo.\n");
            scanf("%c", &escolhamenu);
            setbuf(stdin,NULL);
    }while(!(escolhamenu==1||escolhamenu==2||escolhamenu==3||escolhamenu==4));
    
	switch(escolhamenu) {
		case 1:
		FunCriacao();
		break;
		case 2:
		//funMod();
		case 3:
		FunMostrar();
		break;
                case 4:
                //FunDEl();
                break;
		default:
		printf("Alternativa invalida.\n Digite uma alternativa valida.\n");
		}
        printf("deseja retornar ao menu?\n*Se sim digite '1'.\n*Se não insira '0'.\n >> ")
        scanf("%d",&escolhamenu)
    }while(escolhamenu);
    return (EXIT_SUCCESS);
}

//funções
void FunCriacao(void){
                FILE *fp;
		int choice;
		char gen;
	//nome
         printf("Insira o nome do seu personagem.\n >> ");  
         scanf("%99[^\n]", &A.nome);
         setbuf(stdin,NULL);
	//genero
	printf("\n\tSelecione um genero:\n\n1. Feminino\n2. Masculino\n3. Outros\nNUMBER >> ");
	do{
		scanf("%i",&gen);
			switch(gen){
				case 1:
				strcpy(A.genero,"Feminino");
				break;
				case 2:
				strcpy(A.genero,"Masculino");
				break;
				case 3:
				strcpy(A.genero,"Outros");
				break;
				default:
				printf("Insira um caractere valido.\n>> ");
			}
		 }while(gen!=1&&gen!=2&&gen!=3&&gen!=4);
	//idade
	printf("\n\n\tInsira sua idade.\n>> ");
        do{
        scanf("%d",&A.idade);
        setbuf(stdin,NULL);
	}while(A.idade<0);
	//raça
	printf ("\n\tSelecione a sua raca. \n\n");
        printf ("1. HUMANO\n2. ELFO\n3. ANAO\n4. HALFLINGS\n5. GNOMOS\n6. MEIO-ORC\nNUMBER >> ");
        do{
        scanf ("%i",&choice);
        switch(choice){
         case 1:strcpy(A.raca,"HUMANO");
                break;
         case 2:strcpy(A.raca,"ELFO");
                break;
         case 3:strcpy(A.raca,"ANAO");
                break;
         case 4:strcpy(A.raca,"HALFLINGS");
                break;
         case 5:strcpy(A.raca,"GNOMOS");
                break;
         case 6:strcpy(A.raca,"MEIO-ORC");
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
         case 1:strcpy(A.classe,"GUERREIRO");
                break;
         case 2:strcpy(A.classe,"MAGO");
                break;
         case 3:strcpy(A.classe,"FEITICEIRO");
                break;
         case 4:strcpy(A.classe,"BARBARO");
                break;
         case 5:strcpy(A.classe,"ASSASSINO");
                break;
         case 6:strcpy(A.classe,"DRUIDA");
                break;
         case 7:strcpy(A.classe,"CLERIGO");
                break;
         case 8:strcpy(A.classe,"CACADOR");
                break;
         case 9:strcpy(A.classe,"PALADINO");
                break;
         default: printf ("\nOpcao invalida. \nNUMBER >> ");
        }
    }while (choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5&&choice!=6&&choice!=7&&choice!=8&&choice!=9);
    
    if((fp=fopen(A.nome,"wb"))==NULL){
            printf("arquivo nulo.\n");
            return;
		}
	fwrite(&A,sizeof(personagem), 1,fp);
        fclose(fp);
        A.nome=A.genero=A.idade=A.raca=A.classe=A.status=0;
        return;
	}
void FunMostrar(void){
    FILE *fp;
    printf("Insira o nome de um personagem salvo");
    scanf("%99[^\n]", &A.nome);
    
    if((fp=fopen(A.nome,"r"))==NULL){
            printf("arquivo nulo ou nome errado.\n");
            return;
    }else{
        printf("Nome >> %s\n",A.nome);
        printf("Genero >> %s\n",A.genero);
        printf("Idade >> %d\n",A.idade);
        printf("Raca >> %s\n",A.raca);
        printf("Classe >> %s\n",A.classe);
        printf("Status >>\n");
    
    }
    A.nome=A.genero=A.idade=A.raca=A.classe=A.status=0;  
    fclose(fp);
    return;        
}



