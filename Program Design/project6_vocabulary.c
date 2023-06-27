
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Joshua Bernard U92651625
//This program takes the given words and creates a vocabulary on a new file

#define MAX_STR_LEN 1000

//used to remove duplicate words
int compare(const void *a, const void *b) {

    const char **str_a = (const char **)a;
    const char **str_b = (const char **)b;
    return strcmp(*str_a, *str_b);
}

int main(int argc, char *argv[]) {

    //pointers for input and output files
    char *input_file = argv[1];
    char *output_file = argv[2];

    //opens the files
    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(output_file, "w");

    char str[MAX_STR_LEN + 1];
    char **words = NULL;
    int word_count = 0;
    int i, j;

    //used to count total number of words and convert the words to uppercase
    while (fgets(str, MAX_STR_LEN + 1, in)) {
        for (i = 0; str[i] != '\0'; i++) {
            if (!isalpha(str[i])) {
                continue;
            }
            word_count++;
            words = (char **)realloc(words, word_count * sizeof(char *));
            if (!words) {
                fclose(in);
                fclose(out);
                return 1;
            }
            words[word_count - 1] = (char *)malloc(MAX_STR_LEN + 1);
            if (!words[word_count - 1]) {
                fclose(in);
                fclose(out);
                return 1;
            }
            for (j = i; str[j] != '\0' && isalpha(str[j]); j++) {
                words[word_count - 1][j - i] = toupper(str[j]);
            }
            words[word_count - 1][j - i] = '\0';
            i = j - 1;
        }
    }

    //closes the input file
    fclose(in);

    //sorts the words in alphabetical order
    qsort(words, word_count, sizeof(char *), compare);

    //removes duplicates
    int k = 0;
    for (i = 0; i < word_count; i++) {
        if (i > 0 && strcmp(words[i], words[i-1]) == 0) {
            continue;
        }
        words[k++] = words[i];
    }
    word_count = k;

    for (i = 0; i < word_count; i++) {
        printf("%s\n", words[i]);
    }
    
    //writes the vocabulary to the output file
    for (i = 0; i < word_count; i++) {
        fprintf(out, "%d ", i + 1);
        fprintf(out, "%s\n", words[i]);
    }

    //closes the output file
    fclose(out);

    return 0;
}

