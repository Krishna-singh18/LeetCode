class Solution {
public:
    bool safe(vector<vector<char>>& board,int row,int col,char ch){
        for(int i=0;i<9;i++){
            if((i!=col) && board[row][i]==ch)return false;
            if((i!=row) && board[i][col]==ch)return false;
            int r=3*(row/3)+i/3;
            int c=3*(col/3)+i%3;
            if( (r!=row || c!=col) && board[r][c]==ch)return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col]=='.')continue;

                char ch=board[row][col];
                if(!safe(board,row,col,ch))return false;
                 
            }
        }
        return true;
    }
};