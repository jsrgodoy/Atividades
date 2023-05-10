#include <stdio.h>// Biblioteca padrão
#include <stdlib.h>// Biblioteca para alocação de memória
#include <string.h> // Biblioteca para manipulação de strings
#include <locale.h> // Referencia de biblioteca para usar acentuação gráfica 

  //para iniciar uma lista
typedef struct no {
  char nome[20];
  float nota;
  int turma;
  struct no *anterior;
  struct no *proximo;
} No;

//procedimento para inserir no inicio
void inserir_no_inicio(No **lista, char nome[], float nota, int turma) {
  No *novo = malloc(sizeof(No)); // para alocar memória
    if(novo){// para informar se a memória não foi alocada
    strcpy(novo->nome, nome); // para armazenar uma string literal em uma variável
    novo->nota = nota;
    novo->turma = turma;
    novo->proximo = *lista;
    novo->anterior = NULL;
    if(*lista) 
      (*lista)->anterior = novo;
    *lista = novo;
  }
  else
    printf("Erro ao alocar memória!\n");
}

//procedimento para inserir no fim
void inserir_no_fim(No **lista, char nome[], float nota, int turma) {
  No *aux, *novo = malloc(sizeof(No));

  if(novo){
    strcpy(novo->nome, nome); //para manipulação de strings
    novo->nota = nota;
    novo->turma = turma;
    novo->anterior = *lista;
    novo->proximo = NULL;
    
    //é o primeiro?
    if(*lista == NULL) {
      *lista = novo;
    novo->anterior = NULL;
  } 
    else{
      aux = *lista;
      while(aux->proximo != NULL)
        aux = aux->proximo;
      aux->proximo = novo;
      novo->anterior = aux;
    }
  }
  else
    printf("Erro ao alocar memória!\n");
}

  //procedimento para inserir no meio
  void inserir_no_meio(No **lista, char nome[], float nota, int turma, char ant[]) {
    No *aux, *novo = malloc(sizeof(No));

    if(novo) {
      strcpy(novo->nome, nome);
      novo->nota = nota;
      novo->turma = turma;
          
      // é o primeiro no?
      if (*lista == NULL) {
        novo->proximo = NULL;
        novo->anterior = NULL;
        *lista = novo;
      }
      else{
        aux = *lista; //strcmp usado para comparação de strings
            while(aux && strcmp(aux->nome, ant) != 0)
                aux = aux->proximo;
            if(aux){
                novo->proximo = aux->proximo;
                if(aux->proximo)
                    aux->proximo->anterior = novo;
                novo->anterior = aux;
                aux->proximo = novo;
            }
            else{
                printf("Nó anterior não encontrado!\n");
                free(novo);
            }
      }
    }
    else
      printf("Erro ao alocar memória!\n");
  }

// remover lista

No* remover(No **lista, char nome_excluir[]) {
  No *aux, *remover = NULL;

  if(*lista){//strcmp usado para comparação de strings
    if(strcmp((*lista)->nome, nome_excluir) == 0) {
      remover = *lista;
      *lista = remover->proximo;
      if (*lista)
        (*lista)->anterior = NULL;
    }
    else{
      aux = *lista;
      while(aux->proximo && strcmp(aux->proximo->nome, nome_excluir) != 0) {
        aux = aux->proximo;
      }
      if(aux->proximo){
        remover = aux->proximo;
        aux->proximo = remover->proximo;
        if(aux->proximo){
          aux->proximo->anterior = aux;
        }
      }
    }
  }

return remover;
}


//imprimir e testar lista

void imprimir(No *no) {
  printf("\n\t<> LISTA DE ALUNOS <>\n");
  while(no){
    printf("\n****************************");
    printf("\nNome:  %s ", no->nome);
    printf("\nNota:  %.2f ", no->nota);// limitar em 2 casas decimais
    printf("\nTurma: %d ", no->turma);
    printf("\n****************************\n");
    no = no->proximo;
  }
printf("\n\n");
}

//Função para retornar o ponteiro para o último nó

No* ultimo(No **lista) {  
No *aux = *lista;
  while(aux->proximo)
    aux = aux->proximo;
  return aux;
}
 // imprimir ao contrário

void imprimir_contrario(No *no) {
printf("\n\t<> LISTA DE ALUNOS INVERSA <>\n");
  while(no){
  printf("\n****************************");
    printf("\nNome:  %s ", no->nome);
    printf("\nNota:  %.2f ", no->nota);
    printf("\nTurma: %d ", no->turma);
    printf("\n****************************\n");
    no = no->anterior;
  }
}
  
int main() {
  setlocale (LC_ALL,"");// Referencia de biblioteca para usar acentuação gráfica 
printf("\n\tAtividade de Produção Estrutura de Dados\nAluno: Jeferson da Silveira Rosa - Matrícula 202221001\n");

  printf("\n\t***** CADASTRO DE ALUNOS *****\n");

  char nome[20], anterior[20];
  int opcao, nota, turma;
  No *removido, *lista = NULL;

  do {
  printf("\n\t1 - Inserir no Início\n\t2 - Inserir no Fim\n\t3 - Inserir no Meio\n\t4 - Remover\n\t5 - Imprimir\n\t6 - Imprimir inverso\n\t0 - Para Sair\n");
    scanf("%d", &opcao);
    
    switch(opcao){
    case 1:
       printf("\n>> Digite o nome do Aluno(a) para Cadastro: ");
            scanf("%s", nome);
            printf("\n>> Digite a nota do Aluno(a): ");
            scanf("%d", &nota);
            printf("\n>> Digite a turma do Aluno(a): ");
            scanf("%d", &turma);
            inserir_no_inicio(&lista, nome, nota, turma);
            system("clear");
            printf("\n>> Aluno(a) %s cadastrado(a) com sucesso! >>. \n\n", nome);
    break;
    
    case 2:
printf("\n>> Digite o nome do Aluno(a) para Cadastro: ");
            scanf("%s", nome);
            printf("\n>> Digite a nota do Aluno(a): ");
            scanf("%d", &nota);
            printf("\n>> Digite a turma do Aluno(a): ");
            scanf("%d", &turma);
            inserir_no_fim(&lista, nome, nota, turma);
            system("clear");
            printf("\n>> Aluno(a) %s cadastrado(a) com sucesso! >>. \n\n", nome);      
    break;
    
    case 3:
      printf("\n>> Digite o nome do Aluno(a) para Cadastro: ");
            scanf("%s", nome);
            printf("\n>> Digite a nota do Aluno(a): ");
            scanf("%d", &nota);
            printf("\n>> Digite a turma do Aluno(a): ");
            scanf("%d", &turma);
            printf("\n>> Digite o Aluno(a) anterior: ");
            scanf("%s", anterior);
            inserir_no_meio(&lista, nome, nota, turma, anterior);
            system("clear");
            printf("\n>> Aluno(a) %s cadastrado(a) com sucesso! >>. \n\n", nome);
    break;

    case 4:
       printf("\n>> Digite o nome do Aluno(a) que deseja remover: ");
      scanf("%s", nome);
      removido = remover(&lista, nome);
        if(removido) {
        printf("\n>> Aluno(a) %s removido(a) com sucesso\n", removido->nome);
        free(removido);
        }
    break;
    
    case 5:
      imprimir(lista);
    break;
    
    case 6:
      imprimir_contrario(ultimo(&lista));
      
    break;
    
      default: 
      if(opcao != 0)
        printf("\nOpção inválida!\n");
}
  } while(opcao != 0);

  return 0;
}
    