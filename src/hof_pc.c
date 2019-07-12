#include "global.h"
#include "hall_of_fame.h"
#include "palette.h"
#include "overworld.h"
#include "script.h"
#include "script_menu.h"
#include "task.h"
#include "hall_of_fame.h"
#include "bg.h"
#include "window.h"

static void ReshowPCMenuAfterHallOfFamePC(void);
static void Task_WaitForPaletteFade(u8 taskId);

static void Task_WaitFadeAndSetCallback(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        ResetBgsAndClearDma3BusyFlags(0);
        DestroyTask(taskId);
        SetMainCallback2(sub_80F2978);
    }
}

void HallOfFamePCBeginFade(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
    ScriptContext2_Enable();
    CreateTask(Task_WaitFadeAndSetCallback, 0);
}

void ReturnFromHallOfFamePC(void)
{
    SetMainCallback2(CB2_ReturnToField);
    gFieldCallback = ReshowPCMenuAfterHallOfFamePC;
}

static void ReshowPCMenuAfterHallOfFamePC(void)
{
    ScriptContext2_Enable();
    Overworld_PlaySpecialMapMusic();
    ScrSpecial_CreatePCMenu();
    ScriptMenu_DisplayPCStartupPrompt();
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
    CreateTask(Task_WaitForPaletteFade, 10);
}

static void Task_WaitForPaletteFade(u8 taskId)
{
    if (!gPaletteFade.active)
        DestroyTask(taskId);
}