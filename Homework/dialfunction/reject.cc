#include "common_h/common.h"
#include "common_h/dial.h"

unsigned int Reject(const char *CalledTel)
{
    int UserState = 0;
    int i = 0;
    int RejectState = 0;
    const char *Action = REJECT;
    i = SortArray(CallDB);
    if (UserState = SearchUserDB(CalledTel))
    {
        return UserState;
    }
    if (RejectState = JudgeCallExist(CalledTel, Action))
    {
        return RejectState;
    }
    return RejectState;
}