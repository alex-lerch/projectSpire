/*---------------------------------------------------------------------------------------------*
 *																							   *
 *   MODULE: psOutput.c																	       *
 *																							   *
 *																							   *
 *   Description:																			   *
 *																							   *
 *      Entrance to the program (projectSpire)    											   *
 *																							   *
 *																							   *
 *   Functions:																				   *
 *																							   *
 *      displayTextSlow()            displays the text to the screen at a slow rate            * 
 *      displayTextNormal()          displays the text to the screen at a normal rate          *
 *      displayBattleScreen()        displays character boxes and result of last attack        *
 *      displayBattleResultsScreen() displays character information after a battle is done     *
 *      refreshPage()                refreshes to a blank page                                 *
 *      displayGameLostScreen()      displays the losing game end screen                       *
 *      displayGameWonScreen()       displays the winning game end screen                      *
 *      displayCharacter()           displays character info to the screen                     *
 *																							   *
 *---------------------------------------------------------------------------------------------*
 *   Changes:																				   *
 *																							   *
 *      6/23/2022  Alex Lerch - Created														   *
 *---------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------*
 *        Header Files                                                                         *
 *---------------------------------------------------------------------------------------------*/
#include "systemHeaderFiles.h"
#include "psOutput.h"
#include "psImages.h"
#include "psCharacters.h"

/*---------------------------------------------------------------------------------------------*
 *        Constants                                                                            *
 *---------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------*
 *                                                                                             *
 *   Function: displayTextSlow()                                                               *
 *                                                                                             *
 *                                                                                             *
 *   Description:                                                                              *
 *                                                                                             *
 *      displays the text to the screen at a slow rate                                         *
 *                                                                                             *
 *                                                                                             *
 *   Returns: void                                                                             *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*/
void displayTextSlow(char* text)
{
	int i = 0;
	char ch = *(text + i);
	while ((ch = *(text + i++)) != '\0') {
		printf("%c", ch);
		Sleep(250);
	}
	printf("\n");
}

/*---------------------------------------------------------------------------------------------*
 *                                                                                             *
 *   Function: displayTextNormal()                                                             *
 *                                                                                             *
 *                                                                                             *
 *   Description:                                                                              *
 *                                                                                             *
 *      displays the text to the screen at a normal rate                                       *
 *                                                                                             *
 *                                                                                             *
 *   Returns: void                                                                             *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*/
void displayTextNormal(char* text)
{
	int i = 0;
	char ch = *(text + i);
	while ((ch = *(text + i++)) != '\0') {
		printf("%c", ch);
		Sleep(50);
	}
}


/*---------------------------------------------------------------------------------------------*
 *                                                                                             *
 *   Function: displayBattleScreen()                                                           *
 *                                                                                             *
 *                                                                                             *
 *   Description:                                                                              *
 *                                                                                             *
 *      displays character boxes and result of last attack                                     *
 *                                                                                             *
 *                                                                                             *
 *   Returns: void                                                                             *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*/
void displayBattleScreen(Character* player,
	                     Character* enemy,
	                     Character* attacker,
	                     Character* defender,
	                     BOOL attackSuccess)
{
	displayCharacter(player);
	/* if player is attacker and attack is successful */
	if ((player == attacker) && (attackSuccess == TRUE)) {
		printf("\n\n\n");
		printf("*%d*\n", player->atkValue);
	}
	/* if player is attacker and attack is not successful */
	if ((player == attacker) && (attackSuccess == FALSE)) {
		printf("\n\n\n");
		printf("[[]]\n");
	}
	/* if enemy is attacker and attack is successful */
	if ((enemy == attacker) && (attackSuccess == TRUE)) {
		printf("*%d*\n", enemy->atkValue);
		printf("\n\n\n");
	}
	/* if enemy is attacker and attack is not successful */
	if ((enemy == attacker) && (attackSuccess == FALSE)) {
		printf("[[]]\n");
		printf("\n\n\n");
	}
	/* display enemy info box */
	displayCharacter(enemy);
}


/*---------------------------------------------------------------------------------------------*
 *                                                                                             *
 *   Function: displayBattleResults()                                                          *
 *                                                                                             *
 *                                                                                             *
 *   Description:                                                                              *
 *                                                                                             *
 *      displays character information after a battle is done. is only called when the         *
 *      player wins the battle                                                                 *
 *                                                                                             *
 *                                                                                             *
 *   Returns: void                                                                             *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*/
void displayBattleResults(Character* winningCharacterPtr, Character* player)
{
	/* clear battle screen */
	refreshPage();

	/*-----------------------------------------------------------------------------------------*
	 *        if player won                                                                    *
	 *-----------------------------------------------------------------------------------------*/
	if (winningCharacterPtr == player) {
		//center horizontally
		for (int i = 0; i < (SCREEN_WIDTH - strlen("VICTORY")) / 2; i++) {
			printf(" ");
		}
		//display VICTORY
		printf("VICTORY");
		// center vertically
		for (int i = 0; i < SCREEN_HEIGHT / 2; i++) {
			printf("\n");
		}
		Sleep(3000);
		//clear rest of page
		refreshPage();

		/* display character stats screen */
		printf("Player Stats\n");
		/* display character information */
		displayCharacter(winningCharacterPtr);
		for (int i = 0; i < 9; i++) {
			printf("\n");
		}
		pause();
	}
	/*-----------------------------------------------------------------------------------------*
	 *        if enemy won                                                                     *
	 *-----------------------------------------------------------------------------------------*/
	else {
		//center horizontally
		for (int i = 0; i < (SCREEN_WIDTH - strlen("DEFEAT")) / 2; i++) {
			printf(" ");
		}
		//display VICTORY
		printf("DEFEAT");
		// center vertically
		for (int i = 0; i < SCREEN_HEIGHT / 2; i++) {
			printf("\n");
		}
		Sleep(3000);
		//clear rest of page
		refreshPage();
	}
	
}


/*---------------------------------------------------------------------------------------------*
 *                                                                                             *
 *   Function: refreshPage()                                                                   *
 *                                                                                             *
 *                                                                                             *
 *   Description:                                                                              *
 *                                                                                             *
 *      refreshes the window to a blank page                                                   *
 *                                                                                             *
 *                                                                                             *
 *   Returns: void                                                                             *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*/
void refreshPage()
{
	for (int i = 0; i < 18; i++) {
		printf("\n");
	}
}


/*---------------------------------------------------------------------------------------------*
 *                                                                                             *
 *   Function: displayGameLostScreen()                                                         *
 *                                                                                             *
 *                                                                                             *
 *   Description:                                                                              *
 *                                                                                             *
 *      displays the losing game end screen                                                    *
 *                                                                                             *
 *                                                                                             *
 *   Returns: void                                                                             *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*/
void displayGameLostScreen()
{
	displayGameSymbol();
	displayTextNormal("\nYou succumb to the pressure of the island. As the world around\n");
	displayTextNormal("begins to fade, fear grips you for those you left behind.\n");
	displayTextNormal("They'll be drawn, just as you were.\n");
	displayTextNormal("No one resists the will of the island.");
	pause();
}


/*---------------------------------------------------------------------------------------------*
 *                                                                                             *
 *   Function: displayGameWonScreen()                                                          *
 *                                                                                             *
 *                                                                                             *
 *   Description:                                                                              *
 *                                                                                             *
 *      displays the winning game end screen                                                   *
 *                                                                                             *
 *                                                                                             *
 *   Returns: void                                                                             *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*/
void displayGameWonScreen()
{
	displayDestroyedSpire();
	displayTextNormal("\nIt's finally done. The spire and it's influence are gone.\n");
	displayTextNormal("You send a flare soaring into the sky, then take a well\n");
	displayTextNormal("deserved rest on the beach. Just as you close your eyes,\n");
	displayTextNormal("you notice something");
	printf(".");
	Sleep(1000);
	printf(".");
	Sleep(1000);
	printf(".");
	Sleep(1000);
	displayTextNormal("the air is sweet and fragrant.");
	pause();
}


/*-----------------------------------------------------------------------------------------*
 *                                                                                         *
 *   Function: displayCharacter()                                                          *
 *                                                                                         *
 *   Description:                                                                          *
 *                                                                                         *
 *      prints the character's information to the screen                                   *
 *                                                                                         *
 *   Returns: void                                                                         *
 *                                                                                         *
 *-----------------------------------------------------------------------------------------*/
void displayCharacter(Character* character)
{
	int width = 25;                                                   /* width of the info box */
	int lengthOfHealthLine = 11;
	int lengthOfNameLine = (strlen(character->name) + 1);
	int lengthOfEquipmentLine = (strlen(character->atkIcon) + 10);

	/* print upper border */
	printf("=");
	for (int i = 0; i < width; i++)
		printf("=");
	printf("=\n");

	/* print character name line */
	printf("|");
	printf(" %s", character->name);
	for (int i = 0; i < (width - lengthOfNameLine); i++) {
		printf(" ");
	}
	printf("|\n");

	/* print night health line */
	if (strcmp(character->name, "night") == 0) {
		printf("|");

		printf(" Influence: %2d", character->health);
		for (int i = 0; i < (width - 14); i++) {
			printf(" ");
		}
		printf("|\n");
	}
	
	/* print day health line */
	if (strcmp(character->name, "night") != 0) {
		printf("|");
		printf(" Health: %2d", character->health);
		for (int i = 0; i < (width - lengthOfHealthLine); i++) {
			printf(" ");
		}
		printf("|\n");
	}

	/* print equipment line */
	printf("|");

	printf(" %s   [[%2d]]", character->atkIcon, (int)character->defensePercentage);
	for (int i = 0; i < (width - lengthOfEquipmentLine); i++) {
		printf(" ");
	}
	printf("|\n");

	/* print bottom border */
	printf("=");
	for (int i = 0; i < width; i++)
		printf("=");
	printf("=\n");
}