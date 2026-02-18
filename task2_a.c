#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct charact
{
    char ch;
    int occurs;
    struct charact *next;
} Char;

void letters(char name[50], Char **chars_ptr);
void report(Char *chars);
Char *createnode(char ch, int occurs);

int main(void)
{
    char name[50];
    // arxikopoiw "lista" (kefali ths alysidas)
    Char *chars = NULL;
    // diavazw mia leksh max 49 xarakthres
    scanf(" %49s", name);

    // tha metraei gia kathe gramma toy name se poses theseis ksanaprokyptei to idio.
    // tha krataei ton xarakthra kai to occurs toy se mia lista.
    letters(name, &chars);
    report(chars);
    return 0;
}

Char *createnode(char ch, int occurs)
{
    Char *newnode_ptr;
    newnode_ptr = malloc(sizeof(Char));
    newnode_ptr->ch = ch;
    newnode_ptr->occurs = occurs;
    newnode_ptr->next = NULL;
    return newnode_ptr;
}

// dedomena: deikth sthn metavlhth poy kratei to head_ptr, ch, occurs
// stoxos: na valw sthn prwth thesh enos list enan komvo

void add_to_front(Char **head_ptr, char ch, int occurs)
{
    Char *temp = createnode(ch, occurs);
    temp->next = *head_ptr;
    *head_ptr = temp;
}

// dedomena: thesh grammatos (i), name
// stoxos: na ypologisoyme kai na epistrepsoyme thn apostash poy exei to gramma sthn thesh i apo to epomeno gramma (0 an den yparxei ksana)
int compute_distance(int i, char *name)
{
    int count = 0;
    if (name[i] == '\0')
    {
        return 0;
    }
    for (int j = i + 1; name[j] != '\0'; j++)
    {
        if (name[i] == name[j])
        {
            count = j - i;
            return count;
        }
    }
}

void letters(char name[50], Char **head_ptr)
{
    // gia kathe gramma toy name:
    // // ypologizw apostasth poy ksanaprokyptei
    // // eisagw sthn arxh ths listas enan komvo
    for (int i = 0; i < strlen(name); i++)
    {
        int occurs = compute_distance(i, name);
        add_to_front(head_ptr, name[i], occurs);
    }
}

void report(Char *chars)
{
    while (chars != NULL)
    {
        printf("%c: %d\n", chars->ch, chars->occurs);

        chars = chars->next;
    }
}