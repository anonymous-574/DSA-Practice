#include <vector>
#include <iostream>
#include <bits/stdc++.h> 
#include <queue>
using namespace std;

class Solution {
public:

    int check_neighbour(vector<vector<int>>& board , int x , int y)
    {
        int neigbour_cnt=0;
        int tx=x;
        int ty=y;

        if (board[tx-1][ty-1])
        {
            /* code */
        }
        
    }


    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> copy=board;

        for (int i = 0; i < board.size(); i++)
        {
            for (int i = 0; i < board[i].size(); i++)
            {
                /* code */
            }
            
        }
        
    }
};