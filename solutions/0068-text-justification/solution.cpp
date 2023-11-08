class Solution {
public:
    string justifylast(vector<string>& row,int rowWidth,int maxWidth){
        string ans = row[0];
        for(int i=1;i<row.size();i++){
            ans+=row[i];
        }
        int p = ans.size();
        while(p<maxWidth){
            ans+=" ";
            p++;
        }
        return ans;
    }

    string justify(vector<string>& row,int rowWidth,int maxWidth){
        string ans=row[0];
        int mids = row.size()-1;
        if(mids==0){
         int p = ans.size();
        while(p<maxWidth){
            ans+=" ";
            p++;
        }
        return ans;
        }
        int rem_space = maxWidth-rowWidth;
        int space_to_add = rem_space/mids;
        int next_rem_space = rem_space%mids;
        int k=0;
        for(int i=1;i<row.size();i++){
            string space = "";
            if(k<next_rem_space){
                space+=" ";
                k++;
            }
            int j=space_to_add;
            while(j--){
                space+=" ";
            }
            ans+= space+row[i];
        }
        return ans;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> row;
        vector<string> ans;
        row.push_back(words[0]);
        int i=1;
        int rowwidth=words[0].size();
        while(i<words.size()){
            string nextword  = words[i];
            if(rowwidth+nextword.size()+1<=maxWidth){
                rowwidth+= nextword.size()+1;
                row.push_back(" "+nextword);
            }
            else{
                ans.push_back(justify(row,rowwidth,maxWidth));
                row.clear();
                row.push_back(nextword);
                rowwidth = nextword.size();
            }
            i++;
        }
        ans.push_back(justifylast(row,rowwidth,maxWidth));
        return ans;
    }
};
