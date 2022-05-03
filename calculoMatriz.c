#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int somaTotal = 0;
int *elementos;
int tam = 0;
int inicio = 0;
int termino;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *somarLinhas (void *arg);

int main(void){
	int linha = 0, coluna = 0, k = 0;
	
  	printf("Digite aqui o tamanho da sua matriz> ");
	scanf("%d ", &tam);
	
	termino = tam;
	coluna = linha = tam;
	
	int matriz[linha][coluna];

	elementos = malloc(sizeof(int) * (linha * coluna));

	pthread_t threads[tam];

	for(int i = 0; i<tam; i++){
		for(int j = 0; j<tam; j++){
			scanf(" %d", &elementos[k]);
			matriz[i][j] = elementos[j];
			k++;
		}
	}

	for(int i = 0; i<tam; i++){
		if(pthread_create(&(threads[i]), NULL, somarLinhas, NULL)){
			printf("A thread %d não foi criada!", i);
		}
	}

	for(int i = 0; i<tam; i++){
		pthread_join(threads[i], NULL);
	}

	printf("%d", somaTotal);
	return 0;
}

void *somarLinhas(void *arg){
	pthread_mutex_lock(&mutex);
	
	for(int i = inicio; i < termino; i++){
		somaTotal += elementos[i];
	}
	inicio = termino;
	termino += tam;
	
	pthread_mutex_unlock(&mutex);
	return arg;
}
