#include<iostream>
#include<vector>

using namespace std;


// the interval from [start to mid] and [mid+1 to end] in v are sorted function will merge both of these intervals
// such the interval from [start to end] in v becomes sorted
void merge_double(vector<pair<string, double>>& v, int start, int mid, int end) {

	// temp is used to temporary store the vector obtained by merging
	// elements from [start to mid] and [mid+1 to end] in v
	vector<pair<string, double>> temp;
	int i, j;
	i = start;
	j = mid + 1;
	while (i <= mid && j <= end) {
		if (v[i].second <= v[j].second) {
			temp.push_back(v[i]);
			i++;
		}
		else {
			temp.push_back(v[j]);
			j++;
		}
	}
	while (i <= mid) {
		temp.push_back(v[i]);
		i++;
	}

	while (j <= end) {
		temp.push_back(v[j]);
		j++;
	}

	for (int i = start; i <= end; i++)
		v[i] = temp[i - start];
}
// the MergeSort function Sorts the array in the range [start to end] in v using merge sort algorithm
void MergeSort_double(vector<pair<string, double>>& v, int start, int end)
{
	if (start < end) {
		int mid = (start + end) / 2;
		MergeSort_double(v, start, mid);
		MergeSort_double(v, mid + 1, end);
		merge_double(v, start, mid, end);
	}
}

void merge_int(vector<pair<string, int>>& v, int start, int mid, int end) {

	// temp is used to temporary store the vector obtained by merging
	// elements from [start to mid] and [mid+1 to end] in v
	vector<pair<string, int>> temp;
	int i, j;
	i = start;
	j = mid + 1;
	while (i <= mid && j <= end) {
		if (v[i].second <= v[j].second) {
			temp.push_back(v[i]);
			i++;
		}
		else {
			temp.push_back(v[j]);
			j++;
		}
	}
	while (i <= mid) {
		temp.push_back(v[i]);
		i++;
	}

	while (j <= end) {
		temp.push_back(v[j]);
		j++;
	}

	for (int i = start; i <= end; i++)
		v[i] = temp[i - start];
}

void MergeSort_int(vector<pair<string, int>>& v, int start, int end)
{
	if (start < end) {
		int mid = (start + end) / 2;
		MergeSort_int(v, start, mid);
		MergeSort_int(v, mid + 1, end);
		merge_int(v, start, mid, end);
	}
}