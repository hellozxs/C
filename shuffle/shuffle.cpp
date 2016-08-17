//题目描述：给定1～2n张牌，从上到下依次是1，2，3……2n
//将牌分成两份：1～n，n+1～2n。左手拿1～n，右手拿n+1～2n，
//右手先开始，将最下面的一张牌放下，然后是左手依次放，求经k次洗牌后的牌的顺序
//比如1，2，3，4，5，6
//左手：1，2，3  右手：4，5，6
//经一次洗牌后：从上到下牌的顺序依次是1,4,2,5,3,6




#include <iostream>
#include <vector>

using namespace std;


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> arr(2 * n + 1);
		vector<int> tmp(2 * n + 1);
		int i = 1;
		for (; i < 2 * n + 1; i++)
		{
			cin >> arr[i];
		}

		int count = 0;
		for (; count<k; count++)
		{
			int j = 1;
			int index = 1;
			for (j = n; j>0; j--)
			{
				tmp[index++] = arr[n+j];
				tmp[index++] = arr[j];
			}

			int m = 0;
			for (m = 1; m < 2 * n + 1; m++)
				arr[m] = tmp[2*n+1-m];
		}

		for (i = 2*n; i>0; i--)
		{
			cout << tmp[i] << " ";
		}
		cout << endl;
	}

	return 0;
}
