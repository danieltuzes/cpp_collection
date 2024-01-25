#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <random>

using namespace std;


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (auto & line: board)
        {
            unordered_set<char> occ;
            for (auto val: line)
            {
                if (val != '.' && occ.count(val))
                    return false;
                occ.insert(val);
            }
        }

        for (int i=0; i<9; ++i)
        {
            unordered_set<char> occ;
            for (int j=0; j<9; ++j)
            {
                int val = board[j][i];
                if (val != '.' && occ.count(val))
                    return false;
                occ.insert(val);
            }
        }
        
        for (int i=0; i<3; ++i)
            for (int j=0; j<3; ++j)
            {
                unordered_set<char> occ;
                for (int k=0; k<3; ++k)
                    for (int l=0; l<3; ++l)
                        {
                            int val = board[i*3+k][j*3+l];
                            if (val != '.' && occ.count(val))
                                return false;
                            occ.insert(val);
                        }
            }

        return true;
    }
};


int main()
{
    Solution s;
    vector<vector<char>> sudoku = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    cout << s.isValidSudoku(sudoku);
    cout << "hi";
}