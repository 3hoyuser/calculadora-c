//Calculadora em C.
#include <stdio.h>
#include <string.h>

int opcao;
float num1, num2;

void pedeNum(){
    printf("Insira o primeiro número: ");
    scanf("%f", &num1);
    printf("Insira o segundo número: ");
    scanf("%f", &num2);
}

int menu(){
    char entrada[100];
    int valido;

    while(1) {
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
        
        
        if (fgets(entrada, sizeof(entrada), stdin) == NULL){
            continue;
        }

        entrada[strcspn(entrada, "\r\n")] = '\0';

        
        if (strlen(entrada) == 1 && entrada[0] >= '1' && entrada[0] <= '5'){
            opcao = entrada[0] - '0';
            break;
        } 
        else{
            printf("Opção inválida!\n\n");
        }
    }

    return opcao;
}

int main(){
    char resposta;

    while(1){

        menu();

        if(opcao == 5){
            printf("Obrigado por usar a calculadora! Até a próxima.");
            break;
        }

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
        }
        
        while(1){
            printf("\nDeseja realizar outra operação? (s/n): ");
            scanf(" %c", &resposta);

            if(resposta == 's' || resposta == 'S'){
                break; 
            } 
            else if(resposta == 'n' || resposta == 'N'){
                printf("Obrigado por usar a calculadora! Até a próxima.\n");
                return 0;
            } 
            else {
                printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não.");
                }
        }
    }
    return 0;
}
