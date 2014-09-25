#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


/*mult1*/


int opt1, optl, optc;
int opt, currentchar;
int numln, numsingle, nummulti;
char currbuff[100000];
int buffidx = 0;
char multilinestorage[100][100000];// max limit of 100 multiline comments of 100k char each, since we are not allowed to use dynamic mem allocation
int stage = 0; //if a slash is found, go to stage 1, if a second slash is found print the line, if a slash is found AND an asterisk follows go to stage 2

void transferbuff(){
//printf("7 \n");
//printf("nummulti %i \n", nummulti);
int i;
	for(i = 0; i < buffidx; i++){
	multilinestorage[nummulti][i] = currbuff[i];

	}
	multilinestorage[nummulti][buffidx+1] = '\0';
}

void wipebuff(){
int i;
//printf("5 \n");
	for(i = 0; i < buffidx; i++){
	currbuff[i] = 0;
	}
	buffidx = 0;

}

void printmulti(){
//printf("6 \n");
int i, j = 0;
for(i = 0; i < nummulti; i++){
	printf("/");
	printf("*");
	while(multilinestorage[i][j]!='\0'){
	printf("%c", multilinestorage[i][j]);
	j++;
	}printf("\n");
}

}


int main(int argc, char *argv[]){


while ((opt = getopt(argc, argv, "1lc")) != -1){


		switch (opt){
		case '1':
			opt1 = 1;
			break;
		case 'l':
			optl = 1;
			break;
		case 'c':
			optc = 1;
			break;
		default:
			printf("correct usage is './comments [-l][-1][-c] <yoursourcefile.sourceextension'\n");
			exit(1);
			
		}

}


while((currentchar = fgetc(stdin)) != EOF){
	if(currentchar == '\n'){
	numln++;
	}//increment number of lines
	if(stage == 0){	
	//printf("1 \n");
		if(currentchar == '/'){
		//strcat(currbuff, (const char *)currentchar);
		stage = 1;
		}	
	}else if(stage == 1){
	//printf("2 \n");
		if(currentchar == '/'){//you now have a single line comment			
			//printf("line: %i \n", numln);
			//printf("3 \n");
			printf("/");
			printf("/");
			while((currentchar = fgetc(stdin)) != '\n'){
			printf("%c", currentchar);
			}printf("\n");
			numsingle++;
			stage = 0;
		}else if(currentchar == '*'){ //we have multiliner
		//printf("1 \n");
		stage = 2;
		
		}else{ //was not indicitive of a single liner or a multi liner
		stage = 0;
		}			
	}else if(stage == 2){//copy multiliner into buffer
		//printf("2 \n");
		currbuff[buffidx++] = currentchar;
		if(currentchar == '*'){
		stage = 3;
		}
	
	}else if(stage == 3){
		//printf("3 \n");
		currbuff[buffidx++] = currentchar;
		
		if(currentchar == '/'){//the end of the multiline comment
		//printf("4 \n");
		//store current buffer then wipe buffer
		transferbuff();
		nummulti++;
		wipebuff();
		stage = 0;
		}else{
		stage = 2;
		}
	
	}	
		
		//putchar(currentchar);
}

/* multi multi multi */

printf("\n");
printmulti();

//printf("0: %s \n", argv[0]);
//printf("1: %s \n", argv[1]);
//printf("argc: %i \n", argc);

/* MUKLTASDFADSFASDFASDFASDFFDFFSDSSDFADFASFasd*asdfadf*/

if(optc != 0){
printf("\nnumber of multiline comments: %i\n", nummulti);
}
if(optl != 0){
printf("\nnumber of lines in the file: %i\n", numln += numsingle);
}
if(opt1 != 0){
printf("\nnumber of single line comments: %i\n", numsingle);
}

//end of file
//the above comment makes no sense

return 0;
}
