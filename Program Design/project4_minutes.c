//Joshua Bernard U92651625
//This program takes the given interesting minutes and calculates the average number of minutes a user watches

#include <stdio.h>

//initialization
int find_minute(int *minutes, int n);

int main(){
	//variables
	int numOfMinutes;
	int output;
	int i;

	//gets number of interesting minutes
	printf("Enter the number of interesting minutes: ");
	scanf("%d", &numOfMinutes);

	int allMinutes[numOfMinutes];

	//gets the interesting minutes
	printf("Enter the interesting minutes: ");
	for (i = 0; i < numOfMinutes; i++){
		scanf("%d", &allMinutes[i]);
	}

	//gets the output
	output = find_minute(allMinutes, numOfMinutes);

	//prints the output
	printf("Output: %d\n", output);

	return 0;
}

//calculates the average number of minutes a user watches
int find_minute(int *minutes, int n){
	
	//variables
	int counter = 0;
	int i;
	int a = 0;

	//determines whether it has been 7 minutes since the last interesting minute
	for (i = 1; i <= 45; i++){ 
		if (minutes[a] != i){
			counter++;
			if (counter == 7){
				break;
			}
		}else{
			counter = 0;
			if (a < n){
				a += 1;
			}
		} 	
	}

	if (i > 45)
		i = 45;

	return i;
}
