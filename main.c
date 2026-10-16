//Calculadora em C.
#include <stdio.h>

float num1, num2;

void pedeNum(){
    printf("Insira o primeiro número: ");
    scanf("%f", &num1);
    printf("Insira o segundo número: ");
    scanf("%f", &num2);
}

int menu(){
    int opcao;
    
    printf("===============================\n");
    printf("   Calculadora Simples\n");
    printf("===============================\n");
    printf("Selecione uma operação:\n");
    printf("1. Adição\n");
    printf("2. Subtração\n");
    printf("3. Multiplicação\n");
    printf("4. Divisão\n");
    printf("5. Sair\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    return opcao;
}

int main(){
    int opcao = menu();
    char resposta;

    while(opcao > 0 && opcao < 6){
        switch(opcao){
            case 1: 
                pedeNum();
                printf("Resultado: %.2f + %.2f = %.2f", num1, num2, num1 + num2);
                break;
            case 2:
                pedeNum();
                printf("Resultado: %.2f - %.2f = %.2f", num1, num2, num1 - num2);
                break;
            case 3:
                pedeNum();
                printf("Resultado: %.2f * %.2f = %.2f", num1, num2, num1 * num2);
                break;
            case 4:
                pedeNum();
                if(num2 == 0){
                    printf("Erro: Divisão por zero não é permitida.");
                }   
                else{
                    printf("Resultado: %.2f / %.2f = %.2f", num1, num2, num1 / num2);
                }
                break;
            case 5:
                printf("Obrigado por usar a calculadora! Até a próxima.");
                break;
        }
        
        printf("\nDeseja realizar outra operação? (s/n): ");
        scanf(" %c", &resposta);

        if(resposta == 's')
            opcao = menu();
        else if(resposta == 'n')
            printf("Obrigado por usar a calculadora! Até a próxima.");
            break;
    }

    return 0;
}