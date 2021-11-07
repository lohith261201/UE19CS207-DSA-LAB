#include "hash.h"
HashTable *create_table(int size)
{
    //TODO
    HashTable* hata = (HashTable*)malloc(sizeof(HashTable) + (size * sizeof(int)));
    hata->table = (int*)malloc(size * sizeof(int));
    hata->size = size;
    int i;
    for(i = 0; i < size; i++)
        hata->table[i] = -1;
    return hata;
}

void insert(HashTable *htable, int element)
{
    //TODO
    int hashvalue = (element % htable->size);
    int i;
    for(i = hashvalue; i < htable->size; i++) {
        if(htable->table[i] == -1) {
            htable->table[i] = element;
            return;
        }
    }
    for(i = 0; i < hashvalue; i++) {
        if(htable->table[i] == -1) {
            htable->table[i] = element;
            return;
        }
    }
}

int search(HashTable *htable, int element)
{
    //TODO
    int v;
    for(v= 0; v < htable->size; v++) {
        if(htable->table[v] == element)
            return 1;
    }
    return 0;
}

void delete (HashTable *htable, int element)
{
    //TODO
    int l;
    for(l = 0; l < htable->size; l++) {
        if(htable->table[l] == element) {
            htable->table[l] = -1;
            return;
        }
    }
}


void destroy_table(HashTable *htable)
{
    //TODO
    for(int j = 0; j < htable->size; j++)
        htable->table[j] = 0;
    htable->size = 0;
    free(htable->table);
    free(htable);
}
