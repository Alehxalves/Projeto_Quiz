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
#define MAX_users 5

////// VARIAVEIS GLOBAIS ////////

int user = 0;
int indice_user = 0;

/////////// FIM ////////////////

/////////// ESTRUTURAS /////////
typedef struct{

    char name[MAX_nick];
    int pontuacao;
    int senha;

}Usuario;

typedef struct{

    char enunciado[MAX_char];
    char alternativas[MAX_char];
    char resposta;

}Pergunta;


Pergunta perguntas[MAX_perguntas];

Usuario usuario[MAX_users];

/////////// FIM ////////////////

//// FUNÇÂO CRIAR PERGUNTAS ////
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
/////////// FIM ////////////////

/// FUNÇÃO PERGUNTAS PRONTAS ///
void perguntas_prontas(){
    strcpy(perguntas[0].enunciado, "De onde e a invencao do chuveiro eletrico?");
    strcpy(perguntas[0].alternativas, "a) Brasil\nb) Inglaterra\nc) Franca\nd) Australia\ne) Italia");
    perguntas[0].resposta = 'a';
    
    strcpy(perguntas[1].enunciado, "De quem e a famosa frase, Penso, logo existo?");
    strcpy(perguntas[1].alternativas, "a) Platao\nb) Galileu Galilei\nc) Descartes\nd) Socrates\ne) Francis Bacon");
    perguntas[1].resposta = 'c';

}
/////////// FIM ////////////////

//// FUNÇÃO DO MENU ADMIN //////
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
/////////// FIM ////////////////

// Função cadastro do usuário //
void cadastrar_usuario(){
    printf("========Cadastro=========\n");
    printf("Digite nome de usuario: ");

    scanf(" %[^\n]", usuario[user].name);

    printf("Digite sua senha (No maximo 4 digitos): ");
    scanf(" %d", &usuario[user].senha);

    printf("=========================\n");
    usuario[user].pontuacao = 0;
    user++;
    indice_user = user - 1;
    Quiz();
}
/////////// FIM ////////////////

//// FUNCAO DE BUSCAR USER /////
void busca(char * login, int senha){

    for(int i = 0; i < user; i++){
        if(senha == usuario[i].senha && strcmp(login, usuario[i].name) == 0){
            indice_user = i;
            Quiz();
        }
    }
    printf("Login ou senha errada!\n\n");
}
/////////// FIM ////////////////

///////// FUNCAO LOGIN /////////
int login(){
    char login_user[MAX_nick] = {0};
    int login_senha;
    login_senha = 0;

    printf("=========Login==========\n");
    printf("Login: ");
    scanf(" %[^\n]", &login_user);

    printf("Password: ");
    scanf(" %d", &login_senha);

    printf("========================\n");
    busca(login_user, login_senha);
}
/////////// FIM ////////////////

/////// FUNÇÃO DO QUIZ /////////
void Quiz(){

    perguntas_prontas();
    

    for(int i = 0; i < 2; i++){
        char resp;

        printf("\n");

        printf("%c%c%c%c%c%c%c%c%c QUIZ %c%c%c%c%c%c%c%c%c\n", 254, 254, 254, 254, 254, 254,
        254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254);

        printf("Pergunta %d%c %s\n", i + 1, 41, perguntas[i].enunciado);
        printf("\n");

        printf("%s\n", perguntas[i].alternativas);

        printf("%c%c%c%c%c%c%c%c%c\n", 205, 205, 205, 205, 205, 205, 205, 205, 205);// Apenas caracteres especiais.

        printf("%cLetra: ", 175);
        scanf(" %c", &resp);

        printf("%c%c%c%c%c%c%c%c%c\n",205, 205, 205, 205, 205, 205, 205, 205, 205);// Apenas caracteres especiais.

        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n", 254, 254, 254, 254, 254, 254,
        254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254);

        if(resp == perguntas[i].resposta){
            printf("%c%c%c Voce acertou!!\n", 175, 175, 175);// Apenas caracteres especiais.
            usuario[indice_user].pontuacao +=5;
        }
        else{
            printf("%c%c%c Voce errou :(\n", 175, 175, 175);// Apenas caracteres especiais.
        }
    }
    printf("\n");   
    printf("Voce completou o Quiz, veja sua pontuacao no menu.\n\n");
}
/////////// FIM ////////////////

//// FUNÇÃO DO MENU USUARIO ////
void menu_usuario(){

    bool parar = false;

    while(parar == false){

        int opcao = 0;
        
        // Apenas caracteres especiais //
        printf("%c%c%c%c%c%c%c%c%c QUIZ %c%c%c%c%c%c%c%c%c\n", 254, 254, 254, 254, 254, 254,
        254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254);

        printf("[1]Iniciar o Quiz\n[2]Pontuacao\n[3]Sair\n");

        printf("%cEnter:", 175);
        scanf(" %d", &opcao);

        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 254, 254, 254, 254, 254, 254,
        254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254);

        printf("\n");

        switch(opcao){
            int opc = 0;
            case 1:
                printf("========================\n");

                printf("[1]Entrar\n[2]Cadastrar\n[3]Voltar\n");

                printf("%cEnter:", 175);
                scanf(" %d", &opc);

                printf("========================\n");

                switch(opc){
                    case 1:
                        login();
                        break;
                    case 2: 
                        cadastrar_usuario();
                        break;
                    case 3:
                        break;
                }
                break;
            case 2:
                printf("========== PONTUACAO ==========\n");
                for(int i = 0; i < user; i++){
                        printf("Usuario: %s Pontos:%d\n", usuario[i].name, usuario[i].pontuacao);    
                }
                printf("===============================\n");
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
    }
}
/////////// FIM ////////////////

int main(){
    menu_usuario();
}
