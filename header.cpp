// header.cpp

#include "header.h"

// Costant global variables definition
const char* FILE_NAME = "Dictionary.dat";

//---------------------------------------------------------------------
//							Add New Word
//                         --------------
// 
// General		: The fuction adds new word and definition to the 
//				  dictionary file.
//
// Parameters	: 
//		iszNewWord		- word to add
//		iszWordDef		- definition of the word
//
// Return Value : None.
//
//---------------------------------------------------------------------
void AddNewWord(char* iszNewWord, char* iszWordDef)
{
	// Variables definition
	FILE* fpFilePointer;
	char* record;
	
	// Code section
	fpFilePointer = fopen(FILE_NAME, "at");
	record = iszNewWord;

	// combining the strings
	JoinStrings(&record, iszWordDef);

	fprintf(fpFilePointer, "%s", record);
	fprintf(fpFilePointer, "\n");
	fclose(fpFilePointer);

}

//---------------------------------------------------------------------
//							Join Strings
//                         --------------
// 
// General		: The fuction combines two string together.
//
// Parameters	: 
//		iopszFirstString		- first string.
//		iszSecondString			- second string.
//
// Return Value : None.
//
//---------------------------------------------------------------------
void JoinStrings(char** iopszFirstString, char* iszSecondString)
{
	// Variable definition 
	int nFirstLength;
	int nSecondLength;
	int nFinalStringSize;
	int nFinalIndex;
	char* joined;
	
	// Code section
	nFirstLength = strlen(*iopszFirstString);
	nSecondLength = strlen(iszSecondString);
	nFinalStringSize = nFirstLength + nSecondLength + 2;
	joined = (char*)calloc(nFinalStringSize, sizeof(char));

	if (joined == NULL) {
		printf("error");
		exit(1);
		}

	// Copying the first string to the final one
	for (nFinalIndex = 0; nFinalIndex < nFirstLength; nFinalIndex++)
	{
		joined[nFinalIndex] = iopszFirstString[0][nFinalIndex];
	}
	joined[nFinalIndex] = '-';
	nFinalIndex++;

	// Copying the second string to the final one
	for (int j = 0; nFinalIndex < nFinalStringSize - 1; nFinalIndex++, j++)
	{
		joined[nFinalIndex] = iszSecondString[j];
	}
	joined[nFinalIndex] = '\0';

	// putting the final string in the first string
	*iopszFirstString = (char*)realloc(*iopszFirstString, nFinalStringSize * sizeof(char));
	*iopszFirstString = joined;
}

//-----------------------------------------------------------------------
//						Get Word Defenition
//                     ---------------------
// 
// General		: The fuction gets a key word and return its definition.
//
// Parameters	: 
//		iszWord			- the key word.
//
// Return Value : a string of the definition of the word.
//
//-----------------------------------------------------------------------
char* GetWordDefenition(char* iszWord) 
{
	// Variable definition
	int wordSize;
	FILE* fpFilePointer;
	char* pcDefinition;
	int defSize;
	char fileInput;
	int counter;

	// Code section
	fpFilePointer = fopen(FILE_NAME, "rt");
	wordSize = strlen(iszWord);
	counter = 0;
	defSize = 1;
	pcDefinition = NULL;

	// Finding the word
	while (!feof(fpFilePointer)) 
	{
		if (counter == wordSize) 
		{
			break;
		}
		if (fgetc(fpFilePointer) == iszWord[counter]) 
		{
			counter++;
		}
		else 
		{
			counter = 0;
		}
	}

	// if the word exists
	if (counter == wordSize) 
	{
		pcDefinition = (char*)malloc(sizeof(char));
		fseek(fpFilePointer, -counter, SEEK_CUR);
		fileInput = fgetc(fpFilePointer);
		
		// Finding the definition
		while (fileInput != '\n')
		{
			pcDefinition[defSize - 1] = fileInput;
			pcDefinition = (char*)realloc(pcDefinition, ++defSize * sizeof(char));
			fileInput = fgetc(fpFilePointer);
		}
		pcDefinition[--defSize] = '\0';
	}
	fclose(fpFilePointer);

	return (pcDefinition);
}

//-----------------------------------------------------------------------
//							Print Words Of
//						   ----------------
// 
// General		: The fuction gets a letter and print all the words 
//				  that start with that letter.
//
// Parameters	: 
//		icStartChar		- the letter.
//
// Return Value : None.
//
//-----------------------------------------------------------------------
void PrintWordsOf(char icStartChar)
{
	// Variable definition
	FILE* fpFilePointer;
	char cBeforeChar;
	char cCurrentChar;

	// Code section
	fpFilePointer = fopen(FILE_NAME, "rt");
	cBeforeChar = '\n';

	while (!feof(fpFilePointer)) 
	{
		cCurrentChar = fgetc(fpFilePointer);

		// If the word starts with the letter
		if(cCurrentChar == icStartChar && cBeforeChar == '\n')
		{

			// print only the word
			while (cCurrentChar != '-') 
			{
				printf("%c", cCurrentChar);
				cCurrentChar = fgetc(fpFilePointer);
			}
			printf("\n");
		}
		cBeforeChar = cCurrentChar;
	}
	fclose(fpFilePointer);
}
