#include "common_h/common.h"
#include "common_h/dial.h"

// int JudgeCallExistForAns(const char *CallTel)
int JudgeCallExist(const char *CallTel, const char *UserAction)
{
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = 0;
    const char *AnswerAction = ANSWER;
    const char *RejectAction = REJECT;
    k = SortArray(CallDB);
    j = CountArraySize(CallDB);
    for (i = 0; i < j; i++)
    {
        if (strncmp(CallTel, CallDB[i].CalledTel, TELLENGTH))
        {
            continue;
        }

        if (CALLSTATE_RING == CallDB[i].CallState)
        {
            if (0 == strncmp(UserAction, AnswerAction, sizeof(AnswerAction)))
                CallDB[i].CallState = CALLSTATE_CONNECTED;
            if (0 == strncmp(UserAction, RejectAction, sizeof(RejectAction)))
                CallDB[i].CallState = CALLSTATE_OTHER;
            return CALL_SETUP;
        }

        if (CALLSTATE_CONNECTED == CallDB[i].CallState)
        {
            return ANSWSER_OTHER;
        }
    }
    return CALL_UNEXSIST;
}

/*Anwser() is same with Reject()*/
// int JudgeCallExistForRej(const char *CallTel)
// {
//     unsigned int i = 0;
//     unsigned int j = 0;
//     unsigned int k = 0;
//     k = SortArray(CallDB);
//     j = CountArraySize(CallDB);
//     for (i = 0; i < j; i++)
//     {
//         if (strncmp(CallTel, CallDB[i].CalledTel, TELLENGTH))
//         {
//             continue;
//         }
//         if (CALLSTATE_RING == CallDB[i].CallState)
//         {
//             return CALL_REJECT;
//         }
//         if (CALLSTATE_CONNECTED == CallDB[i].CallState)
//         {
//             return REJECT_OTHER;
//         }
//     }
//     return CALL_UNEXSIST;
// }