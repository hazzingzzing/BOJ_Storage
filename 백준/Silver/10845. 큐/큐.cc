#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int input;
	cin >> input;
	queue<int> Q;

	for (int i = 0; i < input; i++)
	{
		int value; string s;
		cin >> s;

		if (s == "push")
		{
			cin >> value;
			Q.push(value);
		}
		else if (s == "pop")
		{
			if (Q.empty())
			{
				cout << "-1\n";
			}
			else
			{
				auto cur = Q.front(); Q.pop();
				cout << cur << '\n';
			}
		}
		else if (s == "size")
		{
			auto cur = Q.size();
			cout << cur << '\n';
		}
		else if (s == "empty")
		{
			if (Q.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else if (s == "front")
		{
			if (Q.empty())
			{
				cout << "-1\n";
			}
			else
			{
				auto cur = Q.front();
				cout << cur << '\n';
			}
		}
		else if (s == "back")
		{
			if (Q.empty())
			{
				cout << "-1\n";
			}
			else
			{
				auto cur = Q.back();
				cout << cur << '\n';
			}
		}
	}

	return 0;
}