#include <stdio.h>
#include <string.h> // Necessário para strcmp


struct Jogador {
    int id;
    char nome[50];
    int pontuacao;
};
 void trocar(struct Jogador *a, struct Jogador *b) {
    struct Jogador temp = *a;
    *a = *b;
    *b = temp;
}
//Inserir no início do código
#include <string.h> // Necessário para strcmp

int compararJogadores(const struct Jogador* jogador1, const struct Jogador* jogador2) {
    // 1. Compara pelo critério primário: Pontuação (decrescente)
    if (jogador1->pontuacao > jogador2->pontuacao) {
        return -1; // jogador1 tem mais pontos, então vem antes.
    }
    if (jogador1->pontuacao < jogador2->pontuacao) {
        return 1; // jogador1 tem menos pontos, então vem depois.
    }

    // 2. Se chegou aqui, a pontuação é a mesma. Usa o critério secundário.
    // Compara por nome (alfabético crescente).
    // A função strcmp já retorna <0, 0, ou >0 no formato que precisamos.
    // (strcmp(a,b) < 0 significa que 'a' vem antes de 'b')
    return strcmp(jogador1->nome, jogador2->nome);
} 
int particionar(struct Jogador ranking[], int baixo, int alto) {
    struct Jogador pivo = ranking[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        // ANTES: if (ranking[j].pontuacao < pivo.pontuacao)
        // AGORA: Usamos nossa função de comparação complexa!
        // Se compararJogadores retornar -1, significa que ranking[j] deve vir antes do pivô.
        if (compararJogadores(&ranking[j], &pivo) == -1) {
            i++;
            trocar(&ranking[i], &ranking[j]);
        }
    }
    trocar(&ranking[i + 1], &ranking[alto]);
    return (i + 1);
} 
void quickSort(struct Jogador ranking[], int baixo, int alto) {
    if (baixo < alto) {
        //pi é o índice do pivô, ranking[pi] está agora no lugar certo
        int pi = particionar(ranking, baixo, alto);
// Separadamente ordena os elementos antes e depois da partição
        quickSort(ranking, baixo, pi - 1);
        quickSort(ranking, pi + 1, alto);
    }
}

void imprimirRanking(const char* titulo, struct Jogador ranking[], int n) {
    printf("%s\n", titulo);
    printf("------------------------------------------------------------\n");
    printf("ID\tNome\tPontuacao\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%d\n", ranking[i].id, ranking[i].nome, ranking[i].pontuacao);
    }
    printf("\n");
}
int main(void) {
    struct Jogador ranking_originais[] = {
        {1, "Alice", 5000},
        {2, "Bob", 3000},
        {3, "Charlie", 4000},
        {4, "David", 3500},
        {5, "Eve", 2500}
    };

    int n = sizeof(ranking_originais) / sizeof(ranking_originais[0]);

    struct Jogador ranking_teste[5];

    printf("### Prototipo de Otimização de Ranking de Jogadores ###\n");
    printf("Ordenado %d jogadores por pontuação (decrescente) e nome (crescente) usando Quick Sort:\n", n);

    // teste com quick sort
    memcpy(ranking_teste, ranking_originais, sizeof(ranking_originais));
    quickSort(ranking_teste, 0, n - 1);
    imprimirRanking("Lista de Ranking:", ranking_teste, n);

    return 0;
}