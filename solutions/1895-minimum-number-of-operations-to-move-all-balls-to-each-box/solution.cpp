class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> leftpass(boxes.size(),0);
        vector<int> rightpass(boxes.size(),0);
        vector<int> ans(boxes.size(),0);
        int gap = 0;
        for(int i=0;i<boxes.size();i++){
            if(i==0){
                rightpass[i] = gap;
            }
            else{
                rightpass[i]= rightpass[i-1]+gap;
            }
            if(boxes[i]=='1'){
                gap++;
            }
         
        }
   

        gap = 0;
        for(int i=boxes.size()-1;i>=0;i--){
            if(i==boxes.size()-1){
                leftpass[i] = gap;
            }
            else{
                leftpass[i]= leftpass[i+1]+gap;
            }
            if(boxes[i]=='1'){
                gap++;
            }
        }
        

        for(int i=0;i<boxes.size();i++){
            ans[i] = leftpass[i]+rightpass[i];
        }
        return ans;
    }
};
