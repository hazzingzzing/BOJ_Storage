#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int board[501][501];
bool vis[501][501];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int input1, input2, mx = 0;
	
	cin >> input1 >> input2;

	for (int i = 0; i < input1; i++)
	{
		for (int j = 0; j < input2; j++)
		{
			cin >> board[i][j];
		}
	}

	int cnt = 0;

	for (int i = 0; i < input1; i++)
	{
		for (int j = 0; j < input2; j++)
		{
			if (board[i][j] == 0 || vis[i][j])
				continue;
			queue<pair<int, int>> Q;
			Q.push({ i,j });
			vis[i][j] = 1;

			cnt++;
			int area = 0;

			while (!Q.empty())
			{
				auto cur = Q.front(); Q.pop();
				area++;

				for (int i = 0; i < 4; i++)
				{
					int nx = cur.X + dx[i];
					int ny = cur.Y + dy[i];

					if (nx < 0 || ny < 0 || nx > input1 || nx > input2)
						continue;
					if (board[nx][ny] != 1 || vis[nx][ny])
						continue;
					Q.push({ nx, ny });
					vis[nx][ny] = 1;
				}
			}
			mx = max(mx, area);
		}
	}

	cout << cnt << '\n' << mx;




	return 0;
}