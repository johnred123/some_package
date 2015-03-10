/******************************************************************************
  File Name     : HashTable.c
  Version       : Initial Draft
  Author        : john kazmath (johnred123@github)
  Created       : 
  Last Modified :
  Description   : hash table operation function
  Function List :
              hasEqual
              insertNode
              newFunc
              newHashNode
              newHashTable
              newHNode
  History       :
  1.Date        : 
    Author      : john kazmath (johnred123@github)
    Modification: Created file

******************************************************************************/
#include "HashTable.h"

HashTable_t *newHashTable(char* aux)
{
    HashTable_t* foo = (HashTable_t*)malloc(sizeof(HashTable_t));
    foo->name = aux;

    return foo;
}

void newHashNode(HashTable_t* aux, char* t, char* id, char* arg)
{

    int ascValue = 0;
    int hashValue;
    int count;
    for(count = 0; id[count] != '\0'; count++){
        ascValue += id[count];
    }

    do{
        hashValue = ascValue % PRIME;
    }while(hashValue > PRIME);

    HashNode_t* newBucket;

    if(aux->Bucket[hashValue]!= NULL){
        hasEqual(aux->Bucket[hashValue], id);

        newBucket = (HashNode_t*)malloc(sizeof(struct HashNode));
        newBucket->type = t;
        newBucket->identifier = id;
        newBucket->isArg = arg;
        newBucket->next = aux->Bucket[hashValue];
        aux->Bucket[hashValue] = newBucket;
    }else{
        newBucket = (HashNode_t*)malloc(sizeof(struct HashNode));
        newBucket->type = t;
        newBucket->identifier = id;
        newBucket->isArg = arg;
        newBucket->next = NULL;
        aux->Bucket[hashValue] = newBucket;
    }

}

void hasEqual(HashNode_t* foo, char* id)
{
    if(foo){
        if(strcmp(foo->identifier,id) == 0){
            // is equal
        }
        foo = foo->next;
    }       
}

HashTable_t* newFunc(HashTable_t* aux, char* t, char* id)
{
    HashTable_t* foo = newHashTable(id);
    foo->FuncList = aux->FuncList;
    aux->FuncList = foo;
    foo->func_type = t;
    newHashNode(aux,t,id,"FUNC");

    return foo;
}

HashNode_t * newHNode(char* t, char* id, char* isArg){
    HashNode_t* aux = (HashNode_t*)malloc(sizeof(HashNode_t));
    aux->type = t;
    aux->identifier = id;
    aux->isArg = isArg;

    return aux;
}

void insertNode(HashTable_t* aux, HashNode_t* hnode)
{
    char* t = hnode->type;
    char* id = hnode->identifier;
    char* arg = hnode->isArg;
    int ascValue = 0;
    int hashValue;
    int count;
    for(count = 0; id[count] != '\0'; count++){
        ascValue += id[count];
    }

    do{
        hashValue = ascValue % PRIME;
    }while(hashValue > PRIME);

    HashNode_t* newBucket;

    if(aux->Bucket[hashValue]!= NULL){
        hasEqual(aux->Bucket[hashValue], id);

        newBucket = (HashNode_t*)malloc(sizeof(HashNode_t));
        newBucket->type = t;
        newBucket->identifier = id;
        newBucket->isArg = arg;
        newBucket->next = aux->Bucket[hashValue];
        aux->Bucket[hashValue] = newBucket;
    }else{
        newBucket = (HashNode_t*)malloc(sizeof(HashNode_t));
        newBucket->type = t;
        newBucket->identifier = id;
        newBucket->isArg = arg;
        newBucket->next = NULL;
        aux->Bucket[hashValue] = newBucket;
    }
}
