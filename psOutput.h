/*-----------------------------------------------------------------------------------------*
 *																						   *
 *   Header: psOutput.h									              		               *
 *                                                                                         *
 *                                                                                         *
 *   Description:                                                                          *
 *                                                                                         *
 *      various functions relating to output                                               *
 *                                                                                         *
 *-----------------------------------------------------------------------------------------*
 *   Changes:                                                                              *
 *                                                                                         *
 *      6/24/2022  Alex Lerch - Created                                                    *
 *-----------------------------------------------------------------------------------------*/
#ifndef PSOUTPUT_H_
#define PSOUTPUT_H_

/*-----------------------------------------------------------------------------------------*
 *        Header Files                                                                     *
 *-----------------------------------------------------------------------------------------*/
#include "systemHeaderFiles.h"
#include "psCharacters.h"

/*-----------------------------------------------------------------------------------------*
 *        Constants                                                                        *
 *-----------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------*
 *        Functions                                                                        *
 *-----------------------------------------------------------------------------------------*/
void displayTextSlow(char* text);
void displayTextNormal(char* text);
void displayBattleScreen(Character* player, Character* enemy, Character* attacker, Character* defender, BOOL attackSuccess);
void displayBattleResults(Character* winningCharacter, Character* player);
void refreshPage();
void displayGameLostScreen();
void displayGameWonScreen();
void displayCharacter(Character* character);


#endif