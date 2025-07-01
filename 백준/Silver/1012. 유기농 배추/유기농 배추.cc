#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int board[51][51];
bool vis[51][51];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t_case;
	cin >> t_case;

	for (int i = 0; i < t_case; i++)
	{
		int input1, input2, input3, a, b;
		cin >> input1 >> input2 >> input3;

		// 초기화
		memset(board, 0, sizeof(board));
		memset(vis, 0, sizeof(vis));

		for (int j = 0; j < input3; j++)
		{
			cin >> a >> b;
			board[b][a] = 1;  // board[행][열]
		}

		int cnt = 0;
		for (int i = 0; i < input2; i++)  // 행
		{
			for (int j = 0; j < input1; j++)  // 열
			{
				if (board[i][j] == 0 || vis[i][j])
					continue;

				cnt++;
				queue<pair<int, int>> Q;
				Q.push({ i, j });
				vis[i][j] = 1;

				while (!Q.empty())
				{
					auto cur = Q.front(); Q.pop();

					for (int k = 0; k < 4; k++)
					{
						int nx = cur.X + dx[k];
						int ny = cur.Y + dy[k];

						if (nx < 0 || ny < 0 || nx >= input2 || ny >= input1)
							continue;
						if (board[nx][ny] != 1 || vis[nx][ny])
							continue;

						Q.push({ nx, ny });
						vis[nx][ny] = 1;
					}
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
