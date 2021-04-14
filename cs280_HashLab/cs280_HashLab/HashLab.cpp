/******************************************************************
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.

File Name: HashLab.cpp
Project: Lab 5 - Hash
Author: Sunghwan Cho
Creation date: 04/14/2021
******************************************************************/

#include <iostream>
#include <vector>
#include "HashLab.h"

int charCountHashFunction(char pChar)
{
	return static_cast<int>(pChar - 'a');
}

void ShowCharCount(std::string text)
{
	std::cout << text << std::endl;
	const int textSize = static_cast<int>(text.size());
	constexpr int charSize = static_cast<int>('z' - 'a') + 1;
	int charCountArray[charSize] = { 0 , };
	for (int i = 0; i < textSize; ++i)
	{
		char character = text[i];
		if(character >= 'a' && character <= 'z')
		{
			const int charLocation = charCountHashFunction(character);
			++charCountArray[charLocation];
		}
	}

	for(int i = 0; i < charSize; ++i)
	{
		std::cout << static_cast<char>('a' + i) << ": " << charCountArray[i] << std::endl;
	}
}

int checkArrayValid(char singleArray[SudokuBoardSize])
{
	//todo
	return 0;
}

void TestSudoku(char board[SudokuBoardSize][SudokuBoardSize])
{
	char singleArrayInSudoku[SudokuBoardSize] = { -1, };
	int arrayCheckResult[SudokuBoardSize * 3] = { 0, };
	int index = 0;
	//row check
	for(int row = 0; row < SudokuBoardSize; ++row, ++index)
	{
		const int checkingNum = checkArrayValid(board[row]);
		if(checkingNum == NumOfNotValid)
		{
			std::cout << "Error in row: " << row << std::endl;
		}
		arrayCheckResult[index] = checkingNum;
	}

	//column check
	for (int column = 0; column < SudokuBoardSize; ++column, ++index)
	{
		for(int i = 0; i < SudokuBoardSize; ++i)
		{
			singleArrayInSudoku[i] = board[i][column];
		}
		const int checkingNum = checkArrayValid(singleArrayInSudoku);
		if (checkingNum == NumOfNotValid)
		{
			std::cout << "Error in row: " << column << std::endl;
		}
		arrayCheckResult[index] = checkingNum;
	}

	//one small box check
	for (int row = 0; row < SudokuBoardSize; row += 3)
	{
		for(int column = 0; column < SudokuBoardSize; column += 3, ++index)
		{
			for(int i = 0; i < 3; ++i)
			{
				for(int j = 0; j < 3; ++j)
				{
					singleArrayInSudoku[i * 3 + i] = board[row + i][column + j];
				}
			}

			//todo
			
			/*const int checkingNum = checkArrayValid(singleArrayInSudoku);
			if (checkingNum == NumOfNotValid)
			{
				std::cout << "Error in 3x3 starting at index: ( " << row << ", " << column <<")" std::endl;
			}
			arrayCheckResult[index] = checkingNum;*/
			
			arrayCheckResult[index] = checkArrayValid(singleArrayInSudoku);
		}
	}

	bool isUncompleted = false;
	for(int i = 0; i < index; ++i)
	{
		if(arrayCheckResult[i] == NumOfNotCompleted)
		{
			isUncompleted = true;
		}
	}

	if(isUncompleted == true)
	{
		std::cout << "Puzzle doesn't have any errors at the moment" << std::endl;
		return;
	}
	std::cout << "Puzzle solved correctly" << std::endl;
	return;
}

float BirthdayParadox()
{
	return 0.0f;
}

QuickFind::QuickFind(int numNodes): size(numNodes)
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
