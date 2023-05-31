HidingOak_EventScript_ResetHunt::
	msgbox HidingOak_Text_HideAllOaks, MSGBOX_SIGN
    setvar VAR_HIDDEN_OAK_FOUND_COUNTER, 0
    setvar VAR_HIDDEN_OAK_FLAG_OFFSET, 0
    call HidingOak_EventScript_RecursivelyHideAllOaks
    setvar VAR_HIDDEN_OAK_FLAG_OFFSET, 0
    call HidingOak_EventScript_RecursivelyUnFindAllOaks
	warp MAP_PALLET_TOWN, 8, 16
    playfanfare MUS_OBTAIN_KEY_ITEM
	end

HidingOak_EventScript_StartHunt::
	msgbox HidingOak_Text_SpawnOaks, MSGBOX_SIGN
    setvar VAR_HIDDEN_OAK_SPAWN_COUNTER_INDEX, 0
    call HidingOak_EventScript_RecursivelySpawnOaks
	warp MAP_PALLET_TOWN, 8, 16
    playfanfare MUS_OBTAIN_KEY_ITEM
	end

HidingOak_EventScript_TryEndHunt::
    buffernumberstring STR_VAR_1, VAR_HIDDEN_OAK_FOUND_COUNTER
    call_if_ge VAR_HIDDEN_OAK_FOUND_COUNTER, HIDDEN_OAK_SPAWN_COUNT, HidingOak_EventScript_HuntSuccess
    call_if_lt VAR_HIDDEN_OAK_FOUND_COUNTER, HIDDEN_OAK_SPAWN_COUNT, HidingOak_EventScript_HuntFailure
	warp MAP_PALLET_TOWN, 8, 16
	end

HidingOak_EventScript_RecursivelyHideAllOaks::
    setflagwithoffset HIDDEN_OAK_INVISIBLE_FLAGS_START, VAR_HIDDEN_OAK_FLAG_OFFSET
    addvar VAR_HIDDEN_OAK_FLAG_OFFSET, 1
    goto_if_le VAR_HIDDEN_OAK_FLAG_OFFSET, (MAX_HIDDEN_OAK_COUNT - 1), HidingOak_EventScript_RecursivelyHideAllOaks
    return

HidingOak_EventScript_RecursivelyUnFindAllOaks::
    clearflagwithoffset HIDDEN_OAK_FOUND_FLAGS_START, VAR_HIDDEN_OAK_FLAG_OFFSET
    addvar VAR_HIDDEN_OAK_FLAG_OFFSET, 1
    goto_if_le VAR_HIDDEN_OAK_FLAG_OFFSET, (MAX_HIDDEN_OAK_COUNT - 1), HidingOak_EventScript_RecursivelyUnFindAllOaks
    return

HidingOak_EventScript_RecursivelySpawnOaks::
    random MAX_HIDDEN_OAK_COUNT
    copyvar VAR_HIDDEN_OAK_FLAG_OFFSET, VAR_RESULT
    goto_if_unsetwithoffset HIDDEN_OAK_INVISIBLE_FLAGS_START, VAR_HIDDEN_OAK_FLAG_OFFSET, HidingOak_EventScript_RecursivelySpawnOaks
    clearflagwithoffset HIDDEN_OAK_INVISIBLE_FLAGS_START, VAR_HIDDEN_OAK_FLAG_OFFSET
    addvar VAR_HIDDEN_OAK_SPAWN_COUNTER_INDEX, 1
    goto_if_lt VAR_HIDDEN_OAK_SPAWN_COUNTER_INDEX, HIDDEN_OAK_SPAWN_COUNT, HidingOak_EventScript_RecursivelySpawnOaks
    return

HidingOak_EventScript_CheckOak::
    copyvar VAR_HIDDEN_OAK_FLAG_OFFSET, VAR_HIDDEN_OAK_CURRENT_DIALOG
    call_if_setwithoffset HIDDEN_OAK_FOUND_FLAGS_START, VAR_HIDDEN_OAK_FLAG_OFFSET, HidingOak_EventScript_FoundOldOak
    call_if_unsetwithoffset HIDDEN_OAK_FOUND_FLAGS_START, VAR_HIDDEN_OAK_FLAG_OFFSET, HidingOak_EventScript_FoundNewOak
    return

HidingOak_EventScript_FoundNewOak::
    msgbox HidingOak_Text_NewlyFoundOak, MSGBOX_NPC
    setflagwithoffset HIDDEN_OAK_FOUND_FLAGS_START, VAR_HIDDEN_OAK_FLAG_OFFSET
    addvar VAR_HIDDEN_OAK_FOUND_COUNTER, 1
    return    

HidingOak_EventScript_FoundOldOak::
    msgbox HidingOak_Text_PreviouslyFoundOak, MSGBOX_NPC
    return 

HidingOak_EventScript_HuntSuccess::
	playfanfare MUS_OBTAIN_BADGE
    msgbox HidingOak_Text_HuntSuccess, MSGBOX_SIGN
    return

HidingOak_EventScript_HuntFailure::
    msgbox HidingOak_Text_HuntFailure, MSGBOX_SIGN
    return

HidingOak_EventScript_FoundOak_1::
    setvar VAR_HIDDEN_OAK_CURRENT_DIALOG, 1
    call HidingOak_EventScript_CheckOak
	msgbox HidingOak_Text_SecretPhrase_1, MSGBOX_NPC
	end

HidingOak_EventScript_FoundOak_2::
    setvar VAR_HIDDEN_OAK_CURRENT_DIALOG, 2
    call HidingOak_EventScript_CheckOak
	msgbox HidingOak_Text_SecretPhrase_2, MSGBOX_NPC
	end

HidingOak_EventScript_FoundOak_3::
    setvar VAR_HIDDEN_OAK_CURRENT_DIALOG, 3
    call HidingOak_EventScript_CheckOak
	msgbox HidingOak_Text_SecretPhrase_3, MSGBOX_NPC
	end

HidingOak_EventScript_FoundOak_4::
    setvar VAR_HIDDEN_OAK_CURRENT_DIALOG, 4
    call HidingOak_EventScript_CheckOak
	msgbox HidingOak_Text_SecretPhrase_4, MSGBOX_NPC
	end

HidingOak_EventScript_FoundOak_5::
    setvar VAR_HIDDEN_OAK_CURRENT_DIALOG, 5
    call HidingOak_EventScript_CheckOak
	msgbox HidingOak_Text_SecretPhrase_5, MSGBOX_NPC
	end
