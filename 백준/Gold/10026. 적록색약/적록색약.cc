#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

char board[101][101];
bool vis[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int input;

void bfs(int i, int j)
{
	queue<pair<int, int>> Q;
	Q.push({ i, j });
	vis[i][j] = 1;

	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || ny < 0 || nx > input || ny > input)
				continue;
			if (board[nx][ny] != board[cur.X][cur.Y] || vis[nx][ny])
				continue;
			Q.push({ nx,ny });
			vis[nx][ny] = 1;
		}
	}
}

int area()
{
	int cnt = 0;
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			if (!vis[i][j])
			{
				cnt++;
				bfs(i, j);
			}
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;
	input = n;

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			cin >> board[i][j];
		}
	}
	
	int not_g = area();

	for (int i = 0; i < n; i++)
	{
		fill(vis[i], vis[i] + n, 0);
	}

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			if (board[i][j] == 'G')
				board[i][j] = 'R';
		}
	}

	int g = area();
	cout << not_g << ' ' << g;

	return 0;
}