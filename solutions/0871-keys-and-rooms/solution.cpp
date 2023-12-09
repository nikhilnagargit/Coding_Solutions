class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n,false);
        queue<int> q;
        for(int i=0;i<rooms[0].size();i++){
            q.push(rooms[0][i]);
        }
        visited[0] = true;
        while(!q.empty()){
            int curr  = q.front();q.pop();
            if(visited[curr]==false){
                visited[curr] = true;
                for(int i=0;i<rooms[curr].size();i++){
                    q.push(rooms[curr][i]);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(visited[i]==false) return false;
        }
        return true;
    }
};
