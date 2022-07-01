/*-----------------------------------------------------------------------------------------*
 *																						   *
 *   MODULE: psInput.c											                           *
 *                                                                                         *
 *                                                                                         *
 *   Description:                                                                          *
 *                                                                                         *
 *      various functions related to input                                                 *
 *                                                                                         *
 *                                                                                         *
 *   Functions:                                                                            *
 *                                                                                         *
 *      askForString() gets string from user                                               *
 *      pause()        pauses program until user presses enter                             *
 *                                                                                         *
 *-----------------------------------------------------------------------------------------*
 *   Changes:                                                                              *
 *                                                                                         *
 *      6/23/2022  Alex Lerch - Created                                                    *
 *-----------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------*
 *        Header Files                                                                     *
 *-----------------------------------------------------------------------------------------*/
#include "psInput.h"
#include "psOutput.h"

/*-----------------------------------------------------------------------------------------*
 *                                                                                         *
 *   Function: askForString()                                                              *
 *                                                                                         *
 *   Description: gets string from user                                                    *
 *                                                                                         *
 *   Returns: char*                                                                        *
 *                                                                                         *
 *-----------------------------------------------------------------------------------------*/
char* askForString(char* requestMessage,        /* the message to be displayed to the user */
	               char responseStorage[],     /* where the user response should be stored */
				   int   maxSize)                 /* the number of chars that will be read */
{
int currentChar;
int i = 0;

	displayTextNormal(requestMessage);
	while ((currentChar = getchar()) != '\n') {
		if (i < maxSize)
			responseStorage[i++] = currentChar;
	}
	responseStorage[i] = '\0';
	return responseStorage;
}


/*-----------------------------------------------------------------------------------------*
 *                                                                                         *
 *   Function: pause()                                                                     *
 *                                                                                         *
 *   Description:                                                                          *
 *                                                                                         *
 *      pauses the program until the user presses enter                                    *
 *                                                                                         *
 *   Returns: void                                                                         *
 *                                                                                         *
 *-----------------------------------------------------------------------------------------*/
void pause()
{
	printf("enter to continue");
	fflush(stdout);
	getchar();
}