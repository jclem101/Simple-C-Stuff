#include "heapsort.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    
    
    int *data = NULL;
    if(argc != 2) {
        fprintf(stderr, "You must specify an input filename as the only parameter!\n");
        exit(-1);
    } else {
        
        char *fileName = argv[1];
        FILE *fd = fopen(fileName, "r");
        if(fd == NULL) {
            fprintf(stderr, "The file named %s does not exist!\n", fileName);
            exit(-1);
        }
    
        int dataSize = readInt(fd);
        if(dataSize <= 0) {
            fprintf(stderr, "There are no integers to read!\n");
        }
        data = (int *)malloc(sizeof(int) * dataSize);
        bzero(data, sizeof(int) * dataSize);
        int i = 0;
        for(i = 0; i < dataSize; i++) {
            data[i] = readInt(fd);
            fprintf(stdout, "%d ", data[i]);
        }
        fprintf(stdout, "\n");
        fclose(fd);
        
        if(dataSize > 0) {
            if(DEBUG) {
                fprintf(stdout, "The number of integers in %s is %d\n", fileName, dataSize);
            }
            bottomUpHeap(data, dataSize, 0);
            for(i = 0; i < dataSize; i++) {
                fprintf(stdout, "%d ", data[i]);
            }
            fprintf(stdout, "\n");
        } else {
            switch(dataSize) {
                case -1:
                    fprintf(stderr, "The specified file does not exist!");
                    break;
                case 0:
                    fprintf(stderr, "The specified file does not have any data!");
                    break;
            }
        }
    }
    
    if(data != NULL) {
        if(DEBUG) {
            fprintf(stdout, "\nFreeing integer array!\n");
        }
        free(data);
    }
    
    return 0;
}

//This function reads an integer from a file descriptor one character at a time until a newline or space is encountered.
int readInt(FILE *fd) {
    int value = 0;
    char tempArray[10];
    char tmp = 0;
    int i = 0;
    size_t readSize = 0;
    
    if(DEBUG) {
        fprintf(stdout, "Preparing to read an int from the file\n");
    }
    
    if(fd != NULL) {
        while((readSize = fread(&tmp, sizeof(char), 1, fd)) > 0) {
            
            if(tmp != '\n' && tmp != ' ') {
                tempArray[i] = tmp;
                i++;
            } else {
                break;
            }
        }
        tempArray[i] = '\0';
        if(DEBUG) {
            fprintf(stdout, "Character string read from file: %s\n", tempArray);
        }
        value = atoi(tempArray);
        if(DEBUG) {
            fprintf(stdout, "Value read from file: %d\n", value);
        }
    }
    return value;
}

