#include <stdio.h>

int main() {
	//Number of shares purchased, cost per share, commission fee
	int numShares = 1000;
	double shareCost = 45.50;
	double commission = 0.02;

	//Stock Cost before commission
	double stockBuy = (numShares*shareCost);
	printf("Stock Purchase Price: $%.2f\n", stockBuy);

	//Stock Cost after commission
	stockBuy += (numShares*shareCost)*commission;

	//Commission Fee paid for stock purchase
	double commFee = (numShares*shareCost)*commission;
	printf("Stock Purchase Fee: $%.2f\n\n", commFee);

	//Cost per share at sale
	shareCost = 56.90;

	//Stock Sale before commission
	double stockSale = (numShares*shareCost);
	printf("Stock Sale Price: $%.2f\n", stockSale);

	//Stock Sale after paying commission.
	stockSale -= stockSale*commission;

	//Commission Fee paid for stock sale
	commFee = (numShares*shareCost)*commission;
	printf("Stock Sale Fee: $%.2f\n\n", commFee);

	//Total Profit after initial investment and stock fees
	double stockProfit = stockSale - stockBuy;
	printf("Total Profit: $%.2f\n", stockProfit);

}
