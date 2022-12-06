#include<iostream>
#include<vector>

using namespace std;



void merge_double(vector<pair<string, double>>& v, int start, int mid, int end) { // merge the vector of pair, stirng and double (rate, price)
	vector<pair<string, double>> temp_vec; // vector that have the data temporary
	int i = start;
	int j = mid + 1;
	while (i <= mid && j <= end) {
		if (v[i].second <= v[j].second) {
			temp_vec.push_back(v[i]);
			i++;
		}
		else {
			temp_vec.push_back(v[j]);
			j++;
		}
	}
	while (i <= mid) {
		temp_vec.push_back(v[i]);
		i++;
	}

	while (j <= end) {
		temp_vec.push_back(v[j]);
		j++;
	}

	for (int i = start; i <= end; i++)
		v[i] = temp_vec[i - start];
}

void mergeSort_double(vector<pair<string, double>>& v, int start, int end) { // Merge sort for vecotr of pair, string and double (rate, price)
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort_double(v, start, mid);
		mergeSort_double(v, mid + 1, end);
		merge_double(v, start, mid, end);
	}
}

void merge_int(vector<pair<string, int>>& v, int start, int mid, int end) { // merge the vector of pair, stirng and int (pages, liked percent)
	vector<pair<string, int>> temp_vec; // vector that have the data temporary
	int i = start;
	int j = mid + 1;
	while (i <= mid && j <= end) {
		if (v[i].second <= v[j].second) {
			temp_vec.push_back(v[i]);
			i++;
		}
		else {
			temp_vec.push_back(v[j]);
			j++;
		}
	}
	while (i <= mid) {
		temp_vec.push_back(v[i]);
		i++;
	}

	while (j <= end) {
		temp_vec.push_back(v[j]);
		j++;
	}

	for (int i = start; i <= end; i++)
		v[i] = temp_vec[i - start];
}

void mergeSort_int(vector<pair<string, int>>& v, int start, int end) { // Merge sort for vecotr of pair, string and int (page, liked percent)
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort_int(v, start, mid);
		mergeSort_int(v, mid + 1, end);
		merge_int(v, start, mid, end);
	}
}