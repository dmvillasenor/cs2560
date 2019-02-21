#include <stdio.h>

int revArray[];
int *reverseArray(int oldArray[], int length){
	//int size = newArray[].length;

	revArray[length];
	int indexOfOldArray = length - 1;
	for(int i = 0; i < length; i++){
		revArray[i] = oldArray[indexOfOldArray];

		indexOfOldArray--;
	}

	return revArray;
}

int main(void) {
	int length = 3;
	int array[3] = {1,2,3};


	printf("Array Before\n");
	for(int i = 0; i < length; i++){
		printf("Element %d: %d\n", i, array[i]);
	}

	int *revArray;
	revArray = reverseArray(array, 3);

	printf("\nArray After\n");
	for(int i = 0; i < length; i++){
		printf("Element %d: %d\n", i, *(revArray + i));
	}

}
