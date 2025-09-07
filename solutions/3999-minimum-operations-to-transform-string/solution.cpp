class Solution {
public:
    int minOperations(string s) {
        unordered_set<char> myset(s.begin(),s.end());
        if(myset.count('a')){
            myset.erase('a');
        }
        vector<char> v(myset.begin(),myset.end());
        sort(v.begin(),v.end());
        int distance = 0;
        if(v.size()==0) return 0;
        //calculate begin distance if first is not a
        for(int i=0;i<v.size()-1;i++){
                //count for prev group to current grp distance
                distance += (v[i+1]-v[i]);
        }
        distance += (27-(v[(int)v.size()-1]-'a'+1));

        return distance;
    }
};
