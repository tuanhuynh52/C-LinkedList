/*
 * list.h
 *
 *  Created on: May 18, 2015
 *      Author: Tuan Huynh
 */


#ifndef LIST_H_
#define LIST_H_

struct node;

int searchList(struct node **pStart, char currentWord[50]);
void addWord(struct node **pStart, char currentWord[50], int file);
void countWord(struct node **pStart, char currentWord[50], int file);
void bubbleSort(struct node **pStart);
void printList(struct node **pStart);

#endif /* LIST_H_ */
