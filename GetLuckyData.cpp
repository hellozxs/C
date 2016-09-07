#include <iostream>
#include <string>
#include <vector>
using namespace std;

void GetLucky(int N)
{
	if (N <= 0)
		return;
	if (N == 1)
		cout << "4" << endl;
	else if (N == 2)
		cout << "7" << endl;

	vector<string> a;
	a.push_back("4");
	a.push_back("7");
	string s;
	int count = N - 2;
	int index = 0;
	while (count>0)
	{
		if (count != N - 2)
		{
			s = a[index++];
		}

		if (count-- > 0)
		{
			s += "44";
			a.push_back(s);
		}
		if (count-- > 0)
		{
			s[s.size() - 1] = '7';
			a.push_back(s);
		}
		if (count-- > 0)
		{
			s[s.size() - 1] = '4';
			s[s.size() - 2] = '7';
			a.push_back(s);
		}
		if (count-- > 0)
		{
			s[s.size() - 1] = '7';
			a.push_back(s);
		}

	}
	cout << s << endl;

}


int main()
{
	int count;
	cin >> count;
	int N;
	while (count--)
	{
		cin >> N;
		GetLucky(N);
	}

	system("pause");
	return 0;
}