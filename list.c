/*
 * COMP 206 Assignment 3
 * Alex I.
 * Helper functions to work with a linked list
 */

#include "list.h"

typedef struct NODE {
    int value;
    struct NODE* next;
} aNode;

struct NODE *find(int node);

aNode* head;

/*
 * Accepts a value, creates a node and adds it to the linked list
 */
void add(int node)
{
    
    if (head == NULL) {
        head = (aNode *)malloc(sizeof(aNode)); // initialize linked list
        head->value = node;
    } else {
        
        aNode* newNode;
        aNode* emptySpot = head;

        while (emptySpot->next != NULL) {
            emptySpot = emptySpot->next;
        }
        
        newNode = (aNode *)malloc(sizeof(aNode));
        newNode->value = node;
        newNode->next = NULL;
        emptySpot->next = newNode;
    }
}

/*
 * Prints the values of nodes of a linked list
 */
void prettyPrint()
{
    printf("\nNodes: ");
    aNode* currentNode = head;
    while (currentNode != NULL) {
        printf("%d ", currentNode->value);
        currentNode = currentNode->next;
    }
    printf("\n\n");
}

/*
 * Deletes the first node that matches passed value.
 * If it finds a node then the node is deleted and the function return TRUE,
 * otherwise it does not delete anything and returns FALSE.
 */
BOOLEAN delete(int node)
{
    aNode* currentNode = head;
    aNode* deletedNode = find(node);
    
    if (deletedNode != NULL) {
        
        if (currentNode == deletedNode) {
            head = currentNode->next;
            free(deletedNode);
            return TRUE;
        }
        
        while (currentNode != NULL) {
            if (currentNode->next == deletedNode) {
                currentNode->next = currentNode->next->next;
                free(deletedNode);
                return TRUE;
            }
            currentNode = currentNode->next;
        }
    }
    
    return FALSE;
}

/*
 * ****** Hidden method, to be used locally only **********
 * Searches a linked list from the head to the tail,
 * stopping at the first node that matches the given integer number.
 * Returns a pointer to the node it found, else returns NULL.
 */
struct NODE *find(int node)
{
    aNode* deletedNode = head;
    
    while (deletedNode != NULL) {
        if (deletedNode->value == node) {
            return deletedNode;
        }
        deletedNode = deletedNode->next;
    }
    
    return NULL;
}