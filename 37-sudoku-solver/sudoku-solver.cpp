class Solution {
public:
    bool safe(vector<vector<char>>& board,int row,int col,int num){
        
        char ch=num+'0';
        for(int i=0;i<9;i++){
            if(board[row][i]==ch)return false;
            if(board[i][col]==ch)return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch)return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int num=1;num<=9;num++){
                        if(safe(board,i,j,num)){
                            board[i][j]=num+'0';

                            if(solve(board))return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};