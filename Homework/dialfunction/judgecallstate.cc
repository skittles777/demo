#include "common_h/common.h"
#include "common_h/dial.h"

int JudgeCallState(CallData Tmp)
{
    if (DIAL_FREE == SearchCallDB(Tmp.CallerTel, Tmp.CalledTel))
    {
        return CALLSTATE_RING;
    }
    else if (DIAL_BUSY == SearchCallDB(Tmp.CallerTel, Tmp.CalledTel))
    {
        return DIAL_BUSY;
    }
    else
        return DIAL_OTHER;
}