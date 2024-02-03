class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];
        if( (a+b>c and b+c>a and c+a>b) and a==b and b==c and a==c) return "equilateral";
        if((a+b>c and b+c>a and c+a>b) and (a==b or b==c or c==a)) return "isosceles";
        if(a+b>c and b+c>a and c+a>b) return "scalene";
        return "none";
        
    }
};
