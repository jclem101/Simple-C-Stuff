#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#define MAXSTRING 500
#define MAXLINES 100

//structs
typedef struct word word;
struct word{
int id;
int lastlineidx;
int count;
char alphword[MAXSTRING];
int lines[MAXLINES];
word* link;
};


//prototypes
void clearbuff();
void storeword();
void freewords();
void printwords();
word* isExt();
void printlns(word* obj);

//globals
char buff[MAXSTRING];
int buffidx = 0;
char currentchar;
int currline = 1;
int currid = 0;


//linked list pointer globals
word* root; 
word* last; 

//main
int main(int argc, char *argv[]){
//instantiate root pointer to blank obj
root = (word*)malloc(sizeof(word));
//init roots null pointer
root->link = NULL;
//point last to root
last = root;

	
	while((currentchar = fgetc(stdin)) != EOF){//loop through file given on stdin
		
			if(currentchar == ' ' || isalpha(currentchar) == 0 || currentchar == '\n' || buffidx == (MAXSTRING-1)){//if new word detected, 
			//isalpha() == 0 means char is not alpha
				if(currentchar == '\n')
					currline++;
			
				if(buffidx != 0){//only store word if stuff in buffer
					word* tmp = isExt();
						if(tmp == NULL){
							storeword();//create new node with current buffer if word doesnt exist in list
						}else{//modify extant word obj for count and line num;
						tmp->count = tmp->count + 1;
						tmp->lines[tmp->lastlineidx] = currline;
						tmp->lastlineidx = tmp->lastlineidx + 1;
						}
					clearbuff();//clear buffer for future words
					buffidx = 0;//reset buffer index
				}
			}else{//store alpha letter
				
				buff[buffidx] = currentchar; //store current alpha char in next space in buff;
				buffidx++; 
				//printf("%c\n",buff[buffidx]);
			}
		
	}
	
	//printf("%i\n",currline);
	//printf("%i\n",currid);
	//printf("%i\n",);

printwords();
freewords();
return 0;
}



void clearbuff(){
int i;
	for(i = 0; i < MAXSTRING; i++){
		buff[i]='\0';

	}

}

void storeword(){
//allocate new word obj
word *newword = (word*)malloc(sizeof(word));


		//point new object to null
		newword->link = NULL;
		//fill newword
		strcpy(newword->alphword, buff  );//dest, src
		newword->id = currid++;
		newword->lines[0] = currline;
		newword->lastlineidx = newword->lastlineidx + 1;
		
		last->link = newword;
		
		//assign last to point at newword
		last = newword;
		printf("%s\n", newword->alphword);
		//printf("%p\n", last);
		//printf("%p\n", newword->link);
}


void freewords(){
word* temp;	
temp = root;
	while(temp->link != 0){
		//get pointer to next in line, then deallocate memory pointed to by head
		temp = root;
		root = temp->link;
		free(temp);
		//printf("deall");
	}


}



void printwords(){
word* temp;
temp = root; //traverse from root node



	while(temp->link != NULL){
	//printf("1");
	printf("word: %s |count: %i |",temp->alphword, temp->count+1);
	printlns(temp);
	temp = temp->link;

	}



}


word* isExt(){
//parses list until word is found then returns pointer else returns null
word* temp;
temp = root; //traverse from root node

	while(temp->link != NULL){
	//printf("1");
	if(strcmp(temp->alphword, buff) != 0){
	temp = temp->link;
	}else{
	return temp;
	}
	}
return NULL;
}



void printlns(word* obj){
int i;

printf("lines: ");
	for(i = 0;i< obj->lastlineidx; i++){
	printf("%i", obj->lines[i]);
	}
printf("\n");

}












