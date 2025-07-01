#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int dist[304][304];
int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };


int main()
{
	int t_case, input, a, b, c, d;

	cin >> t_case;

	while (t_case--)
	{
		cin >> input;
		queue<pair<int, int>> Q;

		for (int i = 0; i < input; i++)
		{
			fill(dist[i], dist[i] + input, -1);
		}

		cin >> a >> b >> c >> d;
		dist[a][b] = 0;
		Q.push({ a,b });

		while (!Q.empty())
		{
			auto cur = Q.front(); Q.pop();

			if (cur.X == c && cur.Y == d)
				break;

			for (int i = 0; i < 8; i++)
			{
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];

				if (nx < 0 || ny < 0 || nx > input || ny > input)
					continue;
				if (dist[nx][ny] != -1)
					continue;
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				Q.push({ nx, ny });
			}
		}
		

		cout << dist[c][d] << '\n';
	}
		return 0;
}