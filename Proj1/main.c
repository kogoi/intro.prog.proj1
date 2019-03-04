#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

//structs, tipos e etc..

typedef struct {
    int vida_max;
    int energia_max;
    int pt_forca;
    int pt_destreza;
    int pt_const;
    int pt_sab;
    int pt_int;
    int pt_cas;
} status;

typedef struct {
    char nome[100];
    char genero[9];
    int idade;
    char raca[MAX];
    char classe[MAX];
    status status;
} personagem;
//funcoes
void FunCriacao();
void FunMudarTudo(void);
void FunDEL(void);
void FunMostrar(void);

//main

int main(int argc, char* argv) {
    int escolhamenu;

    printf("BEM VINDO AO CRIADOR DE PERSONAGEM C&C(C&C)\n\n\n\n");
    do {
        do {
            printf("\t\tMENU\n*Criar um novo personagem \n>> digite '1'\n\n*Modificar um personagem salvo \n>> digite '2'\n\n*exibir ficha de um personagem salvo\n>> digite '3'\n\n*Deletar personagem Salvo\n>> digite '4'.\n\n*Sair\n>> '0'\n\n>> ");
            scanf("%d", &escolhamenu);
            setbuf(stdin, NULL);
        } while (!(escolhamenu == 1 || escolhamenu == 2 || escolhamenu == 3 || escolhamenu == 4 || escolhamenu == 0));

        switch (escolhamenu) {
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
        printf("deseja retornar ao menu?\n*Se sim digite '1'.\n*Se nao insira '0'.\n >> ");
        scanf("%d", &escolhamenu);
    } while (escolhamenu);
    return (EXIT_SUCCESS);
}

//funcoes

void FunCriacao(void) {
    FILE *fp;
    personagem A;
    int s, choice;
    //nome
    printf("Insira o nome do seu personagem.\n >> ");
    scanf("%99[^\n]", &A.nome);
    setbuf(stdin, NULL);
    //genero
    printf("\n\tSelecione um genero:\n\n1. Feminino\n2. Masculino\n3. Outros\nNUMBER >> ");
    do {
        scanf("%i", &choice);
        switch (choice) {
            case 1:
                strcpy(A.genero, "Feminino");
                break;
            case 2:
                strcpy(A.genero, "Masculino");
                break;
            case 3:
                strcpy(A.genero, "Outros");
                break;
            default:
                printf("Insira um caractere valido.\n>> ");
        }
    } while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
    //idade
    printf("\n\n\tInsira sua idade.\n\nNUMBER>> ");
    do {
        scanf("%d", &A.idade);
        if (A.idade<0){
            printf("insira um valor valido\n");
        }
    } while (A.idade < 0);
    //raça
    printf("\n\tSelecione a sua raca. \n\n");
    printf("1. HUMANO\n2. ELFO\n3. ANAO\n4. HALFLINGS\n5. GNOMOS\n6. MEIO-ORC\nNUMBER >> ");
    do {
        scanf("%i", &choice);
        switch (choice) {
            case 1:strcpy(A.raca, "HUMANO");
                break;
            case 2:strcpy(A.raca, "ELFO");
                break;
            case 3:strcpy(A.raca, "ANAO");
                break;
            case 4:strcpy(A.raca, "HALFLINGS");
                break;
            case 5:strcpy(A.raca, "GNOMOS");
                break;
            case 6:strcpy(A.raca, "MEIO-ORC");
                break;
            default: printf("\nOpcao invalida. \nNUMBER >> ");
        }
    } while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6);
    //classe
    printf("\n\tSelecione a sua classe. \n\n");
    printf("1. GUERREIRO\n2. MAGO\n3. FEITICEIRO\n4. BARBARO\n5. ASSASSINO\n6. DRUIDA\n7. CLERIGO\n8. CACADOR\n9. PALADINO\nNUMBER >> ");
    do {
        scanf("%i", &choice);
        switch (choice) {
            case 1:strcpy(A.classe, "GUERREIRO");
                break;
            case 2:strcpy(A.classe, "MAGO");
                break;
            case 3:strcpy(A.classe, "FEITICEIRO");
                break;
            case 4:strcpy(A.classe, "BARBARO");
                break;
            case 5:strcpy(A.classe, "ASSASSINO");
                break;
            case 6:strcpy(A.classe, "DRUIDA");
                break;
            case 7:strcpy(A.classe, "CLERIGO");
                break;
            case 8:strcpy(A.classe, "CACADOR");
                break;
            case 9:strcpy(A.classe, "PALADINO");
                break;
            default: printf("\nOpcao invalida. \nNUMBER >> ");
        }
    } while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9);
    //status
    A.status.vida_max = A.status.energia_max = A.status.pt_forca = A.status.pt_destreza = A.status.pt_const = A.status.pt_sab = A.status.pt_int = A.status.pt_cas = 0;
    if (!strcmp(A.raca, "HUMANO")) {
        A.status.vida_max += ((s = rand() % 20) < 8) ? 8 + 1 : s + 1;
        A.status.energia_max += ((s = rand() % 20) < 8) ? 8 + 1 : s + 1;
        A.status.pt_forca += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_destreza += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_const += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_sab += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_int += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_cas += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
    }
    if (!strcmp(A.raca, "ELFO")) {
        A.status.vida_max += ((s = rand() % 20) < 8) ? 8 + 1 : s + 1;
        A.status.energia_max += ((s = rand() % 20) < 8) ? 8 + 1 : s + 1;
        A.status.pt_forca += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_destreza += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_const += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_sab += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_int += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_cas += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
    }
    if (!strcmp(A.raca, "ANAO")) {
        A.status.vida_max += ((s = rand() % 20) < 8) ? 8 + 1 : s + 1;
        A.status.energia_max += ((s = rand() % 20) < 8) ? 8 + 1 : s + 1;
        A.status.pt_forca += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_destreza += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_const += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_sab += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_int += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_cas += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
    }
    if (!strcmp(A.raca, "HALFLINGS")) {
        A.status.vida_max += ((s = rand() % 20) < 8) ? 8 + 1 : s + 1;
        A.status.energia_max += ((s = rand() % 20) < 8) ? 8 + 1 : s + 1;
        A.status.pt_forca += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_destreza += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_const += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_sab += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_int += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_cas += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
    }
    if (!strcmp(A.raca, "GNOMOS")) {
        A.status.vida_max += ((s = rand() % 20) < 8) ? 8 + 1 : s + 1;
        A.status.energia_max += ((s = rand() % 20) < 8) ? 8 + 1 : s + 1;
        A.status.pt_forca += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_destreza += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_const += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_sab += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_int += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_cas += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
    }
    if (!strcmp(A.raca, "MEIO-ORC")) {
        A.status.vida_max += ((s = rand() % 20) < 8) ? 8 + 1 : s + 1;
        A.status.energia_max += ((s = rand() % 20) < 8) ? 8 + 1 : s + 1;
        A.status.pt_forca += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_destreza += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_const += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_sab += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_int += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
        A.status.pt_cas += ((s = rand() % 20) < 5) ? 5 + 1 : s + 1;
    }
    //salvando
    if ((fp = fopen(A.nome, "wb")) == NULL) {
        printf("arquivo nulo.\n");
        return;
    }
    fwrite(&A, sizeof (personagem), 1, fp);
    fclose(fp);
    return;
}

void FunMostrar(void) {
    FILE *fp;
    void *pa;
    personagem a;
    pa = &a;
    printf("Insira o nome de um personagem salvo\n\n>> ");
    scanf("%99[^\n]", &a.nome);

    if ((fp = fopen(a.nome, "r")) == NULL) {
        printf("Nome invalido\n");
        return(1);
    }
    fread(pa, sizeof (personagem), 1, fp);

    printf("\tNome:\n\t>> %s\n", a.nome);
    printf("\tGenero:\n\t>> %s\n", a.genero);
    printf("\tIdade:\n\t>> %d anos\n", a.idade);
    printf("\tRaca:\n\t>> %s\n", a.raca);
    printf("\tClasse:\n\t>> %s\n", a.classe);
    printf("\tStatus:\n\tVida Maxima >> %d\n\tEnergia Maxima >> %d\n\tPontos de Forca >> %d\n\tPontos de Destreza >> %d\n\tPontos de Constituicao >> %d\n\tPontos de Sabedoria >> %d\n\tPontos de Inteligencia >> %d\n\tPontos de Carisma >> %d\n\n\n", a.status.vida_max, a.status.energia_max, a.status.pt_forca, a.status.pt_destreza, a.status.pt_const, a.status.pt_sab, a.status.pt_int, a.status.pt_cas);


    //A.nome=A.genero=A.idade=A.raca=A.classe=A.status=0;teste
    fclose(fp);
    return;
}
void FunMudarTudo(void){
    FILE *fp;
    personagem a;
    int ch;

    printf("Insira o nome de um personagem salvo\n\n>> ");
    scanf("%99[^\n]", &a.nome);

    if ((fp = fopen(a.nome, "wr")) == NULL) {
        printf("Nome invalido\n");
        return(1);
    }
    //mudar nome
    printf("Deseja mudar o nome do personagem?\n\n*Se sim digite '1'\n*se nao digite '0'\n>> ");
    do{
        scanf("%d",&ch);
        if(ch<0||ch>1)
            printf("digite um numero valido\n");
    }while(ch<0||ch>1);
        if(ch){
            printf("Qual nome deseja colocar no seu personagem?\n");
            scanf("%99[^\n]",&a.nome);
        }
    //mudar genero
    printf("Deseja mudar o genero\n\n*Se sim digite '1'\n*se nao digite '0'\n>> ");
     do{
        scanf("%d",&ch);
        if(ch<0||ch>1)
            printf("digite um numero valido\n");
    }while(ch<0||ch>1);
        if(ch){
            printf("\n\tSelecione um genero:\n\n1. Feminino\n2. Masculino\n3. Outros\nNUMBER >> ");
            do {
                scanf("%i", &ch);
                switch (ch) {
                    case 1:
                        strcpy(a.genero, "Feminino");
                        break;
                    case 2:
                        strcpy(a.genero, "Masculino");
                        break;
                    case 3:
                        strcpy(a.genero, "Outros");
                        break;
                    default:
                        printf("Insira um caractere valido.\n>> ");
                }
            } while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
            }
    //mudar idade
    printf("Deseja mudar a idade\n\n*Se sim digite '1'\n*se nao digite '0'\n>> ");
    do{
        scanf("%d",&ch);
        if(ch<0||ch>1)
            printf("digite um numero valido\n");
    }while(ch<0||ch>1);
        if(ch){
            printf("\n\n\tInsira sua idade.\n\nNUMBER>> ");
            do {
                scanf("%d", &a.idade);
                if (a.idade<0){
                    printf("insira um valor valido\n");
                }
            } while (a.idade < 0);
        }
    //mudar raca
    printf("Deseja mudar a raca?\n\n*Se sim digite '1'\n*se nao digite '0'\n>> ");
        do{
        scanf("%d",&ch);
        if(ch<0||ch>1)
            printf("digite um numero valido\n");
        }while(ch<0||ch>1);
        if(ch){
            printf("\n\tSelecione a sua raca. \n\n");
            printf("1. HUMANO\n2. ELFO\n3. ANAO\n4. HALFLINGS\n5. GNOMOS\n6. MEIO-ORC\nNUMBER >> ");
        do {
        scanf("%i", &ch);
        switch (ch) {
            case 1:strcpy(a.raca, "HUMANO");
                break;
            case 2:strcpy(a.raca, "ELFO");
                break;
            case 3:strcpy(a.raca, "ANAO");
                break;
            case 4:strcpy(a.raca, "HALFLINGS");
                break;
            case 5:strcpy(a.raca, "GNOMOS");
                break;
            case 6:strcpy(a.raca, "MEIO-ORC");
                break;
            default: printf("\nOpcao invalida. \nNUMBER >> ");
        }
        } while (ch != 1 && ch != 2 && ch != 3 && ch != 4 && ch != 5 && ch != 6);
    }
    //mudar classe
    printf("Deseja mudar a classe\n\n*Se sim digite '1'\n*se nao digite '0'\n>> ");
    do{
        scanf("%d",&ch);
        if(ch<0||ch>1)
            printf("digite um numero valido\n");
        }while(ch<0||ch>1);
        if(ch){
            printf("\n\tSelecione a sua classe. \n\n");
    printf("1. GUERREIRO\n2. MAGO\n3. FEITICEIRO\n4. BARBARO\n5. ASSASSINO\n6. DRUIDA\n7. CLERIGO\n8. CACADOR\n9. PALADINO\nNUMBER >> ");
    do {
        scanf("%i", &ch);
        switch (ch) {
            case 1:strcpy(a.classe, "GUERREIRO");
                break;
            case 2:strcpy(a.classe, "MAGO");
                break;
            case 3:strcpy(a.classe, "FEITICEIRO");
                break;
            case 4:strcpy(a.classe, "BARBARO");
                break;
            case 5:strcpy(a.classe, "ASSASSINO");
                break;
            case 6:strcpy(a.classe, "DRUIDA");
                break;
            case 7:strcpy(a.classe, "CLERIGO");
                break;
            case 8:strcpy(a.classe, "CACADOR");
                break;
            case 9:strcpy(a.classe, "PALADINO");
                break;
            default: printf("\nOpcao invalida. \nNUMBER >> ");
        }
    } while (ch != 1 && ch != 2 && ch != 3 && ch != 4 && ch != 5 && ch != 6 && ch != 7 && ch != 8 && ch != 9);
        }
    //


    fwrite(&a, sizeof (personagem), 1, fp);
    fclose(fp);
    return;
}


