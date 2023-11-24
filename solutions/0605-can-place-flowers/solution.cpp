class Solution {
public:
    bool check(int i,vector<int>&f){
        if(f.size()<=1){
            return true;
        }
        if(i==0 and f[i+1]==0){
            return true;
        }
        if(i==0 and f[i+1]==1){
            return false;
        }
        if(i==(f.size()-1) and f[i-1]==0){
            return true;
        }
        if(i==(f.size()-1) and f[i-1]==1){
            return false;
        }
        if(f[i+1]==0 and f[i-1]==0){
            return true;
        }
        return false;
    }

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int put = 0;
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==0 and check(i,flowerbed)){
                flowerbed[i] = 1;
                put++;
            }
            if(put>=n){
                return true;
            }
        }
        return false;
    }
};
