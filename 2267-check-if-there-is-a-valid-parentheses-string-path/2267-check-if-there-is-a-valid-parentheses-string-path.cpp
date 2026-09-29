class Solution {
    int t[101][101][201];
    bool solve(vector<vector<char>>& grid,int i,int j,int m,int n,int oc){
        if(i<0 || j<0 || i>=m || j>=n){
            return false;
        }
        oc+=(grid[i][j]=='('?1:-1);
        if(oc<0){
            return false;
        }
        if(t[i][j][oc]!=-1){
            return t[i][j][oc];
        }
        if(i == m-1 && j == n-1){
            return t[i][j][oc]=(oc==0);
        }
        if(solve(grid,i+1,j,m,n,oc)){
            return t[i][j][oc]=true;
        }
        if(solve(grid,i,j+1,m,n,oc)){
            return t[i][j][oc]=true;
        }
        return t[i][j][oc]=false;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        memset(t,-1,sizeof(t));
        if((m+n-1)%2==1){
            return false;
        }
        return solve(grid,0,0,m,n,0);
    }
};