class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
            int top=1;
            int index=0;
            vector<string>ans;

            //  loop for every value in target
            while(index<target.size()){
                //  push the current value of top in stack
                ans.push_back("Push");
                if(top==target[index]){
                    // no need to pop
                    index++;
                }
                else{
                // need to pop top value, this can't stay in stack
                    ans.push_back("Pop");
                   
                }
                top++;
            }
            return ans;
        }

    
};
