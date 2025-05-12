#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 4;

vector<vector<int>> goal = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 0}
};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

struct State {
    vector<vector<int>> mat;
    int x, y; // Position of blank tile
    int costFromStart; // g(n)
    int estimatedTotalCost; // f(n) = g(n) + h(n)

    bool operator>(const State& other) const {
        return estimatedTotalCost > other.estimatedTotalCost;
    }
};

void printPuzzle(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int val : row)
            cout << val << "\t";
        cout << "\n";
    }
}

bool isSafe(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

// Heuristic: number of misplaced tiles
int countMisplacedTiles(const vector<vector<int>>& mat) {
    int cost = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (mat[i][j] != 0 && mat[i][j] != goal[i][j])
                cost++;
    return cost;
}

State getInitialState() {
    vector<vector<int>> start(N, vector<int>(N));
    int startX = -1, startY = -1;

    cout << "Enter the 4x4 puzzle (use 0 for blank tile):\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> start[i][j];
            if (start[i][j] == 0) {
                startX = i;
                startY = j;
            }
        }
    }

    State init;
    init.mat = start;
    init.x = startX;
    init.y = startY;
    init.costFromStart = 0;
    init.estimatedTotalCost = countMisplacedTiles(start);
    return init;
}

void solvePuzzle(const State& initialState) {
    priority_queue<State, vector<State>, greater<State>> openSet;
    openSet.push(initialState);

    while (!openSet.empty()) {
        State current = openSet.top();
        openSet.pop();

        if (countMisplacedTiles(current.mat) == 0) {
            cout << "\nSolved Puzzle:\n";
            printPuzzle(current.mat);
            cout << "Total steps: " << current.costFromStart << "\n";
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (isSafe(newX, newY)) {
                State nextState = current;
                swap(nextState.mat[current.x][current.y], nextState.mat[newX][newY]);
                nextState.x = newX;
                nextState.y = newY;
                nextState.costFromStart = current.costFromStart ++;
                nextState.estimatedTotalCost = nextState.costFromStart + countMisplacedTiles(nextState.mat);
                openSet.push(nextState);
            }
        }
    }

    cout << "No solution found.\n";
}

int main() {
    State initialState = getInitialState();
    solvePuzzle(initialState);
    return 0;
}
