/******************************************************************
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.

File Name: HashLab.h
Project: Lab 4 - Hash
Author: Kevin Wright
Creation date: 1/26/2021
******************************************************************/

#include <iostream>
#include <vector>
#include "HashLab.h"

void ShowCharCount(std::string text)
{
	const int textSize = text.size();
	constexpr int charSize = static_cast<int>('z' - 'a') + 1;
	std::vector<int> charCountArray(charSize, 0);
	for (int i = 0; i < textSize; ++i)
	{
		char character = text[i];
		if(character >= 'a' && character <= 'z')
		{
			const int charLocation = static_cast<int>(character - 'a');
			++charCountArray[charLocation];
		}
	}

	for(int i = 0; i < charSize; ++i)
	{
		std::cout << static_cast<char>('a' + i) << ": " << charCountArray[i] << std::endl;
	}
}

void TestSudoku(char board[SudokuBoardSize][SudokuBoardSize])
{
}

float BirthdayParadox()
{
	return 0.0f;
}

QuickFind::QuickFind(int numNodes)
{
	
}

QuickFind::~QuickFind()
{
	
}

void QuickFind::Union(int nodeA, int nodeB)
{
	
}

bool QuickFind::IsConnected(int nodeA, int nodeB)
{
	return false;
}

int QuickFind::Hash(int nodeIndex)
{
	return 0;
}
