class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>m;
        for(auto c: s){
            m[c]++;
        }
        priority_queue<pair<int,char>>heap;
        for(auto item:m){
            heap.push({item.second,item.first});
        }
        string ans  = "";
        while(!heap.empty()){
            int count = heap.top().first;
            int ch = heap.top().second;
            heap.pop();
            for(int i=0;i<count;i++){
                ans+= ch;
            }
        }
        return ans;
    }
};
