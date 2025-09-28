//Incluindo bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>


//Criando a struct
struct territorios{
	char nome[30];
	char cor[10];
	int tropas;
};
//renomeando struct
typedef struct territorios territorios;

//Criando a função de ataque e defesa
void atacar(territorios *mapa, int atacante, int defensor) {
	srand(time(NULL));
	int dadoataque = rand() % 6 + 1;
	srand(time(NULL));
	int dadodefesa = rand() % 6 + 1;
	
	printf("Ataque (%s): %d\n", mapa[atacante].nome, dadoataque);
	printf("Defesa (%s): %d\n", mapa[defensor].nome, dadodefesa);
	
	//lógica do ataque
	if (dadoataque >= dadodefesa) {
    mapa[defensor].tropas--;

    	if (mapa[defensor].tropas <= 0) {
        mapa[defensor].tropas = 1;
        strcpy(mapa[defensor].cor, mapa[atacante].cor);
        printf("Território conquistado!\n");
    	} else {
        printf("Defensor perdeu 1 tropa.\n");
    	}
	} else {
    	printf("Ataque falhou.\n");
	}
}

//corpo
int main (){
	
	//definindo as variáveis e alocação de memoria dinâmica
	territorios *mapa = calloc(5, sizeof(territorios));
	int i;
	
	//Estrutura 'for' para cadastro dos 5 territorios 
	printf("-------------------------- Jogo War --------------------------\n\n");
	for(i=0; i<5; i++){
		printf("-------------- Criando Territorio %d --------------\n\n", i+1);
		printf("Insira o nome do territorio:");
		scanf("%30[^\n]s", mapa[i].nome);
		
		fflush(stdin);
		printf("");
		
		printf("Insira a cor do territorio:");
		scanf("%10[^\n]s", mapa[i].cor);
		
		fflush(stdin);
		printf("");
		
		printf("Insira a qtd de tropas do territorio:");
		scanf("%d", &mapa[i].tropas);
		
		fflush(stdin);
		printf("\n\n");
	}
	//Usei fflush acima por boas práticas para limpeza de memória e system("cls') abaixo para limpeza de tela
	system("Cls");
	
	
	//Estrutura 'for' para mostrar os territorios cadastrados
	printf("------------ Mapa do Mundo ------------\n\n");
	for(i=0; i<5; i++){
		
		printf("Territorio %d\n", i+1);
		printf("Nome: %s\n", mapa[i].nome);
		printf("Cor: %s\n", mapa[i].cor);
		printf("Tropas: %d\n\n", mapa[i].tropas);
		
		if(i==4){
			printf("--------------------------------------");
		}
	}
	
	//função de batalha
	int atacante, defensor;
char continuar;

do {
    printf("\nEscolha o território atacante (1 a 5): ");
    scanf("%d", &atacante);
    printf("Escolha o território defensor (1 a 5): ");
    scanf("%d", &defensor);

    // Corrigindo para índice do vetor (0 a 4)
    atacar(mapa, atacante - 1, defensor - 1);

    // Mostrar mapa atualizado
    printf("\n--- Mapa Atualizado ---\n");
    for(i = 0; i < 5; i++) {
        printf("Território %d\n", i+1);
        printf("Nome: %s\n", mapa[i].nome);
        printf("Cor: %s\n", mapa[i].cor);
        printf("Tropas: %d\n\n", mapa[i].tropas);
    }

    printf("Deseja continuar atacando? (s/n): ");
    scanf(" %c", &continuar);

} while (continuar == 's' || continuar == 'S');
	
	//Liberando a memória
	free(mapa);
}
