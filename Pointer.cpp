#include <iostream>

int StringLength(char* C)
{
	int Length = 0;
	while (C[Length] != '\0')
	{
		Length++;
	}
	return Length;
}

int main()
{
	char C[12] = "Hello World";

	std::cout << StringLength(C) << std::endl;

	return 0;
}