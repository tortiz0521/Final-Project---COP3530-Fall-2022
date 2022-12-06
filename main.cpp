#include <iostream>
#include <map>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <utility>
#include<vector>
#include <chrono>
#include "helper.h"
#include "mergeSort.h"

using namespace std;

void GetDataFromCSV(string filepath, map<string, CSVData>& library) {
	ifstream inFile(filepath);

	if (inFile.is_open()) {
		string lineFromFile;
		getline(inFile, lineFromFile);

		while (getline(inFile, lineFromFile)) {
			istringstream stream(lineFromFile);
			string  bookId, title, author = "";
			string rating, pages, numRatings, likedPercent, bbeScore, bbeVotes, price = "";

			getline(stream, bookId, ',');
			getline(stream, title, ',');
			getline(stream, author, ',');
			getline(stream, rating, ',');
			getline(stream, pages, ',');
			getline(stream, numRatings, ',');
			getline(stream, likedPercent, ',');
			getline(stream, bbeScore, ',');
			getline(stream, bbeVotes, ',');
			getline(stream, price, ',');
			CSVData data;
			data.bookId = bookId;
			data.title = title;
			data.author = author;
			data.rating = stod(rating);
			data.pages = stoi(pages);
			data.numRatings = stoi(numRatings);
			data.likedPercent = stoi(likedPercent);
			data.bbeScore = stoi(bbeScore);
			data.bbeVotes = stoi(bbeVotes);
			data.price = stod(price);
			library[title] = data;
		}

	}
}
vector<pair<string, double>> createListDouble(vector<pair<string, double>>& list, string value, const map<string, CSVData>& library) {
	for (const auto& p : library)
	{
		if (value == "rating")
			list.push_back(std::make_pair(p.first, p.second.rating));
		else if (value == "price")
			list.push_back(std::make_pair(p.first, p.second.price));
	}
	return list;

}
vector<pair<string, int>> createListInt(vector<pair<string, int>>& list, string value, map<string, CSVData>& library) {
	for (auto it = library.begin(); it != library.end(); it++)
	{
		if (value == "pages") {
			list.push_back(std::make_pair(it->first, it->second.pages));
		}
		else if (value == "likedPercent")
			list.push_back(std::make_pair(it->first, it->second.likedPercent));
	}
	return list;

}
int main()
{
	map<string, CSVData> library;

	GetDataFromCSV("FinalCleanedLibrary.csv", library);
	int selection = 0;
	int range;

	int sizeRating;
	int sizePrice;
	int sizePage;
	int sizePercent;

	while (selection != 5) {

		cout << "How would you like to find your book?" << endl;
		cout << "1. Sort by page number" << endl;
		cout << "2. Sort by rating" << endl;
		cout << "3. Sort by price" << endl;
		cout << "4. Sort by liked percentage" << endl;
		cout << "5. Exit Library" << endl;
		cin >> selection;
		if (selection == 1) {
			cout << "How many results would you like to see?" << endl;
			cin >> range;
			vector<pair<string, int>> listPages;
			listPages = createListInt(listPages, "pages", library);
			sizePage = listPages.size();
			auto start1 = chrono::high_resolution_clock::now(); // Count to start the time on here
			mergeSort_int(listPages, 0, sizePage - 1);
			auto end1 = chrono::high_resolution_clock::now(); // stop the time on here
			auto time1 = chrono::duration_cast<chrono::microseconds>(end1 - start1).count(); // Caculate the time 
			cout << endl << "Descending Order: " << endl;
			for (int i = sizePage - 1; i >= sizePage - range; i--) {
				cout << listPages[i].first << ' ' << listPages[i].second << endl;
			}
			cout << endl;
			cout << "Time taken by Merge Sort: " << time1 << " microseconds." << endl; // print the time to execute
			cout << endl;
		}
		else if (selection == 2) {
			cout << "How many results would you like to see?" << endl;
			cin >> range;
			vector<pair<string, double>> listRating;
			listRating = createListDouble(listRating, "rating", library);
			sizeRating = listRating.size();
			auto start1 = chrono::high_resolution_clock::now(); // Count to start the time on here
			mergeSort_double(listRating, 0, sizeRating - 1);
			auto end1 = chrono::high_resolution_clock::now(); // stop the time on here
			auto time1 = chrono::duration_cast<chrono::microseconds>(end1 - start1).count(); // Caculate the time 
			cout << endl << "Descending Order: " << endl;
			for (int i = sizeRating - 1; i >= sizeRating - range; i--) {
				cout << listRating[i].first << ' ' << fixed << showpoint << setprecision(2) << listRating[i].second << endl;
			}
			cout << endl;
			cout << "Time taken by Merge Sort: " << time1 << " microseconds." << endl; // print the time to execute
			cout << endl;
		}
		else if (selection == 3) {
			cout << "How many results would you like to see?" << endl;
			cin >> range;
			vector<pair<string, double>> listPrice;
			listPrice = createListDouble(listPrice, "price", library);
			sizePrice = listPrice.size();
			auto start1 = chrono::high_resolution_clock::now(); // Count to start the time on here
			mergeSort_double(listPrice, 0, sizePrice - 1);
			auto end1 = chrono::high_resolution_clock::now(); // stop the time on here
			auto time1 = chrono::duration_cast<chrono::microseconds>(end1 - start1).count(); // Caculate the time 
			cout << endl << "Descending Order: " << endl;
			for (int i = sizePrice - 1; i >= sizePrice - range; i--) {
				cout << listPrice[i].first << ' ' << fixed << showpoint << setprecision(2) << listPrice[i].second << endl;
			}
			cout << endl;
			cout << "Time taken by Merge Sort: " << time1 << " microseconds." << endl; // print the time to execute
			cout << endl;
		}
		else if (selection == 4) {
			cout << "How many results would you like to see?" << endl;
			cin >> range;
			vector<pair<string, int>> listlikedPercent;
			listlikedPercent = createListInt(listlikedPercent, "likedPercent", library);
			sizePercent = listlikedPercent.size();
			auto start1 = chrono::high_resolution_clock::now(); // Count to start the time on here
			mergeSort_int(listlikedPercent, 0, sizePercent - 1);
			auto end1 = chrono::high_resolution_clock::now(); // stop the time on here
			auto time1 = chrono::duration_cast<chrono::microseconds>(end1 - start1).count(); // Caculate the time 
			cout << endl << "Descending Order: " << endl;
			for (int i = sizePercent - 1; i >= sizePercent - range; i--) {
				cout << listlikedPercent[i].first << ' ' << listlikedPercent[i].second << endl;
			}
			cout << endl;
			cout << "Time taken by Merge Sort: " << time1 << " microseconds." << endl; // print the time to execute
			cout << endl;
		}
		else if (selection == 5) {
			break;
		}
		else
			cout << "Please make a valid selection" << endl;
			break;

	}
	cout << "Thank you for stopping by, I hope you enjoyed our slection and found a good book!";
}
