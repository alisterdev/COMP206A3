/*
 * COMP 206 Assignment 3
 * Alex I.
 * Main file
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

BOOLEAN deleteAgain();

int main(int argc, const char * argv[])
{
    FILE *filePointer;
    char fileName[100];
    char inputNumber[20];
    int isValidFile = FALSE;
    int playAgain = FALSE;
    int node;
    int nodeCounter = 0;
    

    // loops until user enters a valid file
    while (!isValidFile) {
    
        printf("Enter a file name: ");
        
        scanf("%s", fileName);
        
        filePointer = fopen(fileName, "rt");
    
        if (filePointer == NULL) {
            printf("Could not open the file! Try again!\n");
        } else {
            
            isValidFile = TRUE;
            
            while (fscanf(filePointer, "%d", &node) == 1){
                add(node);
                nodeCounter++;
            }
  
            fclose(filePointer);
        }
    }
    
    // If no nodes were added from the file, quit the program
    if (nodeCounter == 0) {
        printf("The file was empty! No nodes were added!\nExiting the program!\n");
        return EXIT_SUCCESS;
    }

    prettyPrint();
    
    // loops until user wants to delete more nodes
    // or there are remaining nodes to delete
    while(!playAgain) {
    
        printf("Enter a number to delete: ");
        
        scanf("%s", inputNumber);
        
        int deleteNode = atoi (inputNumber);
        BOOLEAN isFound = delete(deleteNode);
        
        if (isFound) {
            printf("Number %d was deleted!\n", deleteNode);
            nodeCounter--;
            
        } else {
            printf("Number %d was not found!\n", deleteNode);
        }
        
        prettyPrint();
        
        if (nodeCounter == 0) {
            printf("No more nodes remaining! Exiting the program!\n");
            playAgain = TRUE;
        } else if (!deleteAgain()) {
            playAgain = TRUE;
        }
    }
    
    return EXIT_SUCCESS;
}

/*
 * Helper function
 * Prompts a user with a message. Returns TRUE for positive answer
 * and FALSE for a negative answer
 */
BOOLEAN deleteAgain()
{
    BOOLEAN answer = FALSE;
    
    printf("Do you want to delete another number? (Y/N)");
    
    char answer1[4] = "YES\0";
    char answer2[4] = "Yes\0";
    char answer3[4] = "yes\0";
    char answer4[2] = "Y\0";
    char answer5[2] = "y\0";
    char playAgainInput[4];
    
    scanf("%s", playAgainInput);

    if (strcmp(playAgainInput, answer1) == 0 || strcmp(playAgainInput, answer2) == 0 ||
        strcmp(playAgainInput, answer3) == 0 || strcmp(playAgainInput, answer4) == 0 ||
        strcmp(playAgainInput, answer5) == 0) {
        answer = TRUE;
    }
    
    return answer;
}


