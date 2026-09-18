class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        set<int> s;
        for(int n : arr)
        {
            mp[n]++;
        }
        for(auto it : mp)
        {
            int x = it.second;
            if(s.find(x)!=s.end())
            {
                return false;
            }
            s.insert(x);
        }
        return true;
    }
};