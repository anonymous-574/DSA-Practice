#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iterator>
#include <cstdlib>
#include <ctime>

using namespace std;

void insertion_sort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selection_sort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

int main() {
    vector<int> all_nos;
    vector<double> insert, select;

    const int MAX_NUMBERS = 100000;  
    const int STEP = 100;           

    srand(time(NULL));

    all_nos.reserve(MAX_NUMBERS);
    for (int i = 0; i < MAX_NUMBERS; i++) {
        all_nos.push_back(rand());
    }

    ofstream numbers_file("numbers.txt");
    if (numbers_file.is_open()) {
        for (const auto& num : all_nos) {
            numbers_file << num << endl;
        }
        numbers_file.close();
    } else {
        cerr << "Failed to open numbers.txt for writing.\n";
    }

    for (int block_size = STEP; block_size <= MAX_NUMBERS; block_size += STEP) {
        vector<int> curr(all_nos.begin(), all_nos.begin() + block_size);

        auto start = chrono::high_resolution_clock::now();
        insertion_sort(curr);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        insert.push_back(duration.count());

        // Reset the vector to the unsorted state
        curr.assign(all_nos.begin(), all_nos.begin() + block_size);


        start = chrono::high_resolution_clock::now();
        selection_sort(curr);
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(end - start);
        select.push_back(duration.count());
    }

    ofstream insert_file("insert.txt");
    if (insert_file.is_open()) {
        for (const auto& time : insert) {
            insert_file << time << endl;
        }
        insert_file.close();
    } else {
        cerr << "Failed to open insert.txt for writing.\n";
    }

    ofstream select_file("select.txt");
    if (select_file.is_open()) {
        for (const auto& time : select) {
            select_file << time << endl;
        }
        select_file.close();
    } else {
        cerr << "Failed to open select.txt for writing.\n";
    }

    return 0;
}
