class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        vector<int> unbeatablePlayers;
        vector<int> oneMatchLostPlayers;
        unordered_map<int,pair<int,int>> m;
        for(auto item:matches){
            m[item[0]].first++;
            m[item[1]].second++;
        }
        for(auto item:m){
            if(item.second.second==0){
                unbeatablePlayers.push_back(item.first);
            }
            if(item.second.second==1){
                oneMatchLostPlayers.push_back(item.first);
            }
        }
        sort(unbeatablePlayers.begin(),unbeatablePlayers.end());
        sort(oneMatchLostPlayers.begin(),oneMatchLostPlayers.end());
        ans.push_back(unbeatablePlayers);
        ans.push_back(oneMatchLostPlayers);
        return ans;
    }
};
