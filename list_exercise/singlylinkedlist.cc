#include "list_exercise/linkedlist.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*创建链表*/
SinglyLinked *CreateSinglyLinkedList(const char *Str, int NumOfNode)
{
    SinglyLinked *Head;
    SinglyLinked *Tmp;
    int i;
    CHECKNULL(Str);
    Head = (SinglyLinked *)malloc(sizeof(SinglyLinked));
    CHECKNULL(Head);
    Tmp = Head;
    for (i = 0; i < NumOfNode; i++)
    {
        strncpy(Tmp->str, Str, STRLENGTH - 1);
        Tmp->str[STRLENGTH - 1] = '\0';
        Tmp->order = i + 1;
        Tmp = Tmp->next;
        Tmp = (SinglyLinked *)malloc(sizeof(SinglyLinked));
        CHECKNULL(Tmp);
        Tmp->next = NULL;
    }
    return Head;
}

/*统计链表节点个数*/
int CountListNode(SinglyLinked *Head)
{
    int i = 0;
    SinglyLinked *tmp = Head;
    if (NULL == Head)
    {
        return 0;
    }
    while (NULL != tmp)
    {
        i++;
        tmp = tmp->next;
    }
    return i;
}

/*删除链表中第order个节点*/
SinglyLinked *DeleteOneSingleNode(int order, SinglyLinked *Head)
{
    SinglyLinked *tmp = Head;
    SinglyLinked *tmpprev;
    SinglyLinked *tmpnext;
    SinglyLinked *tmporder;
    int i;
    int j = CountListNode(Head);
    CHECKNULL(Head);
    //delete the first node
    if (order == 1)
    {
        tmpnext = tmp->next;
        free(tmp);
        return tmpnext;
    }
    //delete the last node
    if (order == j)
    {
        for (i = 1; i < order; i++)
        {
            tmp = tmp->next;
        }
        free(tmp);
        return Head;
    }
    //链表节点数为3个以上,且1 < order < j
    if (j >= 3 && 1 < order && order < j)
    {
        //寻找第order个节点之前一个节点
        for (i = 1; i + 1 < order; i++)
        {
            tmp = tmp->next;
        }
        tmpprev = tmp;
        tmporder = tmp->next;
        //寻找第order个节点之后一个节点
        for (i = 1; i < order + 1; i++)
        {
            tmp = tmp->next;
        }
        tmpnext = tmp;
        tmpprev->next = tmpnext;
        free(tmporder);
        return Head;
    }
}

/*Insert one node into the list behind the order*/
SinglyLinked *InsertOneSingleNode(int order, SinglyLinked *Head)
{
    
}

/*打印输出链表内容到屏幕*/
void PrintSinglyLinkedList(SinglyLinked *Head)
{
    SinglyLinked *p;
    if (NULL == Head)
    {
        return;
    }
    p = Head;
    while (NULL != p)
    {
        printf("This is the No.%d Node content: %s", p->order, p->str);
        p = p->next;
    }
}

/*释放链表全部节点*/
void FreeAllNode(SinglyLinked *Head)
{
    SinglyLinked *p;
    SinglyLinked *tmp;
    if (NULL == Head)
    {
        return;
    }
    p = Head;
    while (NULL != p)
    {
        tmp = p->next;
        free(p);
        p = tmp;
    }
}

int main(int argc, char *argv[])
{
}