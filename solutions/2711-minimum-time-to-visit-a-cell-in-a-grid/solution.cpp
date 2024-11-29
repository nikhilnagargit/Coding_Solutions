class Solution {
public:
    int m;
    int n;
    bool isValid(int& i, int& j){
        if(i<0 or i>=m){
            return false;
        }
        if(j<0 or j>=n){
            return false;
        }
        return true;
    }

    int minimumTime(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        unordered_set<string> visited;
        if(grid[0][1]>1 and grid[1][0]>1){
            return -1;
        }
        vector<pair<int,int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
        priority_queue<vector<int>,vector<vector<int>>,greater<>> q;
        q.push({grid[0][0],0,0});

        while(!q.empty()){
            auto item = q.top();q.pop();
            int time = item[0];
            int i = item[1];
            int j = item[2];
      if(i==m-1 and j==n-1){
                return time;
            }
            string s = to_string(i) + "-" + to_string(j);

            if(visited.count(s)){
                continue;
            }
            visited.insert(s);
            for(auto& d:directions){
                int newi = i + d.first;
                int newj = j + d.second;

                if(isValid(newi,newj)){
                    int wait_time = ((grid[newi][newj]-time)%2==0)?1:0;
                    int next_time = max(grid[newi][newj]+wait_time, time+1);
                        q.push({next_time,newi,newj});
                }
           
            }
         
        }

        return -1;
    }
};
