#include<iostream>
using namespace std;

void quickSort(double[], int, int);
double partition(double[], int, int);
double searchElement(double[], int, int);

int main()
{
	int n,element;
	cout << "Enter the size of the array" << endl;
	cin >> n;
	cout << "Enter the elements in the array" << endl;
	double* arr = new double[n];
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	cout << "Sorting using quick sort" << endl;
	int p = 1, r = n;
	quickSort(arr, p, r);
	cout << "Sorted array" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << "a[" << i << "]=" << arr[i] << endl;
	}
	while (true)
	{
		cout << "Enter element that you want to find, enter -100 to exit: ";
		cin >> element;
		double k = searchElement(arr, element, n);
		cout << "Number :" << k; cout << endl;

		if (element == -100)
			break;
	}
	system("pause");
	return 0;
	delete[] arr;
}
double searchElement(double a[], int element,int n) 
{
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		count++;
		if (a[i] == element)
			return count;
	}
	return -1;
}
void quickSort(double a[], int p, int r)
{
	int q;
	if (p<r)
	{
		q = partition(a, p, r);
		quickSort(a, p, q - 1);
		quickSort(a, q + 1, r);
	}
}
double partition(double a[], int p, int r)
{
	int temp, temp1;
	int x = a[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++)
	{
		if (a[j] <= x)
		{

			i = i + 1;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp1 = a[i + 1];
	a[i + 1] = a[r];
	a[r] = temp1;
	return i + 1;
}