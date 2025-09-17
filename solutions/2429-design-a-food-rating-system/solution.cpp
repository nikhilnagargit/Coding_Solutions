
struct cmp{
    bool operator()(pair<int,string>& a, pair<int,string>& b){
        if(a.first<b.first){
            return true;
        }
        else if(a.first==b.first){
            if(a.second>b.second){
                return true;
            }
        }
        return false;
    }
};

class FoodRatings {
public:

    unordered_map<string,priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>> CFR_map;
    unordered_map<string,int> FR_map;
    unordered_map<string,string> FC_map;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            FR_map[foods[i]]  = ratings[i];
            FC_map[foods[i]] = cuisines[i];
            CFR_map[cuisines[i]].push({ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        FR_map[food] = newRating;
        CFR_map[FC_map[food]].push({newRating,food});
    }
    
    string highestRated(string cuisine) {
        while(CFR_map[cuisine].top().first!=FR_map[CFR_map[cuisine].top().second]){
            CFR_map[cuisine].pop();
        }
        return CFR_map[cuisine].top().second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
