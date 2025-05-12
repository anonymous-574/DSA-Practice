#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

// Add two matrices
Matrix add(Matrix A, Matrix B) {
    int n = A.size();
    Matrix result(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] + B[i][j];
    return result;
}

// Subtract two matrices
Matrix subtract(Matrix A, Matrix B) {
    int n = A.size();
    Matrix result(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] - B[i][j];
    return result;
}

// Split a matrix into four submatrices
void splitMatrix(const Matrix &M, Matrix &M11, Matrix &M12, Matrix &M21, Matrix &M22) {
    int k = M.size() / 2;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            M11[i][j] = M[i][j];
            M12[i][j] = M[i][j + k];
            M21[i][j] = M[i + k][j];
            M22[i][j] = M[i + k][j + k];
        }
    }
}

// Strassen’s algorithm
Matrix strassen(Matrix A, Matrix B) {
    int n = A.size();
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int k = n / 2;
    Matrix A11(k, vector<int>(k)), A12(k, vector<int>(k)), A21(k, vector<int>(k)), A22(k, vector<int>(k));
    Matrix B11(k, vector<int>(k)), B12(k, vector<int>(k)), B21(k, vector<int>(k)), B22(k, vector<int>(k));

    splitMatrix(A, A11, A12, A21, A22);
    splitMatrix(B, B11, B12, B21, B22);

    Matrix P = strassen(A11, subtract(B12, B22));
    Matrix Q = strassen(add(A11, A12), B22);
    Matrix R = strassen(add(A21, A22), B11);
    Matrix S = strassen(A22, subtract(B21, B11));
    Matrix T = strassen(add(A11, A22), add(B11, B22));
    Matrix U = strassen(subtract(A12, A22), add(B21, B22));
    Matrix V = strassen(subtract(A11, A21), add(B11, B12));

    Matrix C11 = add(subtract(add(T, S), Q), U);
    Matrix C12 = add(P, Q);
    Matrix C21 = add(R, S);
    Matrix C22 = subtract(subtract(add(P, T), R), V);

    Matrix C(n, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }

    return C;
}

// Print a matrix
void printMatrix(const Matrix &M) {
    for (const auto &row : M) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the matrix (must be a power of 2): ";
    cin >> n;

    Matrix A(n, vector<int>(n)), B(n, vector<int>(n));

    cout << "Enter elements of Matrix A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter elements of Matrix B:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    Matrix C = strassen(A, B);

    cout << "Resultant Matrix C (A x B):\n";
    printMatrix(C);

    return 0;
}
