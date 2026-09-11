class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> s;
        for(int i=0;i<n;i++)
        {
            if(digits[i]!=0)
            {
                for(int j=0;j<n;j++)
                {
                    for(int k=0;k<n;k++)
                    {
                        if(i!=j && j!=k && i!=k && digits[k]%2==0)
                        {
                            s.insert(digits[i]*100+digits[j]*10+digits[k]);
                        }
                    }
                }
            }
        }
        return s.size();
    }
};