#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <cmath>
#include <algorithm>
using namespace std;
typedef vector<vector<double>> Matrix;

/*
David Daniels - 2023300038 Div A Batch C
*/

Matrix generateRandomMatrix(int rows, int cols) {
    Matrix M(rows, vector<double>(cols));
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            M[i][j] = (double)rand() / RAND_MAX;
        }
    }
    return M;
}

void printMatrix(const Matrix &M) {
    for (const auto &row : M) {
        for (double v : row)
            cout << setw(8) << setprecision(4) << v << " ";
        cout << "\n";
    }
}

Matrix regularMultiply(const Matrix &A, const Matrix &B) {
    int r = A.size();
    int c = B[0].size();
    int inner = A[0].size();
    Matrix C(r, vector<double>(c, 0.0));
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            for (int k = 0; k < inner; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}
Matrix addMatrix(const Matrix &A, const Matrix &B) {
    int r = A.size(), c = A[0].size();
    Matrix C(r, vector<double>(c, 0.0));
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

Matrix subMatrix(const Matrix &A, const Matrix &B) {
    int r = A.size(), c = A[0].size();
    Matrix C(r, vector<double>(c, 0.0));
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}
Matrix getSubmatrix(const Matrix &A, int row, int col, int size) {
    Matrix sub(size, vector<double>(size, 0.0));
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            sub[i][j] = A[row + i][col + j];
        }
    }
    return sub;
}

void setSubmatrix(Matrix &C, const Matrix &sub, int row, int col) {
    int size = sub.size();
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            C[row + i][col + j] = sub[i][j];
        }
    }
}

Matrix padMatrix(const Matrix &A, int n) {
    int r = A.size(), c = A[0].size();
    Matrix B(n, vector<double>(n, 0.0));
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            B[i][j] = A[i][j];
        }
    }
    return B;
}

Matrix unpadMatrix(const Matrix &A, int rows, int cols) {
    Matrix B(rows, vector<double>(cols, 0.0));
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            B[i][j] = A[i][j];
        }
    }
    return B;
}

Matrix strassenMultiplySquare(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<double>(n, 0.0));
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    int newSize = n / 2;
    Matrix A11 = getSubmatrix(A, 0, 0, newSize);
    Matrix A12 = getSubmatrix(A, 0, newSize, newSize);
    Matrix A21 = getSubmatrix(A, newSize, 0, newSize);
    Matrix A22 = getSubmatrix(A, newSize, newSize, newSize);

    Matrix B11 = getSubmatrix(B, 0, 0, newSize);
    Matrix B12 = getSubmatrix(B, 0, newSize, newSize);
    Matrix B21 = getSubmatrix(B, newSize, 0, newSize);
    Matrix B22 = getSubmatrix(B, newSize, newSize, newSize);

    Matrix M1 = strassenMultiplySquare(addMatrix(A11, A22), addMatrix(B11, B22));
    Matrix M2 = strassenMultiplySquare(addMatrix(A21, A22), B11);
    Matrix M3 = strassenMultiplySquare(A11, subMatrix(B12, B22));
    Matrix M4 = strassenMultiplySquare(A22, subMatrix(B21, B11));
    Matrix M5 = strassenMultiplySquare(addMatrix(A11, A12), B22);
    Matrix M6 = strassenMultiplySquare(subMatrix(A21, A11), addMatrix(B11, B12));
    Matrix M7 = strassenMultiplySquare(subMatrix(A12, A22), addMatrix(B21, B22));

    Matrix C11 = addMatrix(subMatrix(addMatrix(M1, M4), M5), M7);
    Matrix C12 = addMatrix(M3, M5);
    Matrix C21 = addMatrix(M2, M4);
    Matrix C22 = addMatrix(subMatrix(addMatrix(M1, M3), M2), M6);

    for (int i = 0; i < newSize; i++){
        for (int j = 0; j < newSize; j++){
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
    return C;
}

Matrix strassenMultiply(const Matrix &A, const Matrix &B) {
    int r1 = A.size();
    int c1 = A[0].size();
    int r2 = B.size();
    int c2 = B[0].size();
    int n = max({r1, c1, c2});
    int mSize = 1;
    while (mSize < n) mSize *= 2;
    Matrix A_padded = padMatrix(A, mSize);
    Matrix B_padded = padMatrix(B, mSize);
    Matrix C_padded = strassenMultiplySquare(A_padded, B_padded);
    Matrix C = unpadMatrix(C_padded, r1, c2);
    return C;
}
void matrixChainOrder(const vector<int> &p, vector<vector<long long>> &m, vector<vector<int>> &s) {
    int n = p.size() - 1;
    for (int i = 1; i <= n; i++){
        m[i][i] = 0;
    }
    for (int l = 2; l <= n; l++){
        for (int i = 1; i <= n - l + 1; i++){
            int j = i + l - 1;
            m[i][j] = 1e18; 
            for (int k = i; k < j; k++){
                long long q = m[i][k] + m[k+1][j] + (long long)p[i-1] * p[k] * p[j];
                if (q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printOptimalParens(const vector<vector<int>> &s, int i, int j) {
    if (i == j) {
        cout << "M" << i;
    } else {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        cout << " X ";
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}
Matrix multiplyChainOptimal(const vector<Matrix> &matrices, const vector<vector<int>> &s, int i, int j, bool useStrassen) {
    if (i == j) {
        return matrices[i-1];
    }
    int k = s[i][j];
    Matrix A = multiplyChainOptimal(matrices, s, i, k, useStrassen);
    Matrix B = multiplyChainOptimal(matrices, s, k+1, j, useStrassen);
    return useStrassen ? strassenMultiply(A, B) : regularMultiply(A, B);
}

Matrix multiplyChainTrivial(const vector<Matrix> &matrices, bool useStrassen) {
    Matrix result = matrices[0];
    for (size_t i = 1; i < matrices.size(); i++){
        result = useStrassen ? strassenMultiply(result, matrices[i])
                             : regularMultiply(result, matrices[i]);
    }
    return result;
}

int main() {
    srand(time(0));
    int n = 10;
    vector<int> p(n+1);
   
    vector<int> possible = {8, 16, 32, 64};
    for (int i = 0; i < n+1; i++) {
        p[i] = possible[rand() % possible.size()];
    }
   
    cout << "Matrix dimensions array p: ";
    for (int i = 0; i < n+1; i++) {
        cout << p[i] << " ";
    }
    cout << "\n";

    vector<Matrix> matrices;
    for (int i = 1; i <= n; i++) {
        int rows = p[i-1];
        int cols = p[i];
        Matrix M = generateRandomMatrix(rows, cols);
        matrices.push_back(M);
    }
   
    vector<vector<long long>> m(n+1, vector<long long>(n+1, 0));
    vector<vector<int>> s(n+1, vector<int>(n+1, 0));
    matrixChainOrder(p, m, s);

    cout << "\nMatrix m (Optimal Multiplication Costs):\n";
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(j < i)
                cout << setw(8) << "0";
            else
                cout << setw(8) << m[i][j];
        }
        cout << "\n";
    }
   
    cout << "\nMatrix s (Optimal Splits):\n";
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(j <= i)
                cout << setw(4) << "0";
            else
                cout << setw(4) << s[i][j];
        }
        cout << "\n";
    }
   
    cout << "\nOptimal Parenthesization: ";
    printOptimalParens(s, 1, n);
    cout << "\n";


    auto start = chrono::high_resolution_clock::now();
    Matrix trivialRegular = multiplyChainTrivial(matrices, false);
    auto end = chrono::high_resolution_clock::now();
    auto durationTrivialRegular = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    start = chrono::high_resolution_clock::now();
    Matrix optimalRegular = multiplyChainOptimal(matrices, s, 1, n, false);
    end = chrono::high_resolution_clock::now();
    auto durationOptimalRegular = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    start = chrono::high_resolution_clock::now();
    Matrix trivialStrassen = multiplyChainTrivial(matrices, true);
    end = chrono::high_resolution_clock::now();
    auto durationTrivialStrassen = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    start = chrono::high_resolution_clock::now();
    Matrix optimalStrassen = multiplyChainOptimal(matrices, s, 1, n, true);
    end = chrono::high_resolution_clock::now();
    auto durationOptimalStrassen = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << "\nTiming Results (in milliseconds):\n";
    cout << "1. Trivial order + Regular Multiplication: " << durationTrivialRegular << " ms\n";
    cout << "2. Optimal order + Regular Multiplication: " << durationOptimalRegular << " ms\n";
    cout << "3. Trivial order + Strassen Multiplication: " << durationTrivialStrassen << " ms\n";
    cout << "4. Optimal order + Strassen Multiplication: " << durationOptimalStrassen << " ms\n";

    return 0;
}