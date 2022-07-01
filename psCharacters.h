/*-----------------------------------------------------------------------------------------*
 *																						   *
 *   Header: psCharacters.h									          		               *
 *                                                                                         *
 *                                                                                         *
 *   Description:                                                                          *
 *                                                                                         *
 *      structs and fuctions relating to all the characters                                *
 *                                                                                         *
 *-----------------------------------------------------------------------------------------*
 *   Changes:                                                                              *
 *                                                                                         *
 *      6/24/2022  Alex Lerch - Created                                                    *
 *-----------------------------------------------------------------------------------------*/
#ifndef PSCHARACTERS_H_
#define PSCHARACTERS_H_

/*-----------------------------------------------------------------------------------------*
 *        Header Files                                                                     *
 *-----------------------------------------------------------------------------------------*/
#include "psInput.h"

/*-----------------------------------------------------------------------------------------*
 *        Constants                                                                        *
 *-----------------------------------------------------------------------------------------*/
#define NAME_LENGTH 64

/*-----------------------------------------------------------------------------------------*
 *        Structures                                                                       *
 *-----------------------------------------------------------------------------------------*/
typedef struct {
	char name[NAME_LENGTH + 1];
	int health;
	int atkValue;
	int defensePercentage;
	char* atkIcon;
	int level;
} Character;

/*-----------------------------------------------------------------------------------------*
 *        Functions                                                                        *
 *-----------------------------------------------------------------------------------------*/
Character* generatePlayer(int newHealth, int newAtkValue, float newDefensePercentage);
Character* generateEnemy(char newName[], int newHealth, int newAtkValue, float newDefensePercentage, int level);
char* generateNightAtkIcon(int atkValue);
char* generateDayAtkIcon(int atkValue);
Character* createEnemyPool();

#endif