class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26,-1);
        vector<int> last(26,-1);
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            int c = s[i]-'a';
            if(first[c]==-1)
            {
                first[c] = i;
            }
            last[c] = i; 
        }
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            int c = s[i]-'a';
            if(first[c]!=i) continue;
            int l = first[c];
            int r = last[c];
            bool valid = true;
            for(int j=l;j<=r;j++)
            {
                int k = s[j]-'a';
                if(first[k]<l)
                {
                    valid = false;
                    break;
                }
                r = max(r,last[k]);
            }
            if(valid)
            {
                v.push_back({l,r});
            }
        }
        sort(v.begin(),v.end(),[](pair<int,int> a, pair<int,int> b)
        {
            return a.second < b.second;
        });
        vector<string> ans;
        int end = -1;
        for(auto it : v)
        {
            if(it.first>end)
            {
                ans.push_back(s.substr(it.first,it.second-it.first+1));
                end = it.second;
            }
        }
        return ans;
    }
};