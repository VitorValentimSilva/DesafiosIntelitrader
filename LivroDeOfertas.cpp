#include <stdio.h>

#define MAX_OFERTAS 100

typedef struct{
    int posicao;
    double valor;
    int quantidade;
} Oferta;

void inserir(Oferta ofertas[], int *numOfertas, int posicao, double valor, int quantidade){
    ofertas[*numOfertas].posicao = posicao;
    ofertas[*numOfertas].valor = valor;
    ofertas[*numOfertas].quantidade = quantidade;
    (*numOfertas)++;
}

void modificar(Oferta ofertas[], int numOfertas, int posicao, double valor, int quantidade){
    for (int i = 0; i < numOfertas; i++) {
        if (ofertas[i].posicao == posicao) {
            ofertas[i].valor = valor;
            ofertas[i].quantidade = quantidade;
            return;
        }
    }
}

void deletar(Oferta ofertas[], int *numOfertas, int posicao){
    for (int i = 0; i < *numOfertas; i++) {
        if (ofertas[i].posicao == posicao) {
            for (int j = i; j < *numOfertas - 1; j++) {
                ofertas[j] = ofertas[j + 1];
            }
            (*numOfertas)--;
            return;
        }
    }
}

int main(){
    Oferta ofertas[MAX_OFERTAS];
    int numOfertas = 0;
	int numNotificacoes;
	
    printf("Digite o numero de notificacoes que deseja: \n");  
    scanf("%d", &numNotificacoes);

    

    for (int i = 0; i < numNotificacoes; i++) {
        int posicao, acao, quantidade;
        double valor;
        
        printf("Digite a notificao %d no formato posicao,acao,valor,quantidade: \n", i+1);
    	printf("Acao: 0-Inserir, 1-Modificar, 2-Deletar \n");
        scanf("%d,%d,%lf,%d", &posicao, &acao, &valor, &quantidade);

        switch (acao) {
            case 0:
                inserir(ofertas, &numOfertas, posicao, valor, quantidade);
                break;
            case 1:
                modificar(ofertas, numOfertas, posicao, valor, quantidade);
                break;
            case 2:
                deletar(ofertas, &numOfertas, posicao);
                break;
        }
    }

    printf("Livro de ofertas final:\n");
    for (int i = 0; i < numOfertas; i++) {
        printf("%d,%.2f,%d\n", ofertas[i].posicao, ofertas[i].valor, ofertas[i].quantidade);
    }

    return 0;
}
