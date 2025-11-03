#include <stdio.h>

// =========================================================================
// REQUISITOS NÃO FUNCIONAIS: Definição de Constantes (Entrada de Dados)
// =========================================================================

// Define o número de casas a serem movidas diretamente no código
#define CASAS_TORRE 5
#define CASAS_BISPO 5
#define CASAS_RAINHA 8
// Novo: Define o movimento principal do Cavalo
#define CASAS_VERTICAL_CAVALO 2
#define CASAS_HORIZONTAL_CAVALO 1

// Strings para a Saída de Dados, garantindo legibilidade
const char* DIR_DIREITA = "Direita";
const char* DIR_ESQUERDA = "Esquerda";
const char* DIR_CIMA_DIREITA = "Cima Direita";
const char* DIR_BAIXO = "Baixo"; // Nova direção para o Cavalo
// String para resetar a cor (ajuda na legibilidade do terminal)
const char* RESET_ANSI = "\033[0m";
const char* COR_DESTAQUE = "\033[32m"; // Verde

// =========================================================================
// FUNÇÃO PRINCIPAL
// =========================================================================
int main() {
    // Variáveis de controle de loop (tipo inteiro)
    int i, j;
    int casas_percorridas;

    // Documentação: Imprime o cabeçalho
    printf("%s--- Simulacao de Movimento de Pecas de Xadrez ---\n%s", COR_DESTAQUE, RESET_ANSI);
    printf("Movimentos definidos: Torre=%d, Bispo=%d, Rainha=%d, Cavalo=(%d, %d).\n", 
           CASAS_TORRE, CASAS_BISPO, CASAS_RAINHA, CASAS_VERTICAL_CAVALO, CASAS_HORIZONTAL_CAVALO);

    // -------------------------------------------------------------------------
    // 1. MOVIMENTO DA TORRE: Usando FOR
    // -------------------------------------------------------------------------
    printf("\n1. Torre (FOR): Movimento para a Direita (%d casas):\n", CASAS_TORRE);
    
    for (i = 1; i <= CASAS_TORRE; i++) {
        printf("%s\n", DIR_DIREITA);
    }
    printf("=> Torre finalizada.\n");

    // -------------------------------------------------------------------------
    // 2. MOVIMENTO DO BISPO: Usando WHILE
    // -------------------------------------------------------------------------
    printf("\n2. Bispo (WHILE): Movimento Diagonal (%d casas):\n", CASAS_BISPO);
    
    casas_percorridas = 0;
    while (casas_percorridas < CASAS_BISPO) {
        casas_percorridas++;
        printf("%s\n", DIR_CIMA_DIREITA);
    }
    printf("=> Bispo finalizada.\n");


    // -------------------------------------------------------------------------
    // 3. MOVIMENTO DA RAINHA: Usando DO-WHILE
    // -------------------------------------------------------------------------
    printf("\n3. Rainha (DO-WHILE): Movimento para a Esquerda (%d casas):\n", CASAS_RAINHA);
    
    casas_percorridas = 0;
    
    do {
        casas_percorridas++;
        printf("%s\n", DIR_ESQUERDA);
        
    } while (casas_percorridas < CASAS_RAINHA);
    
    printf("=> Rainha finalizada.\n");

    // -------------------------------------------------------------------------
    // 4. MOVIMENTO DO CAVALO: Usando FOR ANINHADO com WHILE
    // Lógica: 2 casas para Baixo (loop FOR) e 1 casa para a Esquerda (loop WHILE)
    // -------------------------------------------------------------------------
    printf("\n4. Cavalo (FOR + WHILE Aninhado): Movimento 'L' (Baixo %d, Esquerda %d):\n", 
           CASAS_VERTICAL_CAVALO, CASAS_HORIZONTAL_CAVALO);
    
    // Loop Externo (FOR): Simula o movimento de 2 casas na primeira direção (Baixo)
    for (i = 0; i < CASAS_VERTICAL_CAVALO; i++) {
        printf("%s\n", DIR_BAIXO);
    }

    // Loop Aninhado (WHILE): Simula o movimento de 1 casa na direção perpendicular (Esquerda)
    j = 0; // Inicializa o contador do loop WHILE
    while (j < CASAS_HORIZONTAL_CAVALO) {
        printf("%s\n", DIR_ESQUERDA);
        j++;
    }

    printf("=> Cavalo finalizado.\n\n");

    return 0;
}