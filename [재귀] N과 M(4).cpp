#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int> > answer;

void reculsive(const int length, const int goal, int index, int current, vector<int> bucket) {

	if (index > goal) { return; }
	if (index == goal) { 
		for (const int number : bucket) {
			printf("%d ", number);
		}
		printf("\n"); return;
	}

	for (int ii = current - 1; ii < length; ii++) {
		bucket[index] = ii + 1;
		reculsive(length, goal, index + 1, ii + 1, bucket);
	}
}

int main(void)
{
	pair<int, int> input = make_pair(0, 0);
	cin >> input.first >> input.second;

	vector<int> bucket = vector<int>(input.second);
	reculsive(input.first, input.second, 0, 1, bucket);

	return 0;
}