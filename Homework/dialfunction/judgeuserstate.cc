#include "common_h/common.h"
#include "common_h/dial.h"

int JudgeUserState(CallData Tmp)
{
    if (USER_UNEXSIST == SearchUserDB(Tmp.CalledTel) || USER_UNEXSIST == SearchUserDB(Tmp.CallerTel))
    {
        return USER_UNEXSIST;
    }
    else if (USER_EXSIST_UNREGIST == SearchUserDB(Tmp.CalledTel) || USER_EXSIST_UNREGIST == SearchUserDB(Tmp.CallerTel))
    {
        return USER_EXSIST_UNREGIST;
    }
    return 0;
}