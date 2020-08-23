#include "common_h/common.h"
#include "common_h/dial.h"

int JudgeRelease(const char *CallTel, const char *UserRole)
{
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = 0;
    const char *UserCaller = RELEASECALLER;
    const char *UserCalled = RELEASECALLED;
    k = SortArray(CallDB);
    j = CountArraySize(CallDB);
    for (i = 0; i < j; i++)
    {
        if (0 == strncmp(UserRole, UserCalled, sizeof(UserCalled)))
        {
            if (strncmp(CallTel, CallDB[i].CalledTel, TELLENGTH))
            {
                continue;
            }
        }
        else
        {
            if (strncmp(CallTel, CallDB[i].CallerTel, TELLENGTH))
            {
                continue;
            }
        }
        
        if (CALLSTATE_RING == CallDB[i].CallState)
        {
            return RELEASE_OTHER;
        }

        if (CALLSTATE_CONNECTED == CallDB[i].CallState)
        {
            CallDB[i].CallState = CALLSTATE_OTHER;
            return CALL_RELEASE;
        }
    }
    return CALL_UNEXSIST;
}