#include <stdio.h>

int main() {

	double riseRate = 1.5;
	double seaLvl = 0;

	for(int i = 1; i <= 10; i++){
		seaLvl += riseRate;
		if(i == 5 || i == 7 || i == 10){
			printf("Sea level after %d years: %.1fmm\n", i, seaLvl);
		}
	}
}
