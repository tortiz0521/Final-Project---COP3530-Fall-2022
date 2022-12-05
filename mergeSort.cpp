#include<iostream>
#include<vector>
#include <map>
#include <chrono>

using namespace std;

// the interval from [start to mid] and [mid+1 to end] in v are sorted function will merge both of these intervals
// such the interval from [start to end] in v becomes sorted
void MergeSortedIntervals(vector<pair<string, double>>& v, int start, int mid, int end) {

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
void MergeSort(vector<pair<string, double>>& v, int start, int end)
{
	if (start < end) {
		int mid = (start + end) / 2;
		MergeSort(v, start, mid);
		MergeSort(v, mid + 1, end);
		MergeSortedIntervals(v, start, mid, end);
	}
}

int main() {
	map<string, double> books;
	books.insert(std::pair<string, double>("Harry Potter", 4.5));
	books.insert(std::pair<string, double>("Ninja turtles", 4.3));
	books.insert(std::pair<string, double>("Nania", 4.8));
	books.insert(std::pair<string, double>("Frozen", 4.2));
	books.insert(std::pair<string, double>("Toy story", 5.0));
	books.insert(std::pair<string, double>("Bugs Life", 4.7));
	books.insert(std::pair<string, double>("Naruto", 3.9));
	// for check same value
	books.insert(std::pair<string, double>("League of Legend", 4.5));
	books.insert(std::pair<string, double>("OverWatch", 4.3));
	books.insert(std::pair<string, double>("Star Craft", 4.8));
	books.insert(std::pair<string, double>("War Craft", 4.2));
	books.insert(std::pair<string, double>("Counter Strike", 5.0));
	books.insert(std::pair<string, double>("Battle Field", 4.7));
	books.insert(std::pair<string, double>("Steam", 3.9));
	cout << "book size is: " << books.size() << endl;
	cout << endl << "Default map Order is: " << endl;
	vector<pair<string, double>> v;

	// copy the map to vector v 
	for (auto& it : books) {
		v.push_back(it);
	}
	// get the size of the vector
	int n = v.size();
	// print the books with normal order
	for (auto& it : v) {
		cout << it.first << ' ' << it.second << endl;
	}
	auto start1 = chrono::high_resolution_clock::now(); // Count to start the time on here
	MergeSort(v, 0, n - 1);
	auto end1 = chrono::high_resolution_clock::now(); // stop the time on here
	auto time1 = chrono::duration_cast<chrono::microseconds>(end1 - start1).count(); // Caculate the time 
	// print the ascending order
	cout << endl << "Ascending Order: " << endl;
	for (auto& it : v) {
		cout << it.first << ' ' << it.second << endl;
	}
	// print the descending order
	cout << endl << "Descending Order: " << endl;
	for (int i = n - 1; i >= 0; i--) {
		cout << v[i].first << ' ' << v[i].second << endl;
	}
	cout << endl;
	cout << "Time taken by Merge Sort: " << time1 << " microseconds." << endl; // print the time to execute
}
