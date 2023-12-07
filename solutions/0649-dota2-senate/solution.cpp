class Solution {
public:
    string predictPartyVictory(string senate) {
          while(senate.size()>1){
            char first = senate[0];
            if(first=='R'){
                // find first D and remove it
                int i;
                for(i=0;i<senate.size();i++){
                    if(senate[i]=='D'){
                        break;
                    }
                }
                if(i==senate.size()){
                    return "Radiant";
                }
                senate.erase(i,1);
                senate = senate+'R';
                senate.erase(0,1);
            }
            else{
                // find the first R and remove it
  // find first R and remove it
                int i;
                for(i=0;i<senate.size();i++){
                    if(senate[i]=='R'){
                        break;
                    }
                }
                if(i==senate.size()){
                    return "Dire";
                }
                senate.erase(i,1);
                senate = senate+'D';
                senate.erase(0,1);
            }
        }
        if(senate[0]=='R'){
            return "Radiant";
        }
        else{
            return "Dire";
        }
    
    }
};
