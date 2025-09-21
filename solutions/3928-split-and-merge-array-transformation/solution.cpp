class Solution {
public:
    string encode(vector<int>& n){
        string ans = "";
        for(auto& item:n){
            ans += to_string(item)+"-";
        }
        return ans;
    }
    
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<string> visited;
        int count = 0;
        string target = encode(nums2);
        queue<vector<int>> q;
        q.push(nums1);
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto curr = q.front();q.pop();
                if(target==encode(curr)){
                    return count;
                }
                // if(visited.count(encode(curr))){
                //     continue;
                // }
                // visited.insert(encode(curr));
                //make new pairs for this
                
               
                for (int partstart = 0; partstart < curr.size(); partstart++) {
                    for (int partsize = 1; partsize <= (curr.size() - partstart); partsize++) {
                        // Split into three parts: a, b, c
                        vector<int> left(curr.begin(), curr.begin() + partstart);
                        vector<int> mid(curr.begin() + partstart, curr.begin() + partstart + partsize);
                        vector<int> right(curr.begin() + partstart + partsize, curr.end());
                        // a = a + c
                        vector<int> b = left;
                        b.insert(b.end(),right.begin(),right.end());
                        vector<int> a = mid;
                        // Try inserting b back at all possible positions
                        for (int k = 0; k <= b.size(); k++) {
                            vector<int> b1(b.begin(), b.begin() + k);
                            vector<int> b2(b.begin() + k, b.end());
                            vector<int> nxt = b1;
                            nxt.insert(nxt.end(), a.begin(), a.end());
                            nxt.insert(nxt.end(), b2.begin(), b2.end());
                            if (visited.count(encode(nxt))) {
                                continue;
                            }
                            q.push(nxt);
                            visited.insert(encode(nxt));
                        }
                    }
                }
            }
            count++;
        }
        return -1;
    }
};
