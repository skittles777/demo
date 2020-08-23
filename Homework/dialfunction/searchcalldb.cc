#include "common_h/common.h"
#include "common_h/dial.h"

int SearchCallDB(const char *CallerTel, const char *CalledTel)
{
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = 0;
    k = SortArray(CallDB);
    j = CountArraySize(CallDB);
    for (i = 0; i < j; i++)
    {
        /*Search the callstate of ring and connected*/
        if (CALLSTATE_OTHER != CallDB[i].CallState)
        {
            /*Compare calledTel with calledtel of CallDB*/
            if (0 == strncmp(CallDB[i].CalledTel, CalledTel, TELLENGTH))
            {
                if (strncmp(CallDB[i].CallerTel, CallerTel, TELLENGTH))
                {
                    if (strncmp(CallDB[i].CalledTel, CallerTel, TELLENGTH))
                        return DIAL_BUSY;
                    else
                    {
                        return DIAL_OTHER;
                    }
                }
                else
                {
                    return DIAL_OTHER;
                }
            }
            /*Compare calledTel with callertel of CallDB*/
            else if (0 == strncmp(CallDB[i].CallerTel, CalledTel, TELLENGTH))
            {
                if (strncmp(CallDB[i].CalledTel, CallerTel, TELLENGTH))
                {
                    if (strncmp(CallDB[i].CallerTel, CallerTel, TELLENGTH))
                        return DIAL_BUSY;
                }
                return DIAL_OTHER;
            }
        }
    }
    strncpy(CallDB[j].CallerTel, CallerTel, TELLENGTH);
    strncpy(CallDB[j].CalledTel, CalledTel, TELLENGTH);
    CallDB[j].CallState = CALLSTATE_RING;
    return DIAL_FREE;
}