/*-----------------------------------------------------------------------------------------*
 *																						   *
 *   MODULE: psCharacters.c		            								               *
 *                                                                                         *
 *                                                                                         *
 *   Description:                                                                          *
 *                                                                                         *
 *      structs and fuctions relating to all the characters                                *
 *                                                                                         *
 *                                                                                         *
 *   Functions:                                                                            *
 *                                                                                         *
 *      generateEnemy()        generates an enemy                                          *
 *      generatePlayer()       generates a player character                                *
 *      generateNightAtkIcon() generates night attack icon                                 *
 *      generateDayAtkIcon()   generates day attack icon                                   *
 *      createEnemyPool()      creates enemies and puts them in an array                   *
 *                                                                                         *
 *-----------------------------------------------------------------------------------------*
 *   Changes:                                                                              *
 *                                                                                         *
 *      6/24/2022  Alex Lerch - Created                                                    *
 *-----------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------*
 *        Header Files                                                                     *
 *-----------------------------------------------------------------------------------------*/
#include "psCharacters.h"
#include "psOutput.h"

/*-----------------------------------------------------------------------------------------*
 *                                                                                         *
 *   Function: generateEnemy()                                                             *
 *                                                                                         *
 *                                                                                         *
 *   Description:                                                                          *
 *                                                                                         *
 *      generates an enemy                                                                 *
 *                                                                                         *
 *                                                                                         *
 *   Returns: Character*                                                                   *
 *                                                                                         *
 *-----------------------------------------------------------------------------------------*/
Character* generateEnemy(char newName[],
	                    int newHealth,
	                    int newAtkValue,
	                    float newDefensePercentage,
	                    int newLevel)
{
	Character* enemyPtr;
	enemyPtr = malloc(sizeof(Character));
	strcpy(enemyPtr->name, 
		   newName);
	enemyPtr->atkValue = newAtkValue;
	enemyPtr->health = newHealth;
	enemyPtr->defensePercentage = newDefensePercentage;
	enemyPtr->atkIcon = generateDayAtkIcon(enemyPtr->atkValue);
	enemyPtr->level = newLevel;
	return enemyPtr;
}


/*-----------------------------------------------------------------------------------------*
 *                                                                                         *
 *   Function: generatePlayer()                                                            *
 *                                                                                         *
 *                                                                                         *
 *   Description:                                                                          *
 *                                                                                         *
 *      Creates a player                                                                   *
 *                                                                                         *
 *                                                                                         *
 *   Returns: Character*                                                                   *
 *                                                                                         *
 *-----------------------------------------------------------------------------------------*/
Character* generatePlayer(int newHealth,
	                      int newAtkValue,
	                      float newDefensePercentage)
{
	Character* playerPtr;
	playerPtr = malloc(sizeof(Character));
	strcpy(playerPtr->name, "night");
	playerPtr->atkValue = newAtkValue;
	playerPtr->health = newHealth;
	playerPtr->defensePercentage = newDefensePercentage;
	playerPtr->atkIcon = generateNightAtkIcon(playerPtr->atkValue);
	playerPtr->level = 1;
	return playerPtr;
}





/*-----------------------------------------------------------------------------------------*
 *                                                                                         *
 *   Function: generateNightAtkIcon()                                                      *
 *                                                                                         *
 *   Description:                                                                          *
 *                                                                                         *
 *      generates night attack icon                                                        *
 *                                                                                         *
 *   Returns: char[]                                                                       *
 *                                                                                         *
 *-----------------------------------------------------------------------------------------*/
char* generateNightAtkIcon(int atkValue) 
{
	char* nightAtkIcon;
	nightAtkIcon = malloc(atkValue);
	strcpy(nightAtkIcon, ")");
	for (int i = 0; i < atkValue - 1; i++) {
		strcat(nightAtkIcon, ")");
	}
	return nightAtkIcon;
}


/*-----------------------------------------------------------------------------------------*
 *                                                                                         *
 *   Function: createEnemyPool()                                                           *
 *                                                                                         *
 *   Description:                                                                          *
 *                                                                                         *
 *      creates enemies and puts them in an array                                          *
 *                                                                                         *
 *   Returns: char[]                                                                       *
 *                                                                                         *
 *-----------------------------------------------------------------------------------------*/
Character* createEnemyPool()
{
int numEnemies = 4;                                /* number of different types of enemies */
Character* enemyDatabase = NULL;                     /* the database that will be returned */

		enemyDatabase = malloc(numEnemies * sizeof(Character));
		enemyDatabase[0] = *generateEnemy("lunch", 4, 2, 5.0, 1);
		enemyDatabase[1] = *generateEnemy("morning newspaper", 10, 1, 3.0, 1);
		enemyDatabase[2] = *generateEnemy("the beach", 3, 1, 25.0, 2);
		enemyDatabase[3] = *generateEnemy("heliophobia", 10, 2, 10.0, 2);
		/*swing set, glare, sunburn, kite, chloroplast, picnic, apollo, the sun*/

	return enemyDatabase;
}


/*-----------------------------------------------------------------------------------------*
 *                                                                                         *
 *   Function: generateDayAtkIcon()                                                      *
 *                                                                                         *
 *   Description:                                                                          *
 *                                                                                         *
 *      generates night attack icon                                                        *
 *                                                                                         *
 *   Returns: char[]                                                                       *
 *                                                                                         *
 *-----------------------------------------------------------------------------------------*/
char* generateDayAtkIcon(int atkValue)
{
	char* dayAtkIcon;
	dayAtkIcon = malloc(atkValue);
	strcpy(dayAtkIcon, ">");
	for (int i = 0; i < atkValue - 1; i++) {
		strcat(dayAtkIcon, ">");
	}
	return dayAtkIcon;
}