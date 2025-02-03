#include <iostream>
#include <fstream>
#include <chrono>
#include <cstdlib>



using namespace std;
using namespace std::chrono;


void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    const int SIZE = 100000;
    int arr[SIZE];

    
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand();
    }

    
    ofstream outFile("random_numbers.txt");
    for (int i = 0; i < SIZE; ++i) {
        outFile << arr[i] << endl;
    }
    outFile.close();

   
    ofstream resultFile("sort_results.txt");
    resultFile << "Block_Size,Insertion_Sort_Time(ms),Selection_Sort_Time(ms)\n";

    
    for (int blockSize = 100; blockSize <= SIZE; blockSize += 100) {
        int tempArr1[blockSize], tempArr2[blockSize];

        
        for (int i = 0; i < blockSize; ++i) {
            tempArr1[i] = arr[i];
            tempArr2[i] = arr[i];
        }

        
        auto start1 = high_resolution_clock::now();
        insertionSort(tempArr1, blockSize);
        auto end1 = high_resolution_clock::now();
        double insertionTime = duration<double, micro>(end1 - start1).count();

       
        auto start2 = high_resolution_clock::now();
        selectionSort(tempArr2, blockSize);
        auto end2 = high_resolution_clock::now();
        double selectionTime = duration<double, micro>(end2 - start2).count();

        
        resultFile << blockSize << "," << insertionTime << "," << selectionTime << "\n";
        cout << "Block Size: " << blockSize << " | Insertion Sort: " << insertionTime << " ms | Selection Sort: " << selectionTime << " ms" << endl;
    }

    resultFile.close();
    cout << "Results saved to sort_results.txt" << endl;

    return 0;
}
