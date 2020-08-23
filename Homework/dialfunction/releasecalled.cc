#include "common_h/common.h"
#include "common_h/dial.h"

int ReleaseCalled(const char *CalledTel)
{
    int UserState = 0;
    int i = 0;
    int RleaseState = 0;
    const char *UserCalled = RELEASECALLED;
    i = SortArray(CallDB);
    if (UserState = SearchUserDB(CalledTel))
    {
        return UserState;
    }
    
    if (RleaseState = JudgeRelease(CalledTel, UserCalled))
    {
        return RleaseState;
    }
    return RleaseState;
}