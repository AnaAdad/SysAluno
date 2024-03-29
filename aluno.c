/*Utilizando Estruturas, Vetores, Alocação Dinâmica e demais recursos de C 

Faças as funcionalidades abaixo.
Inclua as funcionalidades:
1 - Add aluno
2 - Listar alunos
3 - Atualizar Aluno
4 - Remover Aluno
5 - Buscar aluno por matricula
6 - Buscar aluno por parte do nome

0 - Sair*/

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

#ifdef _WIN32
  #define CLEAR_SCREEN "cls"
  #else
    #define CLEAR_SCREEN "clear"
#endif

    struct Aluno{
        char matricula[8];
        char nome[50];
        int idade;
    };
    
    //Vetor dinamico para armazenar os dados dos alunos
    struct Aluno *alunos = NULL;
    int totalAlunos=0;
    
   

    void adicionar_aluno(){
        totalAlunos++;
        alunos = (struct Aluno*)realloc(alunos, totalAlunos * sizeof(struct Aluno));
        
        if(alunos == NULL){
            printf("\n\tErro ao tentar alocar memoria!\n");
            exit(EXIT_FAILURE);
        }

       struct Aluno novo_aluno;
       printf("\nDigite a Matrícula do Aluno: ");
       scanf("%49s", novo_aluno.matricula);
       printf("\nDigite o Nome do Aluno: ");
       scanf(" %49s", novo_aluno.nome);
       printf("\nDigite a Idade do Aluno: ");
       scanf("%d", &novo_aluno.idade);
       alunos[totalAlunos - 1] = novo_aluno;
       printf("Aluno adicionado com sucesso! \n");
        
    }

    void listar_alunos(){
        printf("Lista de Alunos:\n");
        for(int i=0;i<totalAlunos;i++){
            printf("\nMatricula: %s, Nome: %s, Idade: %d\n ", alunos[i].matricula, alunos[i].nome, alunos[i].idade);
        }
   
    }

    void atualizar_aluno(){
        char matricula[8];
        printf("Digite a matricula que deseja atualizar: ");
        scanf("%7s",matricula);
        int aluno_encontrado = 0;
        for(int i=0;i<totalAlunos;i++){
           if(strcmp(alunos[i].matricula, matricula) == 0){
              printf("Digite o novo nome do aluno: ");
              scanf("%49s", alunos[i].nome);
              printf("Digite a nova idade do aluno: ");
              scanf("%d", &alunos[i].idade);
              printf("Aluno atualizado com sucesso. \n");
              aluno_encontrado =  1;
              break;
           }
        }

        if (!aluno_encontrado) {
            printf("Não foi encontrado um aluno com essa matrícula.\n");
        }
    }

    void remover_aluno(){
        char  matricula[8];
        printf("Digite a matricula do aluno que deseja remover: ");
        scanf("%7s", matricula);
        int aluno_encontrado = 0;
        for (int i = 0; i < totalAlunos; i++) {
          if (strcmp(alunos[i].matricula, matricula) == 0) {
            for (int j = i; j < totalAlunos - 1; j++){
                alunos[j] = alunos[j + 1];
            }

            totalAlunos --;
            aluno_encontrado =  1;
            printf("Aluno  removido com sucesso!\n");
          }
        }

        if(!aluno_encontrado){
            printf("Nao foi possivel localizar o aluno!\n");
        }
    }

    void procurar_por_matricula(){
        char   matricula[8];
        printf("Digite a matricula do aluno que esta procurando: ");
        scanf("%7s", matricula);
        int aluno_encontrado = 0;
        for (int i = 0; i < totalAlunos; i++) {
          if (strcmp(alunos[i].matricula, matricula) == 0 ){
            printf("Matricula: %s, Nome: %s, Idade:%d\n", alunos[i].matricula, alunos[i].nome, alunos[i].idade);
            aluno_encontrado = 1;
            break;
          }
          
        }

        if (aluno_encontrado) {
            printf("Aluno não encontrado.\n");
        }
    }

        
    

    void procurar_por_nome(){
        char nome[50];
        printf("\nDigite um nome para pesquisa: ");
        scanf("%49s", nome);
        int aluno_encontrado = 0;
        for (int i=0; i<totalAlunos; i++) {
            if (strstr(alunos[i].nome, nome) != NULL) {
                printf("Matricula: %s, Nome: %s, Idade: %d\n", alunos[i].matricula, alunos[i].nome, alunos[i].idade);
                aluno_encontrado = 1;
            }
        }
        if (!aluno_encontrado) {
            printf("O nome %s nao foi encontrado no cadastro.", nome);
        }
    }

    int main(){
        int opcao;
        do{
            printf("\n\nMenu  de Opcoes:\n");
            printf("1- Adicionar Aluno\n");
            printf("2- Listar Alunos\n");
            printf("3- Atualizar Aluno\n");
            printf("4- Remover Aluno\n");
            printf("5- Pesquisar por Matrícula\n");
            printf("6- Pesquisar por Nome\n");
            printf("0- Sair\n");
            scanf ("%d", &opcao);
             void clear(){
        system(CLEAR_SCREEN);
    }
            
            switch(opcao){
                case 1: adicionar_aluno(); 
                break;
                case 2: listar_alunos();  
                break;
                case 3: atualizar_aluno();  
                break;
                case 4: remover_aluno();    
                break;
                case 5: procurar_por_matricula();
                break;
                case 6: procurar_por_nome();
                break;
                case 0: 
                    printf("Saindo...\n");
                break;
                default: printf("Opcao invalida!\n");
            }
        }while(opcao != 0);
        free(alunos);
        return 0;
    }
                 
        
    

           
         