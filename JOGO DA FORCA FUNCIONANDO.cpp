#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ERROS 6

char palavras[][20] = {"ELASTICO", "ESCADA", "INDIA", "IRLANDA", "OSSO", "OLHO", "UVA", "UMBU", "ABELHA", "ANTA"};
int qtdPalavras = 10;

void desenhoForca(int erros) {
    switch (erros) {
        case 0:
            printf("  _______\n");
            printf(" |/      |\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf("_|_\n");
            break;
        case 1:
            printf("  _______\n");
            printf(" |/      |\n");
            printf(" |       0\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf("_|_\n");
            break;
        case 2:
            printf("  _______\n");
            printf(" |/      |\n");
            printf(" |       0\n");
            printf(" |       |\n");
            printf(" |        \n");
            printf(" |\n");
            printf("_|_\n");
            break;
        case 3:
            printf("  _______\n");
            printf(" |/      |\n");
            printf(" |       0\n");
            printf(" |      -|\n");
            printf(" | \n");
            printf(" |\n");
            printf("_|_\n");
            break;
        case 4:
            printf("  _______\n");
            printf(" |/      |\n");
            printf(" |       0\n");
            printf(" |      -|-\n");
            printf(" |\n");
            printf(" |\n");
            printf("_|_\n");
            break;
        case 5:
            printf("  _______\n");
            printf(" |/      |\n");
            printf(" |       0\n");
            printf(" |      -|-\n");
            printf(" |        \\\n");
            printf(" |\n");
            printf("_|_\n");
            break;
        case 6:
            printf("  _______\n");
            printf(" |/      |\n");
            printf(" |       0\n");
            printf(" |      -|-\n");
            printf(" |      / \\\n");
            printf(" |\n");
            printf("_|_\n");
            break;
    }
}

void limparTela() {
    system("cls");
}

void menu() {
    printf("=== Bem-vindo! Divirta-se com o Jogo da Forca ===\n\n");
    printf("Digite uma opcao:\n");
    printf("1. Iniciar o Jogo\n");
    printf("2. Instrucoes e Dicas\n");
    printf("3. Sair\n");
}
void instrucaoDicas() {
    printf("Instrucoes: \n");
    printf("Este jogo pode ser jogado sozinho ou com um amigo.\nVoce pode errar no maximo 6x. A cada acerto voce chega mais perto de vencer o jogo, entao boa sorte!!\n\n");
    printf("Dicas: \n");
    printf("O modo solo nao possui dicas na hora de jogar, sugerimos que verifiquem estas caracteristicas a seguir:\n");
    printf("palavras comecadas com a letra 'A' sao animais.\n");
    printf("palavras comecadas com a letra 'E' sao objetos.\n");
    printf("palavras comecadas com a letra 'I' sao paises.\n");
    printf("palavras comecadas com a letra 'O' sao partes do corpo.\n");
    printf("palavras comecadas com a letra 'U' sao frutas.\n\n");
    printf("\n\nPressione Enter para voltar ao menu...");
    while (getchar() != '\n');
    getchar();
    limparTela();
}

char lerOpcao() {
    char escolherOpcao;
    
    printf("Opcao: ");
    scanf(" %c", &escolherOpcao);
    return escolherOpcao;
}

void escolherModoJogo(char *palavra) {
    int escolhaModo;
    
    printf("Escolha uma opcao:\n");
    printf("1. Modo solo\n");
    printf("2. Modo dual player\n");
    printf("Opcao: ");
    scanf("%d", &escolhaModo);
    switch (escolhaModo) {
        case 1:
            strcpy(palavra, palavras[rand() % qtdPalavras]);
            limparTela();
            break;
        case 2:
            printf("Digite a palavra para ser adivinhada em caixa alta (maximo de 20 caracteres): ");
            scanf("%s", palavra);
            limparTela();
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
            escolherModoJogo(palavra);
    }
}

void iniciarJogo() {
    char palavra[20], letra, letrasCertas[20];
    int tamanhoPalavra, erros = 0, acertos = 0, contador;

    escolherModoJogo(palavra);

    tamanhoPalavra = strlen(palavra);
    
    for (contador = 0; contador < tamanhoPalavra; contador++) {
        letrasCertas[contador] = '_';
    }

    while (erros < MAX_ERROS && acertos < tamanhoPalavra) {
    	int encontrou = 0;
    	
    	desenhoForca(erros);
    	
        printf("\nPalavra: ");
        for (contador = 0; contador < tamanhoPalavra; contador++) {
            printf("%c ", letrasCertas[contador]);
        }

        printf("\nDigite uma letra: ");
        scanf(" %c", &letra);
        letra = toupper(letra);

        limparTela();

        for (contador = 0; contador < tamanhoPalavra; contador++) {
            if (palavra[contador] == letra) {
                letrasCertas[contador] = letra;
                acertos++;
                encontrou = 1;
            }
        }

        if (!encontrou) {
            erros++;
            printf("Letra incorreta!\n");
            printf("Tentativas restantes: %d\n", MAX_ERROS - erros);
            desenhoForca(erros);
        }

		 limparTela();
    }

    if (acertos == tamanhoPalavra) {
        printf("\nParabens! Voce venceu!\n");
    } else {
        printf("\nVoce perdeu! A palavra era: %s\n", palavra);
        desenhoForca(erros);
    }

    printf("\n\nPressione Enter para voltar ao menu...");
    while (getchar() != '\n');
    getchar();
    limparTela();
}

int main() {
	char escolha;
	
    srand(time(NULL));

    do {
        menu();
        escolha = lerOpcao();

        limparTela();

        switch (escolha) {
            case '1':
                iniciarJogo();
                break;
            case '2':
                instrucaoDicas();
                break;
            case '3':
                printf("Ate logo!\n");
                return 0;
            default:
                printf("Opcao invalida! Tente novamente.\n\n");
        }

    } while (1);

    return 0;
}
