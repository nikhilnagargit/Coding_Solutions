class Solution {
public:
    string space_multiplier(int k){
        string ans = "";
        while(k--){
            ans+=" ";
        }
        return ans;
    }

    string spacify(vector<string> v,int maxWidth){
        int curr_count = 0;
        for(auto w:v){
            curr_count+= w.size();
        }
        
        string ans = "";
        int extra_space = maxWidth-curr_count;
        int word_count = v.size()-1;
        if(word_count==0){
            return v[0]+space_multiplier(extra_space);
        }
        int rem = 0;
        if(word_count!=0)
        rem = extra_space%(word_count);
        int append = 0;
        if(word_count!=0)
        append = extra_space/(word_count);
        // cout<<append<<","<<rem<<endl;
        for(int i=0;i<v.size();i++){
            string w = v[i];
            if(i!=v.size()-1){
            if(rem>0){
            ans+= w  + space_multiplier(append+1);
            rem--;
            }
            else{
            ans+= w  + space_multiplier(append);  
            }
            }
            else{
                ans+=w;
            }
        }
        return ans;
    }

    string leftSpacify(vector<string>v,int maxWidth){
        int curr_count = 0;
        for(auto w:v){
            curr_count+= w.size();
        }
        
        string ans = "";
        int extra_space = maxWidth-curr_count;
        int word_count = v.size()-1;
        for(auto w:v){
            ans+= w ;
            if(ans.size()<maxWidth){
                ans+=" ";
            }
        }
        while(ans.size()<maxWidth){
            ans+=" ";
        }
        return ans;
    }


    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<string> v;

        for(int i=0;i<words.size();i++){
            int curr_count = 0;
            for(auto w:v){
                curr_count+= w.size();
            }
            curr_count+= v.size()-1;

            if(v.size()==0){
                if(words[i].size() == maxWidth){
                    v.push_back(words[i]);
                    ans.push_back(spacify(v,maxWidth));
                    v.clear();
                    continue;
                }
                else if(words[i].size() > maxWidth){
                    ans.push_back(spacify(v,maxWidth));
                    v.clear();
                    v.push_back(words[i]);
                    continue;
                }
                else{
                    v.push_back(words[i]);
                }
            }
            else{
                if((curr_count+words[i].size()+1) == maxWidth){
                    v.push_back(words[i]);
                    ans.push_back(spacify(v,maxWidth));
                    v.clear();
                    continue;
                }
                else if((curr_count+words[i].size()+1) > maxWidth){
                    ans.push_back(spacify(v,maxWidth));
                    v.clear();
                    v.push_back(words[i]);
                    continue;
                }
                else{
                    v.push_back(words[i]);
                }
            }
        }
        if(v.size()!=0){
            ans.push_back(leftSpacify(v,maxWidth));
        }

        return ans;
    }
};
