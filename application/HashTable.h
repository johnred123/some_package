#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRIME 211

typedef struct HashTable HashTable_t;
typedef struct HashNode HashNode_t;

struct HashTable{
        HashNode_t* Bucket[PRIME];
        char* name;
        HashTable_t* FuncList;
        char* func_type;
};

struct HashNode{
        char* type;
        char* identifier;
        char* isArg;
        HashNode_t* next;
};

HashTable_t * newHashTable(char* aux);

void newHashNode(HashTable_t* aux, char* t, char* id, char* isArg);

HashNode_t * newHNode(char* t, char* id, char* isArg);

HashTable_t * newFunc(HashTable_t* aux, char* t, char* id);

void hasEqual(HashNode_t*, char*);

void insertNode(HashTable_t* aux, HashNode_t* hnode);

#endif /* _HASH_TABLE_H_ */

