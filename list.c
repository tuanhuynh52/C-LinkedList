/*
 * list.c
 *
 *  Created on: May 19, 2015
 *      Author: Tuan Huynh
 */


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "list.h"

struct node {
    char word[30];
    int firstCount;
    int secondCount;
    int smallValue;
    struct node *next;
};


int searchList(struct node **start, char currentWord[30]) {
    int result = 0;
    struct node *current = *start;
    while (current != NULL) {
        if (strcmp(currentWord, current->word) == 0) {
            result = 1;
            break;
        }
        current = current->next;
    }
    return result;
}

void addWord(struct node **start, char currentWord[30], int file) {
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    strcpy(newNode->word, currentWord);
    newNode->next = *start;
    if (file == 1) {
        newNode->firstCount = 1;
    } else {
        newNode->secondCount = 1;
    }
    *start = newNode;
}

void countWord(struct node **start, char currentWord[30], int file) {

    struct node *current = *start;
    while (current != NULL) {
        if (strcmp(currentWord, current->word) == 0) {
            if (file == 1) {
                current->firstCount++;
            } else {
                current->secondCount++;
            }
            if (current->firstCount >= current->secondCount) {
                current->smallValue = current->secondCount;
            } else {
                current->smallValue = current->firstCount;
            }
            break;
        }
        current = current->next;
    }
}

void swapPosition(struct node *currentNode, struct node *nextNode) {

    char tempWord[30];
    int tempFirstCount, tempSecondCount, bigValue;

    strcpy(tempWord, currentNode->word);
    tempFirstCount = currentNode->firstCount;
    tempSecondCount = currentNode->secondCount;
    bigValue = currentNode->smallValue;

    strcpy(currentNode->word, nextNode->word);
    currentNode->firstCount = nextNode->firstCount;
    currentNode->secondCount = nextNode->secondCount;
    currentNode->smallValue = nextNode->smallValue;

    strcpy(nextNode->word, tempWord);
    nextNode->firstCount = tempFirstCount;
    nextNode->secondCount = tempSecondCount;
    nextNode->smallValue = bigValue;
}

void bubbleSort(struct node **start) {

    int swapped = 1;
    struct node *current;
    struct node *pNext;
    pNext = NULL;
    while (swapped) {
        swapped = 0;
        current = *start;
        while (current->next != pNext) {
            if (current->smallValue < current->next->smallValue) {
                swapPosition(current, current->next);
                swapped = 1;
            }
            current = current->next;
        }
        pNext = current;
    }
}

void printList(struct node **start) {

    int i = 0;
    struct node *current = *start;
    printf("TOP50	WordName		BigCount	SmallCount\n");
    while (i < 50 && current != NULL) {
        printf("%d	%s			%d		%d\n", i + 1, current->word, current->firstCount, current->secondCount);
        current = current->next;
        i++;
    }
}
