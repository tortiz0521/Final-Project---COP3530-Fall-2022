#include <iostream>
#include <map>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <utility>
#include<vector>
#include <chrono>
#include <string>
#include "helper.h"
#include "mergeSort.h"
#include "RadixSort.h"

using namespace std;

void GetDataFromCSV(string filepath, map<string, CSVData>& library) {//reads in the file as a csv
	ifstream inFile(filepath);

	if (inFile.is_open()) {//while the file is open read through the lines
		string lineFromFile;
		getline(inFile, lineFromFile);

		while (getline(inFile, lineFromFile)) {//while on a certain line, go through the commas and get specific attributes
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
			library[title] = data;//add the data of each book to the overall library in the form of a map, furthermore since it is a map its alphabetical by default
		}

	}
}
vector<pair<string, double>> createListDouble(vector<pair<string, double>>& list, string value, const map<string, CSVData>& library) {
	//cerates a vector pair with the title as the string and the data type to be sorted. This one focuses on the doubles rating and price
	for (const auto& p : library)
	{
		if (value == "rating")//check if data to be added is rating
			list.push_back(std::make_pair(p.first, p.second.rating));
		else if (value == "price")//check if data to be added is price
			list.push_back(std::make_pair(p.first, p.second.price));
	}
	return list;

}
vector<pair<string, int>> createListInt(vector<pair<string, int>>& list, string value, map<string, CSVData>& library) {
	//cerates a vector pair with the title as the string and the data type to be sorted. This one focuses on the ints pages and liked percent
	for (auto it = library.begin(); it != library.end(); it++)//different type of iterator for practice in both styles
	{
		if (value == "pages") {//check if data to be added is pages
			list.push_back(std::make_pair(it->first, it->second.pages));
		}
		else if (value == "likedPercent")//check if data to be added is likedPercent
			list.push_back(std::make_pair(it->first, it->second.likedPercent));
	}
	return list;

}
void intSelect(int range, vector<pair<string, int>> list, map<string, CSVData>& library, string type) {
	//creates and sorts the given vector pair by specified data types and compares the two types of sorts: Raadix and Merge
	//Focuses on the int values Page num and Liked percentage
	list = createListInt(list, type, library);
	int size = list.size();
	vector<pair<string, int>> forMerge = list; // vector that use on merge sort
	vector<pair<string, int>> forRadix = list; // vector that use on radix sort
	
	// for caclulate the execute time for merge sort 
	auto start1 = chrono::high_resolution_clock::now(); // Count to start the time on here
	mergeSort_int(forMerge, 0, size - 1);
	auto end1 = chrono::high_resolution_clock::now(); // stop the time on here
	auto time1 = chrono::duration_cast<chrono::microseconds>(end1 - start1).count();
	
	// for calculate the execute time for radix sort
	auto start2 = chrono::high_resolution_clock::now(); // Count to start the time on here
	radixSort_int(forRadix);
	auto end2 = chrono::high_resolution_clock::now(); // stop the time on here
	auto time2 = chrono::duration_cast<chrono::microseconds>(end2 - start2).count();
	
	// print the raking order by Merge Sort
	cout << endl << "---------------------------" << endl;
	cout << "Ranking order by Merge Sort" << endl;
	cout << "---------------------------" << endl;
	for (int i = size - 1; i >= size - range; i--) {
		cout << forMerge[i].first << ": " << forMerge[i].second << endl;
	}
	cout << endl;
	
	// print the raking order by Radix Sort
	cout << endl << "---------------------------" << endl;
	cout << "Ranking order by Radix Sort" << endl;
	cout << "---------------------------" << endl;
	for (int i = size - 1; i >= size - range; i--) {
		cout << forRadix[i].first << ": " << forRadix[i].second << endl;
	}
	cout << endl;
	cout << "Time taken by Merge Sort: " << time1 << " microseconds." << endl; // print the time to execute merge Sort
	cout << endl;
	cout << "Time taken by Radix Sort: " << time2 << " microseconds." << endl; // print the time to execute Radix Sort
	cout << endl;
}
void dblSelect(int range, vector<pair<string, double>> list, map<string, CSVData>& library, string type) {
	//creates and sorts the given vector pair by specified data types and compares the two types of sorts: Raadix and Merge
	//Focuses on the double values rating and price
	list = createListDouble(list, type, library);
	int size = list.size();
	vector<pair<string, double>> forMerge = list; // vector that use on merge sort
	vector<pair<string, double>> forRadix = list; // vector that use on radix sort

    // for calculate the execute time for merge sort
	auto start1 = chrono::high_resolution_clock::now(); // Count to start the time on here
	mergeSort_double(forMerge, 0, size - 1);
	auto end1 = chrono::high_resolution_clock::now(); // stop the time on here
	auto time1 = chrono::duration_cast<chrono::microseconds>(end1 - start1).count();
	
	// for calculate the execute time for radix sort
	auto start2 = chrono::high_resolution_clock::now(); // Count to start the time on here
	radixSort_double(forRadix);
	auto end2 = chrono::high_resolution_clock::now(); // stop the time on here
	auto time2 = chrono::duration_cast<chrono::microseconds>(end2 - start2).count();
	
	// print the raking order by Merge Sort
	cout << endl << "-------------------------------"<< endl;
	cout << "Ranking order by Merge Sort" << endl;
	cout << "-------------------------------" << endl;
	for (int i = size - 1; i >= size - range; i--) {
		cout << forMerge[i].first << ": " << fixed << showpoint << setprecision(2) << forMerge[i].second << endl;
	}
	cout << endl;

	// print the raking order by Radix Sort
	cout << endl << "---------------------------" << endl;
	cout << "Ranking order by Radix Sort" << endl;
	cout << "---------------------------" << endl;
	for (int i = size - 1; i >= size - range; i--) {
		cout << forRadix[i].first << ": " << fixed << showpoint << setprecision(2) << forRadix[i].second << endl;
	}
	cout << endl;
	cout << "Time taken by Merge Sort: " << time1 << " microseconds." << endl; // print the time to execute merge sort
	cout << endl;
	cout << "Time taken by Radix Sort: " << time2 << " microseconds." << endl; // print the time to execute Radix Sort
	cout << endl;
}
int main()
{
	map<string, CSVData> library;//create the library from a map of the data object

	GetDataFromCSV("FinalCleanedLibrary.csv", library);//gets the data from the CSV
	int selection = 0;
	int range;


	while (true) {
		//Menu options on loop until exit
		cout << "How would you like to find your book?" << endl;
		cout << "1. Sort by page number" << endl;
		cout << "2. Sort by rating" << endl;
		cout << "3. Sort by price" << endl;
		cout << "4. Sort by liked percentage" << endl;
		cout << "5. Find full book information" << endl;
		cout << "6. Exit Library" << endl;
		cin >> selection;
		cin.clear();
		cin.sync();
		if (selection == 1) {//Sort by Page
			cout << "How many results would you like to see?" << endl;
			cin >> range; //takes in the amount of results you wish to see
			vector<pair<string, int>> listPages;
			intSelect(range, listPages, library, "pages");
			//passes in how many results you want, vector pair, the Library map, and data type you want to find
			//and prints the sorted values with time taken for each sort
		}
		else if (selection == 2) {//Sort by Rating
			cout << "How many results would you like to see?" << endl;
			cin >> range;//takes in the amount of results you wish to see
			vector<pair<string, double>> listRating;
			dblSelect(range, listRating, library, "rating");
			//passes in how many results you want, vector pair, the Library map, and data type you want to find
			//and prints the sorted values with time taken for each sort
		}
		else if (selection == 3) {//Sort by Price
			cout << "How many results would you like to see?" << endl;
			cin >> range;//takes in the amount of results you wish to see
			vector<pair<string, double>> listPrice;
			dblSelect(range, listPrice, library, "price");
			//passes in how many results you want, vector pair, the Library map, and data type you want to find
			//and prints the sorted values with time taken for each sort
		}
		else if (selection == 4) {//Sort by liked percentage
			cout << "How many results would you like to see?" << endl;
			cin >> range;//takes in the amount of results you wish to see
			vector<pair<string, int>> listlikedPercent;
			intSelect(range, listlikedPercent, library, "likedPercent");
			//passes in how many results you want, vector pair, the Library map, and data type you want to find
			//and prints the sorted values with time taken for each sort
		}
		else if (selection == 5) {//Find a specific book in the library and all information with it
			cout << "What is the name of the book you are searching for?" << endl;
			string book;
			getline(cin, book);//looks for the book you want
			if (library[book].rating == 0) {//makes sure book exists
				cout << "This is not a valid book in our Library, please start over." << endl;
				cout << endl;
				continue;
			}
			cout << "Author: " << library[book].author << ", Rating: " << library[book].rating << ", \nNumber of Pages: " <<
				library[book].pages << ", Number of Ratings: " << library[book].numRatings << ", \nPercentage Liked: " <<
				library[book].likedPercent << ", Price of Book: " << library[book].price << ", \nBest Books Ever Score: " <<
				library[book].bbeScore << ", Best Books Ever Votes: " << library[book].bbeVotes << endl;
		}
		else if (selection == 6) {//exit the menu/program
			break;
		}
		else
			cout << "Please make a valid selection" << endl;
		cout << endl;

	}
	cout << "Thank you for stopping by, I hope you enjoyed our slection and found a good book!";
}
