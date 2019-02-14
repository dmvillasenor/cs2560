
#include <stdio.h>

int main() {

	double bill = 88.67;
	double tax = 0.0675;
	double tipPercent = 0.2;

	bill += tax*bill;
	bill += tipPercent*bill;

	printf("Total: $%.2f", bill);

}
