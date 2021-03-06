#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_V 10001

vector<int> answer = vector<int>(MAX_V, INT_MAX);

int main(void)
{
	int input = 0; cin >> input;
	
	vector<int> cost = vector<int>(input + 1, 0);
	for (int ii = 1; ii <= input; ii++) { cin >> cost[ii]; }

	answer[0] = 0;
	for (int ii = 1; ii <= input; ii++) {
		for (int jj = 1; jj <= ii; jj++) {
			// D[N] = min(D[N], D[N - jj] + C[jj] (1 <= jj <= ii)
			answer[ii] = min(answer[ii], answer[ii - jj] + cost[jj]);
		}
	}
	
	cout << answer[input] << endl;

	return 0;
}