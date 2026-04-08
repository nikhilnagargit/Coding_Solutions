
class CustomCompare {
    public:
    bool operator()(pair<int,string> a, pair<int,string> b) {

        if(a.first!=b.first){
            return a.first < b.first;
        }
        return a.second >= b.second;

    }
};

class Solution{
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // convert to map
        unordered_map<string,int> m;
        for (auto w:words){
            m[w]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>, CustomCompare> minheap;

        for (auto item:m){
            minheap.push({m[item.first],item.first});
        }

        vector<string> ans;
        int i=0;
        while(!minheap.empty() and i<k){
            auto t = minheap.top();
            minheap.pop();
            ans.push_back(t.second);
            i++;
        }
        return ans;
    }
};
