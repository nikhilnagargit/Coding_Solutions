class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        vector<int> v;
        v.push_back(0);
        int m = board[0].size();
        int n = board.size();

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(i%2==0){
                    // left to right
                    v.push_back(board[n-i-1][j]);
                }
                else{
                    //right to left
                    v.push_back(board[n-i-1][m-1-j]);
                }
            }
        }

        int N = n*m;

        queue<int> q;
        q.push(1);
        unordered_set<int> visited;
        int count = 0;
        while(!q.empty()){
            int  s = q.size();
            for(int i=0;i<s;i++){
                int curr = q.front();q.pop();
                if(curr==N){
                    return count;
                }
                if(visited.count(curr)){
                    continue;
                }
                visited.insert(curr);
                for(int j=1;j<=6;j++){
                    int next = curr+j;
                    if(next<v.size() and v[next]!=-1){
                        next = v[next];
                    }
                    q.push(next);
                }
            }
            count++;
        }
        
        return -1;

    }
};
