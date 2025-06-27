#include <bits/stdc++.h>
using namespace std;

int board[102][102][102];
int dist[102][102][102];

int dx[6] = { 1, 0, 0, -1, 0, 0 };
int dy[6] = { 0, 1, 0, 0, -1, 0 };
int dz[6] = { 0, 0, 1, 0, 0, -1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	queue<tuple<int, int, int>> Q;

	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < b; j++)
		{
			for (int k = 0; k < a; k++)
			{
				cin >> board[i][j][k];
				if (board[i][j][k] == 1)
					Q.push({ k, j, i });
				if (board[i][j][k] == 0)
					dist[i][j][k] = -1;
			}
		}
	}

	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		int curX, curY, curZ;
		tie(curX, curY, curZ) = cur;

		for (int i = 0; i < 6; i++)
		{
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			int nz = curZ + dz[i];

			if (nx < 0 || ny < 0 || nz < 0 || nx >= a || ny >= b || nz >= c)
				continue;
			if (dist[nz][ny][nx] >= 0)
				continue;

			Q.push({ nx, ny, nz });
			dist[nz][ny][nx] = dist[curZ][curY][curX] + 1;
		}
	}

	int mx = 0;

	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < b; j++)
		{
			for (int k = 0; k < a; k++)
			{
				if (dist[i][j][k] == -1)
				{
					cout << "-1";
					return 0;
				}
				mx = max(mx, dist[i][j][k]);
			}
		}
	}

	cout << mx;
	return 0;
}
