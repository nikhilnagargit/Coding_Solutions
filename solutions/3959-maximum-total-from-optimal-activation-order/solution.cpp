#include <queue>
#include <vector>
using namespace std;

class Solution {
    // Comparator: lower limit ⇒ higher priority; if limits equal, higher value ⇒ higher priority
    struct Cmp {
        bool operator()(const pair<int,int>& a,
                        const pair<int,int>& b) const {
            // first compare limits (a.first, b.first)
            if (a.first != b.first)
                return a.first > b.first;      // smaller limit = higher priority
            // if limits tie, compare values
            return a.second < b.second;        // larger value = higher priority
        }
    };

public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        long long score = 0;
        // pair<limit, value>
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       Cmp> heap;
        priority_queue<int,vector<int>,greater<int>> activatedlimitheap;
        // build heap
        for (int i = 0; i < (int)value.size(); ++i) {
            heap.push({limit[i], value[i]});
            // cout<<"{"<<limit[i]<<","<<value[i]<<"}, ";
        }
        cout<<endl;
        // cout<<"--------------"<<endl;
        while (!heap.empty()) {
            auto [lim, val] = heap.top(); 
            // cout<<"{"<<lim<<","<<val<<"}"<<endl;
        
            // if we’ve reached the limit threshold, stop
            if (activatedlimitheap.size() >= lim)
                break;
            
            // activate this one
            heap.pop();
            activatedlimitheap.push(lim);
            score += val;
            // cout<<"score: "<<score<<endl;
            
            // clean out any who we can never activate
            int x = activatedlimitheap.size();
            // cout<<"x: "<<x<<endl;
            
            while (!heap.empty() && x >= heap.top().first) {
                  // cout<<"poped:"<<heap.top().second<<endl;
                heap.pop();
            }
            
            // clean out or reduce which are active and will get deactivated
            while(!activatedlimitheap.empty() and activatedlimitheap.top()<=x){
                  // cout<<"limitpoped:"<<activatedlimitheap.top()<<endl;
                
                activatedlimitheap.pop();
            }
            // cout<<"----"<<endl;
        }

        return score;
    }
};
