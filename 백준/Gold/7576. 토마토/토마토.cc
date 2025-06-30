#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int board[1002][1002];
int input1, input2;
int dist[1002][1002];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> input2 >> input1;

	queue<pair<int, int>> Q;

	for (int i = 0; i < input1; i++)
	{
		for (int j = 0; j < input2; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
			{
				Q.push({ i,j });
				dist[i][j] = 0;
			}
			if (board[i][j] == 0)
				dist[i][j] = -1;
		}
	}
	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || ny < 0 || nx >= input1 || ny >= input2)
				continue;
			if (dist[nx][ny] >= 0)
				continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({ nx, ny });
		}
	}

	int ans = 0;
	for (int i = 0; i < input1; i++)
	{
		for (int j = 0; j < input2; j++)
		{
			if (dist[i][j] == -1)
			{
				cout << -1;
				return 0;
			}
			ans = max(ans, dist[i][j]);
		}
	}

	cout << ans;
	return 0;
}