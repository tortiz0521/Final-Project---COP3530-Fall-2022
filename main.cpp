#include <iostream>
#include <map>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "helper.h"
using namespace std;

void GetDataFromCSV(string filepath, map<string, CSVData> &library ) {
	ifstream inFile(filepath);

	if (inFile.is_open()) {
		string lineFromFile;
		getline(inFile, lineFromFile);

		while (getline(inFile, lineFromFile)) {
			istringstream stream(lineFromFile);
    			string  bookId, title,author="";
    			string rating, pages,numRatings, likedPercent,bbeScore,bbeVotes,price="";
			
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

int main()
{
	map<string, CSVData> library;
	GetDataFromCSV("FinalCleanedLibrary.csv",library);
	cout << "done";	
}
