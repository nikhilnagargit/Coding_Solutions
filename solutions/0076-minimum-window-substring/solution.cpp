class Solution {
public:
    bool compare_maps(unordered_map<char,int>& d_map, unordered_map<char,int>& c_map){
        for(auto& item:d_map){
            if(c_map.find(item.first)==c_map.end() or c_map[item.first]<d_map[item.first]){
                return false;
            }
        }
        return true;
    }
// // Function to print an unordered_map<char, int>
// void printUnorderedMap(const std::unordered_map<char, int>& d_map) {
//     cout<<"{";
//     for (const auto& pair : d_map) {
//         std::cout<<","<< pair.first <<":"<< pair.second;
//     }
//     cout<<"}"<<endl;
// }
    string minWindow(string s, string t) {
        pair<int,int> smallest = {-1,-1};
        unordered_map<char,int> d_map;
        unordered_map<char,int> c_map;
        for(auto &c:t) d_map[c]++;
        int left = 0;
        for(int right=0;right<s.size();right++){
            // expand the window
            c_map[s[right]]++;
            // cout<<s.substr(left,right-left+1)<<","<<compare_maps(d_map,c_map)<<endl;
            // printUnorderedMap(d_map);
            // printUnorderedMap(c_map);
            // cout<<"-----------------";

            // check if window is complete/extra elements there
            while(left<=right and compare_maps(d_map,c_map)){
                // check for smallest ans and start reducing window.
                // cout<<temp_s<<", "<<smallest_s<<endl;
                if((right-left+1)<(smallest.second-smallest.first+1) or (smallest.first==-1 and smallest.second==-1)){
                    smallest = {left,right};
                }
                // reduce
                c_map[s[left]]--;
                if(c_map[s[left]]==0){
                    c_map.erase(s[left]);
                }
                left++;
            }
        }
        if(smallest.first==-1 and smallest.second==-1) return "";
        return s.substr(smallest.first,smallest.second-smallest.first+1);
    }
};
