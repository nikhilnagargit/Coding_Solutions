class Solution {
public:
    long long minEnd(int n, int x) {

        n = n-1;
        long long curr_mask_n = 1;
        long long curr_mask_x = 1;
        long long result = 0;
        for(int i=0;i<64;i++){
            int curr_bit_n = n & curr_mask_n;
            int curr_bit_x = x & curr_mask_x;
            // cout<<"curr_bit_n:"<<curr_bit_n<<", curr_bit_x:"<<curr_bit_x<<endl;
            if(curr_bit_x==0){
                if(curr_bit_n!=0){
                    result = result|curr_mask_x;
                    // cout<<"i:"<<i<<", result:"<<result<<endl;
                }
                curr_mask_n = curr_mask_n<<1;
            }
            else{
                result = result|curr_mask_x;
            }
            curr_mask_x = curr_mask_x<<1;
        }
        
        return result;
    }
};


