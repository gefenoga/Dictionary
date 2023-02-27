// main.cpp

#include "header.h"

//---------------------------------------------------------------------------------
//                              Oxford Dictionary
//                             -------------------
//	
// General: This program uses a text file to manage a dictionary.
//
// Input  : menu option numbers through 1-5.
//
// Process : executing differnet options according to the input.
//
// Output : depends on the option number.
//
//---------------------------------------------------------------------------------
// Programmer   : Gefen Noga
// Student no   : None.
// Date         : 26.11.2022
//---------------------------------------------------------------------------------
void main()
	{
	int nOptionNumber;
	char* pcWord;
	char* keyWord;
	int nKeyWordSize;
	int nWordSize;
	char* pcDefinition;
	int nDefinitionSize;

	printf("Please Enter Option Number:\n");
	scanf("%d", &nOptionNumber);
	while (1)
	{
		// Menu
		switch (nOptionNumber)
		{
				case 1:

					char cInput;
					keyWord = (char*)calloc(1, sizeof(char));
					nKeyWordSize = 1;

					if (keyWord == NULL) 
					{
						printf("memory error!");
						exit(1);
					}
					printf("Enter word to search: ");
					scanf(" %c", &cInput);

					// Creating the key string
					while (cInput != '\n') 
					{
						keyWord[nKeyWordSize - 1] = cInput;
						keyWord = (char*)realloc(keyWord, ++nKeyWordSize * sizeof(char));
						scanf("%c", &cInput);
					}
					keyWord[--nKeyWordSize] = '\0';
					
					// Result of the call
					printf("%s\n", GetWordDefenition(keyWord));

					break;
				case 2: 
					char input;
					pcWord = (char*)calloc(1, sizeof(char));
					nWordSize = 1;
					pcDefinition = (char*)calloc(1, sizeof(char));
					nDefinitionSize = 1;

					if (pcWord == NULL || pcDefinition == NULL)
					{
						printf("memory error");
						exit(1);
					}

					printf("Enter word: ");
					scanf(" %c", &input);

					while (input != '\n')
					{	
						pcWord[nWordSize - 1] = input;
						pcWord = (char*)realloc(pcWord, ++nWordSize * sizeof(char));
						scanf("%c", &input);
					} 
					pcWord[--nWordSize] = '\0';

					printf("Enter defintition: ");
					scanf(" %c", &input);

					while (input != '\n')
					{
						pcDefinition[nDefinitionSize - 1] = input;
						pcDefinition = (char*)realloc(pcDefinition, ++nDefinitionSize * sizeof(char));
						scanf("%c", &input);
					}
					pcDefinition[--nDefinitionSize] = '\0';

					// Calling the function
					AddNewWord(pcWord, pcDefinition);

					break;
				case 3: 
					char letter;
					printf("Enter a letter: ");
					scanf(" %c", &letter);

					// Calling the function
					PrintWordsOf(letter);

					break;
				case 4:
					exit(1);

					break;
				default:
					printf("Invalid Input!\n");

					break;
		}
		printf("Please Enter Option Number:\n");
		scanf("%d", &nOptionNumber);
	}
}