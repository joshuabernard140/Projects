#include <stdio.h>
//Joshua Bernard U92651625
//This program finds the checksum of the given integer

//function declaration
long int checksum(long int num,long int new_num,long int final_num);

//main function
int main(){

	long int input;

	//gets the given integer
	printf("Input: ");
	scanf("%ld", &input);

	//gets the checksum
	long int a = checksum(input, 0, 0);
	printf("Checksum: %ld", a); 




return 0;
}

//calculates the checksum
long int checksum(long int num,long int new_num,long int final_num){

	new_num = num; 
	new_num = new_num % 10;
	num = num / 10;
	
	if (num > 9){
		final_num = final_num + new_num;
		final_num = checksum(num, 0, final_num); 
	}else{
		final_num = final_num + new_num + num;
	}

	if (final_num > 9){
		checksum(final_num, 0, 0);
	}else{;
		return final_num;
	}

}
