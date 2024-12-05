class Solution {
public:
    bool canChange(string start, string target) {
        //order check
        string startorder = "";
        string targetorder = "";
        for(int i=0;i<start.size();i++){
            if(start[i]!='_'){
                startorder+= start[i];
            }
            if(target[i]!='_'){
                targetorder+=target[i];
            }
        }
        // cout<<startorder<<","<<targetorder<<endl;
        if(startorder!=targetorder)return false;

        //left check
        int target_count = 0;
        int start_count = 0;
        for(int i=0;i<start.size();i++){
            if(start[i]=='L'){
                start_count++;
            }
            if(target[i]=='L'){
                target_count++;
            }
            if(start_count>target_count){
                return false;
            }
        }

        //right check
        target_count = 0;
        start_count = 0;

        for(int i=start.size()-1;i>=0;i--){
            if(start[i]=='R'){
                start_count++;
            }
            if(target[i]=='R'){
                target_count++;
            }
            if(start_count>target_count){
                return false;
            }
        }

        return true;
    }
};
