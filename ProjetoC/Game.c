#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int valor1;
    int valor2;
    int dificuldade;
    int operacao;
    int resultado;
}Calcular;

void jogar();
void mostrarInfo(Calcular calc);
int somar(int resposta, Calcular calc);
int diminuir(int resposta, Calcular calc);
int multiplicar(int resposta, Calcular calc);
int dividir(int resposta, Calcular calc);

int pontos = 0;

int main(){

    srand(time(NULL));
    while(1 == 1){
        jogar();
        printf("%d\n", pontos);
    }
    return 0;
}

void jogar(){

    Calcular calc;
    printf("Informe a dificuldade: [0, 1, 2, 3]\n");
    scanf("%d", &calc.dificuldade);
    calc.operacao = rand() % 4;
    mostrarInfo(calc);
    int resposta;
    int acertou = 0;

    if(calc.dificuldade == 0){
        calc.valor1 = rand() % 11;
        calc.valor2 = rand() % 11;
    }
    else if(calc.dificuldade == 1){
        calc.valor1 = rand() % 26;
        calc.valor2 = rand() % 26;
    }
    else if(calc.dificuldade == 2){
        calc.valor1 = rand() % 51;
        calc.valor2 = rand() % 51;
    }
    else if(calc.dificuldade == 3){
        calc.valor1 = rand() % 101;
        calc.valor2 = rand() % 101;
    }

    if(calc.operacao == 0){
        printf("%d + %d = ", calc.valor1, calc.valor2);
        scanf("%d", &resposta);
        acertou = somar(resposta, calc);
    }
    else if(calc.operacao == 1){
        printf("%d - %d = ", calc.valor1, calc.valor2);
        scanf("%d", &resposta);
        acertou = diminuir(resposta, calc);
    }
    else if(calc.operacao == 2){
        printf("%d * %d = ", calc.valor1, calc.valor2);
        scanf("%d", &resposta);
        acertou = multiplicar(resposta, calc);
    }
    else if(calc.operacao == 3){
        printf("%d : %d = ", calc.valor1, calc.valor2);
        scanf("%d", &resposta);
        acertou = dividir(resposta, calc);
    }

    if(acertou){
        pontos++;
    }

}

void mostrarInfo(Calcular calc){
    char op[25];
    if(calc.operacao == 0){
        sprintf(op, "Somar");
    }
    else if(calc.operacao == 1){
        sprintf(op, "Diminuir");
    }
    else if(calc.operacao == 2){
        sprintf(op, "Multiplicar");
    }
    else if(calc.operacao == 3){
        sprintf(op, "Dividir");
    }
    else{
        sprintf(op, "Opercacao desconhecida");
    }
    printf("Valor 1: %d \nValor 2: %d \nDificuldade: %d \nOpercao: %s\n", calc.valor1,
     calc.valor2, calc.dificuldade, op);

}

int somar(int resposta, Calcular calc){

    int resultado = calc.valor1 + calc.valor2;
    calc.resultado = resultado;
    int certo = 0;
    if(calc.resultado == resposta){
        printf("Reposta correta!\n");
        return 1;
    }else{
        printf("Resposta errada!\n");
        printf("%d + %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
        return 0;
    }
}

int diminuir(int resposta, Calcular calc){
    int resultado = calc.valor1 - calc.valor2;
    calc.resultado = resultado;
    if(calc.resultado == resposta){
        printf("Reposta correta!\n");
        return 1;
    }else{
        printf("Resposta errada!\n");
        printf("%d + %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
        return 0;
    }
}

int multiplicar(int resposta, Calcular calc){
    int resultado = calc.valor1 * calc.valor2;
    calc.resultado = resultado;
    if(calc.resultado == resposta){
        printf("Reposta correta!\n");
        return 1;
    }else{
        printf("Resposta errada!\n");
        printf("%d + %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
        return 0;
    }
}

int dividir(int resposta, Calcular calc){
    int resultado = calc.valor1 / calc.valor2;
    calc.resultado = resultado;
    if(calc.resultado == resposta){
        printf("Reposta correta!\n");
        return 1;
    }else{
        printf("Resposta errada!\n");
        printf("%d + %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
        return 0;
    }
}

