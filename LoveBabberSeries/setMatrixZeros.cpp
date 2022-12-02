//Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's. You must do it in place.

// this solution will work if the array elements are all positives.
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        for(int i =0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                if(matrix[i][j] == 0 ){
                    for(int row = 0;row<matrix.size();row++){
                        if(matrix[row][j] != 0){
                            matrix[row][j] = INT_MAX;
                        }
                    }
                    for(int clm = 0;clm<matrix[0].size();clm++){
                        if(matrix[i][clm] != 0){
                            matrix[i][clm] = INT_MAX;
                        }
                    }
                    
                }
            }
        }
        for(int i = 0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size(); j++){
                if(matrix[i][j] == INT_MAX){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

//this solution works for positives as well as negative matrix values.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        vector<int> ro(rows, -1);
        vector<int> co(columns, -1);
        for(int i =0;i<rows;i++){
            for(int j = 0;j<columns;j++){
                if(matrix[i][j] == 0){
                    ro[i] = 0;
                    co[j] = 0;
                }
            }
        }
        for(int i =0;i<rows;i++){
            for(int j = 0;j< columns;j++){
                if(ro[i] == 0 || co[j] == 0){
                    matrix[i][j] = 0 ;
                }
            }
        }
    }
};



/* Note: As this is a 2D array for the time complexity we will at least need to traverse the entire array. which is
O(M * N) complexity
*/

