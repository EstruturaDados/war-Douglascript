#include <stdio.h>

struct territorios{
	char nome[30];
	char cor[10];
	int tropas;
};

typedef struct territorios territorios;

int main (){
	
	territorios mapa[5];
	
	printf("-------------------------- Jogo War --------------------------\n\n");
	
	int i;
	
	for(i=0; i<5; i++){
		printf("------------ Criando Territorio %d ------------\n\n", i+1);
		printf("Insira o nome do territorio %d\n", i+1);
		scanf("%30[^\n]s", mapa[i].nome);
		
		fflush(stdin);
		printf("");
		
		printf("Insira a cor do territorio %d\n", i+1);
		scanf("%10[^\n]s", mapa[i].cor);
		
		fflush(stdin);
		printf("");
		
		printf("Insira a qtd de tropas do territorio %d\n", i+1);
		scanf("%d", &mapa[i].tropas);
		
		fflush(stdin);
		printf("");
	}
	
	for(i=0; i<5; i++){
		printf("------------ Territorio %d  ------------\n\n", i+1);
		
		printf("Info do Territorio\n");
		printf("Nome: %s\n", mapa[i].nome);
		printf("Cor: %s\n", mapa[i].cor);
		printf("Tropas: %d\n", mapa[i].tropas);
	}
}
