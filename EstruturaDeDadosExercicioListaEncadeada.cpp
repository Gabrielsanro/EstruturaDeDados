#include <stdio.h>
#include <stdlib.h>

//ALUNO: GABRIEL SANTOS ROCHA
//DISCIPLINA: ESTRUTURA DE DADOS I
//PROFESSOR: WALACE BONFIM


typedef struct elementos {
    char nome[50];
} t_elemento;

typedef struct no {
    t_elemento dado;
    struct no * prox;
} t_no;

typedef struct fila {
    t_no* inicio;
    int quant_element;
    t_no* final;
} t_fila;

t_fila * criaCabeca ()
{
    t_fila * fila = (t_fila*) malloc(sizeof(t_fila));

    if (fila) {
        fila->inicio = fila->final = NULL;
        fila->quant_element=0;
    }

    return fila;
}

t_no * criaNo() {
    t_no * no = (t_no*) malloc(sizeof(t_no));

    if (no)
        no->prox = NULL;

    return no;
}

int isVazia (t_fila * fila)
{
    return (fila->quant_element == 0);
}

int inserir (t_fila * fila, t_elemento valor) {
    t_no *novo;
    novo = criaNo();
    if (novo == NULL)
        return 0;
    novo->dado = valor;
    if (isVazia(fila))
        fila->inicio = novo;
    else
        (fila->final)->prox = novo;
    fila->final = novo;
    fila->quant_element++;
    return 1;
}

t_elemento remover (t_fila *fila)
{
    t_no *aux;
    t_elemento valor = { "" } ;
    if (isVazia(fila))
        return valor;
    valor = (fila->inicio)->dado;
    if (fila->inicio == fila->final)
        fila->final = NULL;
    aux = fila->inicio;
    fila->inicio = (fila->inicio)->prox;
    free(aux);
    fila->quant_element--;
    return valor;
}

void exibirInfo(t_elemento info){
    printf("Nome: %s\n", info.nome);
}
void imprimirFila(t_fila *fila){
    if(isVazia(fila1) == 1){
        perror("Fila vazia");
    }{
        t_no * aux = fila->inicio;
        do{
            exibirInfo(aux->dado);
            aux = aux->prox;
        }while(aux !=fila->inicio);
    }
}

void esvaziar(t_fila * fila){
	fila->inicio = NULL;
	fila->final = NULL;
}

int cabecalho(){

    int opcao;

    printf("1 - Criar uma fila\n");
    printf("2 - Ver se a fila esta vazia\n");
    printf("3 - Inserir um elemento na fila\n");
    printf("4 - Remover um elemento da fila\n");
    printf("5 - Exibir um elemento da fila\n");
    printf("6 - Esvaziar a fila\n");
    printf("Escolha uma opcao!: ");
    scanf("%d", &opcao);

    return opcao;
}

int main (){

    int opcao;
    int auxiliar;
    int i;

    t_elemento valor1;
    t_fila * fila1 = criaCabeca();

    while(1){

        opcao = cabecalho();

        switch(opcao){
            case 1:
				printf("Fila criada\n");
                break;
            case 2:
                if(isVazia(fila1) == 1) printf("A fila esta vazia\n");
                else printf("a fila nao esta vaiza\n");
                break;
            case 3:
                printf("informe uma elemento: "); scanf("%s", &valor1.nome);
                auxiliar = inserir(fila1, valor1);
                if(auxiliar) printf("Inserido com sucesso!\n");
                else printf("Falha ao inserir!\n");
                break;
            case 4:
                valor1 = remover(fila1);
                printf("O valor removido foi: %s\n", valor1.nome);
                break;
            case 5:
                imprimirFila(fila1);
                break;
            case 6:
            	esvaziar(fila1);
                break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
