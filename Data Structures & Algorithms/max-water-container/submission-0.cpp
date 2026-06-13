class Solution {
public:

    int maxArea(vector<int>& height) {
        int maxi=INT_MIN;
        int i=0;
        int n=height.size();
        int j=n-1;
        while(i<j){
            int b=j-i;
            int l=min(height[i],height[j]);
            int area=l*b;
            maxi=max(maxi,area);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }

        return maxi;                
    }
};