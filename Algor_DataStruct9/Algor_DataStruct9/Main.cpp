#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

unsigned long long recursion(int n)
{
	if (n < 1)
		return 1;
	return 4 * recursion(n / 5) + 2 * n;
}

class PrintMethods
{
private:


	void case2()
	{
		cout << "Condition : 3\n";
		cout << "If f (n)=O(nlogba) , then T (n)=O(nlogba lg n)\n";

	}


public:
	void equestion()
	{
		cout << "Variant 3\n";
		cout << "Equestion : T(n) = 4 * T(n / 5) + 2*n\n";
		cout << "General :   T(n) = a * T(n / b) + f(n)\n";
		cout << "a = 4, b = 5, f(n) = 2*n\n";
		cout << "\n\n";
		cout << "Condition 2!\n";
		cout << "Complexity : T(n) = O(n * log n) == Merge sort\n";
	}

	void masterMethod()
	{
		cout << "Master Method\n";

		
		cout <<"T(n)=O(n * log n)";

		cout <<"\n\n\n";
		case2();
	
	}

	void substitutionMethod()
	{
		cout << "Substitution Method\n";

		cout << "T(n) = O(n * log n)\n";
		cout << "Try to prove : T(n) <= c * n * log n\n";
		cout << "T(n) <= 4*c* log (n / 5)+2*n\n";
		cout << "     <= 4*c*(2*n/4) * log(n / 5) + 2*n\n";
		cout << "     <= 2*c*n*log(n) - c*2*n*log(5) + 2*n\n";
		cout << "     <= 2*n*c*log(n)+2*n(1-c)\n";
		cout << "     <= c*n*log(n)\n";

		cout << "\n\n\n";
		cout << "T(5) = 4T(1) + 10 = 14\n";
		cout <<"T(10) = 4T(2) +20 = 28\n";
		cout <<"c = 4, 14 <= 4 * 10 * log 5, 28 <= 4 * 20 * log 10\n";
		cout <<"T(n) <= 4 * n * log n for all n >= 4, so T(n) = O(n * log n)\n";
	}

	void convertingToSumMethod()
	{
		cout << "Converting to sum Method\n";
		cout << "Iterate this equestion k times :\n";
		cout << "T(n) = n + n/5 + n/25 + ... + n/p(5, k)\n";
		cout << "T(n) = n * (1 + 1/5 + 1/25 + ... + 1/p(5,k))\n";
		cout << "           k \n";
		cout << "T(n) = n * E 1/p(5, i) = n * 1\n";
		cout << "           i = 0\n";

		cout <<"The worst case of program if T(n) = O(n)\n";
	}
};

int main()
{
	int n;

	cout << "enter n > 1: ";
	cin >> n;
	for (n; n <= 1;)
	{
		cout << "n > 1!\n";
		cout << "enter n > 1: ";
	}
	cout <<"\n\n\n";

	PrintMethods out;
	out.equestion();
	out.masterMethod();
	cout << "\n\n\n";
	out.substitutionMethod();
	cout << "\n\n\n";
	out.convertingToSumMethod();
	cout << "\n\n\n";

	printf("recursion : %i", recursion(n));

	system("pause");
	return 0;
}
