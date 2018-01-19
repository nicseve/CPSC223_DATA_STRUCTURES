#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>



char* letswap(char *s,int len){  //word modifer

	char *s2;
	char *s7;
	char *s8;
	char s3[len+3];
	char s4[len+3];

	char end1[] = "an";
	char end2[] = "o";

	int k = 0;
	int i = 0;
	int j = len-1;

   //CHECK FOR SYMBOLS AT BEG AND END OF WORD
	while( !(isalpha(s[k]))){
		s3[k] = s[k];
		k++;
	}//move forward until first alpha char seen

    s3[k] = '\0'; //BEG OF WORD
	//s8 = strcat(s8,s3);

	while(  !(isalpha(s[j])) ){
		s4[i++] = s[j--];
	}
	s4[i] = '\0'; //END OF WORD
	//printf("%s\n",s4);

	char temp = s[k]; //store first alpha char of word

	if(len >= 2){  //check if word at least length 2 or greater
		if(isupper(temp)){   //if first char upper chase
          s[k+1] = toupper(s[k+1]); //k+1 to get next alphachar?? was 1 before
		  temp = tolower(temp);
		  //s[len] = temp;
		  s[++j] = temp;
		}

		else{
			//s[len] = temp;
			s[++j] = temp;
		}
	}

    //word is 1 or less chars so return with "an" appended
	else {
		return s2 = strcat(s,end1);
	}

	//NULL TERMINATE TRIMMED ORIGINAL WORD
	s[j+1] = '\0';


   //CONCAT APPROPRIATE ENDING
	if(j-k <= 3){  //if length of word less than 3 concat end1
		s2 = strcat(s,end1); //S2 HOLDS WORD WITH CORRECT ENDING
		//printf("%s\n",&s2[1]);

		//ADD SYMBOLIC ENDING  STORED IN S4, S2 TRUNCATED AT K
		s7 = strcat(&s2[k],s4);

		//add symb beginning to truncated
		//s8 = strcat(s8,&s7[1]);
		return &s7[1];
	}

	else{
		s2 = strcat(s,end2);
		//printf("%s\n",&s2[1]);
		s7 = strcat(&s2[k],s4);
		//s8 = strcat(s8,&s7[1]);
		return &s7[1];
	}


	return &s2[k];
	}


//read words of input string;
void wordread(char *s){

	int len = strlen(s);
	int i = 0;
	int p = 0;
	char word[len];
	char *modword;

	while(i <= len){
		if(isspace(s[i]) || s[i] == '\0' || s[i] == '\n' || s[i] == '\r'){
			word[p] = '\0';
			//printf("%s %d\n",word,p);
			modword = letswap(word,p); //POINTER TO MODIFIED WORD STORED
			printf("%s ",modword);

			p = 0; //RESET P INDEX
			word[0] = '\0'; //RESET WORD ARRAY
			}

		else{
           word[p++] = s[i]; //ADD LETTER FROM STRING TO WORD
			}

		i++;
		}
	}



int main(int argc, char **argv)
{
	int c;
	int size = 2;
	int length;
	char *line;
	char *p;

	line = malloc(size);
	result = malloc(size);
	assert(line);
	length = 0;

	while( (c=getchar()) != EOF && c != '\n'){
		if(length >= size-1){
			size *= 2;
			line = realloc(line,size);
			}

		if(isspace(c)){
			size += 2;
			line = realloc(line,size);
			}

		line[length++] = c;
		}

	line[length] = '\0';
	wordread(line);

	return 0;
}
