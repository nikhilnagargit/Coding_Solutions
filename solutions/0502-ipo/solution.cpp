class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> v;
        
        for(int i=0;i<profits.size();i++){
            v.push_back({capital[i],profits[i]});
        }

        sort(v.begin(),v.end());

        int mycapital  = w;
        int count = 0;
        priority_queue<int> pq;
        int i=0;
        while(i<v.size()){
            if(v[i].first<=mycapital){
                cout<<"pushing"<<v[i].second<<" ";
                pq.push(v[i].second);
                i++;
                continue;
            }
            if(!pq.empty()){
                mycapital += pq.top();pq.pop();
                count++;
                if(count==k){
                    return mycapital;
                }
            }
                   else{
                return mycapital;
            }
        }

         while(true){
             if(!pq.empty()){
                mycapital += pq.top();pq.pop();
                count++;
                if(count==k){
                    return mycapital;
                }
             }
            else{
                return mycapital;
            }
         }
        return mycapital;
    }
};
