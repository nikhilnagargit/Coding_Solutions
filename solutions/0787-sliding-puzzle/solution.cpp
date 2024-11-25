class Solution {
public:
    string matrix_to_string(vector<vector<int>>& board){
        string s = "";
        for(auto row:board){
            for(auto item:row){
                s+= to_string(item);
            }
        }
        return s;
    }

    int find_position(string s){
        int i = 0;
        for(auto c:s){
            if(c=='0'){
                return i;
            }
            i++;
        }
        return i;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_set<string> visited;
        queue<string> q;
        q.push(matrix_to_string(board));
        unordered_map<int,vector<int>> move_mapping = { {0,{1,3}}, {1,{0,2,4}}, {2,{5,1}}, {3,{0,4}}, {4,{1,3,5}}, {5,{4,2}}};
        int moves = 0;
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                string item = q.front();q.pop();
                if(item=="123450"){
                    return moves;
                }
                if(!visited.count(item)){
                    //mark visited
                    visited.insert(item);
                    //make the possible moves and push
                    int position = find_position(item);
                    for(int move: move_mapping[position]){
                        string item_copy = item;
                        char temp = item_copy[position];
                        item_copy[position] = item_copy[move];
                        item_copy[move] = temp;
                        q.push(item_copy);
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};
