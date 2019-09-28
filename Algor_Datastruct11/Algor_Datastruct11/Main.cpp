#include <iostream>
#include <algorithm>
#include <functional>
#include <array>
#include <iostream>
#include <iterator> 
using namespace std;

typedef struct
{
	int v;
	int w;
	float d;
	double times = 0;
} Item;
void input(Item items[], int sizeOfItems) {
	cout << "Enter total " << sizeOfItems << " item's values and weight" <<
		endl;
	for (int i = 0; i < sizeOfItems; i++) {
		cout << "Enter " << i + 1 << " V ";
		cin >> items[i].v;
		cout << "Enter " << i + 1 << " W";
		cin >> items[i].w;
	}
}

void display(Item items[], int sizeOfItems) {
	for (int i = 0; i < sizeOfItems; i++) {
		cout << "Item number " << i << " (weight: " << items[i].w << "; cost: " << items[i].v << ") was gotten " << items[i].times << " times" 
			<< std::endl;
	}
	cout << endl;
}
bool compare(Item i1, Item i2) {
	return (i1.d > i2.d);
}

float knapsack(Item items[], int sizeOfItems, int W) {
	int i, j, pos;
	Item mx, temp;
	float totalValue = 0, totalWeight = 0;
	for (int i = 0; i < sizeOfItems; i++) {
		items[i].d = items[i].v / items[i].w;
	}
	sort(items, items + sizeOfItems, compare);
	for (i = 0; i < sizeOfItems; i++) {
		if (totalWeight + items[i].w <= W) {
			items[i].times++;
			totalValue += items[i].v;
			totalWeight += items[i].w;
		}
		else
		{
			int wt = W - totalWeight;
			totalValue += (wt * items[i].d);
			items[i].times += (W - totalWeight) / items[i].w;
			totalWeight += wt;
			break;
		}
	}
	cout << "total weight in bag " << totalWeight << endl;
	return totalValue;
}

int main() 
{
	int W;
	const int number = 4;
	Item items[number];
	input(items, number);
	//cout << "Entered data \n";
	//display(items, 3);
	cout << "Enter Knapsack weight \n";
	cin >> W;
	float mxVal = knapsack(items, number, W);
	cout << "Max value for " << W << " weight is " << mxVal << endl;
	display(items, number);
	system("pause");
	return 0;
}