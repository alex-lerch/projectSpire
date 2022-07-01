/*-----------------------------------------------------------------------------------------*
 *																						   *
 *   MODULE: psInteractions.c		            								           *
 *                                                                                         *
 *                                                                                         *
 *   Description:                                                                          *
 *                                                                                         *
 *      functions relating to all possible interactions between characters                 *
 *                                                                                         *
 *                                                                                         *
 *   Functions:                                                                            *
 *                                                                                         *
 *      processDamage()         removes health from the target                             *
 *      battle()                two characters battle                                      *
 *      isAttackSuccessful()    character processes their attack                           *
 *      processEnemySelection() oversees the process of user selecting an enemy            *
 *                                                                                         *
 *-----------------------------------------------------------------------------------------*
 *   Changes:                                                                              *
 *                                                                                         *
 *      6/27/2022  Alex Lerch - Created                                                    *
 *-----------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------*
 *        Header Files                                                                     *
 *-----------------------------------------------------------------------------------------*/
#include "psInteractions.h"
#include "psCharacters.h"

/*-----------------------------------------------------------------------------------------*
 *                                                                                         *
 *   Function: processDamage()                                                             *
 *                                                                                         *
 *   Description:                                                                          *
 *                                                                                         *
 *    removes health from the target                                                       *
 *                                                                                         *
 *   Returns: void                                                                         *
 *                                                                                         *
 *-----------------------------------------------------------------------------------------*/
void applyDamage(Character* characterPtr, 
	             int dmg)
{
	characterPtr->health -= dmg;
}


/*-----------------------------------------------------------------------------------------*
 *                                                                                         *
 *   Function: battle()                                                                    *
 *                                                                                         *
 *   Description:                                                                          *
 *                                                                                         *
 *      two characters battle                                                              *
 *                                                                                         *
 *   Returns: Character* (the winning character)                                           *
 *                                                                                         *
 *-----------------------------------------------------------------------------------------*/
Character* battle(Character* playerPtr, 
	              Character* enemyPtr)
{
Character* winningCharacter;                           /* the character who won the battle */
BOOL attackSuccessful;                                        /* was the attack successful */

	/*-------------------------------------------------------------------------------------*
	 *        While both characters still have health left                                 *
	 *-------------------------------------------------------------------------------------*/
	while ((playerPtr->health > 0) && (enemyPtr->health > 0)) {
		/*---------------------------------------------------------------------------------*
		 *        Player attack phase                                                      *
		 *---------------------------------------------------------------------------------*/
		/* determine if attack is successful */
		attackSuccessful = isAttackSuccessful(playerPtr,
			                                  enemyPtr);

		/* display character boxes and result of attack attempt */
		displayBattleScreen(playerPtr,
			                enemyPtr,
							playerPtr,
			                enemyPtr,
			                attackSuccessful);

		/* end battle if enemy dies after the attack */
		if (enemyPtr->health <= 0) {
			printf("\n\n");
			Sleep(3000);
			return playerPtr;
		}

		/* create space in command prompt and make program wait so user can read */
		printf("\n\n");
		Sleep(3000);

		/*---------------------------------------------------------------------------------*
		 *        Enemy attack phase                                                       *
		 *---------------------------------------------------------------------------------*/
		/* determine if attack is successful */
		attackSuccessful = isAttackSuccessful(enemyPtr,
								              playerPtr);

		/* display character boxes and result of attack attempt */
		displayBattleScreen(playerPtr,
			                enemyPtr,
			                enemyPtr,
			                playerPtr,
			                attackSuccessful);

		/* end battle if player dies after the attack */
		if (playerPtr->health <= 0) {
			printf("\n\n");
			Sleep(3000);
			return enemyPtr;
		}

		/* create space in command prompt and make program wait so user can read */
		printf("\n\n");
		Sleep(3000);
	}

	/* in case player or enemy start battle with less than 0 or fewer hit points */
	return NULL;
}


/*-----------------------------------------------------------------------------------------*
 *                                                                                         *
 *   Function: isAttackSuccessful()                                                        *
 *                                                                                         *
 *   Description:                                                                          *
 *                                                                                         *
 *      determines if an attack is successful                                              *
 *                                                                                         *
 *   Returns: 0 - attack failed                                                            *
 *            1 - attack succeeded                                                         *
 *                                                                                         *
 *-----------------------------------------------------------------------------------------*/
BOOL isAttackSuccessful(Character* attacker, 
	                    Character* defender)
{
int defPercTargetNum;      /* the target number that the defense percentage needs to reach */

	/*calculate target number for defensePercentage*/
	defPercTargetNum = (rand() % 100) + 1;

	/*-------------------------------------------------------------------------------------*
	 *        if attack is successful                                                      *
	 *-------------------------------------------------------------------------------------*/
	if ((defender->defensePercentage) < defPercTargetNum) {
		/* apply damage to the defender's health */
		applyDamage(defender, 
			        attacker->atkValue);
		return TRUE;
	}

	/*-------------------------------------------------------------------------------------*
	 *        if defender blocks the attack                                                *
	 *-------------------------------------------------------------------------------------*/
	else {
		return FALSE;
	}
}


/*-----------------------------------------------------------------------------------------*
 *                                                                                         *
 *   Function: processEnemySelection()                                                     *
 *                                                                                         *
 *   Description:                                                                          *
 *                                                                                         *
 *      oversees the process of user selecting an enemy                                    *
 *                                                                                         *
 *   Returns: Character*                                                                   *
 *                                                                                         *
 *-----------------------------------------------------------------------------------------*/
Character* processEnemySelection(int currentRound, Character* enemyPool)
{
char optionNum[64];
Character* optionOne;
Character* optionTwo;

	/*-------------------------------------------------------------------------------------*
	 *        randomly select two enemies and display them for the player to pick          *
	 *-------------------------------------------------------------------------------------*/
	/* find out how many enemies/options there are */
	int numInEnemyPool = 4;

	/* get and display the first option */
	printf("          [1]\n");
	do {
		optionOne = (enemyPool + (rand() % numInEnemyPool));
	} while ((optionOne->level) != currentRound);
	displayCharacter(optionOne);

	/* create space between character boxes */
	printf("\n\n\n");

	/* get and display the second option */
	printf("          [2]\n");
	do {
		optionTwo = (enemyPool + (rand() % numInEnemyPool));
	} while ((optionTwo->level) != currentRound);
	displayCharacter(optionTwo);

	/*------------------------------------------------------------------------------------*
	 * get enemy selection from user                                                      *
	 *------------------------------------------------------------------------------------*/
	printf("\nSelect: ");
	for (;;) {
		scanf("%s", optionNum);
		if ((strcmp(optionNum, "1") == 0) || (strcmp(optionNum, "2") == 0)) {
			printf("\n");
			break;
		}
	}
	if ((strcmp(optionNum, "1") == 0))
		return optionOne;
	if ((strcmp(optionNum, "2") == 0))
		return optionTwo;

	/* default return enemy */
	return optionOne;
}