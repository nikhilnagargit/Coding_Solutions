class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> hRanges;
        vector<vector<int>> vRanges;
        for(auto r:rectangles){
            vRanges.push_back({r[1],r[3]});
            hRanges.push_back({r[0],r[2]});
        }
        sort(vRanges.begin(),vRanges.end());
        sort(hRanges.begin(),hRanges.end());

        vector<vector<int>> vRangesMerged;
        vector<vector<int>> hRangesMerged;
        for(int i=1;i<vRanges.size();i++){
            int a = vRanges[i-1][0];
            int b = vRanges[i-1][1];
            int c = vRanges[i][0];
            int d = vRanges[i][1];
            if(c>=b){
                vRangesMerged.push_back({a,b});
                cout<<a<<','<<b<<endl;
                if(vRangesMerged.size()>=2){
                    return true;
                }
            }
            else{
                vRanges[i][0] = a; 
                vRanges[i][1] = max(b,d);
            }
        }
        for(int i=1;i<hRanges.size();i++){
            int a = hRanges[i-1][0];
            int b = hRanges[i-1][1];
            int c = hRanges[i][0];
            int d = hRanges[i][1];
            if(c>=b){
                hRangesMerged.push_back({a,b});
                cout<<a<<','<<b<<endl;
                if(hRangesMerged.size()>=2){
                    return true;
                }
            }
            else{
                hRanges[i][0] = a; 
                hRanges[i][1] = max(b,d);
            }
        }

        return false;

    }
};
