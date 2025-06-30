#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

string board[1002];
int dist1[1002][1002], dist2[1002][1002];
int input1, input2;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> input1 >> input2;

	for (int i = 0; i < input1; i++)
	{
		fill(dist1[i], dist1[i] + input2, -1);
		fill(dist2[i], dist2[i] + input2, -1);
	}

	for (int i = 0; i < input1; i++)
		cin >> board[i];

	queue<pair<int, int>> Q1;
	queue<pair<int, int>> Q2;

	for (int i = 0; i < input1; i++)
	{
		for (int j = 0; j < input2; j++)
		{
			if (board[i][j] == 'F')
			{
				Q1.push({ i,j });
				dist1[i][j] = 0;
			}
			if (board[i][j] == 'J')
			{
				Q2.push({ i,j });
				dist2[i][j] = 0;
			}
		}
	}

	while (!Q1.empty())
	{
		auto cur = Q1.front(); Q1.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || ny < 0 || nx >= input1 || ny >= input2)
				continue;
			if (dist1[nx][ny] >= 0 || board[nx][ny] == '#')
				continue;
			dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
			Q1.push({ nx, ny });
		}
	}

	while (!Q2.empty())
	{
		auto cur = Q2.front(); Q2.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || ny < 0 || nx >= input1 || ny >= input2)
			{
				cout << dist2[cur.X][cur.Y] + 1;
				return 0;
			}
			if (dist2[nx][ny] >= 0 || board[nx][ny] == '#')
				continue;
			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1)
				continue;
			dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
			Q2.push({ nx, ny });
		}
	}

	cout << "IMPOSSIBLE";
	
	return 0;
}