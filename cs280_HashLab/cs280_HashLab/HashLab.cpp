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

int checkArrayValid(const char* singleArray, [[maybe_unused]]int row, [[maybe_unused]]int column, bool is3X3Called)
{
	bool existHashArray[SUDOKU_BOARD_SIZE] = { false, };

	int returnValue = NUM_OF_VALID;
	
	for(int i = SUDOKU_BOARD_SIZE - 1; i >= 0; --i)
	{
		int index = static_cast<int>(singleArray[i]) - 1;
		if (index >= 0 && index < SUDOKU_BOARD_SIZE)
		{
			if (existHashArray[index] == true)
			{
				if (is3X3Called == true)
				{
					std::cout << "Error in 3x3 starting at index: (" << row << ", " << column << ")" << std::endl;
				}
				returnValue = NUM_OF_NOT_VALID;
			}
			existHashArray[index] = true;
		}
	}

	if(returnValue == NUM_OF_NOT_VALID)
	{
		return returnValue;
	}
	
	for(int i = 0; i < SUDOKU_BOARD_SIZE; ++i)
	{
		if(existHashArray[i] == false)
		{
			return NUM_OF_NOT_COMPLETED;
		}
	}
	
	return NUM_OF_VALID;
}


void TestSudoku(char board[SUDOKU_BOARD_SIZE][SUDOKU_BOARD_SIZE])
{
	char singleArrayInSudoku[SUDOKU_BOARD_SIZE] = { -1, };
	int arrayCheckResult[SUDOKU_BOARD_SIZE * 3] = { 0, };
	const int UN_USING_VALUE = 0;
	int index = 0;
	
	//row check
	for(int row = 0; row < SUDOKU_BOARD_SIZE; ++row, ++index)
	{
		const int checkingNum = checkArrayValid(board[row], UN_USING_VALUE, UN_USING_VALUE, false);
		if(checkingNum == NUM_OF_NOT_VALID)
		{
			std::cout << "Error in row: " << row << std::endl;
		}
		arrayCheckResult[index] = checkingNum;
	}

	//column check
	for (int column = 0; column < SUDOKU_BOARD_SIZE; ++column, ++index)
	{
		for(int i = 0; i < SUDOKU_BOARD_SIZE; ++i)
		{
			singleArrayInSudoku[i] = board[i][column];
		}
		const int checkingNum = checkArrayValid(singleArrayInSudoku, UN_USING_VALUE, UN_USING_VALUE, false);
		if (checkingNum == NUM_OF_NOT_VALID)
		{
			std::cout << "Error in column: " << column << std::endl;
		}
		arrayCheckResult[index] = checkingNum;
	}

	//one small box check
	for (int row = 0; row < SUDOKU_BOARD_SIZE; row += 3)
	{
		for(int column = 0; column < SUDOKU_BOARD_SIZE; column += 3, ++index)
		{
			for(int i = 0; i < 3; ++i)
			{
				for(int j = 0; j < 3; ++j)
				{
					singleArrayInSudoku[i * 3 + j] = board[row + i][column + j];
				}
			}
			
			arrayCheckResult[index] = checkArrayValid(singleArrayInSudoku, row, column, true);
		}
	}

	bool isUncompleted = false;
	for(int i = 0; i < index; ++i)
	{
		if(arrayCheckResult[i] == NUM_OF_NOT_VALID)
		{
			return;
		}
		
		if(arrayCheckResult[i] == NUM_OF_NOT_COMPLETED)
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

QuickFind::QuickFind(int numNodes): size(numNodes), data(nullptr)
{
	data = new int[numNodes];

	for(int i = 0; i < size; ++i)
	{
		data[i] = i;
	}
}

QuickFind::~QuickFind()
{
	delete[] data;
	data = nullptr;
}

void QuickFind::Union(int nodeA, int nodeB)
{
	for(int i = 0; i < size; ++i)
	{
		if(IsConnected(nodeB, i) == true &&  nodeB != i)
		{
			data[i] = Hash(nodeA);
		}
	}
	data[nodeB] = data[nodeA];
}

bool QuickFind::IsConnected(int nodeA, int nodeB)
{
	return data[nodeA] == data[nodeB];
}

int QuickFind::Hash(int nodeIndex)
{
	return data[nodeIndex];
}
