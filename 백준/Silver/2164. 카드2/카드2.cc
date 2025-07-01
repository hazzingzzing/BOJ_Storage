#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int input, cnt = 1;
	cin >> input;
	queue<int> Q;

	while (input > 0)
	{
		Q.push(cnt++);
		--input;
	}

	while (Q.size() > 1)
	{
		Q.pop();
		auto cur = Q.front(); Q.pop();
		Q.push(cur);
	}

	cout << Q.front();
	return 0;
}