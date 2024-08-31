/* state_machine.c : sample code to understand state machine. */

#include <stdio.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define SM_DEBUG

enum STATES_IDX
{
    NOP, /* Index of NO OPERATION state: NOP = 0 */
    POWERUP,
    PREREADYSTATE,
    IDLE_STATE,
    NORMAL_STATE,
    FAULT_STATE,
    ERROR_STATE,
    MAX_STATE /* Maximum Number of state          */
};

/* enum Structure for state machine various actions */
enum ACTIONS
{
    NORMAL, /* Normal state, move on to next value                 */
    SKIP,   /* Allows the sequence list to be modified on the fly, */
            /* using the index as specified by the SKIP member of  */
            /* structure SSTATES.                                  */
    END     /* This is the end of the sub state list               */
};

enum STATEMACHINE
{
    STOPPED = 1, /* Indicates that State machine is stopped */
    RUNNING = 2  /* Indicates that State machine is running */
};

/* Sub State Structure */
typedef const struct substates
{
    bool *ValuePtr;           /* Pointer to value to be used for evaluation */
    enum ACTIONS True;        /* What to do if value evaluates to TRUE      */
    enum ACTIONS False;       /* What to do if value evaluates to FALSE     */
    unsigned short SkipIndex; /* Step number in sequence to go to           */
} SSTATES;

/* State Structure*/
typedef struct states
{
    SSTATES *ptr;           /* Pointer to sub state structure             */
    void (*PassPtr)(void);  /* Pointer to function to call every pass     */
    void (*EntryPtr)(void); /* Pointer to function to call on entry       */
    void (*ExitPtr)(void);  /* Pointer to function to call on normal exit */
    enum STATES_IDX state;  /* State currently in                         */
} STATE;

struct DebugStateStruct
{
    enum STATES_IDX Sidx;
    char *StateName;
};

const struct DebugStateStruct DBGS[] =
    {
        {NOP, "NOP_IDX"}, // 0
        {POWERUP, "POWERUP_IDX"},
        {PREREADYSTATE, "PREREADYSTATE_IDX"},
        {IDLE_STATE, "IDLE_STATE_IDX"},
        {NORMAL_STATE, "NORMAL_STATE_IDX"},
        {FAULT_STATE, "FAULT_STATE_IDX"}, // 5
        {ERROR_STATE, "ERROR_IDX"},
        {MAX_STATE, "MAX_STATE"},
};

#ifdef SM_DEBUG
void PrintStateName(int Indx)
{
    printf("\n %s ", DBGS[Indx].StateName);
}
#endif

/*------------------------------ PRIVATE GLOBAL DATA --------------------------------*/
static unsigned short StateMachineFlag = STOPPED; /* Current StateMachineFlag        */
static STATE *CurrentPtr;                         /* Current state pointer           */
static SSTATES *SSptr;                            /* Current sub state pointer       */
short CurrentIndex;                               /* Index to current state pointer */

enum STATES_IDX State;

STATE *Sequence[MAX_STATE + 1];

void StartStateMachine(void)
{
    StateMachineFlag = RUNNING;
}

void StateMachine(void)
{
    bool EndFlag = FALSE;
    enum ACTIONS Cond;
#ifdef SM_DEBUG
    static short LastIndx = -1;
#endif
    // Check state machine Flag
    if (StateMachineFlag == RUNNING)
    {
        CurrentPtr = Sequence[CurrentIndex];
        SSptr = CurrentPtr->ptr; /* Get sub state pointer      */

        if (CurrentPtr->PassPtr)
            CurrentPtr->PassPtr(); /* Execute this pass code     */

        while (EndFlag == FALSE)
        {
#ifdef SM_DEBUG
            if (LastIndx != CurrentIndex)
            {
                LastIndx = CurrentIndex;
                PrintStateName(CurrentIndex);
            }
#endif
            if ((*(SSptr->ValuePtr)) == FALSE) /* Test the value          */
                Cond = SSptr->False;           /* Was FALSE, use FALSE cmd */
            else
                Cond = SSptr->True; /* Was TRUE, use TRUE cmd   */

            switch (Cond)
            {
            case NORMAL:
                SSptr++; /* Move to Next Sub State   */
                break;
            case SKIP:
                if (CurrentPtr->ExitPtr)
                    CurrentPtr->ExitPtr();       /* Execute exit code       */
                CurrentIndex = SSptr->SkipIndex; /* Skip to next state      */
                CurrentPtr = Sequence[CurrentIndex];
                if (CurrentPtr->state != NOP)
                    State = CurrentPtr->state; /* Update state variable   */
                if (CurrentPtr->EntryPtr)
                    CurrentPtr->EntryPtr(); /* Execute new entry code                  */

                EndFlag = TRUE;
                break;

            default:
                EndFlag = TRUE;
                break;
            } // switch(Cond)
        }     // while(EndFlag == FALSE)
    }         // if(StateMachineFlag == RUNNING)
}

/*------------------------------ Global flags and states --------------------------------*/
bool SystemOK = TRUE;
bool DummyFlag = FALSE;

/*    Variable                   TRUE        FALSE       Skip      */
/*    pointer                    Action      Action      Index     */
/*    ----------                 -------     -------     ------    */
SSTATES Initial[] =
    {
        {&SystemOK, SKIP, NORMAL, POWERUP},
        {&DummyFlag, END, END, NOP}};

SSTATES PowerUp[] =
    {
        {&SystemOK, NORMAL, NORMAL, PREREADYSTATE},
        {&DummyFlag, END, END, NOP}};

void PowerUpEntry()
{
    printf(" %s \n ", __FUNCTION__);
}

void PowerUpPass()
{
    printf(" %s \n ", __FUNCTION__);
}

/* Substate Pass_Code Entry_Code Exit_Code	State */
STATE TopOfList =
    {Initial, NULL, NULL, NULL, NOP};

STATE PowerUpState =
    {PowerUp, PowerUpPass, PowerUpEntry, NULL, POWERUP};

void SelectSequence(void)
{
    Sequence[NOP] = &TopOfList;
    Sequence[POWERUP] = &PowerUpState;
    Sequence[PREREADYSTATE] = 0;
    Sequence[IDLE_STATE] = 0;
    Sequence[NORMAL_STATE] = 0;
    Sequence[FAULT_STATE] = 0;
    Sequence[ERROR_STATE] = 0;
    Sequence[MAX_STATE] = 0;
    CurrentPtr = 0;
    CurrentIndex = NOP;
    StateMachineFlag = STOPPED;
}

/* Driver code. */
int main()
{
    SelectSequence();
    /* Start the state machine */
    StartStateMachine();

    /* Get inputs */
    for (int i = 0; i < 10; i++)
    {
        StateMachine();
    }

    getchar();
    return 0;
}
