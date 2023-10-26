class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        // flatten the array
        vector<int> arr;
        arr.push_back(0);
        int n= board.size();
        for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
            if(i%2==0){
              arr.push_back(board[n-i-1][j]);
            }else{
              arr.push_back(board[n-i-1][n-j-1]);
            }
          }
        }
        for(auto i:arr){
            cout<<i<<",";
        }
        cout<<endl;
        // store minimum moves to reach current index, create a vector
        vector<int> moves(n*n+1,-1);
        moves[1]=0;
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            // try all possible moves from current index
            for(int i=curr+1;i<=min(curr+6,n*n);i++){
                int destination;
                if(arr[i]==-1){
                    destination = i;
                }
                else{
                    destination = arr[i];
                }
                if(moves[destination]==-1){
                    moves[destination]=moves[curr]+1;
                    q.push(destination);
                }
            }
        }
        for(auto i:moves){
            cout<<i<<",";
        }
        return moves[n*n];
    }
};
