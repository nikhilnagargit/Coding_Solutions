class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        //users that can't communicate
        unordered_map<int,unordered_set<int>> user_languages;
        for(int i=1;i<=languages.size();i++){
            for(auto& l:languages[i-1]){
                user_languages[i].insert(l);
            }
        }

        unordered_set<int> users_to_teach;

        for(auto& friendship:friendships){
            //check if both can communicate or not
            int a = friendship[0];
            int b = friendship[1];
            bool cancommunicate = false;
            for(auto l: user_languages[a]){
                if(user_languages[b].count(l)){
                    cancommunicate = true;
                    break;
                }
            }
            if(!cancommunicate){
                users_to_teach.insert(a);
                users_to_teach.insert(b);
            }
        }

        //check if we teach all users the language , which language need to be taught minimum
        int minppl = INT_MAX;
        for(int i=1;i<=n;i++){
            int language = i;
            int count = 0;
            //for all users to teach
            for(auto& person:users_to_teach){
                if(user_languages[person].count(language)){
                    //dont teach him
                }
                else{
                    count++;
                    //teach him

                }
            }
            minppl = min(minppl,count);
        }
        return minppl;
    }
};
