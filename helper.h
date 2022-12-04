#pragma once
using namespace std;

struct CSVData{
    string  bookId, title,author=""; 
    int  pages,numRatings, likedPercent,bbeScore,bbeVotes =0;
    double rating = 0.0;
    double price =0.0;
};