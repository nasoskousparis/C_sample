/* code_v3_2.c */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CHARS 10

typedef struct text_t
{
    char **mt;
    int words;
} Text_t;

struct charact
{
    char ch;
    int sec;
};
typedef struct charact Char;

void letters(char *name, Char chars[50]);
void report(Char chars[50], int len);
Text_t readText(void);

int main(void)
{

    Char chars[50];
    Text_t mytext;
    mytext = readText();

    for (int i = 0; i < mytext.words; i++)
    {
        printf("%s\n", mytext.mt[i]);
        letters(mytext.mt[i], chars);
        report(chars, strlen(mytext.mt[i]));
        free(mytext.mt[i]);
    }
    free(mytext.mt);
    return 0;
}

void letters(char *name, Char chars[50])
{
    size_t i, j;
    memset(chars, 0, 50 * sizeof(Char));
    size_t len = strlen(name);

    for (i = 0; i < len; i++)
    {
        chars[i].ch = name[i];
        chars[i].sec = 0;

        for (j = i + 1; j < len; j++)
        {
            if (name[j] == chars[i].ch)
            {
                chars[i].sec = j - i;
                break;
            }
        }
    }

    return;
}

void report(Char t[50], int len)
{
    for (int i = len - 1; i >= 0; i--)
    {
        if (t[i].ch == 0)
            break;
        printf("%c : %d\n", t[i].ch, t[i].sec);
    }
    /* your code here (5-6 lines) */
    return;
}

Text_t readText(void)
{
    Text_t text;
    text.mt = NULL;
    text.words = 0;
    char buffer[CHARS];

    while (scanf(" %s", buffer), strcmp(buffer, "END"))
    {
        (text.words)++;
        text.mt = realloc(text.mt, (text.words) * sizeof(char *));
        text.mt[text.words - 1] = malloc(strlen(buffer) * sizeof(char) + 1);
        strcpy(text.mt[text.words - 1], buffer);
    }

    return text;
}