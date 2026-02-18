#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHARS 100

typedef struct node
{
    char *str;
    struct node *next;
} Node;

Node *readText(void);
void freelist(Node *head);

int main(void)
{
    Node *mytext;
    int i;
    int textlen = 0;
    mytext = readText();
    Node *temp = mytext;
    while (temp != NULL)
    {
        printf("%s\n", temp->str);
        temp = temp->next;
    }
    freelist(mytext);

    return 0;
}
Node *readText(void)
{
    Node *temp;
    Node *head = NULL;
    Node *tail = NULL;
    temp->next = NULL;

    char word[CHARS];

    printf("give name of file:\n>");
    char *textname = malloc(sizeof(char) * CHARS);
    scanf("%s", textname);
    FILE *textfile = fopen(textname, "r");
    if (textfile == NULL)
    {
        printf("file did not open succesfully");
    }

    while (fscanf(textfile, "%s", word) != EOF)
    {
        temp = malloc(sizeof(Node));
        temp->str = malloc(sizeof(char) * (strlen(word) + 1));

        strcpy(temp->str, word);

        temp->next = NULL;

        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}

void freelist(Node *head)
{
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp->str);
        free(temp);
    }
}
// Top1000EnglishWords.txt

/*Η task2_b.c (με δυναμικους πίνακες) κάνει λιγότερη σπατάλη μνήμης από την task2_c.c (με συνδεδεμενες λίστες),
γιατί η λίστα χρειάζεται extra κόμβο για κάθε λέξη (με 2 pointers: str και next), ενώ ο πίνακας θέλει μόνο 1 pointer ανά λέξη.
Οι κόμβοι τρώνε παραπάνω χώρο. Στη λίστα sizeof(Node) = 16 bytes (2 pointers) και το string ενω στον πίνακα 8 bytes (1 pointer) συν το string.*/
