class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        int n = in.size();
        vector<vector<int>> ans;
        sort(in.begin(),in.end());
        ans.push_back(in[0]);
        for(int i=1;i<n;i++)
        {
            if(ans.back()[1]>=in[i][0])
            {
                ans.back()[0]=min(ans.back()[0],in[i][0]);
                ans.back()[1]=max(ans.back()[1],in[i][1]);
            }
            else
            {
                ans.push_back(in[i]);
            }
        }
        return ans;
    }
};