#include <stdio.h>

// =========================================================================
// REQUISITOS NÃO FUNCIONAIS: Definição de Constantes (Entrada de Dados)
// =========================================================================

// Define o número de casas a serem movidas diretamente no código
#define CASAS_TORRE 5
#define CASAS_BISPO 5
#define CASAS_RAINHA 8

// Strings para a Saída de Dados, garantindo legibilidade
const char* DIR_DIREITA = "Direita";
const char* DIR_ESQUERDA = "Esquerda";
const char* DIR_CIMA_DIREITA = "Cima Direita";
// String para resetar a cor (ajuda na legibilidade do terminal)
const char* RESET_ANSI = "\033[0m";
const char* COR_DESTAQUE = "\033[32m"; // Verde

// =========================================================================
// FUNÇÃO PRINCIPAL
// =========================================================================
int main() {
    // Variáveis de controle de loop (tipo inteiro)
    int i;
    int casas_percorridas;

    // Documentação: Imprime o cabeçalho
    printf("%s--- Simulacao de Movimento de Pecas (C) ---\n%s", COR_DESTAQUE, RESET_ANSI);
    printf("Movimentos definidos: Torre=%d, Bispo=%d, Rainha=%d.\n", CASAS_TORRE, CASAS_BISPO, CASAS_RAINHA);

    // -------------------------------------------------------------------------
    // 1. MOVIMENTO DA TORRE: Usando FOR
    // Lógica: Movimento puramente horizontal para a Direita.
    // -------------------------------------------------------------------------
    printf("\n1. Torre (FOR): Movimento para a Direita (%d casas):\n", CASAS_TORRE);
    
    for (i = 1; i <= CASAS_TORRE; i++) {
        // Saída de dado: printf("Direita\n");
        printf("%s\n", DIR_DIREITA);
    }
    printf("=> Torre finalizada.\n");

    // -------------------------------------------------------------------------
    // 2. MOVIMENTO DO BISPO: Usando WHILE
    // Lógica: Movimento puramente diagonal (Cima e Direita).
    // -------------------------------------------------------------------------
    printf("\n2. Bispo (WHILE): Movimento Diagonal (%d casas):\n", CASAS_BISPO);
    
    casas_percorridas = 0;
    while (casas_percorridas < CASAS_BISPO) {
        casas_percorridas++;
        // Saída de dado para diagonal: printf("Cima Direita\n");
        printf("%s\n", DIR_CIMA_DIREITA);
    }
    printf("=> Bispo finalizada.\n");


    // -------------------------------------------------------------------------
    // 3. MOVIMENTO DA RAINHA: Usando DO-WHILE
    // Lógica: Movimento puramente horizontal para a Esquerda.
    // -------------------------------------------------------------------------
    printf("\n3. Rainha (DO-WHILE): Movimento para a Esquerda (%d casas):\n", CASAS_RAINHA);
    
    casas_percorridas = 0;
    
    do {
        casas_percorridas++;
        // Saída de dado: printf("Esquerda\n");
        printf("%s\n", DIR_ESQUERDA);
        
    } while (casas_percorridas < CASAS_RAINHA);
    
    printf("=> Rainha finalizada.\n\n");

    return 0;
}