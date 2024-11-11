class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes(1001,0);
        primes[0] = 1;
        primes[1] = 1;

        for(int i=2;i*i<=1000;i++){
            int counter  = 2;
            int mul = i*counter;
            while(mul<=1000){
                primes[i*counter] = 1;
                counter++;
                mul =i*counter;
            }
        }
        vector<int> primes_arr;
        // cout<<"Primes: ";
        for(int i=0;i<primes.size();i++){
            if(primes[i]==0){
                primes_arr.push_back(i);
                // cout<<i<<",";
            }
        }
        // cout<<endl;

        int prev = nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            int curr = nums[i];
            if(prev>curr){
            }
            else{
                // minus a prime number such that result will be just less then prev
                int idx = 0;
                int flag = 0;
                for(int k=0;k<primes_arr.size();k++){
                    if(primes_arr[k]>=curr){
                        break;
                    }
                    if(curr-primes_arr[k]<prev){
                        nums[i] = curr-primes_arr[k];
                        flag = 1;
                        break;
                    }
                }
                if(flag==0){
                    return false;
                }
            }
            prev = nums[i];
        }
        return true;

    }
};
