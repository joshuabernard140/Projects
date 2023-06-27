#include <stdio.h>
// Joshua Bernard U92651625
// This program takes hours and the number of people and calculates the total cost of selected package.
int main()
{

	//variables
	int package_num = 0;
	int hours = 0;
	int people_num = 0;
	int charge = 0;


	//gets the package number
	printf("Please select from three packages: 1, 2, and 3\n");
	printf("Enter package selection: ");
	scanf("%d", &package_num);


	//handles package 1
	if (package_num == 1)
	{
		//gets the hours
		printf("Enter hours: "); 
		scanf("%d", &hours);	
		if (hours < 1)
		{
			printf("Invalid input. Enter a positive number less than or equal to 4 for number of hours.\n");
			return 0;
			}	
		else if (hours > 4)
		{
			printf("Invalid input. Enter a positive number less than or equal to 4 for number of hours.\n");
			return 0;
			}
		else 
			//gets number of people
			printf("Enter number of people: ");
			scanf("%d", &people_num);
			if (people_num < 50)
			{
				printf("Not meeting minimum requirement for number of guests.\n");
				return 0;
				}
			else if (people_num > 200)
			{
				printf("Exceeded maximum number of guests.\n");
				return 0;
				}
			else
				//calculates total charge
				if (hours == 1)
					charge = (50 + (people_num * 25));
				else if (hours == 2)
					charge = (75 + (people_num * 25));
				else
					charge = (95 + (people_num * 25));
				//prints total charge
				printf("Charge($): $%d\n", charge);
	return 0;
	}


	//handles package 2
	//same code as package 1 but different numbers
	if (package_num == 2)
	{
		printf("Enter hours: "); 
		scanf("%d", &hours);	
		if (hours < 1)
		{
			printf("Invalid input. Enter a positive number less than or equal to 4 for number of hours.\n");
			return 0;
			}	
		else if (hours > 4)
		{
			printf("Invalid input. Enter a positive number less than or equal to 4 for number of hours.\n");
			return 0;
			}
		else 
			printf("Enter number of people: ");
			scanf("%d", &people_num);
			if (people_num < 80)
			{
				printf("Not meeting minimum requirement for number of guests.\n");
				return 0;
				}
			else if (people_num > 300)
			{
				printf("Exceeded maximum number of guests.\n");
				return 0;
				}
			else
				if (hours == 1)
					charge = (30 + (people_num * 22));
				else if (hours == 2)
					charge = (45 + (people_num * 22));
				else
					charge = (55 + (people_num * 22));
				printf("Charge($): $%d\n", charge);
	return 0;
	}


	//handles package 3
	//same code as package 1 but different numbers
	if (package_num == 3)
	{
		printf("Enter hours: "); 
		scanf("%d", &hours);	
		if (hours < 1)
		{
			printf("Invalid input. Enter a positive number less than or equal to 4 for number of hours.\n");
			return 0;
			}	
		else if (hours > 4)
		{
			printf("Invalid input. Enter a positive number less than or equal to 4 for number of hours.\n");
			return 0;
			}
		else 
			printf("Enter number of people: ");
			scanf("%d", &people_num);
			if (people_num < 30)
			{
				printf("Not meeting minimum requirement for number of guests.\n");
				return 0;
				}
			else if (people_num > 1500)
			{
				printf("Exceeded maximum number of guests.\n");
				return 0;
				}
			else
				if (hours == 1)
					charge = (20 + (people_num * 20));
				else if (hours == 2)
					charge = (32 + (people_num * 20));
				else
					charge = (40 + (people_num * 20));
				printf("Charge($): $%d\n", charge);
	return 0;
	}	


	//handles invalid package inputs
	if (package_num > 3)
		printf("Invalid selection. Select from 1 to 3.\n");
	else
		printf("Invalid selection. Select from 1 to 3.\n");	


return 0;
}
