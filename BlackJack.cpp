#include <iostream>
#include <random>

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));

	int ComputerCard[3] = {};
	int MyCard[3] = {};

	int ComputerResult = 0;
	int MyResult = 0;

	int Card[4][12] = {
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 'J', 'Q', 'K'}, // 하트
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 'J', 'Q', 'K'}, // 다이아
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 'J', 'Q', 'K'}, // 스페이드
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 'J', 'Q', 'K'}  // 클로버
	};

	bool ComputerPickedCard[4][12] = { false, };
	bool MyPickedCard[4][12] = { false, };

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
			ComputerPickedCard[CardShape][CardNum] = true;
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
			MyPickedCard[CardShape][CardNum] = true;
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
	
	// 카드 Print
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 12; ++j)
		{
			if (ComputerPickedCard[i][j]) {
				switch (i)
				{
				case 0:
					if (Card[i][j] == 'J')
					{
						std::cout << "하트 J ";
					}
					else if(Card[i][j] == 'Q')
					{
						std::cout << "하트 Q ";
					}
					else if (Card[i][j] == 'K')
					{
						std::cout << "하트 K ";
					}
					else
					{
						std::cout << "하트 " << Card[i][j] << " ";
					}
					break;
				case 1:
					if (Card[i][j] == 'J')
					{
						std::cout << "다이아 J ";
					}
					else if (Card[i][j] == 'Q')
					{
						std::cout << "다이아 Q ";
					}
					else if (Card[i][j] == 'K')
					{
						std::cout << "다이아 K ";
					}
					else
					{
						std::cout << "다이아 " << Card[i][j] << " ";
					}
					break;
				case 2:
					if (Card[i][j] == 'J')
					{
						std::cout << "클로버 J ";
					}
					else if (Card[i][j] == 'Q')
					{
						std::cout << "클로버 Q ";
					}
					else if (Card[i][j] == 'K')
					{
						std::cout << "클로버 K ";
					}
					else
					{
						std::cout << "클로버 " << Card[i][j] << " ";
					}
					break;
				case 3:
					if (Card[i][j] == 'J')
					{
						std::cout << "스페이드 J ";
					}
					else if (Card[i][j] == 'Q')
					{
						std::cout << "스페이드 Q ";
					}
					else if (Card[i][j] == 'K')
					{
						std::cout << "스페이드 K ";
					}
					else
					{
						std::cout << "하트 " << Card[i][j] << " ";
					}
					break;
				}
			}
		}
	}
	std::cout << "컴퓨터 카드 총합 : " << ComputerResult << std::endl << std::endl;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 12; ++j)
		{
			if (MyPickedCard[i][j]) {
				switch (i)
				{
				case 0:
					if (Card[i][j] == 'J')
					{
						std::cout << "하트 J ";
					}
					else if (Card[i][j] == 'Q')
					{
						std::cout << "하트 Q ";
					}
					else if (Card[i][j] == 'K')
					{
						std::cout << "하트 K ";
					}
					else
					{
						std::cout << "하트 " << Card[i][j] << " ";
					}
					break;
				case 1:
					if (Card[i][j] == 'J')
					{
						std::cout << "다이아 J ";
					}
					else if (Card[i][j] == 'Q')
					{
						std::cout << "다이아 Q ";
					}
					else if (Card[i][j] == 'K')
					{
						std::cout << "다이아 K ";
					}
					else
					{
						std::cout << "다이아 " << Card[i][j] << " ";
					}
					break;
				case 2:
					if (Card[i][j] == 'J')
					{
						std::cout << "클로버 J ";
					}
					else if (Card[i][j] == 'Q')
					{
						std::cout << "클로버 Q ";
					}
					else if (Card[i][j] == 'K')
					{
						std::cout << "클로버 K ";
					}
					else
					{
						std::cout << "클로버 " << Card[i][j] << " ";
					}
					break;
				case 3:
					if (Card[i][j] == 'J')
					{
						std::cout << "스페이드 J ";
					}
					else if (Card[i][j] == 'Q')
					{
						std::cout << "스페이드 Q ";
					}
					else if (Card[i][j] == 'K')
					{
						std::cout << "스페이드 K ";
					}
					else
					{
						std::cout << "하트 " << Card[i][j] << " ";
					}
					break;
				}
			}
		}
	}
	std::cout << "내 카드 총합 : " << MyResult << std::endl << std::endl;


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