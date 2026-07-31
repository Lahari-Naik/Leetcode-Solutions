class Solution {
public:
    int minimumPushes(string w) {
        int n = w.size();
        vector<int> freq(26,0);
        for(char c : w)
        {
            freq[c-'a']++;
        }
        sort(freq.begin(),freq.end(),[](int a,int b){
            return a>b;
        });
        int sum = 0;
        for(int i=0;i<26;i++)
        {
            if(freq[i]==0) break;
            int x = i/8+1;
            sum += freq[i]*x;
        }
        return sum;
    }
};