#include <stdio.h>

int main() {

	for(int i = 1; i <= 10; i++){
		for( int j = 0; j < i; j++){
			printf("+ ");
		}
		printf("\n");
	}

	for(int i = 10; i >= 1; i--){
		for( int j = 0; j < i; j++){
			printf("+ ");
		}
		printf("\n");
	}
}
