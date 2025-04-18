//David Daniels
//2023300038


#include <bits/stdc++.h>
using namespace std;

const int PUZZLE_SIZE = 4;
const int GRID_SIZE = PUZZLE_SIZE * PUZZLE_SIZE;

int calculateManhattanDistance(const vector<int>& state, const vector<int>& goal) {
    int distance = 0;
    for (int i = 0; i < GRID_SIZE; ++i) {
        if (state[i] != 0) {
            int goalIndex = -1;
            for (int j = 0; j < GRID_SIZE; ++j) {
                if (goal[j] == state[i]) {
                    goalIndex = j;
                    break;
                }
            }

            if (goalIndex != -1) {
                int stateRow = i / PUZZLE_SIZE;
                int stateCol = i % PUZZLE_SIZE;
                int goalRow = goalIndex / PUZZLE_SIZE;
                int goalCol = goalIndex % PUZZLE_SIZE;
                distance += abs(stateRow - goalRow) + abs(stateCol - goalCol);
            }
        }
    }
    return distance;
}

void printPuzzleState(const vector<int>& state) {
    for (int i = 0; i < GRID_SIZE; ++i) {
        if (state[i] == 0) {
            cout << setw(4) << " ";
        } else {
            cout << setw(4) << state[i];
        }
        if ((i + 1) % PUZZLE_SIZE == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

vector<pair<vector<int>, string>> generateNextStates(const vector<int>& state) {
    vector<pair<vector<int>, string>> nextStates;
    int blankIndex = -1;
    for (int i = 0; i < GRID_SIZE; ++i) {
        if (state[i] == 0) {
            blankIndex = i;
            break;
        }
    }

    int blankRow = blankIndex / PUZZLE_SIZE;
    int blankCol = blankIndex % PUZZLE_SIZE;

    int possibleMoves[4][2] = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };
    string moveNames[4] = {"Up", "Down", "Left", "Right"};

    for (int i = 0; i < 4; ++i) {
        int newRow = blankRow + possibleMoves[i][0];
        int newCol = blankCol + possibleMoves[i][1];

        if (newRow >= 0 && newRow < PUZZLE_SIZE && newCol >= 0 && newCol < PUZZLE_SIZE) {
            int newIndex = newRow * PUZZLE_SIZE + newCol;
            vector<int> newState = state;
            swap(newState[blankIndex], newState[newIndex]);
            nextStates.push_back({newState, moveNames[i]});
        }
    }
    return nextStates;
}

struct Node {
    vector<int> state;
    int g;
    int h;
    int f;
    string move;
    int level;
    vector<string> path;

    Node(const vector<int>& s, int g_val, int h_val, const string& m, int lvl, const vector<string>& p)
        : state(s), g(g_val), h(h_val), f(g + h), move(m), level(lvl), path(p) {}

    bool operator>(const Node& other) const {
        return f > other.f;
    }
};

void solve15Puzzle(const vector<int>& startState, const vector<int>& goalState) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    map<vector<int>, vector<string>> visitedStates;

    int initialHeuristic = calculateManhattanDistance(startState, goalState);
    Node initialNode(startState, 0, initialHeuristic, "Start", 0, {});
    pq.push(initialNode);
    visitedStates[startState] = {};

    int nodesExplored = 0;
    int maxQueueSize = 0;

    while (!pq.empty()) {
        Node currentNode = pq.top();
        pq.pop();
        nodesExplored++;

        if (pq.size() > maxQueueSize) {
            maxQueueSize = pq.size();
        }

        cout << "Level: " << currentNode.level << ", Move: " << currentNode.move << ", f = " << currentNode.f << ", g = " << currentNode.g << ", h = " << currentNode.h << endl;
        printPuzzleState(currentNode.state);

        if (currentNode.state == goalState) {
            cout << "Goal state found" << endl;
            cout << "Total nodes explored: " << nodesExplored << endl;
            cout << "Maximum queue size: " << maxQueueSize << endl;
            cout << "Path: ";
            for (const string& move : currentNode.path) {
                cout << move << " -> ";
            }
            cout << "Goal" << endl;
            return;
        }

        vector<pair<vector<int>, string>> nextStates = generateNextStates(currentNode.state);
        for (const auto& nextStatePair : nextStates) {
            const vector<int>& nextState = nextStatePair.first;
            const string& moveName = nextStatePair.second;

            if (visitedStates.find(nextState) == visitedStates.end()) {
                vector<string> newPath = currentNode.path;
                newPath.push_back(moveName);
                int newG = currentNode.g + 1;
                int newH = calculateManhattanDistance(nextState, goalState);
                Node nextNode(nextState, newG, newH, moveName, currentNode.level + 1, newPath);
                pq.push(nextNode);
                visitedStates[nextState] = newPath;
            }
        }
    }

    cout << "No solution found." << endl;
    cout << "Total nodes explored: " << nodesExplored << endl;
    cout << "Maximum queue size: " << maxQueueSize << endl;
}

int main() {

    //good example
    //vector<int> startState = {
    //    5, 1, 2, 3,
    //    9, 6, 7, 4,
    //    13, 10, 11, 8,
    //    14, 15, 0, 12
    //};

    vector<int> startState(GRID_SIZE);
    cout << "Enter the initial state of the 15-puzzle (enter 0 for the blank tile):" << endl;
    for (int i = 0; i < GRID_SIZE; ++i) {
        cout << "Tile " << i + 1 << ": ";
        cin >> startState[i];
    }

    vector<int> goalState = {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12,
        13, 14, 15, 0
    };

    cout << "Solving 15-Puzzle with Branch and Bound:" << endl;
    cout << "Initial State:" << endl;
    printPuzzleState(startState);
    cout << "Goal State:" << endl;
    printPuzzleState(goalState);

    solve15Puzzle(startState, goalState);

    return 0;
}
