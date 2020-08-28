#include <stdio.h>
#include <stdlib.h>





int main(){

	int i = 1;
	for (; i <= 5000; i++){
		printf("Numero: %d \n", i );
	}
	return 0;
}





for()
 
void swap(int vetor[], int pos_i, int pos_j) {
  int aux;
  aux = vetor[pos_i]; 
  vetor[pos_i] = vetor[pos_j]; 
  vetor[pos_j] = aux;
}



int verificaCombinacao(int linhas[], int totalRainhas){
  int i;
  int coluna_atual,linha_atual;
  
  for(i = 0; i < totalRainhas; i++){
    coluna_atual = i;
    linha_atual = linhas[i];
 
    int coluna_frente = coluna_atual;
    int linha_acima = linha_atual;
    while(1){
      coluna_frente += 1;
      linha_acima -= 1;
      if(coluna_frente > (totalRainhas-1) || linha_acima < 0) break;
       
      if(linha_acima == linhas[coluna_frente]) 
        return 0;
    }
 
    int coluna_anterior = coluna_atual;
     linha_acima = linha_atual;
    while(1){
      coluna_anterior -= 1;
      linha_acima -= 1;
      if(coluna_anterior < 0 || linha_acima < 0) break;
       
      if(linha_acima == linhas[coluna_anterior]) 
        return 0;
    }
  }
  return 1;
}

void ImprimeSolucao(int linhas[], int totalRainhas){
  char tabuleiro[totalRainhas][totalRainhas];
  int i,j;
  int x,y;
  static int contSolucao = 0;
 
  contSolucao++;
 
  printf("---------------- Solução num: %d \n",contSolucao);
 
  for(i = 0; i < totalRainhas; i++)
    for(j = 0; j < totalRainhas; j++)
      tabuleiro[i][j] = '.';
 
  for(i = 0; i < totalRainhas; i++){
    x = i;
    y = linhas[i];
    tabuleiro[y][x] = 'R';
  }
 
  for(i = 0; i < totalRainhas; i++){
    for(j = 0; j < totalRainhas; j++){
      printf(" %c ",tabuleiro[i][j]);
    }    
    printf("\n");
  }
}




void TestaPermutacoes(int linhas[], int rainhaAtual, int totalRainhas) {
  int i;
   
  if(rainhaAtual == totalRainhas) {
    if(verificaCombinacao(linhas,totalRainhas))
      ImprimeSolucao(linhas, totalRainhas);
  }
  else{
    for(i = rainhaAtual; i < totalRainhas; i++) {
      swap(linhas, rainhaAtual, i);
      TestaPermutacoes(linhas, rainhaAtual + 1, totalRainhas);
      swap(linhas, i, rainhaAtual);
    }
  }
}

void oitoRainhas(int qtdRainhas) {
  int linhas[qtdRainhas];
  int i;
  for(i = 0; i < qtdRainhas; i++)
    linhas[i] = i;
  
  TestaPermutacoes(linhas, 0, qtdRainhas);
}


int main(){
  int qtdRainhas;
  printf("Informe a quantidade de rainhas \n");
  scanf("%d",&qtdRainhas);
  oitoRainhas(qtdRainhas);
  return 0;
}