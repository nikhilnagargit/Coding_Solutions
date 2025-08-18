class Solution {
public:
    bool dfs(vector<double>& nums){
        if(nums.size()==1){
            if(abs(nums[0]-24.0) <= 1e-6){
                return true;
            }
            return false;
        }
        //pick two numbers and try all operations
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i==j) continue;
                //tow numbers 
                double a = nums[i];
                double b = nums[j];
                //try all operations and push the result back and continue
                //make new vector
                vector<double> newnums;
                for(int k=0;k<nums.size();k++){
                    if(k==i or k==j)continue;
                    newnums.push_back(nums[k]);
                }
                //took two numbers make result and push it back in new nums and see how it goes
                double c =0;

                c= a*b;
                newnums.push_back(c);
                if(dfs(newnums)) return true;
                newnums.pop_back();

                c = a-b;
                newnums.push_back(c);
                if(dfs(newnums)) return true;
                newnums.pop_back();

                c = a+b;
                newnums.push_back(c);
                if(dfs(newnums)) return true;
                newnums.pop_back();

                c = a/b;
                newnums.push_back(c);
                if(dfs(newnums)) return true;
                newnums.pop_back();

            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for(auto& c:cards){
            nums.push_back((double)c);
        }
        return dfs(nums);
    }
};
