#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_char 255
#define MAX_nick 21
#define MAX_perguntas 10
#define MAX_users 5

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

///FUNÇÃO ADICIONAR PERGUNTA////
void adicionar_pergunta(){

    for(int i = 0; i < MAX_perguntas; i++){

        if(strlen(perguntas[i].enunciado) == 0){
            printf("Escreva o enunciado da pergunta, utilize o caractere '*' para indicar uma quebra de linha: \n");
            scanf(" %[^\n]", perguntas[i].enunciado);

            printf("Escreva 5 alternativas, de a) a e), utilize '*' no final da alternativa (a)* b)* c)* ...): \n" );
            scanf(" %[^\n]", perguntas[i].alternativas);

            ///QUEBRAR LINHAS ///
            for(int j = 0; j < strlen(perguntas[i].enunciado); j++){

                if(perguntas[i].enunciado[j] == '*'){
                    perguntas[i].enunciado[j] = '\n';
                }
            }

            for(int j = 0; j < strlen(perguntas[i].alternativas); j++){

                if(perguntas[i].alternativas[j] == '*'){
                    perguntas[i].alternativas[j] = '\n';
                }
            }
            /////////
            printf("Digite qual a alternativa correta, entre a & e: ");

            scanf(" %c", &perguntas[i].resposta);

            if(perguntas[i].resposta >= 'A' && perguntas[i].resposta <= 'Z'){
                int D = perguntas[i].resposta - 'A';
                perguntas[i].resposta = D + 'a';
            }
            break;
        }
    }
}
/////////// FIM ////////////////

//// FUNÇÃO REMOVER PERGUNTA ///
void remover_pergunta(){
    int indice;
    for(int i = 0; i < MAX_perguntas; i++){
        if(strlen(perguntas[i].enunciado) > 1){
            printf("INDICE %d, pergunta: %s\n", i + 1, perguntas[i].enunciado);
        }
    }

    printf("Remover pergunta do indice: ");
    scanf(" %d", &indice);

    if(strlen(perguntas[indice - 1].enunciado) > 1){    
        strcpy(perguntas[indice - 1].enunciado, "0");
    }

    else{ printf("Nao existe pergunta no indice %d\n", indice);}
}
/////////// FIM ////////////////

//// FUNÇÃO DO MENU ADMIN //////
void menu_admin(){

    bool parar = false;

    while(parar == false){

        int opcao;

        printf("%c%c%c%c%c%c%c%c%c ADMIN %c%c%c%c%c%c%c%c\n", 254, 254, 254, 254, 254, 254,
        254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254);

        printf("[1]Adicionar perguntas\n[2]Remover perguntas\n[3]Sair\n");
        printf("Enter:");
        scanf(" %d", &opcao);

        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 254, 254, 254, 254, 254, 254,
        254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254);

        switch(opcao){
            case 1:
                adicionar_pergunta();
                break;
            case 2:
                remover_pergunta();
                break;
            case 3:
                parar = true;
                break;
            default:
                parar = true;
                break;
        } 
    }
}
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

/////// FUNÇÃO DO QUIZ /////////
void Quiz(int user){ 

    for(int i = 0; i < MAX_perguntas; i++){

        if(strlen(perguntas[i].enunciado) > 1){
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

            printf("%c%c%c%c%c%c%c%c%c QUIZ %c%c%c%c%c%c%c%c%c\n\n", 254, 254, 254, 254, 254, 254,
            254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254);

            if(resp == perguntas[i].resposta){
                printf("%c%c%c Voce acertou!!\n", 175, 175, 175);// Apenas caracteres especiais.
                usuario[user].pontuacao +=5;
            }
            else{
                printf("%c%c%c Voce errou :(\n", 175, 175, 175);// Apenas caracteres especiais.
            }
        }
    }

    printf("\n");   
    printf("Voce completou o Quiz, veja sua pontuacao no menu.\n\n");
    
    menu_usuario();

}
/////////// FIM ////////////////

//// FUNCAO DE BUSCAR USER /////
void busca(char * login, int senha){

    for(int i = 0; i < MAX_users; i++){
        if(senha == usuario[i].senha && strcmp(login, usuario[i].name) == 0){
            Quiz(i);
        }
    }
    printf("Login ou senha errada!\n\n");
}
/////////// FIM ////////////////

///////// FUNCAO LOGIN /////////
void login(){
    char login_user[MAX_nick];
    int login_senha;

    printf("=========Login==========\n");
    printf("Login: ");
    scanf(" %[^\n]", login_user);

    printf("Password: ");
    scanf(" %d", &login_senha);

    printf("========================\n");
    busca(login_user, login_senha);
}
/////////// FIM ////////////////

// Função cadastro do usuário //
void cadastrar_usuario(int user){

    printf("========Cadastro=========\n");
    printf("Digite nome de usuario: ");

    scanf(" %[^\n]", usuario[user].name);

    printf("Digite sua senha (No maximo 4 digitos): ");
    scanf(" %d", &usuario[user].senha);

    printf("=========================\n");
    usuario[user].pontuacao = 0;

    Quiz(user);
}
/////////// FIM ////////////////

//// FUNÇÃO DO MENU USUARIO ////
void menu_usuario(){

    bool parar = false;

    while(parar == false){

        int opcao;
        int n_users;
        if(n_users > MAX_users){ n_users = 0;}
        
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
            int opc;
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
                        n_users++;
                        cadastrar_usuario(n_users);
                        break;
                    case 3:
                        break;
                }
                break;
            case 2:
                printf("========== RANKING ==========\n");
                int i, j;
                Usuario aux;
                for(i = 1; i < MAX_users; i++){
                    aux = usuario[i];
                    for(j = i; j > 0 && (aux.pontuacao > usuario[j - 1].pontuacao); j--){
                        usuario[j] = usuario[j - 1];
                    }
                    usuario[j] = aux;
                }
                for(int k = 0; k < MAX_users; k++){
                    if(strlen(usuario[k].name) > 0){ 
                        printf("%d Lugar: %s %c %d PTS!\n", k + 1, usuario[k].name, 206, usuario[k].pontuacao); 
                    }  
                }
                printf("===============================\n");
                break;
            case 3:
                parar = true;
                break;
            case 2020: // OPÇÃO PARA ACESSAR O MENU DE ADMIN //
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
    perguntas_prontas();
    menu_usuario();
}
