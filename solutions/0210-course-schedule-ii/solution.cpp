class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> inDegrees(numCourses,0);
        unordered_map<int,vector<int>>m;
        for(auto& p:prerequisites){
            m[p[1]].push_back(p[0]);
            inDegrees[p[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(inDegrees[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int s= q.size();
            for(int i=0;i<s;i++){
                int curr = q.front();q.pop();
                ans.push_back(curr);
                for(auto& n:m[curr]){
                    inDegrees[n]--;
                    if(inDegrees[n]==0){
                        q.push(n);
                    }
                }
            }
        }

        if(ans.size()!=numCourses){
            return vector<int>();
        }
        return ans;
    }
};
