/*-----------------------------------------------------------------------------------------*
 *																						   *
 *   Header: psInteractions.h								          		               *
 *                                                                                         *
 *                                                                                         *
 *   Description:                                                                          *
 *                                                                                         *
 *      functions relating to all possible interactions between characters                 *
 *                                                                                         *
 *-----------------------------------------------------------------------------------------*
 *   Changes:                                                                              *
 *                                                                                         *
 *      6/27/2022  Alex Lerch - Created                                                    *
 *-----------------------------------------------------------------------------------------*/
#ifndef PSINTERACTIONS_H_
#define PSINTERACTIONS_H_

/*-----------------------------------------------------------------------------------------*
 *        Header Files                                                                     *
 *-----------------------------------------------------------------------------------------*/
#include "systemHeaderFiles.h"
#include "psCharacters.h"
#include "psOutput.h"

/*-----------------------------------------------------------------------------------------*
 *        Constants                                                                        *
 *-----------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------*
 *        Functions                                                                        *
 *-----------------------------------------------------------------------------------------*/
void applyDamage(Character* character, int dmg);
Character* battle(Character* player, Character* enemy);
BOOL isAttackSuccessful(Character* attacker, Character* defender);
Character* processEnemySelection(int currentFloor, Character* enemyPool);

#endif