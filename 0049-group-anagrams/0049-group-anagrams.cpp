class Solution {
public:
    void match(string s, vector<vector<string>>& ans)
    {
        int n = ans.size();
        vector<int> freq1(26,0);
        for(char c:s)
        {
            freq1[c-'a']++;
        }
        int flag = 0;
        for(int i=0;i<n;i++)
        {
            if(s.length()!=ans[i][0].length())
            {
                continue;
            }
            vector<int> freq2(26,0);
            for(char c : ans[i][0])
            {
                freq2[c-'a']++;
            }
            if(freq1==freq2)
            {
                ans[i].push_back(s);
                flag = 1;
                break;
            }
        }
        if(flag==0) ans.push_back({s});
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if(strs.size()==0) return {{""}};
        if(strs.size()==1) return {strs};
        int n = strs.size();
        ans.push_back({strs[0]});
        for(int i=1;i<n;i++)
        {
            match(strs[i],ans);
        }
        return ans;
    }
};