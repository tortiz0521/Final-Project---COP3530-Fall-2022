#include <iostream>
#include <map>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "helper.h"
#include<vector>
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
vector<pair<string, double>> createListDouble(vector<pair<string, double>> &list, string value,map<string, CSVData> &library ){
	
	for (auto it = library.begin(); it != library.end(); it++)
{	if (value == "rating")
     list.push_back(std::make_pair(it->first, it->second.rating));    
	else if (value == "price")
	list.push_back(std::make_pair(it->first, it->second.price));   
}
	return list;

}
vector<pair<string, int>> createListInt(vector<pair<string, int>> &list, string value,map<string, CSVData> &library ){
	
	for (auto it = library.begin(); it != library.end(); it++)
{	if (value == "pages")
    list.push_back(std::make_pair(it->first, it->second.pages));    
	else if (value == "likedPercent")
	list.push_back(std::make_pair(it->first, it->second.likedPercent));   
}
	return list;

}
int main()
{
	map<string, CSVData> library;

	GetDataFromCSV("FinalCleanedLibrary.csv",library);
	int selection;
	int range;



	while(selection!=5){
		
		cout << "How would you like to find your book?"<<endl;
		cout << "1. Sort by page number"<<endl;
		cout << "2. Sort by rating"<<endl;
		cout << "3. Sort by price"<<endl;
		cout << "4. Sort by liked percentage"<<endl;
		cout << "5. Exit Library"<<endl;
		cin >>selection;

	if(selection ==1 ){
		cout << "How many results would you like to see?"<<endl;
		cin >> range;
		vector<pair<string, int>> listPages = createListInt(listPages,"pages",library);
	}
	else if (selection ==2){
		cout << "How many results would you like to see?"<<endl;
		cin >> range;
		vector<pair<string, double>> listRating = createListDouble(listRating,"rating",library);
		
	}
	else if (selection ==3){
		cout << "How many results would you like to see?"<<endl;
		cin >> range;
		vector<pair<string, double>> listPrice = createListDouble(listPrice,"price",library);
	}
	else if (selection ==4){
		cout << "How many results would you like to see?"<<endl;
		cin >> range;
		vector<pair<string, int>> listlikedPercent = createListInt(listlikedPercent,"likedPercent",library);
	}
	else if (selection ==5){
		break;
	}
	else
	cout << "Please make a valid selection"<<endl;
	
	}
	cout << "Thank you for stopping by, I hope you enjoyed our slection and found a good book!";
	
}
