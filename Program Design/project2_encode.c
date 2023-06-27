#include <stdio.h>
//Joshua Bernard U92651625
//This program converts given characters into a secret cypher.

int main(){
	
	char ch; //variable for given charcter
	char newch; //variable for converted character
	printf("Enter input: ");


        //for loop used to convert each character
	for (int i = 0; i < 100; ++i){
		ch = getchar(); //gets character
		if (ch ==  ' '){
			continue; //ignore spaces
	
			}else if (ch >= '0' && ch <= '9'){ //converts chracters that are 0 through 9
				newch = (ch + 8) % 10;
				printf("%d",newch);
				continue;

			}else if (ch >= 'a' && ch <= 'z'){ //converts characters that are lowercase a through z
				if (ch >= 'a' && ch <= 't'){
					newch = ch + 6;
					printf("%c", newch);
					continue;
				}else if (ch == 'u'){
                                        printf("a");
                                        continue;
				}else if (ch == 'v'){
                                        printf("b");
                                        continue;
				}else if (ch == 'w'){
                                        printf("c");
                                        continue;
				}else if (ch == 'x'){
                                        printf("d");
                                        continue;
				}else if (ch == 'y'){
                                        printf("e");
                                        continue;
				}else if (ch == 'z'){
                                        printf("f");
                                        continue;
				}

			}else if (ch >= 'A' && ch <= 'Z'){ //converts characters that are upper case A through Z
				if (ch >= 'A' && ch <= 'T'){
                                        newch = ch + 6;
                                        printf("%c", newch);
                                        continue;
                                }else if (ch == 'U'){
                                        printf("A");
                                        continue;
                                }else if (ch == 'V'){
                                        printf("B");
                                        continue;
                                }else if (ch == 'W'){
                                        printf("C");
                                        continue;
                                }else if (ch == 'X'){
                                        printf("D");
                                        continue;
                                }else if (ch == 'Y'){
                                        printf("E");
                                        continue;
                                }else if (ch == 'Z'){
                                        printf("F");
                                        continue;
                                }

			}else if (ch == '\n'){ //ends for loop once there are no more characters
				break;

			}else //all other symbols are converted to _
				printf("_");
				continue;
			
	}
	
return 0;
}
