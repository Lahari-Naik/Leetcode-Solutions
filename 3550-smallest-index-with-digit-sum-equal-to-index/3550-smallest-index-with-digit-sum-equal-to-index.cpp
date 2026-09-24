class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int k = nums[i];
            int x = 0;
            while(k>0)
            {
                x+=k%10;
                k/=10;
            }
            if(i==x)
            {
                return i;
            }
        }
        return -1;
    }
};