#ifndef RadixSort_h
#define RadixSort_h

#include <iostream>
#include <vector>
#include <string>
using namespace std;


int findMax(const vector<int> data)
{
	int max = data[0];
	for (int i = 0; i < data.size(); i++) {
		if (data[i] > max) {
			max = data[i];
		}
	}

	return max;
}

void countingSort(vector<int>& data, int digit)
{
	vector<int> out(data.size());
	int helpArr[10] = { 0 };

	for (int i = 0; i < data.size(); i++) {
		int searchVal = (data[i] / digit) % 10;
		helpArr[searchVal]++;
	}

	for (int i = 1; i < 10; i++) {
		helpArr[i] += helpArr[i - 1];
	}

	for (int i = 0; i < data.size(); i++) {
		int searchVal = (data[i] / digit) % 10;
		out[helpArr[searchVal - 1]] = data[i];
		helpArr[searchVal]--;
	}

	for (int i = 0; i < out.size(); i++) {
		data[i] = out[i];
	}
}

void radixSort(vector<int>& data)
{
	int max = findMax(data);

	for (int d = 1; max / d > 0; d *= 10) {
		countingSort(data, d);
	}
}

#endif
