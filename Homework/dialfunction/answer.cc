#include "common_h/common.h"
#include "common_h/dial.h"

unsigned int Answer(const char *CalledTel)
{
    int UserState = 0;
    int i = 0;
    int AnswerState = 0;
    const char *UserAction = ANSWER;
    i = SortArray(CallDB);
    if (UserState = SearchUserDB(CalledTel))
    {
        return UserState;
    }
    if (AnswerState = JudgeCallExist(CalledTel,UserAction))
    {
        return AnswerState;
    }
    return AnswerState;
}