class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int mod = 1000000007;
        unordered_set<int> widths;
        unordered_set<int> heights;
        hFences.push_back(m);
        hFences.push_back(1);
        vFences.push_back(n);
        vFences.push_back(1);

        for(int i=0;i<hFences.size();i++){
            for(int j=i+1;j<hFences.size();j++){
                heights.insert(abs(hFences[i]-hFences[j]));
            }
        }

        for(int i=0;i<vFences.size();i++){
            for(int j=i+1;j<vFences.size();j++){
                widths.insert(abs(vFences[i]-vFences[j]));
            }
        }
        heights.erase(0);
        widths.erase(0);

        vector<int>vw(widths.begin(),widths.end());
        vector<int>vh(heights.begin(),heights.end());
        sort(vw.begin(),vw.end(),greater<int>());
        sort(vh.begin(),vh.end(),greater<int>());
        int i=0;
        int j=0;
        // for(auto i:vw){
        //     cout<<i<<",";
        // }
        // cout<<endl;
        // for(auto j:vh){
        //     cout<<j<<",";
        // }
        // cout<<endl<<endl;
        while(i<vw.size() and j<vh.size()){
            if(vw[i]==vh[j]){
                long long a = vw[i];
                long long b = vh[j];
                return ((a%mod)*(b%mod))%mod;
            }
            else if(vw[i]>vh[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return -1;
    }
};
