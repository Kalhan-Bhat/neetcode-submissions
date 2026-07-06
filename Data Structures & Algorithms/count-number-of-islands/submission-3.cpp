class Solution {
public:
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,1,-1};
    void dfs(vector<vector<int>>& vis, vector<vector<char>>& grid , int row,int col){
        int m=grid.size();
        int n=grid[0].size(); 
        
        if(row < 0 || row >= m || col < 0 || col >= n){return;}
  

        for(int i=0;i<4;i++){

            int nrow=row+dr[i];
            int ncol=col+dc[i];

            if(nrow<m && nrow>=0 && ncol <n && ncol>=0 && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                vis[nrow][ncol]=1;
                dfs(vis,grid,nrow,ncol);
            }
        }



    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<int>> vis(m, vector<int> (n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(vis[i][j]!=1 && grid[i][j]=='1'){
                    vis[i][j]=1;
                    dfs(vis,grid,i,j);
                    count++;
                }
            }
        }

        return count;
    }
};
