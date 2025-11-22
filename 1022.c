#include <stdio.h>
#include <stdlib.h>

// Função para calcular MDC usando Algoritmo de Euclides
int mdc(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Função para simplificar fração
void simplificar(int *num, int *den) {
    int divisor = mdc(*num, *den);
    *num /= divisor;
    *den /= divisor;
    
    // Garantir que o denominador seja positivo
    if (*den < 0) {
        *num = -(*num);
        *den = -(*den);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    
    while (N--) {
        int N1, D1, N2, D2;
        char op1, op2, operacao;
        
        // Ler a expressão: N1 / D1 operacao N2 / D2
        scanf("%d %c %d %c %d %c %d", &N1, &op1, &D1, &operacao, &N2, &op2, &D2);
        
        int resultado_num, resultado_den;
        
        // Realizar a operação conforme o operador
        switch (operacao) {
            case '+':
                // Soma: (N1*D2 + N2*D1) / (D1*D2)
                resultado_num = N1 * D2 + N2 * D1;
                resultado_den = D1 * D2;
                break;
                
            case '-':
                // Subtração: (N1*D2 - N2*D1) / (D1*D2)
                resultado_num = N1 * D2 - N2 * D1;
                resultado_den = D1 * D2;
                break;
                
            case '*':
                // Multiplicação: (N1*N2) / (D1*D2)
                resultado_num = N1 * N2;
                resultado_den = D1 * D2;
                break;
                
            case '/':
                // Divisão: (N1*D2) / (N2*D1)
                resultado_num = N1 * D2;
                resultado_den = N2 * D1;
                break;
        }
        
        // Calcular versão simplificada
        int simplificado_num = resultado_num;
        int simplificado_den = resultado_den;
        simplificar(&simplificado_num, &simplificado_den);
        
        // Imprimir resultado
        printf("%d/%d = %d/%d\n", resultado_num, resultado_den, simplificado_num, simplificado_den);
    }
    
    return 0;
}