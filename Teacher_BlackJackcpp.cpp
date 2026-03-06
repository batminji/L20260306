#include <iostream>
#include <string>

#define CARDSIZE	52

std::string PrintCard(int CardNumber)
{
	int Shape = (CardNumber % 13 + 1);

	if (Shape == 11)
	{
		return "J";
	}
	else if (Shape == 12)
	{
		return "K";
	}
	else if (Shape == 13)
	{
		return "K";
	}
	else if (Shape == 1)
	{
		return "A";
	}

	return std::to_string(Shape);
}

int main()
{
	int Cards[CARDSIZE] = { 0, };
	std::string CardType[4] = { "Heart", "Spade", "Diamond" , "Clover" };

	for (int i = 0; i < CARDSIZE; ++i)
	{
		Cards[i] = i;
	}

	// Shuffle
	srand((unsigned int)time(nullptr));
	for (int i = 0; i < CARDSIZE * 10; ++i)
	{
		int FirstIndex = rand() % CARDSIZE;
		int SecondIndex = rand() % CARDSIZE;

		int Temp = Cards[FirstIndex];
		Cards[FirstIndex] = Cards[SecondIndex];
		Cards[SecondIndex] = Temp;
	}

	// Roll
	int ComputerCard[3] = {};
	int PlayerCard[3] = {};
	for (int i = 0; i < 3; ++i)
	{
		ComputerCard[i] = Cards[i * 2];
		PlayerCard[i] = Cards[( i * 2 ) + 1];
	}

	// PreProcess
	int ComputerScore[3] = { 0, };
	int PlayerScore[3] = { 0, };
	for (int i = 0; i < 3; ++i)
	{
		ComputerScore[i] = ComputerCard[i] % 13 + 1;
		ComputerScore[i] > 10 ? 10 : ComputerScore[i];
		PlayerScore[i] = PlayerCard[i] % 13 + 1;
		PlayerScore[i] > 10 ? 10 : PlayerScore[i];
	}

	// Draw
	int TotalComputerScore = ComputerScore[0] + ComputerScore[1] + ComputerScore[2];
	int TotalPlayerScore = PlayerScore[0] + PlayerScore[1] + PlayerScore[2];

	if (TotalComputerScore > 21)
	{
		std::cout << "Player Win" << std::endl;
	}
	else if (TotalPlayerScore > 21)
	{
		std::cout << "Player Lose" << std::endl;
	}
	else if (TotalComputerScore > TotalPlayerScore)
	{
		std::cout << "Player Lose" << std::endl;
	}
	else
	{
		std::cout << "Player Win" << std::endl;
	}

	std::cout << std::endl << "Computer Card" << std::endl;

	for (int i = 0; i < 3; ++i)
	{
		int CardTypeIndex = ComputerCard[i] / 13;
		
		std::cout << CardType[CardTypeIndex] << " " << PrintCard(ComputerCard[i]) << std::endl;
	}

	std::cout << std::endl << "Player Card" << std::endl;

	for (int i = 0; i < 3; ++i)
	{
		int CardTypeIndex = PlayerCard[i] / 13;

		std::cout << CardType[CardTypeIndex] << " " << PrintCard(PlayerCard[i]) << std::endl;
	}

	return 0;
}