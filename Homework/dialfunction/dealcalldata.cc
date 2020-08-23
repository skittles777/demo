#include "common_h/common.h"

void DealCallData(const char *CallTels, CallData *Tmp)
{
    unsigned int i = 0;

    strncpy(Tmp->CallerTel, CallTels, TELLENGTH);
    Tmp->CallerTel[TELLENGTH - 1] = 0;
    for (i = TELLENGTH; i < DOUBLETELLENGTH; i++)
    {
        Tmp->CalledTel[i - TELLENGTH] = CallTels[i];
    }
}