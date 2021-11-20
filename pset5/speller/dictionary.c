// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 25;

// Number of words in dictionary
unsigned int disctionary_words = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hash_n = hash(word);
    for (node *tmp = table[hash_n]; tmp != NULL; tmp = tmp->next)
    {
        int same_word = strcasecmp(word,tmp->word);
        if(same_word == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    char first_char = tolower(word[0]);
    return (int)(first_char) - 97;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        return false;
    }
    
    char word[LENGTH + 1];
    
    while(fscanf(fp, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if(n != NULL)
        {
            int hash_n = hash(word);
            strcpy(n->word, word);
            n->next = table[hash_n];
            table[hash_n] = n;
            disctionary_words++;
        }
    }
    fclose(fp);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return disctionary_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }

        if (i == N - 1 && cursor == NULL)
        {
            return true;
        }
    }
    return false;
}
