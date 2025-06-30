#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> stk;

	int input, sum = 0;
	cin >> input;

	for (int i = 0; i < input; i++)
	{
		int value;
		cin >> value;

		if (value == 0)
		{
			sum -= stk.top();
			stk.pop();
		}
		else
		{
			stk.push(value);
			sum += stk.top();
		}
			
	}
	cout << sum;
	return 0;
}