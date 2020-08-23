#include "common_h/common.h"
#include "common_h/dial.h"

int SearchUserDB(const char *CallTel)
{
    unsigned int i = 0;
    for (i = 0; i < DBLENGTH; i++)
    {
        if (0 == strncmp(UserDB[i].UserTel, CallTel, TELLENGTH))
        {
            if (UserDB[i].RegistState)
            {
                return USER_EXSIST_UNREGIST;
            }
            else
                return USER_EXSIST_REGIST;
        }
    }
    return USER_UNEXSIST;
}