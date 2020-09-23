#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* Projeto Final De FUP-2020 
    Sistema de Quiz

Deve Contem:

Menu de Usuário.
Cadastro de Usuário.
Perguntas
Resposta do usuário
Informação de erro ou acerto da pergunta.
Pontuação

Menu Admin
Cadastro de Perguntas juntamente com as resposta.
Excluir pergunta.

*/

typedef struct{

    char name[51];
    int pontuacao;
}Usuario;

typedef struct{

    char enunciado[256];
    char alternativas[51];
    int resposta;
}Pergunta;

Pergunta criar_perguntas(Pergunta * pergunta){
    printf("Escreva o enunciado da pergunta: \n");
    scanf("%[^\n]", pergunta->enunciado);
    printf("Escreva 4 alternativas para essa pergunta: \n")
    scanf("%[^\n]", pergunta->alternativa);
    printf("Digite qual a alternativa correta: \n");
    scanf("%d", pergunta->resposta)
}

void menu_admin(){
    bool parar = false;

    printf("[1]Adicionar perguntas\n[2]Remover Perguntas\n[3]Sair\n");
    while(parar == false){
        int opcao = 0;
        printf("Enter:");
        scanf(" %d", &opcao);
        switch(opcao){
            case 1:
                //Adicionar Perguntas
                break;
            case 2:
                //Remover Perguntas
                break;
            case 3:
                parar = true;
                menu_usuario();
                break;
            default:
                break;
        } 
    }
}

void menu_usuario(){

    bool parar = false;

    printf("[1]Iniciar o Quiz\n[2]Pontuaçao\n[3]Sair\n");
   
    while(parar == false){
        int opcao = 0;
        printf("Enter:");
        scanf(" %d", &opcao);
        switch(opcao){
            case 1:
                //Iniciar o Quiz
                break;
            case 2:
                //Exibir pontuação
                break;
            case 3:
                parar = true;
                break;
            case 2020:
                menu_admin();
                break;
            default:
                parar = true;
                break;
        } 
        parar = true;
    }
}

int main(){
    menu_usuario();
}
