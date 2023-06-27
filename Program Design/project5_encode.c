#include <stdio.h>
#include <string.h>

//Joshua Bernard U92651625
//This program converts given characters into a secret cypher.

void encode(char *input, char *output);

int main(int argc, char *argv[]){
        char array[100];
        char newArray[100];
        int i;
        int j;

        //ends if there is no input
        if (argc < 2){
                printf("Invalid input!");
                return 0;
        }

        //Combines the inputs into one string 
        for (i = 1, j = 0; i < argc && j < 100 - 1; i++){
                strncpy(&array[j], argv[i], 100 - j - 1);
                j += strlen(argv[i]);
        }

        //Adds a null terminator to the end of the array
        array[j] = '\0';

        encode(array, newArray);

        printf("Output: %s\n", newArray);

        return 0;
}

//encodes the input
void encode(char *input, char *output){

        //for loop used to convert each character
	for (int i = 0; i < 1001; i++){
		char ch;
                char newch;
                char temp;
                
                ch = input[i];

		if (ch ==  ' '){
			continue; //ignore spaces
	
			}else if (ch >= '0' && ch <= '9'){ //converts chracters that are 0 through 9
				newch = (ch + 8) % 10;
                                *output = newch + '0';
                                output++;
				//printf("%d",newch);
				continue;

			}else if (ch >= 'a' && ch <= 'z'){ //converts characters that are lowercase a through z
				if (ch >= 'a' && ch <= 't'){
					newch = ch + 6;
                                        *output = newch;
                                        output++;
					//printf("%c", newch);
					continue;
				}else if (ch == 'u'){
                                        temp = 'a';
                                        *output = temp;
                                        output++;
                                        //printf("a");
                                        continue;
				}else if (ch == 'v'){
                                        temp = 'b';
                                        *output = temp;
                                        output++;
                                        //printf("b");
                                        continue;
				}else if (ch == 'w'){
                                        temp = 'c';
                                        *output = temp;
                                        output++;
                                        //printf("c");
                                        continue;
				}else if (ch == 'x'){
                                        temp = 'd';
                                        *output = temp;
                                        output++;
                                        //printf("d");
                                        continue;
				}else if (ch == 'y'){
                                        temp = 'e';
                                        *output = temp;
                                        output++;
                                        //printf("e");
                                        continue;
				}else if (ch == 'z'){
                                        temp = 'f';
                                        *output = temp;
                                        output++;
                                        //printf("f");
                                        continue;
				}

			}else if (ch >= 'A' && ch <= 'Z'){ //converts characters that are upper case A through Z
				if (ch >= 'A' && ch <= 'T'){
                                        newch = ch + 6;
                                        *output = newch;
                                        output++;
                                        //printf("%c", newch);
                                        continue;
                                }else if (ch == 'U'){
                                        temp = 'A';
                                        *output = temp;
                                        output++;
                                       // printf("A");
                                        continue;
                                }else if (ch == 'V'){
                                        temp = 'B';
                                        *output = temp;
                                        output++;
                                        //printf("B");
                                        continue;
                                }else if (ch == 'W'){
                                        temp = 'C';
                                        *output = temp;
                                        output++;
                                        //printf("C");
                                        continue;
                                }else if (ch == 'X'){
                                        temp = 'D';
                                        *output = temp;
                                        output++;
                                        //printf("D");
                                        continue;
                                }else if (ch == 'Y'){
                                        temp = 'E';
                                        *output = temp;
                                        output++;
                                        //printf("E");
                                        continue;
                                }else if (ch == 'Z'){
                                        temp = 'F';
                                        *output = temp;
                                        output++;
                                        //printf("F");
                                        continue;
                                }

			}else if (ch == '\0'){ //ends for loop once there are no more characters
				break;

			}else //all other symbols are converted to _
                                temp = '_';
                                *output = temp;
                                output++;
				//printf("_");
				continue;
			
	}
}