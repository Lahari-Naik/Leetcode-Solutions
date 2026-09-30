class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int o=0;
        vector<int> ans;
        int n=seq.size();
        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                o++;
                if(o&1){
                    ans.push_back(0);
                }else{
                    ans.push_back(1);
                }
            }else{
                o--;
                if(o%2==0){
                    ans.push_back(0);
                }else{
                    ans.push_back(1);
                }
            }
        }
        return ans;
    }
};