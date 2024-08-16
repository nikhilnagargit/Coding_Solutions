class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int max_num = INT_MIN;
        int max_num_item_idx = 0;
        int min_num_item_idx = 0;
        int second_max_num = INT_MIN;
        int min_num = INT_MAX;
        int second_min_num = INT_MAX;

        for(int i=0 ; i<arrays.size() ; i++){
            int tempo = arrays[i][0];
            if(min_num >= tempo){
                second_min_num = min_num;
                min_num_item_idx = i;
                min_num = tempo;
            }
            else if(second_min_num >= tempo){
                second_min_num = tempo;
            }

            int temp = arrays[i][arrays[i].size()-1];
            if(temp>=max_num){
                second_max_num = max_num;
                max_num_item_idx = i;
                max_num = temp;
            }
            else if(second_max_num <= temp){
                second_max_num = temp;
            }
        }

        // cout<<max_num<<" "<<min_num<<" "<< second_max_num << " "<<max_num_item_idx<<" "<<min_num_item_idx<<endl;
        if(max_num_item_idx == min_num_item_idx){
            return max(abs(second_max_num - min_num),abs(max_num-second_min_num));
        }
        return abs(max_num - min_num);
    }
};
