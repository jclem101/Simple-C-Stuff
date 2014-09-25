
#include <time.h>
#include <stdlib.h>

//based off of algorithms found here on rosetta code http://rosettacode.org/wiki/Sorting_algorithms/Quicksort and http://rosettacode.org/wiki/Sorting_algorithms/Merge_sort


int get_total_ints();
void quick_sort(int start[], int startidx, int stopidx);
void printArray(int* array, int total);
void merge_sort(int input[], int total);

int getrandomidx(int limit);


int main() {
    
    srand(time(NULL)); //seed the Pseudo-random number generator
    int total = get_total_ints(); //gettotalints() is not implemented here, but you can use code similar to HW4 in order to obtain an integer from the user.
    int *inputData = (int *)malloc(sizeof(int) * total);
    int *unsortedData = (int *)malloc(sizeof(int) * total); //you will copy the original in array into this one...
    int *outputData = (int *)malloc(sizeof(int) * total);	
    int i = 0;
    bzero(inputData, sizeof(int) *total);
    bzero(unsortedData, sizeof(int) * total);
    bzero(outputData, sizeof(int) * total);
    
    for(i = 0; i < total; i++) {
        inputData[i] = rand() % 100; //this ensures the random data is between 0 and 100
        printf("%d ", inputData[i]);
        unsortedData[i] = inputData[i];
    }
    
    printf("\n\n"); //put in two new lines for formatting...
    
    //invoke merge sort...
	merge_sort(unsortedData, total);
    	printArray(unsortedData, total);
    //since merge sort will sort the data, copy the original unsorted data back into unsorted data
    
    for(i = 0; i < total; i++) {
        unsortedData[i] = inputData[i];
    }
    
    //now invoke quick sort
	quick_sort(unsortedData, 0, total-1);
    	printArray(unsortedData, total);
    	
  	free(inputData);
  	free(unsortedData);
  	free(outputData);  	
}

int get_total_ints() {
    int total = 0;
    printf("Enter number of integers to be generated: ");
    scanf("%d", &total);
    return total;
    
}


void merge_sort(int input[], int total){
	
	//recursion end condition
	if(total<=1)return;
	int half = total/2; //top
	//if input is even number of elements
	
	if(total%2 == 0){//for even total
		int left[half], right[half];

		//copy input to left and right arrays
		int i, j;
		
		for(i = 0; i < half; i++){
			left[i] = input[i];
		}
		
		j = i;
		
		for(i = 0; i < half; i++){
			right[i] = input[i+j];
		}
		//recurse with larrays as input, merge back together after both recursions into input larray from calling function
		//recurse for left 
		merge_sort(left, half); //pass pointer to area in input with totalidx to endidx
		//recurse for right
		merge_sort(right, half);
		//merge left and right back into input. 
		int currentleftidx = 0, currentrightidx = 0, currentinputidx = 0; 
		
		while(currentleftidx < half && currentrightidx < half){
			if(left[currentleftidx] <= right[currentrightidx]){
				input[currentinputidx++] = left[currentleftidx++];
			}else{
				input[currentinputidx++] = right[currentrightidx++];
			}
		}
		while(currentleftidx < half){ 
			input[currentinputidx++] = left[currentleftidx++];
		}
		//do the rest of the right array if any left
		while(currentrightidx < half){
			input[currentinputidx++] = right[currentrightidx++];
		}
		
	}else{//for odd total, odd factor is designated left larray
		int left[half+1], right[half];
		int i, j;
		for(i = 0; i < half+1; i++){
			left[i] = input[i];
		}
		j = i;
		for(i = 0; i < half; i++){
			right[i] = input[i+j];
		}
		//recurse for left 
		merge_sort(left, half+1);
		//recurse for right
		merge_sort(right, half);
	
		//merge left and right back into input. 
		int currentleftidx = 0, currentrightidx = 0, currentinputidx = 0; 
		
		
		while(currentleftidx < half+1 && currentrightidx < half){
			if(left[currentleftidx] <= right[currentrightidx]){
				input[currentinputidx++] = left[currentleftidx++];
			}else{
				input[currentinputidx++] = right[currentrightidx++];
			}
		}
		while(currentleftidx < half+1){ 
			input[currentinputidx++] = left[currentleftidx++];
		}
		//do the rest of the right array if any left
		while(currentrightidx < half){
			input[currentinputidx++] = right[currentrightidx++];
		}
		

	}
	//merge left and right back into input. this creates a chain of mem transfer up through the recursion. 
	
}

void quick_sort(int input[], int startidx, int stopidx){
	
	int pivot;
	
	if((stopidx - startidx) > 0){
		int currentleftidx = startidx, currentrightidx = stopidx;
		int pivotvalue = input[startidx];

		while(currentleftidx < currentrightidx){
			while(input[currentleftidx] <= pivotvalue){
			currentleftidx++;
			} 
			while(input[currentrightidx] > pivotvalue){
			currentrightidx--;
			}
			if(currentleftidx < currentrightidx){
			int temp;
		 	temp = input[currentleftidx];
		 	input[currentleftidx] = input[currentrightidx];
		 	input[currentrightidx] = temp; 
			}
		}

		input[startidx] = input[currentrightidx];
		input[currentrightidx] = pivotvalue;
		pivot = currentrightidx;


		quick_sort( input, startidx, pivot-1);
		quick_sort( input, pivot+1, stopidx );
	}
	

}



void printArray(int* array, int total){
int i;
//printf("\n");
for(i = 0; i< total; i++){
printf("%i ", *(array + i));
}
printf("\n");
}

int getrandomidx(int limit){
int lreturn = rand() % limit;
return lreturn;
}


