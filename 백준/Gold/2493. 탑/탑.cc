#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<pair<int, int>> s;
	s.push({ 100000001, 0 });

	int input;
	cin >> input;

	for (int i = 1; i <= input; i++)
	{
		int value;
		cin >> value;
		
		while (value > s.top().X)
		{
			s.pop();
		}
		cout << s.top().Y << ' ';
		s.push({ value, i });
	}
	return 0;
}