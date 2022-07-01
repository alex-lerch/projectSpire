/*---------------------------------------------------------------------------------------------*
 *																							   *
 *   MODULE: main.c																			   *
 *																							   *
 *																							   *
 *   Description:																			   *
 *																							   *
 *      Entrance to the program (projectSpire)    											   *
 *																							   *
 *																							   *
 *   Functions:																				   *
 *																							   *
 *      main() the main function															   *
 *																							   *
 *---------------------------------------------------------------------------------------------*
 *   Changes:																				   *
 *																							   *
 *      6/23/2022  Alex Lerch - Created														   *
 *---------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------*
 *        Header Files																		   *
 *---------------------------------------------------------------------------------------------*/
#include "systemHeaderFiles.h"
#include "psMenuFunctionality.h"
#include "psInput.h"
#include "psCharacters.h"
#include "psOutput.h"
#include "psImages.h"
#include "psInteractions.h"

/*---------------------------------------------------------------------------------------------*
 *        Constants   																		   *
 *---------------------------------------------------------------------------------------------*/
#define FINAL_ROUND 2

/*---------------------------------------------------------------------------------------------*
 *																							   *
 *   Function: main()																		   *
 *																							   *
 *   Description: the main function						                 					   *
 *																							   *
 *   return: 0 - Success																	   *
 *																							   *
 *   Error:																					   *
 *																							   *
 *---------------------------------------------------------------------------------------------*/
int main(void) 
{
srand(time(0));                                         /* random seed used for various things */
Character* playerPtr;
Character* enemyPtr;
Character* winningCharacterPtr = NULL;                  /* character who won the current round */
int currentRound = 1;

	/*-----------------------------------------------------------------------------------------*
	 *        Start Screen                                                                     *
	 *-----------------------------------------------------------------------------------------*/
	displayStartScreen();

	/*-----------------------------------------------------------------------------------------*
	 *        Create enemy pool                                                                *
	 *-----------------------------------------------------------------------------------------*/
	Character* enemyPool = createEnemyPool();

	/*-----------------------------------------------------------------------------------------*
	 *        Create the player's character                                                    *
	 *-----------------------------------------------------------------------------------------*/
	playerPtr = generatePlayer(10, 2, 99.0);
	printf("\n\n");

	/*-----------------------------------------------------------------------------------------*
	 *        Process round                                                                    *
	 *-----------------------------------------------------------------------------------------*/
	do {
		/* enemy selection */
		enemyPtr = processEnemySelection(currentRound, enemyPool);

		/* character and enemy battle */
		winningCharacterPtr = battle(playerPtr, enemyPtr);

		/* display the results of the battle */
		displayBattleResults(winningCharacterPtr, playerPtr);

		/* while it is not the final round and player won last round */
	} while ((currentRound++ != FINAL_ROUND) && (winningCharacterPtr == playerPtr));

	/*-----------------------------------------------------------------------------------------*
	 *        Game end screens                                                                 *
	 *-----------------------------------------------------------------------------------------*/
	/* if the enemy won */
	if (winningCharacterPtr != playerPtr)
		displayGameLostScreen();

	/* if the player won */
	if (winningCharacterPtr == playerPtr)
		displayGameWonScreen();


	/*-----------------------------------------------------------------------------------------*
	 *        Program Exit                                                                     *
	 *-----------------------------------------------------------------------------------------*/
	return 0;
}