class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int black_count = 0;
        int max_black = 0;
        for(int i=0;i<k;i++){
            if(blocks[i]=='B'){
                black_count++;
            }
        }
        max_black = black_count;
        for(int i=k;i<blocks.size();i++){
            if(blocks[i-k]=='B'){
                black_count--;
            }
            if(blocks[i]=='B'){
                black_count++;
            }
            max_black = max(max_black,black_count);
        }
        return k-max_black;
    }
};
