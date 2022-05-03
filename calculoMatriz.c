#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int somaTotal = 0;
int *elementos;
int linha = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *somarLinhas (void *arg);

int main(void){
	int linha = 0, coluna = 0;

  	printf("Digite aqui o tamanho da sua matriz> ");
	scanf("%d ", &linha);
	coluna = linha;

	int matriz[linha][coluna];

	elementos = malloc(sizeof(int) * linha);

	pthread_t threads[linha];

	for(int i = 0; i<linha; i++){
		if(pthread_create(&(threads[i]), NULL, somarLinhas, NULL)){
			printf("A thread %d não foi criada!", i);
		}
	}

	for(int i = 0; i<coluna; i++){
		for(int j = 0; j<linha; j++){
			scanf(" %d", &elementos[j]);
			matriz[i][j] = elementos[j];
		}
		pthread_join(threads[i], NULL);
	}
	
	printf("O total da soma das linha foi: %d", somaTotal);

	return 0;
}

void *somarLinhas(void *arg){
	pthread_mutex_lock(&mutex);
	for(int i = 0; i < linha; i++){
		somaTotal += elementos[i];
	}
	printf("%d", somaTotal);
	pthread_mutex_unlock(&mutex);
}