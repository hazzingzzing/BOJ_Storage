#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

string board[102];
int input1, input2;
int dist[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> input1 >> input2;

	for (int i = 0; i < input1; i++)
	{
		cin >> board[i];
	}

	for (int i = 0; i < input1; i++)
	{
		fill(dist[i], dist[i] + input2, -1);
	}

	queue<pair<int, int>> Q;
	Q.push({ 0,0 });
	dist[0][0] = 0;

	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || ny < 0 || nx > input1 || ny > input2)
				continue;
			if (dist[nx][ny] >= 0 || board[nx][ny] != '1')
				continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({ nx, ny });
		}
	}

	cout << dist[input1 - 1][input2 - 1] + 1;
	return 0;
}