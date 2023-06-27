#include <stdio.h>
#include <string.h>

//Joshua Bernard U92651625
//This program reads a file, sorts each line based on the totalScore, and prints it to a new file

//structure for coffee
struct coffee{

    char country[150];
    char region[150];
    char owner[150];
    char variety[150];
    double totalScore;

};
//initialization
void selection_sort_coffee(struct coffee list[], int n);

int main(){

    //creates a structure array
    struct coffee list[100];

    //variables
    char inputFile[50];
    char outputFile[50] = {"sorted_"};
    char line[100];
    int count = 0;
    int i;

    //gets read file and write file names
    printf("Enter the file name: ");
    scanf("%s", &inputFile);
    strcat(outputFile, inputFile);
    printf("Output file name: \n");
    printf("%s", outputFile);

    //opens read file
    FILE *file = fopen(inputFile, "r");

    //scans each line into list sctructure array
    while(fgets(line, sizeof(line), file) != NULL && count < 100){
        fscanf(file, "%[^,],%[^,],%[^,],%[^,], %lf", list[count].country, list[count].region, list[count].owner, list[count].variety, &list[count].totalScore);
        count++;
    }

    //closes read file
    fclose(file);

    //sorts structure array based on totalScore
    selection_sort_coffee(list, count - 1);

    //opens write file
    FILE *newFile = fopen(outputFile, "w");

    //prints each line to write file
    for(i = count - 2; i > -1; i--){
        if(list[i].totalScore == 0)
            continue;
        fprintf(newFile, "%s, %s, %s, %s, %.2f\n", list[i].country, list[i].region, list[i].owner, list[i].variety, list[i].totalScore);
    }

    //closes write file
    fclose(newFile);

    return 0;
}

//sorts the structure array
void selection_sort_coffee(struct coffee list[], int n){

    int i, largest = 0;
    struct coffee temp;

    if (n == 1)
        return;

    for (i = 1; i < n; i++)
        if (list[i].totalScore > list[largest].totalScore)
            largest = i;

    if (largest < n - 1){
        temp = list[n-1];
        list[n-1] = list[largest];
        list[largest] = temp;
    }

    selection_sort_coffee(list, n - 1);
}