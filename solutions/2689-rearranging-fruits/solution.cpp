class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int mini = INT_MAX;
        for(auto& i:basket1){
            mini = min(mini,i);
        }
        for(auto& i:basket2){
            mini = min(mini,i);
        }

        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        for(auto& i:basket1){
            m1[i]++;
        }
        for(auto& i:basket2){
            m2[i]++;
        }

        // check if basket 1 and basket 2 can be equal or not
        for(auto item:m1){
            int total = item.second;
            if(m2.find(item.first)!=m2.end()){
                total+= m2[item.first];
            }
            if(total%2!=0){
                return -1;
            }
        }
        for(auto item:m2){
            int total = item.second;
            if(m1.find(item.first)!=m1.end()){
                total+= m1[item.first];
            }
            if(total%2!=0){
                return -1;
            }
        }

        // subtract the counts of m2 from m1
        for(auto item:m1){
            int key = item.first;
            int m1count = item.second;
            int m2count = 0;
            if(m2.find(item.first)!=m2.end()){
                m2count = m2[item.first];
            }
            if(m2count>=m1count){
                m1[key] = 0;
                m2[key] = m2count-m1count; 
            }
            else{
                m1[key] = m1count-m2count;
                m2[key] = 0;
            }
        }

        // subtract the counts of m1 from m2
        for(auto item:m2){
            int key = item.first;
            int m2count = item.second;
            int m1count = 0;
            if(m1.find(item.first)!=m1.end()){
                m1count = m1[item.first];
            }
            if(m1count>=m2count){
                m2[key]=0;
                m1[key] = m1count-m2count; 
            }
            else{
                m2[key] = m2count-m1count;
                if(m1.find(key)!=m1.end())
                m1[key]=0;
            }
        }


        vector<int> first;
        vector<int> second;
        for(auto i:m1){
            if(i.second!=0){
                int count = i.second/2;
                while(count--){
                    first.push_back(i.first);
                }
            }
        }
        for(auto i:m2){
            if(i.second!=0){
                int count = i.second/2;
                while(count--){
                    second.push_back(i.first);
                }
            }
        }
        sort(first.begin(),first.end());
        sort(second.begin(),second.end());

        long long sum = 0;

        for(int i=0;i<first.size();i++){
            sum += min(mini*2,min(first[i],second[second.size()-1-i]));
        }
        return sum;

    }
};
