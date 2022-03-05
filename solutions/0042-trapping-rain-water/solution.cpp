class Solution {
public:
    int trap(vector<int>& height) {
        int LtoR[height.size()];
        int RtoL[height.size()];
        
        
        int max=-1;
        for(int i=0;i<height.size();i++){
            if(height[i]>max){
                max = height[i];
            }
            LtoR[i]= max;
        }
        max= -1;
        for(int i=height.size()-1;i>=0;i--){
                if(height[i]>max){
                max = height[i];
            }
            RtoL[i]= max;
        }
        
        int sum=0;
        
          for(int i=0;i<height.size();i++){
              // cout<<LtoR[i]<<" "<<RtoL[i]<<endl;
              sum+= min(LtoR[i],RtoL[i])-height[i];
          }
        return sum;
    }
};
