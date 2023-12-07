class Solution {
public:
    void collide(vector<int>&ans,int outsider){
        // if there is no asteroid exist in the stable vector 
        if(ans.size()==0){
            ans.push_back(outsider);
            return;
        }
        // if the outsider vector want to go right, it won't collide with anyone, (because the existing stable vector will not have collisions on right)
        if(outsider>0){
            ans.push_back(outsider);
            return;
        }

        // if we encounter a negative outsider(goind left)
        while(ans.size()>0){
            int last  = ans[ans.size()-1];
            // if last asteroid of stable vector is negative, that means no collision will happend with negative outsider
            if(last<0){
                ans.push_back(outsider);
                return;
            }
                // if last element if the ans is positive, they will collide
            else if(last<abs(outsider)){
                ans.pop_back();
            }
            //  both will get destoryed 
            else if(last==abs(outsider)){
                ans.pop_back();
                return;
            }
            else{
                return;
            }
        }
        // outsider has destroyed all smaller asteroids in stable vector, so it will now be added in stable state.
        ans.push_back(outsider);

    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
    //   we will try to maintain a stable state in vector ans
      vector<int>ans;

    //   add a asteroid to out stable vector one by one to simulate collisions
      for(int i:asteroids){
          collide(ans,i);
      }
      return ans;
    }
};
