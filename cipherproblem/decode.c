#include <stdio.h>
#include<stdlib.h>
#include"decode.h"
/*

	short int word[4]={17729,21074,18766,18259};
	int *arr;
	char *string;
	int choice;

*/

// Write your functions here...
int* bitmaskToArray(short int word[])
{

    int *arr = malloc(64 * sizeof(int));

    for(int i = 0; i < 4; i++){
        unsigned short w = (unsigned short)word[i];
        for(int j = 0;j < 16;j++){
            arr[i * 16 + j] = (w >> (15 - j)) & 1;
        }
    }

    return arr;
}

char* decodeString(int arr[])
{

    char *string = malloc(9);

    for(int i = 0; i < 8; i++){
        int val = 0;
        for(int j = 0; j < 8; j++){
            val = (val << 1) | arr[i * 8 + j];
        }
        string[i] = (char)val;
    }
    string[8] = '\0';

    return string;
}

void displayBitPattern(int arr[])
{   

    for(int i = 0; i < 64; i++){
        if(i > 0 && i % 16 == 0){
            printf(" ");
        }
        printf("%d",arr[i]);
    }
}
