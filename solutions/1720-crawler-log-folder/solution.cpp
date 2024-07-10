class Solution {
public:
    int minOperations(vector<string>& logs) {
        int level = 0;
        for(string& command:logs){
            if(command=="../"){
                if(level>0)
                level--;
            }
            else if(command=="./"){
            }
            else{
                level++;
            }
        }
        return level;
    }
};
