
#include <stdio.h>

int main() {

	double bill = 88.67;
	double tax = 0.0675;
	double tipPercent = 0.2;

	printf("Meal Cost: %.2f\n", bill);
	printf("Tax: %0.2f\n", tax*bill);

	bill += tax*bill;

	printf("Tip Amount: %.2f\n", tipPercent*bill);

	bill += tipPercent*bill;


	printf("Total: $%.2f", bill);

}
