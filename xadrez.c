#include <stdio.h>

// ----------------------------------------------------------
// MOVIMENTAÇÕES PEÇAS DE XADREZ - NÍVEL MESTRE
// ----------------------------------------------------------

// 🔷 TORRE: movimento horizontal em linha reta.
// Requisito: Recursividade. Simula 5 casas para a direita.
void moverTorre(int casa, int limite) {
    // Caso base: Quando o contador de casas (casa) excede o limite (limite)
    if (casa > limite) {
        return; 
    }
    // Saída: Imprime a direção a cada passo
    printf("Direita (%d)\n", casa);
    
    // Chamada recursiva: Move para a próxima casa
    moverTorre(casa + 1, limite); 
}

// 🔶 BISPO: movimento diagonal (Cima e Direita).
// Requisito: Recursividade (vertical) E Loops Aninhados (horizontal).
// O movimento real é uma única direção, os loops aninhados são forçados pelo requisito.
void moverBispo(int passo_vertical, int limite_passos) {
    // Caso base: Fim dos passos diagonais
    if (passo_vertical > limite_passos) {
        return;
    }

    // Loop mais externo (Recursão para vertical) - passo_vertical
    
    // Loop mais interno (Horizontal) - Forçado pelo requisito (Bispo move 1x na horizontal por passo)
    for (int h = 1; h <= 1; h++) {
        // Impressão da direção (Cima, Direita) que avança no vertical e horizontal simultaneamente
        printf("Cima, Direita (Passo %d)\n", passo_vertical);
    }

    // Chamada recursiva: Próximo passo diagonal
    moverBispo(passo_vertical + 1, limite_passos); 
}

// 👑 RAINHA: movimento livre.
// Requisito: Recursividade. Simula 8 casas para a esquerda.
void moverRainha(int casa, int limite) {
    // Caso base
    if (casa > limite) {
        return; 
    }
    // Saída: Imprime a direção a cada passo
    printf("Esquerda (%d)\n", casa);
    
    // Chamada recursiva
    moverRainha(casa + 1, limite);
}

// ----------------------------------------------------------
// 🐴 CAVALO: Loops Complexos
// ----------------------------------------------------------
// Movimento em “L”: 2 casas para cima e 1 para a direita.
// Requisito: Loops aninhados com múltiplas variáveis e/ou condições, e uso de continue/break.
void moverCavaloComplexo() {
    int movVertical = 2; // casas para cima
    int movHorizontal = 1; // casas para a direita
    int v = 1; // Contador para movimento vertical

    printf("Movimento do Cavalo (2 Cima, 1 Direita):\n");

    // Loop Externo (para o movimento vertical) - for
    for (; v <= movVertical; v++) {
        printf("Cima (%d de %d)\n", v, movVertical);
        
        // Uso de continue - apenas para demonstrar o requisito
        if (v == movVertical) {
            continue; 
        }
    }
    
    // Loop Interno/Sequencial (para o movimento horizontal) - do-while para demonstrar o requisito de loop complexo
    // Este loop simula 1 único passo horizontal, usando break/múltiplas condições
    int h = 1; // Contador para movimento horizontal
    int condicao_extra = 0; // Variável extra para condição complexa
    do {
        if (h <= movHorizontal && condicao_extra == 0) {
            printf("Direita (%d de %d)\n", h, movHorizontal);
            condicao_extra = 1; // Altera a variável extra
        } else {
            break; // Uso de break para parar o loop após o primeiro passo
        }
        h++; // Incremento
    } while (h <= movHorizontal || condicao_extra == 0); // Múltiplas condições
}

// ----------------------------------------------------------
// Função principal
// ----------------------------------------------------------
int main() {
    printf("=== Simulação de Movimentos de Xadrez (Nível Mestre) ===\n\n");

    // 1️⃣ Torre (Recursiva) - 5 casas para a direita
    printf("Movimento da Torre:\n");
    moverTorre(1, 5); 
    printf("\n");

    // 2️⃣ Bispo (Recursiva + Loops Aninhados) - 5 passos na diagonal Cima/Direita
    printf("Movimento do Bispo:\n");
    moverBispo(1, 5); // 5 passos
    printf("\n");

    // 3️⃣ Rainha (Recursiva) - 8 casas para a esquerda
    printf("Movimento da Rainha:\n");
    moverRainha(1, 8); 
    printf("\n");

    // 4️⃣ Cavalo (Loops Complexos) - 2 Cima, 1 Direita
    moverCavaloComplexo();

    printf("\nSimulação concluída!\n");
    return 0;
}
