#ifndef LINKEDLIST_WH_
#define LINKEDLIST_WH_

#define STRLENGTH (int)20
#define CHECKNULL(ptr) \
    if (NULL == ptr)   \
    {                  \
        return NULL;   \
    }

typedef struct SinglyLinkedList
{
    int order;
    char str[STRLENGTH];
    struct SinglyLinkedList *next;
} SinglyLinked;

typedef struct DoublyLinkedList
{
    int order;
    char str[STRLENGTH];
    struct DoublyLinkedList *prev;
    struct DoublyLinkedList *next;
} DoublyLinked;

#endif
