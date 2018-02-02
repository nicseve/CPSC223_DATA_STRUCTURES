#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* block, int n, int a, int b){
    int i = 0;
//    char *blockcopy = malloc(sizeof(char)*n);
//    blockcopy = strcpy(blockcopy,block);     //create copy of block and reference might need memcopy

    while(i < n){
        if ( (a*i+b)%n > strlen(block)-1){
                printf("%c",'\0');
                i++;
        }
        else {
                printf("%c",block[((a * i) + b) % n]);
                //block[i] = blockcopy[((a * i) + b) % n];
                i++;
            }
        }

//    while(i < strlen(block)){
//        block[i] = blockcopy[((a*i) +b)%n];
//        i++;
//
//    }
    //printf("%s",block);
    //free(blockcopy);
//    return block;
}



int main(int argc, char **argv)
{
    char *block;
    int c;

    int n;
    int a; //could be negative or zero
    int b; //could be negative or zero
    int len = 0;

    n = 5;//HARDCODE TEST
    a = 3;
    b = 2;

//    if (argc != 4 || *argv[1] == 0 ){
//        printf("Usage: Please enter correct arguments");
//    }
//    else{
//        n = *argv[1];
//        a = *argv[2];
//        b = *argv[3];
//    }

    block = malloc(sizeof(int) * n*2);

    int i = 0; //count index from 0 to n


    while((c = getchar()) != '\n' ){
        if(i < n){
            block[i++] = c;
            len++;

        }
        else{
            block[i] = '\0';
            encrypt(block,n,a,b);
            i = 0;
            block[i++] = c;
            len = 0;
        }
    }
     //EOF REACHED CHECK BLOCK IS CORRECT LEN
//    if(i < n-1){
//        block[i] = '\0';
//        char null[]="\\0";   //not correct, encrypt function reads null char as two chars instead of one, incorrect indexing results
//        while(i < n){
//            strcat(block,null);
//            i++;
//        }
//    }
    block[i] = '\0';
    encrypt(block,n,a,b);
    //printf("%s",block);

    return 0;
}