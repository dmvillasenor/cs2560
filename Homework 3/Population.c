#include <stdio.h>

int rateInput(){
	int value;
	int positive = 0;
	while(positive == 0){
		scanf("%d", &value);
		if( value <= 0){
			printf("Input a positive number for rate");
		}
		else {
			positive = 1;
		}
	}
	return value;
}

int populationInput(){
	int value;
	int greaterTwo = 0;

	while(greaterTwo == 0){
		scanf("%d", &value);
		if(value < 2){
			printf("Please input a number >= 2");
		}
		else{
			greaterTwo = 1;
		}
	}
	return value;
}

int populationCalc(int pop, int bRate, int dRate){
	//N = P + BP - DP
	int newPop = pop + (bRate * pop) - (dRate * pop);
	return newPop;
}
int main() {

	printf("Input the population size");
	int population = populationInput();

	printf("Input the birth rate");
	int birthRate = rateInput();

	printf("Input the death rate");
	int deathRate = rateInput();

	printf("Input the number of years");
	int numYears = rateInput();


	for( int i = 0; i < numYears; i++){
		population = populationCalc(population, birthRate, deathRate);
	}

	printf("Final Pop Size: %d", population);


}
