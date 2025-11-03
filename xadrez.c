#include <stdio.h>

// =========================================================================
// REQUISITOS NÃO FUNCIONAIS: Definição de Constantes e Variáveis
// (Entrada de Dados definida diretamente no código)
// =========================================================================

// Define o número de casas a serem movidas para as funções recursivas
#define CASAS_TORRE_RECURSIVIDADE 5
#define CASAS_BISPO_RECURSIVIDADE 5
#define CASAS_RAINHA_RECURSIVIDADE 8

// Define o movimento principal do Cavalo (para loops complexos)
const int MOV_VERT_CAVALO = 2; // Duas casas na vertical
const int MOV_HORZ_CAVALO = 1; // Uma casa na horizontal

// Strings para a Saída de Dados (garantindo legibilidade e padrão de saída)
const char* DIR_CIMA = "Cima";
const char* DIR_BAIXO = "Baixo";
const char* DIR_ESQUERDA = "Esquerda";
const char* DIR_DIREITA = "Direita";
const char* DIR_CIMA_DIREITA = "Cima Direita"; // Usado para o output simplificado do Bispo recursivo

// =========================================================================
// FUNÇÕES RECURSIVAS
// =========================================================================

/**
 * Requisito: Recursividade (Torre). Move-se numa direção (ex: Direita).
 * @param casas_restantes Número de casas a percorrer.
 */
void moverTorreRecursivo(int casas_restantes) {
    if (casas_restantes <= 0) {
        return; // Caso base: condição de parada da recursão
    }
    // Saída de Dados padrão
    printf("%s\n", DIR_DIREITA);
    // Passo recursivo: chama a si mesma com uma casa a menos
    moverTorreRecursivo(casas_restantes - 1);
}

/**
 * Requisito: Recursividade (Bispo). Move-se na diagonal.
 * @param casas_restantes Número de casas a percorrer.
 */
void moverBispoRecursivo(int casas_restantes) {
    if (casas_restantes <= 0) {
        return; // Caso base
    }
    // Saída de Dados padrão (simplificado para diagonal)
    printf("%s\n", DIR_CIMA_DIREITA); 
    // Passo recursivo
    moverBispoRecursivo(casas_restantes - 1);
}

/**
 * Requisito: Recursividade (Rainha). Move-se numa direção (ex: Esquerda).
 * @param casas_restantes Número de casas a percorrer.
 */
void moverRainhaRecursivo(int casas_restantes) {
    if (casas_restantes == 0) {
        return; // Caso base
    }
    // Saída de Dados padrão
    printf("%s\n", DIR_ESQUERDA);
    // Passo recursivo
    moverRainhaRecursivo(casas_restantes - 1);
}

// =========================================================================
// FUNÇÃO PRINCIPAL
// =========================================================================
int main() {
    // Variáveis de controle de loop
    int i, j;

    // Cabeçalho Inicial
    printf("--- Simulacao de Movimento de Pecas de Xadrez ---\n");
    printf("Valores definidos: Torre=%d, Bispo=%d, Rainha=%d, Cavalo=(%d vertical, %d horizontal).\n\n", 
           CASAS_TORRE_RECURSIVIDADE, CASAS_BISPO_RECURSIVIDADE, CASAS_RAINHA_RECURSIVIDADE, 
           MOV_VERT_CAVALO, MOV_HORZ_CAVALO);

    // -------------------------------------------------------------------------
    // 1. MOVIMENTO DA TORRE: Usando RECURSIVIDADE
    // -------------------------------------------------------------------------
    printf("1. Torre (Recursivo): Movimento para a Direita (%d casas):\n", CASAS_TORRE_RECURSIVIDADE);
    moverTorreRecursivo(CASAS_TORRE_RECURSIVIDADE);
    printf("=> Torre finalizada.\n\n"); // Linha em branco para separar a saída

    // -------------------------------------------------------------------------
    // 2. MOVIMENTO DO BISPO: Usando RECURSIVIDADE (Versão 1, simplificada)
    // -------------------------------------------------------------------------
    printf("2. Bispo (Recursivo): Movimento Diagonal (%d casas):\n", CASAS_BISPO_RECURSIVIDADE);
    moverBispoRecursivo(CASAS_BISPO_RECURSIVIDADE);
    printf("=> Bispo finalizado.\n\n"); // Linha em branco para separar a saída

    // -------------------------------------------------------------------------
    // 3. MOVIMENTO DA RAINHA: Usando RECURSIVIDADE
    // -------------------------------------------------------------------------
    printf("3. Rainha (Recursivo): Movimento para a Esquerda (%d casas):\n", CASAS_RAINHA_RECURSIVIDADE);
    moverRainhaRecursivo(CASAS_RAINHA_RECURSIVIDADE);
    printf("=> Rainha finalizada.\n\n"); // Linha em branco para separar a saída

    // -------------------------------------------------------------------------
    // 4. MOVIMENTO DO CAVALO: Usando LOOPS COMPLEXOS ANINHADOS
    // Requisito: 2 casas para Cima, 1 casa para a Direita.
    // -------------------------------------------------------------------------
    printf("4. Cavalo (Loops Aninhados Complexos): Movimento 'L' (Cima %d, Direita %d):\n", 
           MOV_VERT_CAVALO, MOV_HORZ_CAVALO);
    
    // Loop externo (i): Controla as casas verticais (Cima)
    for (i = 0; i < MOV_VERT_CAVALO; i++) {
        printf("%s\n", DIR_CIMA);
    }

    // Loop interno (j): Controla as casas horizontais (Direita) - executa 1 vez
    for (j = 0; j < MOV_HORZ_CAVALO; j++) {
        printf("%s\n", DIR_DIREITA);
    }
    printf("=> Cavalo finalizado.\n\n"); // Linha em branco para separar a saída

    // -------------------------------------------------------------------------
    // 5. BISPO: Versão alternativa com LOOPS ANINHADOS (conforme solicitado no requisito)
    // Requisito: Loop externo vertical, interno horizontal.
    // -------------------------------------------------------------------------
    printf("5. Bispo (Loops Aninhados - Alternativo): Diagonal (%d casas):\n", CASAS_BISPO_RECURSIVIDADE);
    
    for (i = 0; i < CASAS_BISPO_RECURSIVIDADE; i++) {
        // Loop externo: movimento vertical
        printf("%s\n", DIR_CIMA); 

        // Loop interno: movimento horizontal (executa uma vez por iteração do loop externo)
        for (j = 0; j < 1; j++) {
             printf("%s\n", DIR_DIREITA);
        }
    }
    printf("=> Bispo alternativo finalizado.\n\n");

    return 0;
}
