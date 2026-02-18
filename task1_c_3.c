#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHARS 100

typedef struct text_t
{
    char **mt;
    int words;
} Text_t;

Text_t readText(void);

int main(void)
{
    Text_t mytext;
    int i;
    mytext = readText();

    for (i = 0; i < mytext.words; i++)
    {
        printf("%s\n", mytext.mt[i]);
        free(mytext.mt[i]); //??
    }
    free(mytext.mt);
    return 0;
}

Text_t readText(void)
{
    Text_t text;
    text.mt = NULL;
    text.words = 0;
    char buffer[CHARS];
    char textname[100];
    printf("give name of file:\n>");
    scanf("%s", textname);
    FILE *textfile = fopen(textname, "r");

    while (fscanf(textfile, " %s", buffer) != EOF)
    {

        (text.words)++;

        text.mt = realloc(text.mt, (text.words) * sizeof(char *));

        text.mt[text.words - 1] = malloc(strlen(buffer) * sizeof(char) + 1);

        strcpy(text.mt[text.words - 1], buffer);
    }

    return text;
}