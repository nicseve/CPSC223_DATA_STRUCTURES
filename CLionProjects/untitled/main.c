#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>



char* letswap(char *s,int len){  //word modifier

	char *s2;
	char *s7;
	char *s8 = (char *)malloc(sizeof(char) * 256);
	char s3[len];
	char s4[len];
	char end1[] = "an";
	char end2[] = "o";
	int k = 0;
	int i = len-1;
	int j = len-1;

    //CHECK FOR SYMBOLS AT BEG AND END OF WORD
    //BEG OF WORD
	while( !(isalpha(s[k]))){
		s3[k] = s[k];
		k++;
	}

    s3[k] = '\0';
	s8 = strcat(s8,s3);


    //END OF WORD
	while(!(isalpha(s[j])) ){
		s4[i--] = s[j--];
	}
	s4[len] = '\0';


	char temp = s[k]; //store first alpha char of word

	if(len >= 2){  //check if word at least length 2 or greater    (NEEDS TO BE BASED ON J-K NOT LEN)
		if(isupper(temp)){   //if first char upper chase
          s[k+1] = (char) toupper(s[k + 1]); //k+1 to get next alphachar was 1 before
		  temp = (char) tolower(temp);
		  s[++j] = temp;
		}

		else{
			s[++j] = temp;
		}
	}

    //word is 1 or less chars so return with "an" appended
	else {
		return strcat(s,end1);
	}

	//NULL TERMINATE TRIMMED ORIGINAL WORD
	s[j+1] = '\0';

   //CONCAT APPROPRIATE ENDINGS & BEGINNINGS
	if(j-k <= 3){  //if length of word less than 3 concat end1
		s2 = strcat(s,end1); //S2 HOLDS WORD WITH CORRECT ENDING
		s7 = strcat(&s2[k],&s4[i+1]); //ADD SYMBOLIC ENDING  STORED IN S4, S2 TRUNCATED AT K
		s8 = strcat(s8,&s7[1]); //add symb beginning
		return s8;
	}

	else{
		s2 = strcat(s,end2);
		s7 = strcat(&s2[k],&s4[i+1]);
		s8 = strcat(s8,&s7[1]);
		return s8;
	}
}

char* symbcheck(char *s,int len){
	char first[len*2];
	char *second = s;

    for(int i = 0; i < len;i++){
        if (isalpha(s[i + 1])) {
            if (isalpha(s[i - 1])) {
                if (!(isalpha(s[i]))) {  //check if char before i is alpha and after is alpha
                    first[i] = s[i];
                    first[i + 1] = '\0';
                    return strcat(letswap(first, strlen(first)), letswap(&second[i + 1], strlen(s) - i - 1));
                } else {
                    first[i] = s[i];
                }
            } else {
                first[i] = s[i];
            }
        } else {
            first[i] = s[i];
        }
    }
   //first[0] = '\0';
   return letswap(s,strlen(s));
}
//read words of input string;
void wordread(char *s){

	int len = strlen(s);
	int i = 0;
	int p = 0;
	char word[len];
	char *modword;

	while(i <= len){
		if(isspace(s[i]) || s[i] == '\0' || s[i] == '\r' || s[i] == '\n'){

            if(s[i] == '\n'){  //CHECK IF END OF LINE REACHED AND PRESERVE IN OUTPUT
                word[p] = '\0';
                len-=1; ///'\n' originally counted in length
                modword = symbcheck(word,p);
                printf("%s\n",modword);
                p = 0; //RESET P INDEX
                word[0] = '\0'; //RESET WORD ARRAY

            }
            else {
                word[p] = '\0';
                modword = symbcheck(word, p); //POINTER TO MODIFIED WORD STORED
                printf("%s ", modword);

                p = 0; //RESET P INDEX
                word[0] = '\0'; //RESET WORD ARRAY

            }
        }
		else{
           word[p++] = s[i]; //ADD LETTER FROM STRING TO WORD
		}
		i++;
	}
}

int main(int argc, char **argv) {
    int c;
    char first;
    int init = 0;
    int init2 = 2;
    int size = 2;
    int length = 0;
    int len = 0;
    char *line;
    char *word;

    //line = malloc(size);
    //assert(line);
    //length = 0;


//
//    //FILE *fptr = fopen(NAME, "r");
//    char line[5000] = ""; //MUST DYNAMICALLY ADJUST SIZE OF LINE;
//    int count = 0;
//    //if (fptr == NULL) {
//      //  perror("Error");
//    //}
//
//
//            while ( fgets (line, sizeof(line), stdin) != 0){
//                //printf("\n%s",line);
//                wordread(line);
//            }
//            //fclose (fptr);
//
//        //printf("\nLinecount = %d\n", count);




    while ((c = fgetc(stdin)) != EOF) {


        if (isalpha(c) || c == '\n') {

            if (c != '\n') {
                length++;
                if (length == 1) {
                    first = c;
                }
            }


            if (c == '\n') {
                if (length <= 0) {
                    putchar(c);

                } else if (length <= 3) {
                    printf("%can\n",first);
                    length = 0;

                } else {
                    printf("%co\n",first);
                    length = 0;
                }
            }

            if (length > 1) {
                putchar(c);
            }

        }


         else if (isspace(c)) {

            if (length <= 3) {
                printf("%can ", first);
                length = 0;
                }
            else{
                printf("%co ", first);
                length = 0;
            }

        }

    else {
        if(length > 0){
            if (length <= 3) {
                printf("%can", first);
                putchar(c);
                length = 0;
            }
            else{
                printf("%co", first);
                putchar(c);
                length = 0;
            }

        }
        else {
            putchar(c);
        }
    }

}









    //NEED TO PRESERVE NEWLINE CHAR
    //NEED TO READ FROM STDINI
//	while( (c=fgetc(stdin)) != EOF){
//		if(length >= size-1){
//			size *= 2;
//			line = realloc(line,size);
//		}
//
//
//		if(isspace(c)){
//			size += 2;
//			line = realloc(line,size);
//		}
//
//
//
//		line[length++] = c;
//	}
//
//	line[length] = '\0';
//	wordread(line);

	return 0;
}