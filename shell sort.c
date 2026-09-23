
#include <stdio.h>
#include <string.h> 

// Estrutura para armazenar informações de um funcionário
struct Funcionario {
    int id;
    char nome[50];
    char cargo[50];
    float preco;
    int tempo_de_servico_meses;
};

// Estrutura para armazenar métricas de desempenho do algoritmo
struct Metricas {
        long long comparacoes;
        long long trocas;

};

// Função para imprimir os funcionários
 void imprimirFuncionarios(const char* titulo, struct Funcionario arr[], int n){
    printf("%s\n", titulo); 
    printf("------------------------------------------------------------\n");
    printf("ID\tNome\tCargo\tPreco\tTempo de Servico (meses)\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%s\t%.2f\t%d\n", arr[i].id, arr[i].nome, arr[i].cargo, arr[i].preco, arr[i].tempo_de_servico_meses);
    } 
    printf("\n");

}

// insertion sort
void insertionSort(struct Funcionario  arr [], int n, struct Metricas *stats) {
    
    for (int i = 1; i < n; i++) {
        struct Funcionario chave = arr[i];
        int j = i - 1;

        // Move os elementos que são maiores que a chave para uma posição à frente
        while (j >= 0 ) {
            stats->comparacoes++;
            //se o funcionario na parte ordenada tem MENOS tempo de serviço
            // ele é enviado para a a direita para dar espaço para a chave 
            if(arr[j + 1].tempo_de_servico_meses < chave.tempo_de_servico_meses) {
                arr[j + 1] = arr[j];
                stats->trocas++;
                j--;
            }else {
                break; // Se não for maior, sai do loop
            }
            
        }
        arr[j + 1] = chave; // Coloca a chave na posição correta
    }
}

//shell sort
void shellSort(struct Funcionario arr[], int n, struct Metricas *stats) {
    int h = n / 2;
    for (h = 1; h < n / 3; h = 3 * h + 1); // Incremento de Knuth

    for (; h >= 1; h /= 3) {
        for (int i = h; i < n; i++) {
            struct Funcionario chave = arr[i];
            int j =  i;
           
           //a condição foi alterada para '<' para ordenar em ordem decrescente
            while (j >= h) {
                stats->comparacoes++;
                if(arr[j - h].tempo_de_servico_meses < chave.tempo_de_servico_meses) {
                arr[j] = arr[j - h];
                stats->trocas++;
                j -= h;
                } else {
                    break; // Se não for maior, sai do loop     
                }
                
            }
            arr[j] = chave;
        
    }
    
    }
}

int main() {
    struct Funcionario funcionarios_originais[] = {
        {1, "Alice", "Gerente", 5000.0, 24},
        {2, "Bob", "Analista", 3000.0, 12},
        {3, "Charlie", "Desenvolvedor", 4000.0, 36},
        {4, "David", "Designer", 3500.0, 18},
        {5, "Eve", "Tester", 2500.0, 6}
    };

    int n = sizeof(funcionarios_originais) / sizeof(funcionarios_originais[0]);

    struct Funcionario funcionarios_teste[5];
    struct Metricas metricas;

    printf("### Protototipo de Otimização de RH ###\n");
    printf("Ordenado %d funcionarios por tempo de servico (decrescente) usando Insertion Sort:\n", n);

    // teste com insertion sort

    printf("===============================================\n");
    printf("               1. Testando Metodo Antigo: Insertion Sort\n");
    printf("===============================================\n");
    metricas =(struct Metricas){0, 0}; 
    memcpy(funcionarios_teste, funcionarios_originais, sizeof(funcionarios_originais));
    insertionSort(funcionarios_teste, n, &metricas);
    imprimirFuncionarios("Lista de Senioridade:", funcionarios_teste, n);
    printf("metricas do Insertion Sort - Comparacoes: %lld | Trocas: %lld\n", metricas.comparacoes, metricas.trocas);

     // teste com shell sort
    printf("===============================================\n");                
    printf("               2. Testando Metodo Otimizado: Shell Sort\n");
    printf("===============================================\n");
    metricas =(struct Metricas){0, 0};  
    memcpy(funcionarios_teste, funcionarios_originais, sizeof(funcionarios_originais));
    shellSort(funcionarios_teste, n, &metricas);
    imprimirFuncionarios("Lista de Senioridade:", funcionarios_teste, n);
    printf("metricas do Shell Sort - Comparacoes: %lld | Trocas: %lld\n", metricas.comparacoes, metricas.trocas);

printf("===============================================\n");
    printf("               3. Conclusao\n");
    printf("===============================================\n");
    printf("O Shell Sort é mais eficiente que o Insertion Sort para listas maiores, pois reduz o número de comparações e trocas necessárias para ordenar a lista.\n");

    return 0;

}