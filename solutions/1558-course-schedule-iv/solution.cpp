class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,unordered_set<int>> prereq_group_map;
        unordered_map<int,vector<int>> adjMt;
        for(auto& prereq:prerequisites){
            adjMt[prereq[1]].push_back(prereq[0]);
        }
        for(int i=0;i<numCourses;i++){
            queue<int> q;
            vector<bool> isVisited(numCourses,0);
            q.push(i);
            while(!q.empty()){
                int curr = q.front();q.pop();
                if(isVisited[curr]==1){
                    continue;
                }
                isVisited[curr] = 1;
                for(auto& neighbour:adjMt[curr]){
                    if(isVisited[neighbour]==1){
                        continue;
                    }
                    prereq_group_map[i].insert(neighbour);
                    q.push(neighbour);
                }
            }

        }

        vector<bool>ans;
        for(auto& q:queries){
            if(prereq_group_map[q[1]].count(q[0])){
                ans.push_back(1);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};
