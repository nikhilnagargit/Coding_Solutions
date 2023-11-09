class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()){
            return "";
        }
        unordered_map<char,int> target_map;
        unordered_map<char,int> curr_map;
        for(auto item:t){
            target_map[item]++;
        }
        int count_to_meet = target_map.size();
        int left=0;
        int right=0;
        int count_met = 0;
        int min_start=INT_MAX;
        int min_len = INT_MAX;

        
        while(right<s.size()){
            char curr = s[right];
            if(target_map.find(curr)!=target_map.end()){
                curr_map[curr]++;
                if(curr_map[curr]==target_map[curr]){
                    count_met+=1;
                }
            }
            while(count_met==count_to_meet){
                //save result and start shrinking from left side.
                if(min_len>=right-left+1){
                    min_start = left;
                    min_len = right-left+1;
                }
                if(curr_map.find(s[left])!=curr_map.end()){
                    curr_map[s[left]]--;
                    if(curr_map[s[left]]<target_map[s[left]]){
                        count_met--;
                    }
                }
                left++;
            }
            right++;
        }
        if(min_start==INT_MAX){
            return "";
        }
        return s.substr(min_start,min_len);

    }
};
