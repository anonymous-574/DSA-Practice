#include <iostream>
#include <fstream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;


void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}


int partition(int arr[], int low, int high) {
   
    int pivot = arr[high];
   
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
   
    swap(&arr[i + 1], &arr[high]);  
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
       

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int SIZE = 100000;
    int arr[SIZE];

    srand(time(NULL));
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand();
    }

   
    ofstream outFile("random_numbers.txt");
    for (int i = 0; i < SIZE; ++i) {
        outFile << arr[i] << endl;
    }
    outFile.close();

   

    double ans1[1000],ans2[1000];
    int i=0;
    for (int blockSize = 100; blockSize <= SIZE; blockSize += 100) {
        int tempArr1[blockSize], tempArr2[blockSize];
       
        for (int k = 0; k < blockSize; ++k) {
            tempArr1[k] = arr[k];
            tempArr2[k] = arr[k];
        }

       
        auto start1 = high_resolution_clock::now();
        mergeSort(tempArr1, 0, blockSize);
        auto end1 = high_resolution_clock::now();
        double insertionTime = duration<double, micro>(end1 - start1).count();

       
        auto start2 = high_resolution_clock::now();
        quickSort(tempArr2, 0,blockSize);
        auto end2 = high_resolution_clock::now();
        double selectionTime = duration<double, micro>(end2 - start2).count();
        ans1[i]=insertionTime;
        ans2[i]=selectionTime;
        i++;
    }

    ofstream insert_file("merge.txt");
    if (insert_file.is_open()) {
        for (int j=0; j<1000 ; j++) {
            insert_file << ans1[j] << endl;
        }
        insert_file.close();
    } else {
        cerr << "Failed to open merge.txt for writing.\n";
    }

    ofstream select_file("quick.txt");
    if (select_file.is_open()) {
        for (int j=0; j<1000 ; j++) {
            select_file << ans2[j] << endl;
        }
        select_file.close();
    } else {
        cerr << "Failed to open quick.txt for writing.\n";
    }

   

    return 0;
}