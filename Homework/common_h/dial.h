#ifndef DIAL_H_
#define DIAL_H_

#define CHECK_MALLOC(ptr) \
    if (NULL == ptr)      \
    {                     \
        return 1;         \
    }
/*return of Dial()*/
#define USER_UNEXSIST (int)1
#define USER_EXSIST_REGIST (int)0
#define USER_EXSIST_UNREGIST (int)2
#define DIAL_BUSY (int)3
#define DIAL_OTHER (int)4

#define DIAL_FREE (int)0
/*return of Answer()*/
#define CALL_SETUP (int)0
#define CALL_UNEXSIST (int)3
#define ANSWSER_OTHER (int)4

/*return of Answer()*/
#define CALL_REJECT (int)0
#define REJECT_OTHER (int)4
#define ANSWER "Answer"
#define REJECT "Reject"

/*return of Release()*/
#define CALL_RELEASE (int)0
#define RELEASE_OTHER (int)4
#define RELEASECALLER "Caller"
#define RELEASECALLED "Called"

void DealCallData(const char *CallTels, CallData *Tmp);
int SearchUserDB(const char *CallTel);
int SearchCallDB(const char *CallerTel, const char *CalledTel);
int JudgeUserState(CallData Tmp);
int JudgeCallState(CallData Tmp);
int JudgeCallExist(const char *CallTel, const char *UserAction);
int JudgeRelease(const char *CallTel, const char *UserRole);
int ReleaseCalled(const char *CalledTel);
int ReleaseCaller(const char *CallerTel);
int SortArray(CallData *CallDB);
unsigned int CountArraySize(CallData *CallDB);

#endif