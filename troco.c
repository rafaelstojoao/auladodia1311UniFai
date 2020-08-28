#include <stdio.h>

int main(){

	int moedas[] 	= {1,4,6};
	int solucao[10];
	int troco 		= 8;
	int somaMoedas 	= 0;
	int qtdMoedas 	= 0;
	int moedaUsada 	= 2;


		while(moedaUsada>=0 || somaMoedas != troco){	
			if (somaMoedas + moedas[moedaUsada] > troco ){
				moedaUsada--;
			}
			else if(somaMoedas + moedas[moedaUsada] <= troco ){
				somaMoedas += moedas[moedaUsada];
				qtdMoedas++;
				printf(" Incluindo a moeda %d no troco \n", moedas[moedaUsada]);
			}	
	}
	printf("Total do troco: %d\n",somaMoedas );
	printf("Total de moedas utilizadas: %d\n", qtdMoedas );
	return 0;
}