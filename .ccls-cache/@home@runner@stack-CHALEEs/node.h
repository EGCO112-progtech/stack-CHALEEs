//
//  linkedlist.h
//  LinkedList_simple
//
//  Created by Mingmanas Sivaraksa
//
#include <stdio.h>
#include <stdlib.h>
#ifndef linkedlist_h
#define linkedlist_h

struct node {
  char data;
  struct node *nextPtr;
};

typedef struct node Node;
typedef struct node *NodePtr;

#endif