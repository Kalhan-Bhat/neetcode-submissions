class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> mpp;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){continue;}
                string row=string(1,board[i][j]) + "row" + to_string(i);
                string col=string(1,board[i][j]) + "col" + to_string(j);
                string box=string(1,board[i][j]) + "box" + to_string(i/3) + "_" + to_string(j/3);

                if(mpp.find(row)!=mpp.end() || mpp.find(col)!=mpp.end() || mpp.find(box)!=mpp.end()){
                    return false;
                }

                mpp.insert(row);
                mpp.insert(col);
                mpp.insert(box);
            }
        }

        return true;
    }
};