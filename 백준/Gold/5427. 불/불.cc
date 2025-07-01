#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

char board[1001][1001];
int dist1[1001][1001]; // 불
int dist2[1001][1001]; // 상근이
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t_case;
	cin >> t_case;

	while (t_case--)
	{
		int a, b;
		cin >> b >> a;

		queue<pair<int, int>> Q1;
		queue<pair<int, int>> Q2;

		for (int i = 0; i < a; i++)
		{
			fill(dist1[i], dist1[i] + b, -1);
			fill(dist2[i], dist2[i] + b, -1);
		}

		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				cin >> board[i][j];

				if (board[i][j] == '*')
				{
					dist1[i][j] = 0;
					Q1.push({ i, j });
				}
				if (board[i][j] == '@')
				{
					dist2[i][j] = 0;
					Q2.push({ i, j });
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
				
				if (nx < 0 || ny < 0 || nx >= a || ny >= b)
					continue;
				if (dist1[nx][ny] != -1 || board[nx][ny] == '#')
					continue;
				Q1.push({ nx, ny });
				dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
			}
		}
		
		bool escape = false;

		while (!Q2.empty())
		{
			auto cur = Q2.front(); Q2.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];

				if (nx < 0 || ny < 0 || nx >= a || ny >= b)
				{
					cout << dist2[cur.X][cur.Y] + 1 << '\n';
					escape = 1;
					break;
				}
				if (dist2[nx][ny] != -1 || board[nx][ny] == '#')
					continue;
				if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1)
					continue;
				
				Q2.push({ nx, ny });
				dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
			}
			if (escape == 1)
				break;
		}

		if (escape == 1)
			continue;
		cout << "IMPOSSIBLE" << '\n';
	}

	return 0;
}