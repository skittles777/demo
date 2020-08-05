#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*声明定义顺序一定不能错，这里typedef定义了结构和结构指针，
后面insert和print函数声明则用到pline，弄反了，编译不能过*/
typedef struct line
{
    char strline[30];
    struct line *next;
} line, *pline;

pline insert(char *str);
void print(pline Head);

int main(int argc, int *agrv[])
{
    int i = 0;
    char str[30];
    FILE *fp;
    pline Head = NULL, p = NULL, q = NULL;
    fp = fopen("file.txt", "r");
    if (fp == NULL)
    {
        perror("打开文件时发生错误");
        return 1;
    }
    while (fgets(str, 30, fp))
    {
        if (NULL == Head)
        {
            Head = insert(str);
            p = Head;
        }
        else
        {
            // p = p->next; //顺序反了
            p->next = insert(str);
            p = p->next;
        }
    }
    q = Head;
    for (i = 0; i < 2; i++)
    {
        print(q);
       // printf("a");
        q = q->next;
    }
    return 0;
}

pline insert(char *str)
{
    pline temp = (pline)malloc(sizeof(struct line));
    if (NULL == temp)
        return NULL;
    strncpy(temp->strline, str, 30);
    temp->next = NULL;
    return temp;
}

void print(pline Head)
{
    printf("%s", Head->strline);
}