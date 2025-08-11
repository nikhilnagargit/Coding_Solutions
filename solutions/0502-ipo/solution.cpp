class Cmp{
    public:
    bool operator()(pair<int,int>& a,pair<int,int>&b)const{
        if(a.first > b.first)
        return true;
        if(a.first==b.first){
            return a.second<b.second;
        }
        return false;
    }
};
class Cmp2{
    public:
    bool operator()(pair<int,int>& a,pair<int,int>&b)const{
        return a.second < b.second;
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,Cmp> min_heap;
        for(int i=0;i<profits.size();i++){
            min_heap.push({capital[i],profits[i]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,Cmp2> max_heap;
        while((!min_heap.empty() or !max_heap.empty()) and k>0){
            while(!min_heap.empty() and min_heap.top().first<=w){
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
            if(max_heap.empty()) break;
            //select one with max profit from max heap
            w+= max_heap.top().second;
            max_heap.pop();
            k--;
        }
        return w;
    }
};
