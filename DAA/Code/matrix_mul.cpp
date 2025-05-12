#include <bits/stdc++.h>
using namespace std;

void printOptimalParens(vector<vector<int>> &s, int i, int j) {
    if (i == j) {
        cout << "M" << i + 1;
    } else {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

void printMatrix(const vector<vector<int>> &matrix, const string &name) {
    cout << "\n" << name << " Matrix:\n";
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) cout << "       ";
        for (int j = i; j < n; j++) {
            if (matrix[i][j] == INT_MAX)
                cout << "  INF ";
            else
                printf("%6d ", matrix[i][j]);        }
        cout << "\n";
    }
}

void matrixChainOrder(int n, int dim[]) {
    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<vector<int>> s(n, vector<int>(n, 0));

    // Initialize diagonal as 0 and others as INF
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                m[i][j] = 0;
            else
                m[i][j] = INT_MAX;
        }
    }


    for (int l = 2; l <= n; l++) {
        for (int i = 0; i < n - l + 1; i++) {
            int j = i + l - 1;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + dim[i] * dim[k + 1] * dim[j + 1];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printMatrix(m, "m");
    printMatrix(s, "s");
    cout << "\nOptimal Parenthesization: ";
    printOptimalParens(s, 0, n - 1);
    cout << "\nMinimum number of multiplications: " << m[0][n - 1] << endl;
}

int main() {
    int n;
    cout << "Number of matrices: ";
    cin >> n;
    int dim[n+1];
    cout << "Enter dimensions: ";
    for (int i = 0; i <= n; i++) cin >> dim[i];
    matrixChainOrder(n,dim);
    return 0;
}