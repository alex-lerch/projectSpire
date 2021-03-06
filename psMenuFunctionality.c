/*-----------------------------------------------------------------------------------------*
 *																						   *
 *   MODULE: psMenuFunctionality.c											               *
 *                                                                                         *
 *                                                                                         *
 *   Description:                                                                          *
 *                                                                                         *
 *      various functions that populate and manipulate menus                               *
 *                                                                                         *
 *                                                                                         *
 *   Functions:                                                                            *
 *                                                                                         *
 *      displayStartScreen() displays the start screen                                     *
 *                                                                                         *
 *-----------------------------------------------------------------------------------------*
 *   Changes:                                                                              *
 *                                                                                         *
 *      6/23/2022  Alex Lerch - Created                                                    *
 *-----------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------*
 *        Header Files                                                                     *
 *-----------------------------------------------------------------------------------------*/
#include "psMenuFunctionality.h"
#include "psOutput.h"

/*-----------------------------------------------------------------------------------------*
 *                                                                                         *
 *   Function: displayStartScreen()                                                        *
 *                                                                                         *
 *   Description: displays the start screen                                                *
 *                                                                                         *
 *   Returns: void                                                                         *
 *                                                                                         *
 *-----------------------------------------------------------------------------------------*/
void displayStartScreen()
{
	/*-------------------------------------------------------------------------------------*
	 *        title screen                                                                 *
	 *-------------------------------------------------------------------------------------*/
	refreshPage();
	displayGameSymbol();
	displayTextSlow("Spark in the Night\n\n");
	pause();

	/*-------------------------------------------------------------------------------------*
	 *        print story intro                                                            *
	 *-------------------------------------------------------------------------------------*/
	refreshPage();
}