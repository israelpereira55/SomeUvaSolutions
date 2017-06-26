#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F 0.5
#define N 40
#define MAX1 150

/* The metaheuristic Differential Evolution was implemented to solve this problem.
 * The crossover was not necessary to be coded because the population has just one
 * dimension.
 * For further details about DE, see: "Differential Evolution – A Simple and Efficient
 * Heuristic for Global Optimization over Continuous Spaces" (Rainer Storn, Kenneth Price) 1997.
 */

int p, q, r, s, t, u;

double calcula(double mut){
	double x = p * exp(-mut) + q * sin(mut) + r * cos(mut) + s * tan(mut) + t * mut * mut + u;
	if(x < 0){
		x = -x;
	}
	return x;
}

int main(){
	double geracao[N];
	
	int i;
	int r1, r2, r3;
	
	double mut, fit, orig;
	double melhor = 0, mx;
	int it;
	
	while( scanf("%d %d %d %d %d %d\n", &p, &q, &r, &s, &t, &u) != EOF ){
		 
		for (i = 0; i < N; i++){
			geracao[i] = (double) rand()/RAND_MAX;
		}
	
		melhor = 2;
		it = 0;
		while(it < MAX1 && melhor > 0.00000001){ 
			for(i = 0; i < N; i++){
				do{ r1 = rand() % N; }while(r1 == i);
				do{ r2 = rand() % N; }while(r2 == r1 || r2 == i);
				do{ r3 = rand() % N; }while(r3 == r2 || r3 == r1 || r3 == i);
			
				mut = geracao[r1] + F * (geracao[r2] - geracao[r3]);
				fit = calcula(mut);
				orig = calcula(geracao[i]);
			
				if(fit < orig){
					geracao[i] = mut;
				
					if(fit < melhor && mut <= 1 && mut >= 0) melhor = fit, mx = geracao[i];
				}
			
			
			}
			it++;
		}
		
		if(it == MAX1){
			printf("No solution\n");
		} else  printf("%.4lf\n", mx);
	}			
			
	return 0;
}	
