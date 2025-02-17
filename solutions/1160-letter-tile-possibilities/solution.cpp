class Solution {
public:
    void solve(string tiles,unordered_set<string>&s,string word){
        s.insert(word);
        if(tiles==""){
            return;
        }
        // if(s.count(word)){
        //     return;
        // }
        string tiles_copy = tiles;
        for(int i=0;i<tiles.size();i++){
            char c = tiles[i];
            string newWord = word + c;
            tiles = tiles.erase(i,1);
            solve(tiles,s,newWord);
            tiles = tiles_copy;
        }
    }
    int numTilePossibilities(string tiles) {
        unordered_set<string> s;
        solve(tiles,s,"");
        return s.size()-1;
    }
};
