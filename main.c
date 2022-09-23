/**********************************
Gal Giladi
**********************************/
//#define _CRTDBG_MAP_ALLOC
//#include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#define SIZE 500
#define SIZE1 50

/********************************
Function Name: isCharRep
Input: char type as a capital letter or lower 
Output: int - 1 or 0
Function Operation: the function returns 1 if the given char
can be represented by seven-segment display, or 0 if it can't.
********************************/
int isCharRep(char character)
{
	/*array of all the possible capital letters that can be 
	represented by seven - segment display*/
	char strUpperChar[] = { 'A', 'C', 'E', 'F','G','H','I','J','L','O','P','S','U','\0' };
	size_t UpperLength = strlen(strUpperChar);
	//if the character that is given as an input fits, then return 1, o.w return 0
	for (int i = 0; i < UpperLength; i++)
	{
		if (character == strUpperChar[i])
		{
			return 1;
		}
	}

	/*array of all the possible lower letters that can be
	represented by seven - segment display*/
	char strLowerChar[] = { 'b', 'c', 'd', 'h','i','n','o','q','r','t','u','y','\0' };
	size_t LowerLength = strlen(strLowerChar);
	//if the character that is given as an input fits, then return 1, o.w return 0
	for (int i = 0; i < LowerLength; i++)
	{
		if (character == strLowerChar[i])
		{
			return 1;
		}
	}

	return 0;
}

/********************************
Function Name: isStrRep
Input: a string (char*)
Output: int - 1 or 0
Function Operation: the function returns 1 if the given string
can be represented by seven-segment display, or 0 if it can't.
********************************/
int isStrRep(char* str)
{
	/*calls isCharRep fucntion for every char of the given string,
	and checks if all the chars are possible to be represented by the
	seven-segment display.*/
	for (int i = 0; str[i] != '\0'; i++)
	{
		//that means there is one char or more that can't be represented, so returns 0
		if (isCharRep(str[i]) == 0)
		{
			return 0;
		}
	}
	//then return 1, after checking every char of the string
	return 1;
}

/********************************
Function Name: isCharacter
Input: char type as a capital letter or lower, Hex or decimal
Output: int - 1 or 0
Function Operation: the function returns 1 if the given state
represents a seven-segment display char, or 0 if it's not.
********************************/
int isCharacter(char state)
{
	//function that returns 1 if the user entered a char type (like 'w','N',0x17,119,.. etc)
	char validChar[] = { 0x06,0x0E,0x07,0x7F,0x1F,0x0D,0x17,0x10,0x15,0x1D,0x05,0x0F,0x1C,0x77,0x39,0x4E,0x79,0x4F,0x71,0x47,0x5E,0x37,0x38,0x7E,0x67,0x5B,0x3E,0x3F,0x30,0x6D,0x79,0x33,0x66,0x6D,0x5F,0x7D,0x70,0x7B,0x6F,0x7C,0x3D,0x73,0x3B };
	for (int i = 0; i < SIZE1; i++)
	{
		if (state == validChar[i])
		{
			return 1;
		}
	}
	return 0;
}

/********************************
Function Name: isString
Input: a string (char*) 
Output: int - 1 or 0
Function Operation: the function returns 1 if the given state
as a string represent a seven-segment display string, or 0 if it's not.
********************************/
int isString(char* states)
{
	/*calls isCharacter fucntion for every state of the string that is given,
	and checks if all the states represents a seven-segment display char.
	returns 1 for a possible represented states, or 0 if not*/
	for (int i = 0; states[i] != '\0'; i++)
	{
		if (isCharacter(states[i]) == 0)
		{
			return 0;
		}
	}
	return 1;
}

/********************************
Function Name: print1inARow
Input: char void
Output: void (just printing)
Function Operation: the function let the user enter as many strings
as he\she wants to, until the user enters "*", then the function prints the
summerize of all of the strings with - 1 if the given string
can be represented by seven-segment display, or 0 if it can't.
********************************/
void print1inARow()
{
	int result = 0;
	int count = 0;
	//allocates dynamic array of structs
	String* strings = malloc(SIZE * sizeof(String*));
	//if malloc failed
	if (strings == NULL)
	{
		printf("Error\n");
		free(strings);
		return;
	}
	//for each different struct, allocates dynamic array for the string
	for (int i = 0; i < SIZE * sizeof(char); i++)
	{
		strings[i].str = malloc(SIZE * sizeof(char));
	}
	/*now we have a dynamic array of structs, that for each struct we have
	a dynamic array as well for it's string.
	now we scanf the string itself for each struct, untill the user enters "*". */
	printf("Enter a string to see if it's valid\n");
	for (int i = 0; i < SIZE * sizeof(String*); i++)
	{
		scanf("%s", strings[i].str);
		if (strcmp(strings[i].str,"*") == 0)
		{
			break;
		}
		//counts how many strings the user entered
		count++;
	}
	/*for each string, we call isStrRep to check if the string can
	be represented by seven-segment display, and prints every string*/
	for (int i = 0; i < count ; i++)
	{
		result=isStrRep(strings[i].str);
		// 1 - can be represented, 0 if not
		printf("%d - %s\n",result, strings[i].str);
	}
	//free all the allocates strings
	for (int i = 0; i < SIZE * sizeof(char); i++)
	{
		if (strings[i].str != NULL)
		{
			free(strings[i].str);
		}
	}
	free(strings);
	return;
}

/********************************
Function Name: print2inARow
Input: char void
Output: void (just printing)
Function Operation: the function let the user enter as many strings
as he\she wants to, until entering "*", then the function prints the
summerize of all of the strings with - 1 if the states are given
as a string represent a seven-segment display string, or 0 if it's not.
********************************/
void print2inARow()
{
	int result = 0;
	int count = 0;
	//allocates dynamic array of structs
	States* statesArray = malloc(SIZE * sizeof(String*));
	//if malloc failed
	if (statesArray == NULL)
	{
		printf("Error\n");
		free(statesArray);
		return;
	}
	//for each different struct, allocates dynamic array for the states
	for (int i = 0; i < SIZE * sizeof(char); i++)
	{
		statesArray[i].states = malloc(SIZE * sizeof(char));
	}
	/*now we have a dynamic array of structs, that for each struct we have
	a dynamic array as well for it's states.
	now we scanf the states itself for each struct, untill the user enters "*". */
	printf("Enter a string to see if it's valid\n");
	for (int i = 0; i < SIZE * sizeof(States*); i++)
	{
		scanf("%s", statesArray[i].states);
		if (strcmp(statesArray[i].states, "*") == 0)
		{
			break;
		}
		//counts how many states the user entered
		count++;
	}
	/*for each state, we call isString to check if the states are given
	as a string represent a seven-segment display string, and prints every string*/
	for (int i = 0; i < count; i++)
	{
		result=isString(statesArray[i].states);
		// 1 - represents a state, 0 if not
		printf("%d - %s\n", result, statesArray[i].states);
	}
	//free all the allocates states
	for (int i = 0; i < SIZE * sizeof(char); i++)
	{
		if (statesArray[i].states != NULL)
		{
			free(statesArray[i].states);
		}
	}
	free(statesArray);
	return;
}

int main()
{
	//to your use, if you would like to.
	/*
	printf("%d\n", isCharRep('a'));
	printf("%d\n", isCharRep('A'));
	printf("%d\n", isStrRep("Abc"));
	printf("%d\n", isStrRep("ABc"));
	printf("%d\n", isCharacter(119));
	printf("%d\n", isCharacter(0x77));
	printf("%d\n", isCharacter('w'));
	printf("%d\n", isCharacter(0x40));
	printf("%d\n", isCharacter(64));
	printf("%d\n", isCharacter('@'));
	printf("%d\n", isString("v"));
	printf("%d\n", isString("www"));
	printf("%d\n", isString("w@w"));
	printf("%d\n", isString("vv"));
	*/
	char menu='\0';
	do {
		printf("Enter 1 to check if the string can be represented by a seven-segment display\n");
		printf("Enter 2 to check if the states can be represented by a seven-segment display\n");
		printf("Enter 3 to exit\n");
		scanf(" %c", &menu);
		{
			switch (menu)
			{
			case '1':
				print1inARow();
				break;

			case '2':
				print2inARow();
				break;

			case '3':
				menu = '\0';
				break;

			default:
				printf("Bzzzzzz.. wrong choice. Try again\n");
				break;
			}
		}
	} while (menu);
	//_CrtDumpMemoryLeaks();
	return 0;
}
