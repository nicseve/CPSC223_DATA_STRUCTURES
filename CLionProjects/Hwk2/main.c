#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *encrypt(char* block, int n, int a, int b){




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
    int j;

    while((c = getchar()) != '\n' ){
        if(i < n){
            block[i++] = c;
            len++;

        }
        else{
            block[i] = '\0';
            printf("%s",block);
            i = 0;
            block[i++] = c;
            len = 0;
        }
    }

     //EOF REACHED CHECK BLOCK IS CORRECT LEN
    if(i < n-1){
        block[i] = '\0';
        char null[]="\\0";
        while(i < n){
            strcat(block,null);
            i++;
        }
    }

    printf("%s",block);

    return 0;
}