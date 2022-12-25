//main
#include <stdio.h>
#include <stdlib.h>
#include "filadeints.h"

int main(){
    Fila *fi; 
//criafila,  colocanafila,  tiradafila,  filavazia  e  filacheia. 
    fi =  criafila();

    int a = colocanafila(fi, 50);
    printf("%d\n", a);

    int x = tamanhofila(fi);
		printf("%d\n", x);

    int b = tiradafila(fi);
		printf("%d\n", b);

    int y = filacheia(fi);
		printf("%d\n", y);

    int z = filavazia(fi);
		printf("%d\n", z);

    liberafila(fi);

/*A fila deve ter um indicador de tamanho máximo de elementos, bem como os índices que indicam o início e o fim da fila. 
Escreva também uma interface filadeints.h  para o módulo. 
*/
//inserções e exclusões de elementos ocorrem nas extremidades da "lista"
//cada elemento aponta para seu sucessor na lista
//usa um nó descritor para representar o início e final da fila e uma indicação de final de fila

}


//filadeints.c
#include <stdio.h>
#include <stdlib.h>
#include "filadeints.h"
#define N 100
int dist[N];
int p, u;
int fila[N];

Fila *fi; 
//Jacksson Yuri e Andressa Nunes
//criafila,  colocanafila,  tiradafila,  filavazia  e  filacheia. 
int tam;
/* 
 função para criar a fila
*/
Fila* criafila(){
		Fila* fi = (Fila*) malloc(sizeof(Fila)); // aloco a memória dinâmica
		if(fi != NULL){ //verifico se essa alocação se deu certo
			fi -> final = NULL; //final e inicio recebem null
			fi -> inicio = NULL;
		}
		return fi;
}
/* 
 função para liberar a fila
*/
void liberafila(Fila* fi){ //destruir fila
		if(fi != NULL){
			No* no;
			while(fi -> inicio != NULL){ //enquanto o inicio for diferente de null
				no = fi -> inicio; //no recebe o inicio
				fi -> inicio = fi -> inicio -> proximo; //inicio aponta pro proximo elemento
				free(no);
			}
			free(fi);
		}
}
/* 
 função para informar o tamanho da fila, retorna a variável cont
*/
int tamanhofila(Fila* fi){
		if(fi == NULL) //se for null não tem fila
			return 0;
		int cont = 0;
		No* no = fi -> inicio; //no auxiliar recebe o inicio da fila
		while(no != NULL){
			cont++;
			no = no -> proximo; //no anda pro proximo elemento
		}
		return cont;
}
/* 
 função para verificar se a fila está cheia, caso esteja cheia retorna 1, caso não retorna 0
*/
int filacheia(Fila* fi){
	
	if(fi -> tam == TAM_MAX)
		return 1;
	else 
		return 0;
}
/* 
 função para verificar se a fila está vazia, retorna 1 se estiver vazia e 0 se não.
*/
int filavazia(Fila* fi){
		if(fi == NULL) //retorna 1 se for vazia
			return 1;
		if(fi -> inicio == NULL)
			return 1; //se o inicio da fila for NULL, significa que a lista está vazia
			return 0;
}
//a inserção é sempre no final
//n se pode inserir numa fila cheia
/* 
 função para inserir na fila, se retornar 0 é pq não existe uma fila, retorna 1 se deu tudo certo
*/
int colocanafila(Fila* fi, int valor){
		if(fi == NULL)
			return 0; //deu erro na inserção
		No* no = (No*) malloc(sizeof(No));
		if(no == NULL)
			return 0;
		//se deu certo pego o valor e copio pro campo de daods do no
		no -> valor = valor;
		no -> proximo = NULL;
		if(fi -> final == NULL) //fila vazia, se o final for null
			fi -> inicio = no; //então o inicio recebe o no
		else 
			fi -> final -> proximo = no; //aqui insiro no final da fila
		fi -> final = no;
		return 1;
}

//a remoção é sempre no final
//não se pode remover uma fila vazia
/* 
 função para remover da fila, retorna 1 se deu tudo certo
*/
int tiradafila(Fila* fi){
		if(fi == NULL)
			return 0;
		if(fi -> inicio == NULL) //fila vazia
			return 0;
		No* no = fi -> inicio;
		fi -> inicio = fi -> inicio -> proximo;
		if(fi -> inicio == NULL)
			fi -> final = NULL;
		free(no);
		return 1;
}

int distancias(int A[][N], int c){
	for(int j = 0; j < N; ++j) 
	dist[j] = N; //dist da cidade J é N
	dist[c] = 0; //dist da cidade c é 0 
	colocanafila(fi, 50);

	while(!filavazia(fi)){
		int i = tiradafila(fi);
		for(int j = 0; j < N; ++j)
			if(A[i][j] == 1 && dist[j] >= N){
				dist[j]  = dist[i] + 1;
			}
	}
}


//filadeints.h
#ifndef FILADEINTS_H
#define FILADEINTS_H
#define TAM_MAX 100
#define N 100
int dist[N];
int p, u;
int fila[N];

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *proximo;
} No;


typedef struct fila
{
		struct No *inicio;
		struct No *final;
		int tam;
}Fila;

/* função para criar a fila */
Fila* criafila();
/* função para liberar a fila */
void liberafila(Fila* fi);
/* função para informar o tamanho da fila, retorna a variável cont */
int tamanhofila(Fila* fi);
/* função para verificar se a fila está cheia, caso esteja cheia retorna 1, caso não retorna 0 */
int filacheia(Fila* fi);
/* função para verificar se a fila está vazia, retorna 1 se estiver vazia e 0 se não.*/
int filavazia(Fila* fi);
/* função para inserir na fila, se retornar 0 é pq não existe uma fila, retorna 1 se deu tudo certo */
int colocanafila(Fila* fi, int valor);
/* função para remover da fila, retorna 1 se deu tudo certo */
int tiradafila(Fila* fi);

int distancias(int A[][N], int c);

#endif

//makefile 
all: main

main: filadeints.o
	gcc main.c filadeints.o -o main
filadeints.o:
	gcc -c filadeints.c 
rm: 
	rm *.o