/*************************************************************************
  > File Name: word_search.cpp
  > Author:Haoson 
  > Created Time: Tue 10 Mar 2015 07:32:22 PM PDT
  > 解题思路:dfs 
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(word.empty()||board.empty()||board[0].empty())return false;
        size_t row = board.size();
        size_t col = board[0].size();
        string str_tmp = word;
        vector<vector<bool> >is_visited(row,vector<bool>(col,false));
        for(size_t i=0;i<row;++i){
            for(size_t j=0;j<col;++j){
                if(board[i][j]==word[0]){
                    if(dfs(board,str_tmp,i,j,is_visited))return true;
                    std::fill(is_visited.begin(),is_visited.end(),vector<bool>(col,false));
                }
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char> > &board,string &word,size_t start_row,size_t start_col,vector<vector<bool> >& is_visited){
        if(word.size()==1){
            return word[0]==board[start_row][start_col];
        }else{
            is_visited[start_row][start_col] = true;
            bool res = false;
            if(word[0]!=board[start_row][start_col])
                return false;
            int row_index[] = {1,-1,0,0};//对应下上右左
            int col_index[] = {0,0,1,-1};
            for(size_t i=0;i<4;++i){
                int new_row = static_cast<int>(start_row)+row_index[i];
                int new_col = static_cast<int>(start_col)+col_index[i];
                if(isValid(static_cast<int>(board.size()),static_cast<int>(board[0].size()),new_row,new_col)&&
                        !is_visited[static_cast<size_t>(new_row)][static_cast<size_t>(new_col)]){
                    char c = word[0];
                    word.erase(word.begin());
                    if(!(res = res||dfs(board,word,static_cast<size_t>(new_row),static_cast<size_t>(new_col),is_visited))){
                        is_visited[static_cast<size_t>(new_row)][static_cast<size_t>(new_col)] = false;
                    }                  
                    word.insert(word.begin(),c);
                }
            } 
            return res;
        }
    }
    bool isValid(int board_row,int board_col,int row,int col){
        return  row>=0&&col>=0&&row<board_row&&col<board_col; 
    }
};

int main(int argc,char* argv[]){
    Solution s;
    vector<vector<char> >board = {{'C','A','A'},{'A','A','A'},{'B','C','D'}};
    cout<<(s.exist(board,"AAB")?"true":"false")<<endl;
    return 0;
}
