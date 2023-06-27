#include <stdio.h>
//Joshua Bernard U92651625
//This program checks the conditions of the given array

//initialization
void selection_sort(int a[], int e);
int find_largest(int a[], int e);


//main function
int main(void){

	//variables
        int i, n, test = 1;
        
	//gets length
        printf("Enter the length of the input array: ");
        scanf("%d", &n);
        int array[n], new_array[n];
        
	//gets array elements
        printf("Enter the array elements: ");
        for (i = 0; i < n; i++)
                scanf("%d", &array[i]);

	//creates duplicate array to compare
        for (i = 0; i < n; i++)
                new_array[i] = array[i];

	//calls selection_sort function to sort new_array 
        selection_sort(new_array, n);

	//checks if given array is in order
        for ( i = 0; i < n; i++){
		if (array[i] == new_array[i])
			continue;
		else
			test = 0;
			break;
	}
	
	//checks if i is divisible by i-1
	if (test){
		for ( i = 1; i < n; i++){
		        if (array[i] % array[i - 1] != 0){
				continue;
			}
			else{
                    		test = 0;
			        break;
			}
		}
	}
	
	//checks if given array meets the conditions
	if (test)
		printf("Output: yes");
        else
        	printf("Output: no");

return 0;
}


//function to sort an array
void selection_sort(int a[], int e){

        int largest = 0, temp;
        if (e == 1)
                return;

        largest = find_largest(a, e);

        temp = a[e - 1];
        a[e - 1] = a[largest];
        a[largest] = temp;

        selection_sort(a, e - 1);

}

//function to find largest digit in array to use in selection_array
int find_largest(int a[], int e){

        int i, index_largest = 0;
        for (i = 1; i < e; i++)
                if (a[i] > a[index_largest])
                        index_largest = i;
        return index_largest;
}
