class FoodRatings {
public:

// Declaring a custom comparator
struct comp {
    // Operator() overloading
    bool operator() (const pair<int, string>& p1,
                    const pair<int, string>& p2) const
    {
        if(p1.first>p2.first){
            return false;
        }
        else if(p1.first<p2.first){
            return true;
        }
        if(p1.second<=p2.second){
            return false;
        }
        return true;
    }
};

        // cout<<endl<<"After change- ";
        // for(auto item:Map[FC_mapping[food]]){
        //     cout<<item.first<<":"<<item.second<<", ";
        // }
        // cout<<endl;
    unordered_map<string,set<pair<int,string>,comp>> Map;
    unordered_map<string,string>FC_mapping;
    unordered_map<string,int>FR_mapping;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            FC_mapping[foods[i]] = cuisines[i];
            FR_mapping[foods[i]] = ratings[i];
            pair<int,string> p = {ratings[i],foods[i]};
            Map[cuisines[i]].insert(p);
        }
    }
    
    void changeRating(string food, int newRating) {
        Map[FC_mapping[food]].erase({FR_mapping[food],food});
        FR_mapping[food] = newRating;
        Map[FC_mapping[food]].insert({newRating,food});
    }
    
    string highestRated(string cuisine) {
        auto item =  *(Map[cuisine].rbegin());
        return item.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
