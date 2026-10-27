class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> s;
        string k = "";
        for(int j=0;j<n;j++)
        {
            k+='.';
        }
        s.push_back(k);
        for(int i=1;i<m;i++)
        {
            k = "";
            for(int j=0;j<n-1;j++)
            {
                k+='#';
            }
            k+='.';
            s.push_back(k);
        }
        return s;
    }
};