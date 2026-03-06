#include <iostream>

void Swap(int* Num1, int* Num2)
{
	int Temp = *Num1;
	*Num1 = *Num2;
	*Num2 = Temp;
}

int main()
{
	int A = 10;
	int B = 20;

	Swap(&A, &B);

	std::cout << "A : " << A << std::endl;
	std::cout << "B : " << B << std::endl;

	return 0;
}