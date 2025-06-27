#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#define X first
#define Y second

using namespace std;
int board[501][501];
bool vis[501][501];
int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}

	int count = 0, mx = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0 || vis[i][j])
				continue;
			count++;
			queue < pair<int, int>> Q;
			vis[i][j] = 1;
			Q.push({ i,j });
			int area = 0;
		
			while (!Q.empty())
			{
				area++;
				pair <int, int> cur = Q.front(); Q.pop();

				for (int i =0; i < 4; i++)
				{
					int nx = cur.X + dx[i];
					int ny = cur.Y + dy[i];

					if (nx < 0 || ny < 0 || nx > n || ny > m)
						continue;
					if (vis[nx][ny] || board[nx][ny] != 1)
						continue;
					vis[nx][ny] = 1;
					Q.push({ nx, ny });
				}
			}
			mx = max(mx, area);
		}
	}
	cout << count << "\n" << mx;
	return 0;
}