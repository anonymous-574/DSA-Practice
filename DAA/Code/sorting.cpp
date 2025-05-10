#include <bits/stdc++.h>
using namespace std;

// Merge Sort functions
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int a1[n1], a2[n2];

    for (int i = 0; i < n1; i++) a1[i] = arr[left + i];
    for (int i = 0; i < n2; i++) a2[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (a1[i] <= a2[j]) arr[k++] = a1[i++];
        else arr[k++] = a2[j++];
    }

    while (i < n1) arr[k++] = a1[i++];
    while (j < n2) arr[k++] = a2[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
//END MERGE

// Quick Sort functions
int Partition(int arr[], int left, int right) {
    int x = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] <= x) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = Partition(arr, left, right);
        quickSort(arr, left, mid - 1);
        quickSort(arr, mid + 1, right);
    }
}
//END QUICK

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int choice;
    cout << "Choose sorting algorithm:\n";
    cout << "1. Merge Sort\n2. Quick Sort\n3. Insertion Sort\n";
    cin >> choice;

    switch (choice) {
        case 1: mergeSort(arr, 0, n - 1); break;
        case 2: quickSort(arr, 0, n - 1); break;
        case 3: insertionSort(arr, n); break;
        default: cout << "Invalid choice.\n"; return 0;
    }

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    return 0;
}
