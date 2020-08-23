#include "common_h/common.h"
#include "common_h/dial.h"

int ReleaseCaller(const char *CallerTel)
{
    int UserState = 0;
    int i = 0;
    int RleaseState = 0;
    const char *UserCaller = RELEASECALLER;
    i = SortArray(CallDB);
    if (UserState = SearchUserDB(CallerTel))
    {
        return UserState;
    }

    if (RleaseState = JudgeRelease(CallerTel, UserCaller))
    {
        return RleaseState;
    }
    return RleaseState;
}