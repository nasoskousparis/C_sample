1. task1_c_1.c README-->  This is a basic text reader program. It reads words from the standard input 
(keyboard) into a dynamically allocated array of strings. It stops reading when the user types 
the word "END".Finally, it prints all the words back to the console and frees the allocated memory.

2. task1_c_2.c README-->This program extends the basic text reader. As it prints each word back to
the user, it also performs a character analysis. For every character in the word, it calculates the
distance to its next occurrence (if any) and prints a report. It demonstrates nested loops and
struct usage for character tracking.

3. task1_c_3.c README-->This version modifies the text reader to accept input from a file instead
of the keyboard. The user is prompted to enter a filename. The program then opens that file,
reads all words into a dynamic array until the End of File (EOF) is reached, prints them, and cleans
up memory.

4. task2_a.c README-->A standalone utility that focuses on linked list operations and character
distance logic. It reads a single word (up to 49 characters), calculates the distance between
recurring characters, and stores these results in a linked list. It then traverses the list to
print the character and its "recurrence distance".

5. task2_b.c README-->This program implements file-based text storage using Dynamic Arrays. It is designed
to be memory-efficient, using a single pointer for each word plus the string itself.
It reads a file, stores every word dynamically, prints them, and then frees all memory.
It serves as a benchmark for memory usage against linked lists.

6. task2_c.c README-->This program implements file-based text storage using Linked Lists. It reads a file
and creates a new node for every word. It includes internal documentation comparing its memory usage to
the dynamic array approach, noting that linked lists consume more memory due to the overhead of extra
pointers (next) for every node.
