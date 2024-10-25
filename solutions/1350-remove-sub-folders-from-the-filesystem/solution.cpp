
class Solution { 
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> myset (folder.begin(),folder.end());
        vector<string> result ;
        for(auto item:folder){
            bool isSubfolder = false;
            string path = item;
            while(path!=""){
                // cout<<"path-"<<path<<", ";
                int pos = path.find_last_of('/');
                // cout<<"pos-"<<pos<<",";
           
                if(pos==0){
                    break;
                }
                path = path.substr(0,pos);
                if(path!="")
                if(myset.find(path)!=myset.end()){
                    isSubfolder = true;
                    break;
                }
            
            }
            if(!isSubfolder){
                result.push_back(item);
            }
        }
        return result;
    }
};
