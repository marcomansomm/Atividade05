#include <stdio.h>
#include <pthread.h>

int somaGeral = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *somaGeral (int soma);

int main(void){
	int linha, coluna = 0;

	scanf("%d", linha);
	coluna = linha;

	int matriz[linha][coluna];
	pthread_t threads[linha];

	for(int i = 0; i<linha; i++){
		if(pthread_create(&(threads[i]), NULL, somaGeral, soma)){
			printf("A thread %d não foi criada!", i);
		}
	}

	for(int i = 0; i<coluna; i++){
		for(int j = 0; j<linha; j++){
			scanf("%d", elementos);
			pthread_join(threads[i], NULL);
			soma += elementos;
		}
		soma = 0;
	}

	return 0;
}

void *somaGeral(int soma){
	pthread_mutex_lock(&mutex);
	somaGeral += soma;
	pthread_mutex_unlock(&mutex);

}
