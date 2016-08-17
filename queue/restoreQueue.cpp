//对一个队列执行以下操作后，发现输出为 1，2，3，4，……,n
//    操作：（如果队列不为空）
//    1：取队头元素，放入队尾，将队头pop
//    2；输出队头，将队头pop
//  输入n，求原始队列？
//
//输入：z -> 表示将要输入的数据的个数
//输入z个n的具体值



#include <iostream>
#include <vector>

using namespace std;


typedef struct MyData
{
	int _data;
	bool _flag;

}MyData;


int main()
{
	int z;
	cin >> z;
	vector<int> arr(z);
	for (int i = 0; i < z; i++)
	{
		cin >> arr[i];
	}

	int i = 0;
	for (i = 0; i< z; i++)
	{
		if (arr[i] == 1)
			cout << 1 << endl;
		else
		{
			vector<MyData> a(arr[i]);
			int j = 0;
			int count = arr[i];
			int tmp = 1;
			for (; count--; j ++)
			{
				int flag = 1;
				while (flag)
				{
					if (j == arr[i])
						j = 0;
					if (a[j]._flag == false)
						flag--;
					j++;
				}

				if (j == arr[i])
					j = 0;
				while (a[j]._flag == true)
				{
					j++;
					if (j == arr[i])
						j = 0;

				}
				a[j]._data =tmp++;
				a[j]._flag = true;
			}

			int k = 0;
			for (; k < arr[i]; k++)
				cout << a[k]._data << " ";
			cout << endl;
		}
	}


	return 0;
}
