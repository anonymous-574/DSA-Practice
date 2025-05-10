#include <bits/stdc++.h>
using namespace std;

const int GRID_SIZE = 4;
const int dirRow[4] = { -1, 0, 1, 0 };
const int dirCol[4] = { 0, 1, 0, -1 };

int countMisplacedTiles(const vector<vector<int>>& current, const vector<vector<int>>& goal) {
    int misplaced = 0;
    for (int row = 0; row < GRID_SIZE; ++row)
        for (int col = 0; col < GRID_SIZE; ++col)
            if (current[row][col] != 0 && current[row][col] != goal[row][col])
                misplaced++;
    return misplaced;
}

void printBoard(const vector<vector<int>>& board) {
    for (int row = 0; row < GRID_SIZE; ++row) {
        for (int col = 0; col < GRID_SIZE; ++col)
            cout << setw(2) << board[row][col] << ' ';
        cout << "\n";
    }
}

void solvePuzzle(const vector<vector<int>>& startBoard, const vector<vector<int>>& goalBoard) {
    vector<vector<int>> currentBoard = startBoard;
    vector<vector<int>> previousBoard = startBoard;

    int blankRowIdx = -1, blankColIdx = -1;
    for (int i = 0; i < GRID_SIZE; i++)
        for (int j = 0; j < GRID_SIZE; j++)
            if (currentBoard[i][j] == 0) {
                blankRowIdx = i;
                blankColIdx = j;
            }

    int costSoFar = 0;
    int heuristicValue = countMisplacedTiles(currentBoard, goalBoard);

    cout << "Level 0 (Start State):\n";
    cout << "Cost = " << costSoFar + heuristicValue << "  (g=" << costSoFar << ", h=" << heuristicValue << ")\n";
    printBoard(currentBoard);
    cout << "---------------------\n";

    int steps = 0;
    while (heuristicValue != 0) {
        struct Candidate {
            vector<vector<int>> board;
            int totalCost, heuristic, cost;
            int blankRow, blankCol;
        };

        vector<Candidate> candidates;

        for (int d = 0; d < 4; d++) {
            int newRow = blankRowIdx + dirRow[d];
            int newCol = blankColIdx + dirCol[d];
            if (newRow < 0 || newRow >= GRID_SIZE || newCol < 0 || newCol >= GRID_SIZE)
                continue;

            vector<vector<int>> newBoard = currentBoard;
            swap(newBoard[blankRowIdx][blankColIdx], newBoard[newRow][newCol]);
            if (newBoard == previousBoard)
                continue;

            int newHeuristic = countMisplacedTiles(newBoard, goalBoard);
            candidates.push_back({ newBoard, costSoFar + 1 + newHeuristic, newHeuristic, costSoFar + 1, newRow, newCol });
        }

        if (candidates.empty()) {
            cout << "No further moves possible. Stuck.\n";
            return;
        }

        auto best = *min_element(candidates.begin(), candidates.end(), [](auto& a, auto& b) {
            return tie(a.totalCost, a.heuristic) < tie(b.totalCost, b.heuristic);
        });

        previousBoard = currentBoard;
        currentBoard = best.board;
        blankRowIdx = best.blankRow;
        blankColIdx = best.blankCol;
        costSoFar = best.cost;
        heuristicValue = best.heuristic;
        steps++;

        cout << "Level " << steps << ":\n";
        cout << "Cost = " << best.totalCost << "  (g=" << costSoFar << ", h=" << heuristicValue << ")\n";
        printBoard(currentBoard);
        cout << "---------------------\n";
    }

    cout << "Reached goal in " << steps << " steps.\n";
}

int main() {
    vector<vector<int>> startBoard(GRID_SIZE, vector<int>(GRID_SIZE));
    vector<vector<int>> goalBoard(GRID_SIZE, vector<int>(GRID_SIZE));

    cout << "Enter initial 4x4 board (0 = blank):\n";
    for (int i = 0; i < GRID_SIZE; i++)
        for (int j = 0; j < GRID_SIZE; j++)
            cin >> startBoard[i][j];

    cout << "Enter goal 4x4 board (0 = blank):\n";
    for (int i = 0; i < GRID_SIZE; i++)
        for (int j = 0; j < GRID_SIZE; j++)
            cin >> goalBoard[i][j];

    solvePuzzle(startBoard, goalBoard);
    return 0;
}