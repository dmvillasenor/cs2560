#include <stdio.h>

double Circle(){

	printf("Input Radius");
	double radius;
	scanf ("%lf", &radius);

	double area = 3.14159 * radius * radius;

	return area;
}

double Rectangle(){

	printf("Input Length");
	double length;
	scanf ("%lf", &length);

	printf("Input Width");
	double width;
	scanf ("%lf", &width);

	double area = width * length;

	return area;
}

double Triangle(){


	printf("Input Base");
	double base;
	scanf ("%lf", &base);

	printf("Input Height");
	double height;
	scanf ("%lf", &height);

	double area = 0.5 * base * height;

	return area;

}

int main() {
	int cont = 1;
	while(cont == 1){
		printf("1. Calculate the Area of a Circle\n"
				"2. Calculate the Area of a Rectangle\n"
				"3. Calculate the Area of a Triangle\n"
				"4. Quit\n");
		int response;
		scanf ("%d", &response);

		switch(response){

		case 1:
			printf("\nArea: %.2f\n\n", Circle());
			break;

		case 2:
			printf("\nArea: %.2f\n\n", Rectangle());
			break;

		case 3:
			printf("\nArea: %.2f\n\n", Triangle());
			break;

		case 4:
			cont = 0;
			break;

		default:
			printf("Response must be 1-4");

		}
	}
}
