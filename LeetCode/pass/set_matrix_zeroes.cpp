/*************************************************************************
  > File Name: set_matrix_zeroes.cpp
  > Author:Haoson 
  > Created Time: Mon 02 Mar 2015 11:00:25 AM PST
  > 解题思路:利用矩阵第一行第一列，记录矩阵每行每列是否存在0，同时利用两个布尔变量记录第一行第一列是否存在0值。 
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        bool row1_has_zero = false;
        bool col1_has_zero = false;
        size_t row_size = matrix.size();
        size_t col_size = matrix[0].size();
        for(size_t i=0;i<row_size;++i){
            if(matrix[i][0]==0){
                col1_has_zero = true;
                break;
            }
        }
        for(size_t i=0;i<col_size;++i){
            if(matrix[0][i]==0){
                row1_has_zero = true;
                break;
            }
        }
        for(size_t i=1;i<row_size;++i){
            for(size_t j=1;j<col_size;++j){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(size_t i=1;i<row_size;++i){
            if(matrix[i][0]==0)
                std::fill(matrix[i].begin(),matrix[i].end(),0);
        }
        for(size_t i=1;i<col_size;++i){
            if(matrix[0][i]==0)
                for(size_t j=0;j<row_size;++j)
                    matrix[j][i] = 0;
        }
        if(row1_has_zero)
            std::fill(matrix[0].begin(),matrix[0].end(),0);
        if(col1_has_zero)
            for(size_t i=0;i<row_size;++i)
                matrix[i][0] = 0;
    }
};
