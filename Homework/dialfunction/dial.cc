#include "common_h/common.h"
#include "common_h/dial.h"

unsigned int Dial(const char *UserTel)
{
    CallData Tmp = {0};
    int UserState = 0;
    int CallState = 0;
    DealCallData(UserTel, &Tmp);

    /*Search UserDB*/
    if (UserState = JudgeUserState(Tmp, UserDB))
    {
        return UserState;
    }
    /*Search CallDB*/
    if (CallState = JudgeCallState(Tmp, UserDB))
    {
        return CallState;
    }
    return CALLSTATE_RING;
}