#include"Header.h"



int main()
{
	int size, lagA, lagB,k,n;
	double variable, result;
	double sum = 0.0;
	cout << "Lag A must be from interval (1;256)" << endl;
	cout << "Lag B must be from interval (1;Lag A)" << endl;
	cout << "Enter size "; cin >> size;
	cout << "Enter lagA, Enter lagB: "; cin >> lagA; cin>>lagB;
	double* sequence = new double[size];
    for (int i = 0; i < lagA; i++)
	{
		sequence[i] = Randomize(0, 0.9999);
	}
	cout << "Basic sequence: ";
	for (int i = 0; i < lagA; i++)
	{
		cout<<sequence[i] << " ";
	}
	k = lagA;
	for (k; k < size; k++) 
	{
		sequence[k] = FibonacciGenerator(lagA, lagB, k, sequence);
	}
	cout << endl;
	cout << "New sequence: ";
	for (int i = 0; i < size; i++)
	{
		cout << sequence[i] << " ";
	}
	cout << endl;
	double* autocrlt = new double[size];
	autocrlt[0] = 1;
	for (int i = 0; i < size; i++)
	{
		autocrlt[i] = autocorrelation(sequence, i, size);
	}
	BitFrequency test;
	test.setSize(size);
	test.convertToBits(sequence);
	cout << endl;
	cout << endl;
	sum = test.findQuantityOf01(sequence);
	n = test.test2();
	result = erfc((sum / n)/sqrt(2));
	if (result > 0.01) 
	{
		cout << "Sequence is Random" << endl;
	}
	else 
	{
		cout << "Sequence is not Random" << endl;
	}
	int* autocrlt2 = new int[size];
	for (int i = 0; i < size; i++)
	{
		autocrlt2[i] = autocrlt[i] * 100;
	}

	printf("\n\n");
	int x; string errorShift = "0 < shift < 256\n";
	do
	{
		printf("Interval : "); checkInput(x);
	} while (!checkConditions(x > 0 && x < 256, errorShift));

	ofstream out;
	out.open("Output.txt");
	out.is_open();
	if (!out.is_open())
		printf("Error!\n");
	else
	{
		int y;
		out << "x ***|";
		for (int i = 0; i <= 110; i++)
		{
			if (i % 10 == 0)
				out << i;
			else
				out << " ";
		}
		out << endl;

		for (int i = 0; i < size; i += x)
		{
			if (i < 10)
				out << "x= " << i << "  |";
			else if (i >= 10 && i < 100)
				out << "x= " << i << " |";
			else
				out << "x= " << i << "|";


			y = autocrlt2[i];
			for (int j = 0; j < y; j++)
			{
				out << " ";
			}
			out << "." << endl;
		}
	}
	out.close();


	system("pause");
	return 0;
	delete[]sequence;
	delete[]autocrlt;
	delete[]autocrlt2;
}
/*	for (int i = 0; i < lagA; i++)
	{
		cin >> variable;
		while (!checkConditions(variable >= 0 && variable < 1, errorBasicVar))
		{
			checkInput(variable);
		}
		sequence[i] = variable;
	}
	for (int i = 0; i < lagA; i++)
	{
		do
		{
			cin >> variable;

		} while(variable==-100);
		sequence[i] = variable;
	}*/