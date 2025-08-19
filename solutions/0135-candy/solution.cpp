class Solution {
public:
    int candy(vector<int>& ratings) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;
        int i=0;
        for(auto&r:ratings){
            min_heap.push({r,i});
            i++;
        }
        vector<int> v(ratings.size(),0);
        int sum = 0;
        while(!min_heap.empty()){
            pair<int,int> p = min_heap.top();min_heap.pop();
            int i= p.second;
            int leftr = INT_MAX;
            int rightr = INT_MAX;
            int leftv = 0;
            int rightv = 0;
            int currr = ratings[i];
            if(i-1>=0){
                leftr = ratings[i-1];
                leftv = v[i-1];
            }
            if(i+1<ratings.size()){
                rightr = ratings[i+1];
                rightv = v[i+1];
            }
            //higher point
            if(currr>leftr and currr>rightr){
                v[i] = max(1+leftv,1+rightv);
            }
            else if(currr<leftr and currr<rightr){
                 v[i]=1;
            }
            else if(currr>leftr){
                 v[i]=leftv+1;
            }
            else if(currr>rightr){
                v[i]=rightv+1;
            }
            else {
                v[i]=1;
            }
            sum+= v[i];
        }
        return sum;
    }
};
