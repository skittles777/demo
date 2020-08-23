#ifndef COMMON_H_
#define COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TELLENGTH (unsigned int)12
#define DOUBLETELLENGTH (unsigned int)24
#define DBLENGTH (unsigned int)100

/*Default Regist State：USER_UNREGIST*/
#define USER_REGIST (int)0
#define USER_UNREGIST (int)1

#define CALLSTATE_RING (int)0
#define CALLSTATE_CONNECTED (int)1
#define CALLSTATE_OTHER (int)2

typedef struct UserData
{
    char UserTel[TELLENGTH];
    int RegistState;
} UserData;

typedef struct CallData
{
    char CallerTel[TELLENGTH];
    char CalledTel[TELLENGTH];
    int CallState;
} CallData;

UserData UserDB[DBLENGTH] = {0};
CallData CallDB[DBLENGTH] = {0};

#endif