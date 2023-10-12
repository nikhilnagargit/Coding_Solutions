/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int findPeak(MountainArray& m_arr){
        int left =0;
        int right=m_arr.length()-1;
        int mid;
        int mid_el;
        while(left<=right){
            mid = left+(right-left)/2; 
            mid_el = m_arr.get(mid);
            if(mid==0){
                if(mid_el>m_arr.get(mid+1)){
                    return mid;
                 }
                else{
                    left = mid+1;
                }
            }
            else if(mid==m_arr.length()-1){
                if(mid_el>m_arr.get(mid-1))
                return mid;
                else
                right = mid-1;
            }
            else if(mid_el>m_arr.get(mid-1) and mid_el>m_arr.get(mid+1)){
                return mid;
            }
            else if(mid_el>m_arr.get(mid-1)){
                left= mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return 0;
    }

    int binary_search_asc(MountainArray &m_arr,int target,int left,int right){
        int mid;
        int mid_el;
        while(left<=right){
            mid = left+(right-left)/2; 
            mid_el = m_arr.get(mid);
        
            if(mid_el==target){
                return mid;
            }
            else if(mid_el>target){
                
                right = mid-1;
            }
            else{
                left= mid+1;
            }
        }
        return -1;
    }
    
    int binary_search_desc(MountainArray &m_arr,int target,int left,int right){
        int mid;
        int mid_el;
        while(left<=right){
            mid = left+(right-left)/2; 
            mid_el = m_arr.get(mid);
       
            if(mid_el==target){
                return mid;
            }
            else if(mid_el>target){
                left= mid+1;
            }
            else{
                
                right = mid-1;
            }
        }
        return -1;
    }


    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = findPeak(mountainArr);
        cout<<peak;
        // divide in two arrays and search for target in lower array
        int one = binary_search_asc(mountainArr,target,0,peak);

        int two;
        if(one==-1){
            two = binary_search_desc(mountainArr,target,peak+1,mountainArr.length()-1);
            if(two==-1){
                return -1;
            }
            else{
                return two;
            }
        }
        return one ;
        
    }
};
