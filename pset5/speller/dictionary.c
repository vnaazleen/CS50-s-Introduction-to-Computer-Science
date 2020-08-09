// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <strings.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;
// TO keep track of size of hash table ( no of words)
int nwords = 0;
// Check whether loading dict is successful or not
bool is_loaded_dict;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    char word_check[strlen(word)];
    strcpy(word_check, word);
    // Converting word to lower case
    for (int i = 0; word[i] != '\0'; ++i)
    {
        word_check[i] = tolower(word_check[i]);
    }

    int index = hash(word_check);
    if (table[index] == NULL)
    {
        return false;
    }

    // Check whether the word exists in table
    for (node *n = table[index]; n != NULL; n = n -> next)
    {
        if (strcmp(n -> word, word_check) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return word[0] - 'a';
    //return 0;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    FILE *f = fopen(dictionary, "r");
    if (f == NULL)
    {
        return false;
    }

    // Fill all the values in hash table with NULL
    for (int t = 0; t < N; ++t)
    {
        table[t] = NULL;
    }

    node *n;
    char word[LENGTH + 1];
    int index;
    while (fscanf(f, "%s", word) != EOF)
    {
        nwords++;
        n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        strcpy(n -> word, word);
        index = hash(word);
        n -> next = table[index];
        table[index] = n;
    }

    fclose(f);
    is_loaded_dict = true;
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (is_loaded_dict)
    {
        return nwords;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    if (!is_loaded_dict)
    {
        return false;
    }

    // Free all the allocated memory
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            node *ptr = table[i];
            while (ptr != NULL)
            {
                node *nt = ptr;
                ptr = ptr -> next;
                free(nt);
            }
        }
    }
    return true;
}