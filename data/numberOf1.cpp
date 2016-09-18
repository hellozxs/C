#include <iostream>
#include <stdlib.h>

using namespace std;


long long NumOf1(int num)
{
	if (num < 1)
		return 0;
	int ret = 0;
	int i = 1;
	for (; i <= num; i++)
	{
		int tmp = i;
		while (tmp)
		{
			if (tmp % 10 == 1)
				ret++;
			tmp /= 10;
		}
	}

	return ret;
}



#include <math.h>
long long NumOf1_Pro(int num)
{
	if (num < 1)
		return 0;

	long long ret = 0;

	int i = 0;
	for (; pow(10, i) <= num; i++)
	{
		int next = num % (int)pow(10, i);
		int cur = num / (int)pow(10, i) % 10;
		int pre = num / (int)pow(10, i + 1);

		int tmp = 0;
		if (cur == 0)
			tmp = pre*pow(10, i);
		else if (cur == 1)
			tmp = pre *pow(10, i) + next + 1;
		else
			tmp = (pre + 1)*pow(10, i);

		ret += tmp;
	}

	return ret;
}




int main()
{
	int num;
	while (cin >> num)
	{
		cout << NumOf1_Pro(num) << endl;
	}

	system("pause");
	return 0;

}