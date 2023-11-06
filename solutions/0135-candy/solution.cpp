class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> values(ratings.size(),1);

        // a>b
        for(int i=ratings.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                values[i]=values[i+1]+1;
            }
        }

        // a<b
        for(int i=1;i<ratings.size();i++){
            if(ratings[i-1]<ratings[i] and values[i-1]>=values[i]){
                values[i]=values[i-1]+1;
            }
        
        }
        int sum =0;
        for(auto i:values)
        sum+=i;

        return sum;
    }
};
