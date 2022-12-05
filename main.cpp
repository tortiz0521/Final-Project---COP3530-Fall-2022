#include <iostream>
#include <vector>
using namespace std;

vector<int> temp(7);
vector<int> vec = { 38, 27, 43, 9, 3, 82, 10 };

void merge(int start, int end) {
    int mid = (start + end) / 2;
    int left_index = start;
    int right_index = mid + 1;
    int k = start;

    while (k <= end) {
        if (left_index > mid) {
            temp[k++] = vec[right_index++];
            continue;
        }
        if (right_index > end) {
            temp[k++] = vec[left_index++];
            continue;
        }
        if (vec[left_index] <= vec[right_index])
            temp[k++] = vec[left_index++];
        else
            temp[k++] = vec[right_index++];
    }
    for (int i = start; i <= end; i++) vec[i] = temp[i];
}

void merge_sort(int start, int end) {
    if (start >= end) return;
    int mid = (start + end) / 2;
    merge_sort(start, mid);
    merge_sort(mid + 1, end);
    merge(start, end);
}

void print() { // print all of the element in the vector
    for (const int& n : vec) cout << n << ' ';
}

int main() {
    merge_sort(0, 6);
    // print the result
    print();

    return 0;
}