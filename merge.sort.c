#include <stdio.h>
#include <stdlib.h>


struct Jogador {
    int id;
    char nome[50];
    char cargo[50];
    int pontuacao;
};

// função auxiliar para trocar dois jogadores de posição
void trocar(struct Jogador *a, struct Jogador *b) {
    struct Jogador temp = *a;
    *a = *b;
    *b = temp;
}

// logica do  merge sort
void merge(struct Jogador ranking[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;


    // cria os vetores tempoarios (a area de trabalho) para armazenar os elementos das duas metades
    struct Jogador *Esquerda = malloc(n1 * sizeof *Esquerda);
    struct Jogador *Direita = malloc(n2 * sizeof *Direita);

    // copia os dados para os vetores temporarios
    for (int i = 0; i < n1; i++) Esquerda[i] = ranking[inicio + i];
    for (int j = 0; j < n2; j++) Direita[j] = ranking[meio + 1 + j];

    //INTERCALA OS VETORES TEMPORARIOS DE VOLTA PARA O VETOR ORIGINAL
    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        //ORDENAÇÃO CRESCENTE: se a pontuação do jogador da esquerda for maior ou igual à do jogador da direita, ele é colocado primeiro
        if (Esquerda[i].pontuacao <= Direita[j].pontuacao) {
            ranking[k] = Esquerda[i++]; 
        } else {
            ranking[k] = Direita[j++];
            
        }
        k++;
    }

    while (i < n1) {
        ranking[k] = Esquerda[i];
        i++;
        k++;
    }
//copia os jogaores restantes de esquerda ou direita, se houver algum
    while (i < n1) ranking[k++] = Esquerda[i++];
    while (j < n2) ranking[k++] = Direita[j++];


}

void mergeSort(struct Jogador ranking[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        //dividir:ordenar a primeira metade e a segunda metade do vetor
        mergeSort(ranking, inicio, meio);
        mergeSort(ranking, meio + 1, fim);

        //conquistar: intercalar as duas metades ordenadas
        merge(ranking, inicio, meio, fim);
    }
}

void imprimirTime(struct Jogador time[], int n) {
    printf("ID\tNome\tPontuação\n");
    printf("----------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d | Nome: %s | Cargo: %s | Pontuação: %d\n",
               time[i].id, time[i].nome, time[i].cargo, time[i].pontuacao);
    }
}  

// FUNÇÃO PRINCIPAL
int main(void) {

    // 1. gerando dados para 5 jogadores inicias
    struct Jogador time[5] = {
        {1, "Alice", "Atacante", 1500},
        {2, "Bob", "Defensor", 1200},
        {3, "Charlie", "Meio-campo", 1800},
        {4, "Diana", "Goleiro", 1100},
        {5, "Eve", "Atacante", 1600}
    };

    printf("Ranking inicial dos jogadores:\n");
    imprimirTime(time, 5);

    // 2. ordenando o ranking usando merge sort
    mergeSort(time, 0, 4);

    printf("\nRanking ordenado pelos pontos:\n");
    imprimirTime(time, 5);

    return 0;
}