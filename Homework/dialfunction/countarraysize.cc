#include "common_h/common.h"
#include "common_h/dial.h"

unsigned int CountArraySize(CallData *CallDB)
{
    unsigned int i = 0;
    for (i = 0; 0 == CallDB[i].CallerTel[0]; i++)
        ;
    return i;
}

int SortArray(CallData *CallDB)
{
    unsigned int i = 0;
    unsigned int j = 0;
    char *tmp = (char *)malloc(TELLENGTH);
    int statetmp = 0;
    CHECK_MALLOC(tmp);
    for (i = 0; i < DBLENGTH - 1; i++)
    {

        if (0 == CallDB[i].CallerTel[0])
        {
            for (j = i + 1; j < DBLENGTH; j++)
            {
                if (CallDB[j].CallerTel[0])
                    break;
            }
            if (j < DBLENGTH)
            {
                strncpy(tmp, CallDB[j].CallerTel, TELLENGTH);
                strncpy(CallDB[i].CallerTel, tmp, TELLENGTH);
                strncpy(tmp, CallDB[j].CalledTel, TELLENGTH);
                strncpy(CallDB[i].CalledTel, tmp, TELLENGTH);
                statetmp = CallDB[j].CallState;
                CallDB[i].CallState = statetmp;
                memset(&CallDB[j], 0, sizeof(CallData));
            }
            else
            {
                break;
            }
        }
    }
    free(tmp);
    return 0;
}