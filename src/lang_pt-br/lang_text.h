// lang_text.h

#ifndef _LANG_TEXT_H
#define _LANG_TEXT_H


// == This has default strings
#include "../lang_text_defaults.inc"


// == #define overrides for language strings go here

// Brazilian Portuguese: Translation by Daniel Tolentino, revision by Bruno Maestrini

#undef INTRO_DIALOG_WIN_Y
#define INTRO_DIALOG_WIN_Y DIALOG_TEXT_HEIGHT_LINES(15)
#undef __INTRO_MESSAGE_STR
#define __INTRO_MESSAGE_STR \
/*  |------------------| Available space (18 chars wide) */\
    "IDIOMA: " STR(LANG_CODE) "\n" \
    "  APENAS PALAVRAS\n" \
    "  SEM ACENTO\n" \
    "\n" \
    "ABRIR MENU:\n" \
    "  3 x SELECT\n" \
    "\n" \
    "MOVER CURSOR:\n" \
    "  SELECT + B OU A\n" \
    "\n" \
    "COPIAR ACERTOS:\n" \
    "  SELECT + START\n" \
    "\n" \
    "APERTE A PARA\n" \
    "  JOGAR"


// #undef HELP_LEGEND_MAP_Y
// #undef HELP_LEGEND_MAP_Y_GAP
// #define HELP_LEGEND_MAP_Y (2u)     // Start Win Y for color key board letters
// #define HELP_LEGEND_MAP_Y_GAP (0u) // Gap between color key board letters in case more space is needed        
#undef HELP_LEGEND_DIALOG_WIN_Y
#define HELP_LEGEND_DIALOG_WIN_Y  DIALOG_TEXT_HEIGHT_LINES(7)
#undef __HELP_LEGEND_DIALOG_STR
#define __HELP_LEGEND_DIALOG_STR \
/*  |----------------XX| Available space (16 chars wide, 2 reserved for letter legend tiles) */\
    "TABELA DE CORES:\n" \
    "\n" \
    "LETRA ERRADA ...\n" \
    "\n" \
    "LUGAR ERRADO ...\n" \
    "\n" \
    "LUGAR CERTO ...."


#undef MENU_Y_EXIT
#undef MENU_Y_HARD_MODE
#undef MENU_Y_AUTO_FILL
#undef MENU_Y_SKIP_FILLED
#undef MENU_Y_SOUND_FX
#undef MENU_Y_SHOW_STATS
#undef MENU_Y_FORFEIT_ROUND
#undef MENU_Y_RESET_STATS
#undef MENU_Y_HELP
// "^" char gets replaced with a UI checkboxes reflecting option on/off state
// Leading space on each line is room for Cursor
// MAX Height is 16
#undef OPTIONS_MENU_DIALOG_WIN_Y
#define OPTIONS_MENU_DIALOG_WIN_Y  DIALOG_TEXT_HEIGHT_LINES(15)
#undef __OPTIONS_MENU_STR
#define __OPTIONS_MENU_STR \
/*  |------------------| Available space (18 chars wide) */\
    "  ... MENU ...\n" \
    "\n" \
    " FECHAR MENU\n" \
    "\n" \
    " MODO PRO .. ^\n" \
    " AUTOCOMPLETAR . ^\n" \
    " SALTAR\n" \
    "   AUTOCOMPLETAR ^\n" \
    " SOM ........... ^\n" \
    "\n" \
    " VER HISTÓRICO\n" \
    " DESISTIR PARTIDA\n" \
    " APAGAR HISTÓRICO\n" \
    "\n" \
    " AJUDA"

// "SKIP FILLED" is ok for "SKIP AUTOFILLED"

// These need to exactly match the menu order & formating above
// Line 0 is the first line of text
// menu header               0
// space                     1
#define MENU_Y_EXIT          2
// space                     3
#define MENU_Y_HARD_MODE     4
#define MENU_Y_AUTO_FILL     5
#define MENU_Y_SKIP_FILLED   6
#define MENU_Y_SOUND_FX      8
// space                     9
#define MENU_Y_SHOW_STATS    10
#define MENU_Y_FORFEIT_ROUND 11
#define MENU_Y_RESET_STATS   12
// space                     13
#define MENU_Y_HELP          14



#define CONFIRM_DIALOG_WIN_Y  DIALOG_TEXT_HEIGHT_LINES(6)
#undef __CONFIRM_DIALOG_STR
#define __CONFIRM_DIALOG_STR \
/*  |------------------| Available space (18 chars wide) */ \
    "CONFIRMAR:^\n" \
    "CANCELAR: \n"\
    "QUALQUER OUTRA\n" \
    "\n" \

#undef __CONFIRM_FORFEIT_STR
#define __CONFIRM_FORFEIT_STR     "DESISTE?"

#undef __CONFIRM_STATS_RESET_STR
#define __CONFIRM_STATS_RESET_STR "APAGAR HISTÓRICO?"


// Display hard mode indicator at top of screen
#undef OPT_HARDMODE_DISPLAY_X
#undef OPT_HARDMODE_DISPLAY_Y
#define OPT_HARDMODE_DISPLAY_X 5
#define OPT_HARDMODE_DISPLAY_Y 0

#undef __STR_HARD_MODE_DISPLAY
#undef __STR_HARD_MODE_HIDE
#define __STR_HARD_MODE_DISPLAY "PRO"
#define __STR_HARD_MODE_HIDE    "       "


#undef __MESSAGE_HARD_MODE_CANT_CHANGE_STR
#define __MESSAGE_HARD_MODE_CANT_CHANGE_STR \
/*  |------------------| Available space (18 chars wide) */\
    "MODO PRO: SOLO\n" \
    "MUDA APENAS EM\n" \
    "NOVA RODADA"


// Avoid increasing this popup height so it doesn't obscure the board
#undef __MESSAGE_HARD_MODE_GUESS_NOT_VALID_STR
#define __MESSAGE_HARD_MODE_GUESS_NOT_VALID_STR \
/*  |------------------| Available space (18 chars wide) */\
    "MODO PRO:\n" \
    "DEVE INCLUIR\n" \
    "LETRAS ACERTADAS"


// Avoid increasing this popup height so it doesn't obscure the board
#undef __MESSAGE_LOSE_STR
#define __MESSAGE_LOSE_STR \
/*  |------------------| Available space (18 chars wide) */\
    "Perdeu!\n" \
    "\n" \
    "Resposta: "    // <-- Needs 5 chars left for answer word!


// NOTE! ^ gets replaced with guess 5 letter word num
//
// Avoid increasing this popup height so it doesn't obscure the board
#undef __MESSAGE_GAME_WON_STR
#define __MESSAGE_GAME_WON_STR \
/*  |------------------| Available space (18 chars wide) */\
    "Acertou!\n" \
    "\n" \
    "Tentativa ^ DE 6"


// Avoid increasing this popup height so it doesn't obscure the board
#undef __MESSAGE_WORD_TOO_SHORT_STR
#define __MESSAGE_WORD_TOO_SHORT_STR \
/*  |------------------| Available space (18 chars wide) */\
    "Apenas palavras\n" \
    "\n" \
    "de 5 Letras"


// Avoid increasing this popup height so it doesn't obscure the board
#undef __MESSAGE_WORD_NOT_IN_DICT_STR
#define __MESSAGE_WORD_NOT_IN_DICT_STR \
/*  |------------------| Available space (18 chars wide) */\
    "Palavra\n" \
    "\n" \
    "desconhecida!"


#undef __MESSAGE_STATS_RESET_STR
#define __MESSAGE_STATS_RESET_STR \
/*  |------------------| Available space (18 chars wide) */\
    "HISTÓRICO APAGADO!"


#undef __STATS_TEMPLATE_STR
#define __STATS_TEMPLATE_STR \
/*  |------------------| Available space (18 chars wide) */\
    " Jogos ..... ____^\n" \
    " Invictos .. ____^\n" \
    " Acertos ... ____^\n" \
    " Erros ..... ____^\n" \
    "\n" \
    "Tentativas\n" \
    " Menor # ... ____^\n" \
    " Maior # ... ____^\n" \
    " Média...... ____^\n"   // <-- All "____^" get replaced by numbers

// Should be no more than 18 chars
#undef __INTRO_PRESS_START_STR
#undef __INTRO_PRESS_START_STR_BLANK
#define __INTRO_PRESS_START_STR       "APERTE START"
#define __INTRO_PRESS_START_STR_BLANK "            "


// X, Y controls upper-left corner coordinates
#undef __INTRO_CREDITS_STR
#define __INTRO_CREDITS_STR \
/*  |--------------------| */\
    "AGRADECIMENTOS:\n" \
    "TOXA\n" \
    "DAEO\n" \
    "ARPRUSS\n" \
    "COFFEE 'VALEN' BAT\n" \
    "STACKSMASHING\n" \
    "ZERAPHY\n" \
    "\n" \
    "GBDK2020\n" \
    "EMULICIOUS\n" \
    "FERRANTE CRAFTS"


#endif
