#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DICTIONARY_SIZE 1000

typedef struct {
    char* word;
} Entry;

typedef struct {
    Entry* entries[DICTIONARY_SIZE];
    int size;
} Dictionary;

unsigned int hash(const char* word, int table_size) {
    unsigned int hash_value = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        hash_value = (hash_value * 31) + word[i];
    }
    return hash_value % table_size;
}

void initDictionary(Dictionary* dict) {
    dict->size = 0;
    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        dict->entries[i] = NULL;
    }
}

void insert(Dictionary* dict, const char* word) {
    if (dict->size >= DICTIONARY_SIZE) {
        printf("Dictionary is full. Cannot insert %s.\n", word);
        return;
    }

    unsigned int index = hash(word, DICTIONARY_SIZE);
    int attempts = 0;

    while (dict->entries[index] != NULL) {
        attempts++;
        index = (index + attempts * attempts) % DICTIONARY_SIZE;
    }

    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    newEntry->word = strdup(word);
    dict->entries[index] = newEntry;
    dict->size++;
}

int search(Dictionary* dict, const char* word) {
    unsigned int index = hash(word, DICTIONARY_SIZE);
    int attempts = 0;

    while (dict->entries[index] != NULL) {
        if (strcmp(dict->entries[index]->word, word) == 0) {
            return 1; // Word found in the dictionary
        }
        attempts++;
        index = (index + attempts * attempts) % DICTIONARY_SIZE;
    }

    return 0; // Word not found
}

void destroyDictionary(Dictionary* dict) {
    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        if (dict->entries[i] != NULL) {
            free(dict->entries[i]->word);
            free(dict->entries[i]);
        }
    }
}

int main() {
    Dictionary dict;
    initDictionary(&dict);

    // Add words to the dictionary
    insert(&dict, "apple");
    insert(&dict, "banana");
    insert(&dict, "orange");
    insert(&dict, "grape");
    insert(&dict, "kiwi");
    insert(&dict, "watermelon");
    insert(&dict, "strawberry");
    insert(&dict, "pineapple");
    insert(&dict, "mango");

    char word[100];
    while(1)
    {
    printf("Enter a word to check its spelling: ");
    scanf("%s", word);

    if (search(&dict, word)) {
        printf("%s is spelled correctly!\n", word);
    } else {
        printf("%s is misspelled!\n", word);
    }
    }

    return 0;
}
