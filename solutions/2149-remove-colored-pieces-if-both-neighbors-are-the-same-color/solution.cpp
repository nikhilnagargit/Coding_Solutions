class Solution {
public:
    bool winnerOfGame(string colors) {
        int chances_a = 0;
        int count_a = 0;
        int count_b = 0;
        int chances_b = 0;
        int i=0;
        while(i<colors.size()){
            while(i<colors.size() and colors[i]!='B'){
                i++;
                count_a++;
            }
            while(i<colors.size() and colors[i]!='A'){
                i++;
                count_b++;
            }
            cout<<count_a<<" "<<count_b<<endl;
            if(count_a>=3){
                chances_a += count_a-2;
            }
                            count_a=0;
            if(count_b>=3){
                chances_b += count_b-2;

            }
                            count_b=0;
        }
        return chances_a>chances_b;
    }
};
