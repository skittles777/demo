#include<stdio.h>
void main()
{
    // char ch,a;
    // scanf("%3c%c",&ch,&a);
    /*%3c意味着需要读取3个char字符，但是ch只存储第一个；当读取第4个字符的时候，才赋值给了a*/
    // printf("%3c,%c",ch,a);
    /*这里输出%3c，前两位用空格补齐，第三位为ch值；*/
    int i,j;
    scanf("%d%2d",&i,&j);
    /*这里%3d意味着读取输入的前三位作为i；如果是%d，则会一直读取，直至遇到空格为止，作为i；*/
    printf("i=%d,j=%d\n",i,j);
}