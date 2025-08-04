#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50
#define MAX_PARAGRAPH_LEN 1000

// Structure to hold word and frequency
typedef struct {
    char word[MAX_WORD_LEN];
    int freq;
} WordFreq;

// Convert string to lowercase
void toLowerCase(char *str) {
    for (; *str; ++str) *str = tolower(*str);
}

int main() {
    char paragraph[MAX_PARAGRAPH_LEN];
    WordFreq wordFreq[MAX_WORDS];
    int count = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, sizeof(paragraph), stdin);

    // Remove newline at the end if exists
    size_t len = strlen(paragraph);
    if (len > 0 && paragraph[len-1] == '\n') {
        paragraph[len-1] = '\0';
    }

    char *token = strtok(paragraph, " ,.!?;:\"()\t\n");

    while (token != NULL) {
        toLowerCase(token);

        // Check if the word already exists
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(wordFreq[i].word, token) == 0) {
                wordFreq[i].freq++;
                found = 1;
                break;
            }
        }

        // If not found, add new word
        if (!found && count < MAX_WORDS) {
            strcpy(wordFreq[count].word, token);
            wordFreq[count].freq = 1;
            count++;
        }

        token = strtok(NULL, " ,.!?;:\"()\t\n");
    }

    printf("\nWord frequencies:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", wordFreq[i].word, wordFreq[i].freq);
    }

    return 0;
}
