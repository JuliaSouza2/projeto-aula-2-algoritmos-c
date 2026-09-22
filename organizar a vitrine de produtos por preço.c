#include <stdio.h>
#include <stdlib.h>

struct Carta {
int id;
char nome[50];
int ataque;
int defesa;
int energia;
int raridade;
};

// Função para ordenar por energia
void insertionSort(struct Carta cartas[], int n) {
for (int i = 1; i < n; i++) {


    // Guarda a carta que será posicionada
    struct Carta chave = cartas[i];

    int j = i - 1;

    // Move as cartas com energia maior para a direita
    while (j >= 0 && cartas[j].energia > chave.energia) {
        cartas[j + 1] = cartas[j];
        j--;
    }

    // Coloca a carta na posição correta
    cartas[j + 1] = chave;
}


}

int main(void) {


struct Carta mao_inicial[7] = {
    {105, "Ogro Esmagador", 5, 4, 5, 2},
    {102, "Elfa Arqueira", 2, 1, 2, 1},
    {107, "Anjo da Furia", 6, 5, 6, 3},
    {101, "Goblin Batedor", 1, 1, 1, 1},
    {103, "Guardiao de Pedra", 2, 5, 4, 1},
    {106, "Cavaleiro de Aco", 3, 3, 3, 2},
    {104, "Dragao das Cinzas", 7, 7, 8, 3}
};

int n = sizeof(mao_inicial) / sizeof(mao_inicial[0]);

// Chama a função de ordenação
insertionSort(mao_inicial, n);

printf("\nMao inicial ordenada por energia:\n\n");

// Mostra as cartas depois da ordenação
for (int i = 0; i < n; i++) {
    printf("Carta ID: %d | Nome: %s | Ataque: %d | Defesa: %d | Energia: %d | Raridade: %d\n",
           mao_inicial[i].id,
           mao_inicial[i].nome,
           mao_inicial[i].ataque,
           mao_inicial[i].defesa,
           mao_inicial[i].energia,
           mao_inicial[i].raridade);
}

return 0;

}