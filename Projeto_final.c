/* Projeto Final De FUP-2020 
    Sistema de Quiz

Deve Conter:

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

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_char 255
#define MAX_nick 21
#define MAX_perguntas 10


///////////////////// Estruturas//////////////
typedef struct{

    char name[MAX_nick];
    int pontuacao;

}Usuario;

typedef struct{

    char enunciado[MAX_char;
    char alternativas[MAX_char];
    char resposta;

}Pergunta;

Pergunta perguntas[MAX_perguntas];

Usuario usuario;


/////////////////////////////////////////

// Função para criar perguntas //
/*
Pergunta criar_perguntas(Pergunta * pergunta){
    printf("Escreva o enunciado da pergunta: \n");
    scanf("%[^\n]", pergunta.enunciado);
    printf("Escreva 4 alternativas para essa pergunta: \n")
    scanf("%[^\n]", pergunta.alternativa);
    printf("Digite qual a alternativa correta: \n");
    scanf("%d", &pergunta.resposta)

    return * pergunta;
}
*/
//

// FUNÇÃO PERGUNTAS PRONTAS //
void perguntas_prontas(){
    strcpy(perguntas[0].enunciado, "De onde e a invencao do chuveiro eletrico?");
    strcpy(perguntas[0].alternativas, "a) Brasil\nb) Inglaterra\nc) Franca\nd) Australia\ne) Italia");
    perguntas[0].resposta = 'a';
    
    strcpy(perguntas[1].enunciado, "De quem e a famosa frase, Penso, logo existo?");
    strcpy(perguntas[1].alternativas, "a) Platao\nb) Galileu Galilei\nc) Descartes\nd) Socrates\ne) Francis Bacon");
    perguntas[1].resposta = 'c';

}

///////////////////////////

// FUNÇÃO DO MENU ADMIN //
void menu_admin(){
    bool parar = false;

    printf("[1]Adicionar perguntas\n[2]Remover perguntas\n[3]Sair\n");
    while(parar == false){
        int opcao = 0;
        printf("Enter:");
        scanf(" %d", &opcao);
        switch(opcao){
            case 1:
                //Adicionar perguntas
                break;
            case 2:
                //Remover perguntas
                break;
            case 3:
                parar = true;
                break;
            default:
                break;
        } 
    }
}
////////////////////////////////

// Função cadastro do usuário //
void cadastrar_usuario(){
    printf("Digite seu nickname: ");
    scanf(" %[^\n]", usuario.name);
    usuario.pontuacao = 0;

}
////////////////////////////////

// FUNÇÃO DO QUIZ //
void Quiz(){

    perguntas_prontas();

    for(int i = 0; i < 2; i++){
        char resp;
        printf("\n");
        printf("Pergunta %d%c %s\n", i + 1, 41, perguntas[i].enunciado);
        printf("\n");
        printf("%s\n", perguntas[i].alternativas);
        printf("%c%c%c%c%c%c%c%c%c\n", 205, 205, 205, 205, 205, 205, 205, 205, 187);
        printf("Letra:");
        scanf(" %c", &resp);
        printf("%c%c%c%c%c%c%c%c%c\n",205, 205, 205, 205, 205, 205, 205, 205, 188);
        if(resp == perguntas[i].resposta){
            printf("%c%c%c Voce acertou!!\n\n", 175, 175, 175);
            usuario.pontuacao +=5;
        }
        else{
            printf("%c%c%c Voce errou :(\n\n", 175, 175, 175);
        }
    }   
    printf("Voce completou o Quiz, veja sua pontuacao no menu.\n\n");
}
/////////////////////////////

// FUNÇÃO DO MENU USUARIO //
void menu_usuario(){

    bool parar = false;

    while(parar == false){

        int opcao = 0;

        printf("%c%c%c%c%c%c%c%c%c QUIZ %c%c%c%c%c%c%c%c%c\n", 254, 254, 254, 254, 254, 254,
        254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254);
        printf("[1]Iniciar o Quiz\n[2]Pontuacao\n[3]Sair\n");
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 254, 254, 254, 254, 254, 254, 
        254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254);

        printf("%cEnter:", 175);
        scanf(" %d", &opcao);
        printf("\n");

        switch(opcao){
            case 1:
                cadastrar_usuario();
                Quiz();
                break;
            case 2:
                printf("========== PONTUACAO ==========\n");
                printf("Nickname: %s\nPontos:%d\n", usuario.name, usuario.pontuacao);
                printf("===============================\n");
                break;
            case 3:
                parar = true;
                break;
            case 2020:
                printf("AINDA NAO ESTA FUNCIONANDO\n");
                break;
            default:
                parar = true;
                break;
        } 
    }
}
//////////////////////
int main(){
    menu_usuario();
}
