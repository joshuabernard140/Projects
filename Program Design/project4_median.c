//Joshua Bernard U92651625
//This program finds the median value of a given array and determines how mnay values are equal to it

#include <stdio.h>

//function declarations
int compute_median(int *a, int n);
void selection_sort(int a[], int n);
int find_largest(int a[], int n);

int main(void){

	int i;
	int arraySize;
	int final;

	//gets array size
	printf("Enter array size: ");
    scanf("%d", &arraySize);

	int a[arraySize];

	//gets elements in array
	printf("Enter array elements: ");
	for (i = 0; i < arraySize; i++)
		scanf("%d", &a[i]);

	//sorts the array
	selection_sort(a, arraySize);

	//determines how manhy values equal the median
	final = compute_median(a, arraySize);
	printf("Output: %d", final);

	return 0;
}

//finds the median value and how manhy values equal it
int compute_median(int *a, int n){

    int *array = a;
    int median = (n + 1) / 2;
    int totalMedian = 0;
	int i;

    for (i = 0; i < n; i++)
		if (*(array + median - 1) == *(array + i))
			totalMedian += 1;

    return totalMedian;
}
     
void selection_sort(int a[], int n){

	int largest = 0, temp;
	//stopping condition
	if (n == 1)
		return;

	//find the index of the largest element
	largest = find_largest(a, n);

	//swap largest element with the last element
	temp = a[n - 1];
	a[n - 1] = a[largest];
	a[largest] = temp;

	//call selection_sort recursively
	selection_sort(a, n - 1);

}

//finds largest value in array for sorting
int find_largest(int a[], int n){

	int i, index_largest = 0;
	for (i = 1; i < n; i++)
		if (a[i] > a[index_largest])
			index_largest = i;
	return index_largest;
}

