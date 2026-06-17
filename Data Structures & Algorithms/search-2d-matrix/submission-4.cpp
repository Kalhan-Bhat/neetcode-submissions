class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int m=matrix.size();
            int n=matrix[0].size();
            // binary search for getting the exact row
            int l=0;
            int r=m-1;
            int mid;
            while(l<=r){
               mid=l +(r-l)/2;
                if(target>matrix[mid][n-1]){
                    l=mid+1;
                }
                else if(target<matrix[mid][0]){
                    r=mid-1;
                }
                else {
                    break;
                }
         }
            if(!(l<=r)){
                return false;
            }
            int row=mid;
            l=0;
            r=n-1;
            while(l<=r){
                int m= l+ (r-l)/2;
                if(target>matrix[row][m]){
                    l=m+1;
                }
                else if (target<matrix[row][m]){
                    r=m-1;
                }
                else{
                    return true;
                }
            }     

              

        return false;
    }
};
