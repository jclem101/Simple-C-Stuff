

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//works but ordering is off
void downheap(int* data, int datasize, int rootidx){
//int minval;
int lchildidx = (rootidx*2)+1;
int rchildidx = (rootidx*2)+2;
	if(lchildidx < datasize && rchildidx < datasize){//if next nodes exist then recurse, then sort
	downheap(data,datasize,lchildidx);
	downheap(data,datasize,rchildidx);
	if(data[lchildidx] <= data[rootidx] && data[lchildidx] <= data[rchildidx]){
	int temp = data[rootidx];
	data[rootidx] = data[lchildidx];
	data[lchildidx] = temp;
	downheap(data,datasize,lchildidx);
	}
	
	if(data[rchildidx] <= data[rootidx] && data[rchildidx] <= data[lchildidx]){
	int temp = data[rootidx];
	data[rootidx] = data[rchildidx];
	data[rchildidx] = temp;	
	downheap(data, datasize, rchildidx);
	}

		
	}else{

	return;
	}


}


/*
void downheap(int* data, int datasize, int rootidx){
bool done = false;
int lchildidx = (rootidx*2)+1;
int rchildidx = (rootidx*2)+2;
int s = 0;

if(lchildidx < datasize && rchildidx < datasize){
	while(done == false){
	
		if(lchildidx > datasize && rchildidx > datasize){
		done = true;
		}

			if(data[lchildidx] <= data[rootidx] && data[lchildidx] <= data[rchildidx]){
			s = lchildidx;
			}
			if(data[rchildidx] <= data[rootidx] && data[rchildidx] <= data[lchildidx]){
			s = rchildidx;
			}
		
		if(data[s] < data[rootidx]){
		int temp = data[rootidx];
		data[rootidx] = data[s];
		data[s] = temp;
		downheap(data, datasize, s);
		}else{
		done = true;
		}
	}
}
}
*/

//int downheapleft(int* data, int datasize, int rootidx){}

//int downheapright(int* data, int datasize, int rootidx){}

void bottomUpHeap(int* data, int datasize, int rootidx){

if(*data ==  NULL ||datasize == 0){
fprintf(stderr, "error");
return;

}else{
int lchildidx = (rootidx*2)+1;
int rchildidx = (rootidx*2)+2;
if(lchildidx < datasize|| rchildidx < datasize){

bottomUpHeap(data, datasize, lchildidx);//left branch
bottomUpHeap(data, datasize, rchildidx);//right branch
downheap(data, datasize, rootidx); //downheap
}else{
//downheap();
return;
}



}


}



