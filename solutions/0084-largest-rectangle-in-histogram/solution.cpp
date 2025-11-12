
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //store next smaller elements for left to right - 

        vector<int> leftNextSmaller(heights.size(),-1);
        vector<int> rightNextSmaller(heights.size(),heights.size());

        stack<int> stk;
        for(int i=0;i<heights.size();i++){
            while(!stk.empty() and heights[i]<=heights[stk.top()]){
                stk.pop();
            }
            if(!stk.empty()){
                leftNextSmaller[i] = stk.top();
            }
            stk.push(i);
        }
        while(!stk.empty()){
            stk.pop();
        }
        for(int i=heights.size()-1;i>=0;i--){
            while(!stk.empty() and heights[i]<=heights[stk.top()]){
                stk.pop();
            }
            if(!stk.empty()){
                rightNextSmaller[i] = stk.top();
            }
            stk.push(i);
        }  
        int maxarea = 0;
        for(int i=0;i<heights.size();i++){
            int area =(rightNextSmaller[i]-leftNextSmaller[i]-1)*heights[i];
            maxarea = max(maxarea,area);
        }
        return maxarea;
    }
};

