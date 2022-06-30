#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	int numProcessos, numRecursos, i, j, k;
	numProcessos = 5;
	numRecursos = 3;
	int allocation[5][3] = {{0, 1, 0}, //Processo 0 
				{2, 0, 0}, //Processo 1 
				{3, 0, 2}, //Processo 2 
				{2, 1, 1}, //Processo 3 
				{0, 0, 2}}; //Processo 4
							
	int max[5][3] = {{7, 5, 3}, //Necessario para P0 
			{3, 2, 2}, //Necessario para P1
			{9, 0, 2}, //Necessario para P2 
			{2, 2, 2}, //Necessario para P3
			{4, 3, 3}}; //Necessario para P4					
							
	int disponivel[3] = {3, 3, 2};
	
	int f[numProcessos], ans[numProcessos], ind = 0;
	for(k = 0; k < numProcessos; k++){
		f[k] = 0;
	}
	
	int algoritmo[numProcessos][numRecursos];
	for(i = 0; i < numProcessos; i++){
		for(j = 0; j < numRecursos; j++)
			algoritmo[i][j] = max[i][j] - allocation[i][j];
	}
	
	int y= 0;
	for(k = 0; k < 5; k++){
		for(i = 0; i < numProcessos; i++){
			if(f[i] == 0){
				int verification = 0;
				for(j = 0; j < numRecursos; j++){
					if(algoritmo[i][j] > disponivel[j]){
						verification = 1;
						break;
					}
				}
				if(verification == 0){
					ans[ind++] = i;
					for(y = 0; y < numRecursos; y++)
						disponivel[y] += allocation[i][y];
					f[i] = 1;
				}
			}
		}
	}
	
	printf("A sequência segura eh\n");
	for(i = 0; i < numProcessos - 1; i++)
		printf(" Processo%d ->", ans[i]);
	printf(" Processo%d", ans[numProcessos - 1]);
	return 0;
}
