// header.h

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string>

// Function prototypes
void AddNewWord(char* iszNewWord, char* iszWordDef);
char* GetWordDefenition(char* iszWord);
void JoinStrings(char** iopszFirstString, char* iszSecondString);
void PrintWordsOf(char icStartChar);

