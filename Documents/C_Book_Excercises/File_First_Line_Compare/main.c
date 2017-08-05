#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void  filecompare(FILE *fp, FILE *ofp ){
	char f1[500];
	char f2[500];

	while ( fgets(f1,sizeof(f1),fp) != 0  && fgets(f2,sizeof(f2),ofp) != 0 ){
		for( int i = 0; f1[i] != '\0'; i++ ){
			if( f1[i] != f2[i] ){
				printf("%s \n ",f1);
			}
		}
	}
	fclose(fp);
	fclose(ofp);
}


int main(int argc, char **argv)
{
	FILE *fp;
	FILE *ofp;

	if(argc <= 2 || argc > 3){
		printf("Usage: please enter two filenames for comparison");
		exit(0);
	}
	else if(--argc == 2){
			if(  (fp=fopen(*++argv,"r")) == NULL || (ofp=fopen(*++argv,"r") ) == NULL ){
				printf("Invalid filename or file not found.");
			}
			else{
				filecompare(fp, ofp);
			}
	}
	return 0;
}
