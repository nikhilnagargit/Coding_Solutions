class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> arr;
        for(int i=0;i<nums1.size();i++){
            arr.push_back({nums2[i],nums1[i]});
        }
        priority_queue<int,vector<int>,greater<int>>heap;
        sort(arr.begin(),arr.end(),greater<pair<int,int>>());
        int i=0;

        long long sum=0;
        while(i<k){
            sum+= arr[i].second;
            heap.push(arr[i].second);
            i++;
        }
        long long mini  = arr[k-1].first;
        long long ans  = sum*mini;

        for(int i=k;i<arr.size();i++){
            sum+= arr[i].second;
            heap.push(arr[i].second);
            sum-=heap.top();
            heap.pop();
            mini = arr[i].first;
            ans = max(ans,sum*mini);
        }
        return ans;
    }
};
