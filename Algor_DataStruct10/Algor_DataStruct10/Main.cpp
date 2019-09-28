#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include<iostream>

int **m;
int **s;

void matrixOptimalOrder(int *dims, int n) {
	int len, i, j, k, temp, cost;
	n--;
	m = (int **)malloc(n * sizeof(int *));
	for (i = 0; i < n; ++i) {
		m[i] = (int *)calloc(n, sizeof(int));
	}

	s = (int **)malloc(n * sizeof(int *));
	for (i = 0; i < n; ++i) {
		s[i] = (int *)calloc(n, sizeof(int));
	}

	for (len = 1; len < n; ++len) {
		for (i = 0; i < n - len; ++i) {
			j = i + len;
			m[i][j] = INT_MAX;
			for (k = i; k < j; ++k) {
				temp = dims[i] * dims[k + 1] * dims[j + 1];
				cost = m[i][k] + m[k + 1][j] + temp;
				if (cost < m[i][j]) {
					m[i][j] = cost;
					s[i][j] = k;
				}
			}
		}
	}
}

void PrintOptimalChainOrder(int i, int j) {
	if (i == j)
		printf("%c", i + 65);
	else {
		printf("(");
		PrintOptimalChainOrder(i, s[i][j]);
		PrintOptimalChainOrder(s[i][j] + 1, j);
		printf(")");
	}
}

int main() 
{
	int i, j, n, k;
	int num;
	std::cout << "Enter amount of sizes: ";
	std::cin >> num; 
	std::cout << "Enter sizes of first pairs od matricies:";
	int *p_darr = new int[num]; 
	for (int i = 0; i < num; i++) 
	{
		std::cin >> k;
		p_darr[i] = k;
	}
	std::cout << "Enter sizes of second pairs od matricies:";
	int *arr = new int[num];
	for (int i = 0; i < num; i++)
	{
		std::cin >> k;
		arr[i] = k;
	}
	std::cout << "Enter sizes of third pairs od matricies:";
	int *arr2 = new int[num];
	for (int i = 0; i < num; i++)
	{
		std::cin >> k;
		arr2[i] = k;
	}

	/*int a1[4] = { 5, 6, 3, 1 };
	int a2[5] = { 4, 4, 12, 5, 3 };
	int a3[7] = { 25,6,3,72,9,41,8 };*/
	int *dims_list[3] = {p_darr,arr,arr2};
	int sizes[3] = { num,num,num };
	for (i = 0; i < 3; ++i) 
	{
		printf("Dimensions  : [");
		n = num;
		for (j = 0; j < n; ++j) 
		{
			printf("%d", dims_list[i][j]);
			if (j < n - 1) printf(", "); else printf("]\n");
		}
		matrixOptimalOrder(dims_list[i], n);
		printf("Order : ");
		PrintOptimalChainOrder(0, n - 2);
		printf("\nMin cost  : %d\n\n", m[0][n - 2]);
		for (j = 0; j <= n - 2; ++j) free(m[j]);
		free(m);
		for (j = 0; j <= n - 2; ++j) free(s[j]);
		free(s);
	}
	delete[]p_darr;
	delete[] arr;
	delete[]arr2;
	system("pause");
	return 0;
	
}