/*
 * hw4.c
 *
 *  Created on: May 18, 2015
 *      Author: tuanhuynh
 */


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "list.h"

void getNextWord(char currentWord[30]) {
    int i;
    for (i = 0; i < strlen(currentWord); i++) {
        if (isupper((int) currentWord[i]) != 0) {
            int lowerValue = tolower((int) currentWord[i]);
            currentWord[i] = (char) lowerValue;
        }
        int charValue = (int) currentWord[i];
        if ((charValue != 45) && (charValue != 39) && (isalpha(charValue) == 0)) {
            if (i == 0) {
                memmove(&currentWord[i], &currentWord[i + 1], strlen(currentWord) - i);
                i--;
            } else {
                currentWord[i] = '\0';
                break;
            }
        }
    }
}

void processingFile() {

    FILE* firstFile = fopen("RedBadge.txt", "r");
    FILE* secondFile = fopen("LittleRegiment.txt", "r");
    char currentWord[30];
    struct node *start;
    start = NULL;

    while (fscanf(firstFile, "%s", currentWord) == 1) {
        getNextWord(currentWord);
        if (searchList(&start, currentWord) == 1) {
            countWord(&start, currentWord, 1);
        } else {
            addWord(&start, currentWord, 1);
        }
    }
    while (fscanf(secondFile, "%s", currentWord) == 1) {
        getNextWord(currentWord);
        if (searchList(&start, currentWord) == 1) {
            countWord(&start, currentWord, 2);
        } else {
            addWord(&start, currentWord, 2);
        }
    }
    bubbleSort(&start);
    printList(&start);
}

int main(void) {

    setvbuf(stdout, NULL, _IONBF, 0);

    processingFile();

    return 0;
}
