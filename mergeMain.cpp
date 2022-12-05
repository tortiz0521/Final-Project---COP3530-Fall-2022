#include<iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include <unordered_map>
#include "mergeSort.h"

int main() {
	unordered_map<string, double> booksDouble;

	booksDouble.insert(std::pair<string, double>("Harry Potter", 4.5));
	booksDouble.insert(std::pair<string, double>("Ninja turtles", 4.3));
	booksDouble.insert(std::pair<string, double>("Nania", 4.8));
	booksDouble.insert(std::pair<string, double>("Frozen", 4.2));
	booksDouble.insert(std::pair<string, double>("Toy story", 5.0));
	booksDouble.insert(std::pair<string, double>("Bugs Life", 4.7));
	booksDouble.insert(std::pair<string, double>("Naruto", 3.9));
	booksDouble.insert(std::pair<string, double>("League of Legend", 4.5));
	booksDouble.insert(std::pair<string, double>("OverWatch", 4.3));
	booksDouble.insert(std::pair<string, double>("Star Craft", 4.8));
	booksDouble.insert(std::pair<string, double>("War Craft", 4.2));
	booksDouble.insert(std::pair<string, double>("Counter Strike", 5.0));
	booksDouble.insert(std::pair<string, double>("Battle Field", 4.7));
	booksDouble.insert(std::pair<string, double>("Steam", 3.9));

	cout << "book size is: " << booksDouble.size() << endl;
	cout << endl << "Default map Order is: " << endl;
	vector<pair<string, double>> v1;
	// copy the map to vector v 
	for (auto& it : booksDouble) {
		v1.push_back(it);
	}

	// get the size of the vector
	int n1 = v1.size();
	// print the books with normal order
	for (auto& it : v1) {
		cout << it.first << ' ' << it.second << endl;
	}

	auto start1 = chrono::high_resolution_clock::now(); // Count to start the time on here
	MergeSort_double(v1, 0, n1 - 1);
	auto end1 = chrono::high_resolution_clock::now(); // stop the time on here
	auto time1 = chrono::duration_cast<chrono::microseconds>(end1 - start1).count(); // Caculate the time 
	// print the ascending order
	cout << endl << "Ascending Order: " << endl;
	for (auto& it : v1) {
		cout << it.first << ' ' << it.second << endl;
	}
	// print the descending order
	cout << endl << "Descending Order: " << endl;
	for (int i = n1 - 1; i >= 0; i--) {
		cout << v1[i].first << ' ' << v1[i].second << endl;
	}
	cout << endl;
	cout << "Time taken by Merge Sort: " << time1 << " microseconds." << endl; // print the time to execute

	cout << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << endl;

	unordered_map<string, int> bookInt;
	bookInt.insert(std::pair<string, int>("Harry Potter", 278));
	bookInt.insert(std::pair<string, int>("Ninja turtles", 3751));
	bookInt.insert(std::pair<string, int>("Nania", 257));
	bookInt.insert(std::pair<string, int>("Frozen", 978));
	bookInt.insert(std::pair<string, int>("Toy story", 1577));
	bookInt.insert(std::pair<string, int>("Bugs Life", 3578));
	bookInt.insert(std::pair<string, int>("Naruto", 742124));
	bookInt.insert(std::pair<string, int>("League of Legend", 642));
	bookInt.insert(std::pair<string, int>("OverWatch", 498));
	bookInt.insert(std::pair<string, int>("Star Craft", 378));
	bookInt.insert(std::pair<string, int>("War Craft", 6574));
	bookInt.insert(std::pair<string, int>("Counter Strike", 25378));
	bookInt.insert(std::pair<string, int>("Battle Field", 30483));
	bookInt.insert(std::pair<string, int>("Steam", 753));

	vector<pair<string, int>> v2;
	cout << "book size is: " << bookInt.size() << endl;
	cout << endl << "Default map Order is: " << endl;
	for (auto& it : bookInt) {
		v2.push_back(it);
	}
	int n2 = v2.size();
	for (auto& it : v2) {
		cout << it.first << ' ' << it.second << endl;
	}

	auto start2 = chrono::high_resolution_clock::now(); // Count to start the time on here
	MergeSort_int(v2, 0, n2 - 1);
	auto end2 = chrono::high_resolution_clock::now(); // stop the time on here
	auto time2 = chrono::duration_cast<chrono::microseconds>(end2 - start2).count(); // Caculate the time 
	// print the ascending order
	cout << endl << "Ascending Order: " << endl;
	for (auto& it : v2) {
		cout << it.first << ' ' << it.second << endl;
	}
	// print the descending order
	cout << endl << "Descending Order: " << endl;
	for (int i = n2 - 1; i >= 0; i--) {
		cout << v2[i].first << ' ' << v2[i].second << endl;
	}
	cout << endl;
	cout << "Time taken by Merge Sort: " << time2 << " microseconds." << endl; // print the time to execute
}