#include <iostream>
#include <vector>
using namespace std;
bool found = false;

void backtrack(const vector<int>& arr, int index, int currSum, int target, vector<int>& sol) {
    if (currSum == target) {
        cout << "Ans [";
        for (size_t i = 0; i < sol.size(); ++i) {
            cout << sol[i];
            if (i < sol.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
        found = true;
        return;
    }
    if (index >= arr.size() || currSum > target)
        return;
    sol.push_back(arr[index]);
    backtrack(arr, index + 1, currSum + arr[index], target, sol);
    sol.pop_back(); 
    backtrack(arr, index + 1, currSum, target, sol);
}

int main() {
    int n, target;
    cout << "Enter the number of elements in the set: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements (non-negative integers): ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << "Enter the target sum: ";
    cin >> target;
    vector<int> sol;
    backtrack(arr, 0, 0, target, sol);

    if (!found) {
        cout << "No subset found that adds up to " << target << "." << endl;
    }

    return 0;
}


/*
OUTPUT
Enter the number of elements in the set: 6
Enter the elements (non-negative integers): 5 10 12 13 15 18
Enter the target sum: 30
Ans [5,10,15]
Ans [5,12,13]
Ans [12,18]

*/