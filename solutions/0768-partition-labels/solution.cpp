class Solution {
public:
    vector<int> partitionLabels(string s) {
        int count = 0;
        int globallastidx = 0;
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            count++;
            char curr = s[i];
            //find last indx of curr
            int lastidx = i;
            for(int j=i+1;j<s.size();j++){
                if(s[j]==curr) lastidx=j;
            }
            globallastidx = max(globallastidx,lastidx);
            if(i==globallastidx){
                //partitiaion
                ans.push_back(count);
                count = 0;
            }
        }
        return ans;
    }
};
