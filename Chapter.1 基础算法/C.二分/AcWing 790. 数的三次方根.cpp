#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double n = 0;
	cin >> n;

	double root_left = -100;
	double root_right = 100;

	/*
	 * 我们这里循环1k次可以是因为:
	 * 	100^3 / 2^1000 < 1e-6
	 */
	for (auto i = 1; i <= 1000; i++)
	{
		double root_mid = (root_left + root_right) / 2;
		double cube = pow(root_mid, 3);
		if (cube > n)
		{
			root_right = root_mid;
		}
		else
		{
			root_left = root_mid;
		}
	}

	printf("%.6f\n", root_left);

	return 0;
}