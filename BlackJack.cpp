#include <iostream>
#include <random>

int main()
{
	int ComputerCard[3] = {};
	int MyCard[3] = {};

	int ComputerResult = 0;
	int MyResult = 0;

	int Card[4][12] = {
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 'J', 'Q', 'K'},
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 'J', 'Q', 'K'},
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 'J', 'Q', 'K'},
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 'J', 'Q', 'K'}
	};

	bool bCardPicked[4][12] = { false, };

	std::cout << "컴퓨터 카드 뽑기" << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		int CardShape = rand() % 4;
		int CardNum = rand() % 12;

		ComputerCard[i] = Card[CardShape][CardNum];

		if (bCardPicked[CardShape][CardNum])
		{
			--i;
		}
		else
		{
			bCardPicked[CardShape][CardNum] = true;
		}
	}

	std::cout << "내 카드 뽑기" << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		int CardShape = rand() % 4;
		int CardNum = rand() % 12;

		MyCard[i] = Card[CardShape][CardNum];

		if (bCardPicked[CardShape][CardNum])
		{
			--i;
		}
		else
		{
			bCardPicked[CardShape][CardNum] = true;
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		if (ComputerCard[i] == 'J' || ComputerCard[i] == 'Q' || ComputerCard[i] == 'K')
		{
			ComputerResult += 10;
		}
		else
		{
			ComputerResult += ComputerCard[i];
		}

		if (MyCard[i] == 'J' || MyCard[i] == 'Q' || MyCard[i] == 'K')
		{
			MyResult += 10;
		}
		else
		{
			MyResult += MyCard[i];
		}
	}

	std::cout << std::endl;
	std::cout << "컴퓨터 카드 총합 : " << ComputerResult << std::endl;
	std::cout << "내 카드 총합 : " << MyResult << std::endl;
	if (ComputerResult > 21 && MyResult > 21)
	{
		std::cout << "둘 다 졌습니다" << std::endl;
	}
	else if (ComputerResult > 21)
	{
		std::cout << "당신이 승리했습니다" << std::endl;
	}
	else if (MyResult > 21)
	{
		std::cout << "당신이 패배했습니다" << std::endl;
	}
	else
	{
		if (ComputerResult > MyResult)
		{
			std::cout << "당신이 패배했습니다" << std::endl;
		}
		else
		{
			std::cout << "당신이 승리했습니다" << std::endl;
		}
	}
}