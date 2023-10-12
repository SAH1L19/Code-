class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start =0;
        int rows = matrix.size();
        int cols = matrix[0].size() ;
    int end =(rows*cols)-1;
    int mid = start  + (end-start)/2;
    while(start<=end){
         // c*i + j
        int rowindex = mid/cols;
        int colindex = mid%cols; 
           if(matrix[rowindex][colindex]==target){
               return true ;
           }
           if(matrix[rowindex][colindex]>target){
               //search left 
               end= mid -1 ;
           }
           else 
           {   start = mid + 1; 
           }
           
           mid = start + (end - start)/2;
        
    }
     return false ;
 }
};
