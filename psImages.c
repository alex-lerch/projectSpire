/*-----------------------------------------------------------------------------------------*
 *																						   *
 *   MODULE: psImages.c		            									               *
 *                                                                                         *
 *                                                                                         *
 *   Description:                                                                          *
 *                                                                                         *
 *      various text art displays                                                          *
 *                                                                                         *
 *                                                                                         *
 *   Functions:                                                                            *
 *                                                                                         *
 *      displayGameSymbol()     displays the game symbol                                   *
 *      displayDestroyedSpire() displays the game symbol destroyed                         *
 *                                                                                         *
 *-----------------------------------------------------------------------------------------*
 *   Changes:                                                                              *
 *                                                                                         *
 *      6/24/2022  Alex Lerch - Created                                                    *
 *-----------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------*
 *        Header Files                                                                     *
 *-----------------------------------------------------------------------------------------*/
#include "psImages.h"

/*-----------------------------------------------------------------------------------------*
 *                                                                                         *
 *   Function: displayGameSymbol()                                                         *
 *                                                                                         *
 *                                                                                         *
 *   Description:                                                                          *
 *                                                                                         *
 *      displays the game symbol                                                           *
 *                                                                                         *
 *                                                                                         *
 *   Returns: void                                                                         *
 *                                                                                         *
 *-----------------------------------------------------------------------------------------*/
void displayGameSymbol()
{
int sleepDuration = 500;

	puts("        *      ");
	Sleep(sleepDuration);
	puts("   *           ");
	Sleep(sleepDuration);
	puts("               ");
	Sleep(sleepDuration);
	puts("        *    *");
	Sleep(sleepDuration);
	puts("                ");
	Sleep(sleepDuration);
	puts("     *          ");
	Sleep(sleepDuration);
	puts("               ");
	Sleep(sleepDuration);
	puts("              ");
	Sleep(sleepDuration);
	puts("               ");
	Sleep(sleepDuration);
	puts("    __________");
	Sleep(sleepDuration);
	puts("   /__________\\");
	Sleep(sleepDuration);
	puts("    | []     |");
	Sleep(sleepDuration);
	puts("    |        |");
	Sleep(sleepDuration);
	puts("    |        |");
	Sleep(sleepDuration);
	puts("''''''''''''''''''''");
}


/*-----------------------------------------------------------------------------------------*
 *                                                                                         *
 *   Function: displayDestroyedSpire()                                                     *
 *                                                                                         *
 *                                                                                         *
 *   Description:                                                                          *
 *                                                                                         *
 *      displays the game symbol destroyed                                                 *
 *                                                                                         *
 *                                                                                         *
 *   Returns: void                                                                         *
 *                                                                                         *
 *-----------------------------------------------------------------------------------------*/
void displayDestroyedSpire()
{
	puts("      /;");
	puts("     /_;");
	puts("  .,/__|,.,.");
	puts("~~~~~~~~~~~~");
	puts("  ~~~~~~~~~~~~");
	puts("~~~~~~~~~~~~");
}