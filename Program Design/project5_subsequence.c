#include <stdio.h>

//Joshua Bernard U92651625
//This program determines of the first word is a subsequence of the second word

int main(){

        //variables
	int i;
	int a;
        int length1 = 0;
        int length2 = 0;
	char word1[1001];
	char word2[1001];

        //gets the two words
	printf("Enter first word: ");
	scanf("%s", word1);
	printf("Enter second word: ");
        scanf("%s", word2);

        //converts all uppercase letter to lowercase
        for(i = 0; word1[i]; i++){
                if(word1[i] >= 'A' && word1[i] <= 'Z'){
                word1[i] += 32;
                }
        }
        for(i = 0; word2[i]; i++){
                if(word2[i] >= 'A' && word2[i] <= 'Z'){
                word2[i] += 32;
                }
        }

        //gets the length of each word
        while (word1[length1] != '\0'){
                length1++;
        }
        while (word2[length2] != '\0'){
                length2++;
        }

        //determines of word1 is subsequence of word2
        for (i = 0, a = 0; i < length2 && a < length1; i++){
                if (word1[a] == word2[i]) {
                a++;
                }
        }

        //prints whether or not word1 is subsequence of word2
        if (a == length1){
                printf("YES");
        }else{
                printf("NO");
        }

        return 0;
}

