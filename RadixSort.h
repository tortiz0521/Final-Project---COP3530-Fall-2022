#ifndef RadixSort_h
#define RadixSort_h

#include <iostream>
#include <vector>
#include <string>
using namespace std;


int findMax(const vector<pair<string, int>> data)
{
	int max = data[0].second;
	for (int i = 0; i < data.size(); i++) {
		if (data[i].second > max) {
			max = data[i].second;
		}
	}

	return max;
}

void countingSort(vector<pair<string, int>>& data, int digit)
{
	vector<pair<string, int>> out(data.size());
	int helpArr[10] = { 0 };

	for (int i = 0; i < data.size(); i++) {
		int sVal = (data[i].second / digit) % 10;
		helpArr[sVal]++;
	}

	for (int i = 1; i < 10; i++) {
		helpArr[i] += helpArr[i - 1];
	}

	for (int i = data.size() - 1; i >= 0; i--) {
		int sVal = (data[i].second / digit) % 10;
		out[helpArr[sVal] - 1].first = data[i].first;
		out[helpArr[sVal] - 1].second = data[i].second;
		helpArr[sVal]--;
	}

	for (int i = 0; i < out.size(); i++) {
		data[i].first = out[i].first;
		data[i].second = out[i].second;
	}
}

vector<pair<string, int>> dedecimal(vector<pair<string, double>> data)
{
	vector<pair<string, int>> d;
	for (int i = 0; i < data.size(); i++) {
		d.push_back(make_pair(data[i].first, data[i].second * 100));
	}

	return d;
}

vector<pair<string, double>> redecimal(vector<pair<string, int>> data)
{
	vector<pair<string, double>> d;
	for (int i = 0; i < data.size(); i++) {
		d.push_back(make_pair(data[i].first, (double)data[i].second / 100.0));
	}

	return d;
}

void radixSort(vector<pair<string, double>>& data)
{
	vector<pair<string, int>> de = dedecimal(data);
	int max = findMax(de);

	for (int d = 1; max / d > 0; d *= 10) {
		countingSort(de, d);
	}

	data = redecimal(de);
}

void radixSort(vector<pair<string, int>>& data)
{
	vector<pair<string, int>> de;
	int max = findMax(de);

	for (int d = 1; max / d > 0; d *= 10) {
		countingSort(de, d);
	}

}

#endif
