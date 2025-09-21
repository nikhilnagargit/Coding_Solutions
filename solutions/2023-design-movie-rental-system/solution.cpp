class MovieRentingSystem {
public:
    //            movie: <price,shop>
    unordered_map<int,set<pair<int,int>>> unrented_movies;
    map<pair<int,int>,int> shopmovie_price;
    // price,shop,movie
    set<vector<int>> rented_movies;

    //                                          <shop,movie,price>
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto& entry:entries){
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];
            unrented_movies[movie].insert({price,shop});
            shopmovie_price[{shop,movie}]=price;
        }
    }

    vector<int> search(int movie) {
        vector<int> ans;
        int i=0;
        for(auto& item:unrented_movies[movie]){
            if(i==5){
                break;
            }
            ans.push_back(item.second);
            i++;
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        //remove from unrented
        int price = shopmovie_price[{shop,movie}];
        unrented_movies[movie].erase({price,shop});
        //add in rented
        rented_movies.insert({price,shop,movie});
    }
    
    void drop(int shop, int movie) {
        //remove from rented
        int price = shopmovie_price[{shop,movie}];
        unrented_movies[movie].insert({price,shop});
        //add in unrented
        rented_movies.erase({price,shop,movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int i=0;
        for(auto& item:rented_movies){
            if(i==5){
                break;
            }
            //item = price,shop,movie
            ans.push_back({item[1],item[2]});
            i++;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
