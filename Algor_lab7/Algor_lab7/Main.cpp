#include"ConvexHull.h"

int main()
{
	/*Point points[] = { {0, 3}, {1, 1}, {2, 2}, {4, 4},
					 {0, 0}, {1, 2}, {3, 1}, {3, 3} */

	Point points[] = { {15,27},{2,26}, {5,24},{11,20},{23,12},{18,25},{8,22},{17,22},{6,4},{13,19} };
	int n = sizeof(points) / sizeof(points[0]);
	convexHull(points, n);
	system("pause");
	return 0;
}