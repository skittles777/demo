#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* ExternRead(char* FileDir)
{
    FILE *fp;
    char str[60];
    /* 打开用于读取的文件 */
    fp = fopen(FileDir , "r");
    if(fp == NULL) {
        perror("打开文件时发生错误");
        return NULL;
   }
    if( fgets (str, 60, fp)!=NULL ) {
    /* 向标准输出 stdout 写入内容 */
        puts(str);
        printf("%d",strlen(str));
   }
}