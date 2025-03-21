class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>> recipe_ingredient_map;
        queue<string> q;
        for(int i=0;i<recipes.size();i++){
            recipe_ingredient_map[recipes[i]] = ingredients[i];
            q.push(recipes[i]);
        }
        unordered_set<string> available_supplies(supplies.begin(),supplies.end());
        // cout<<available_supplies.size()<<endl;
        vector<string> ans;
        int pending_count = -1;
        while(pending_count != q.size()){
            // cout<<pending_count<<","<<q.size()<<endl;
            pending_count = q.size();
            for(int i=0;i<pending_count;i++){
                string curr_recipe = q.front();q.pop();
                // check if current is possible
                bool flag = true;
                for(auto& req_item: recipe_ingredient_map[curr_recipe]){
                    if(available_supplies.find(req_item)==available_supplies.end()){
                        q.push(curr_recipe);
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    ans.push_back(curr_recipe);
                    available_supplies.insert(curr_recipe);
                }

            }
        }

        return ans;

    }
};
