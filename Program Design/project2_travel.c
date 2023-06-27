#include <stdio.h>
//Joshua Bernars U92651625
//This program calculates how many days it would take for spacecraft B to pass spacecraft A

int main(){

	//variables
	int initA;
	int initB;
	int newA;
	int newB;
	int numCases;
	int currentCase = 0;
	int numDays = 0;

	//gets the number of cases 
	printf("Number of cases: ");
	scanf("%d", &numCases);

	//calculates how long it would take for B to pass A for each case
	for(int i = 1; i <= numCases; ++i){
		currentCase = currentCase + 1;
		printf("Speed of A: ");
		scanf("%d", &initA);
		printf("Speed of B: ");   
                scanf("%d", &initB);
		
		while(initB <= initA) {
			if(numDays == 0){
				numDays = numDays + 1;
				newA = initA * 2;
				newB = initB * 3;
				if(newB > newA)
					break;
				continue;
			}else{
				numDays = numDays + 1;
				newA = newA * 2;
				newB = newB * 3;
				if(newB > newA)
					break;
				continue;
			} 		

		}

		//prints details for each case
		printf("Case #%d: %d day(s)\n", currentCase, numDays);
		numDays = 0;
	
	}


return 0;
}
