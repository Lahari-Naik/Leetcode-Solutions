class Solution {
public:
    int maxi(vector<vector<int>>& mat, int c)
    {
        int n = mat.size();
        int sum = INT_MIN;
        int index = -1;
        for(int i=0;i<n;i++)
        {
            if(sum<mat[i][c])
            {
                sum = mat[i][c];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat[0].size();
        int l = 0;
        int h = n-1;
        while(l<=h)
        {
            int c = l+(h-l)/2;
            int r = maxi(mat,c);
            int left = c-1;
            int right = c+1;
            if(c-1>=0)
            {
                left = mat[r][c-1];
            }
            else
            {
                INT_MIN;
            }
            if(c+1<n)
            {
                right = mat[r][c+1];
            }
            else
            {
                INT_MIN;
            }
            if (mat[r][c] > left && mat[r][c] > right) 
            {
                  return {r, c};
            } 
            else if (left > mat[r][c]) 
            {
                  h = c - 1;
            } 
            else 
            {
                  l = c + 1;
            }
        }
        return {-1,-1};
    }
};