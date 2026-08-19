class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& r) {
        unordered_map<int, vector<int>> v;
        for (auto x : r) {
            v[x[0]].push_back(x[1]);
        }
        int ans = 2 * n;
        for (auto row : v) {
            bool left = true, middle = true, right = true;

            for (int seat : row.second) {
                if (seat >= 2 && seat <= 5)
                    left = false;

                if (seat >= 4 && seat <= 7)
                    middle = false;

                if (seat >= 6 && seat <= 9)
                    right = false;
            }
            if (left && right)
                continue;       
            if (left || middle || right)
                ans--;           

            else
                ans -= 2;        
        }
        return ans;
    }
};