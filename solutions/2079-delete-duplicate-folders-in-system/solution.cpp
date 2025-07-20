class TrieNode {
public:
    bool marked;
    unordered_map<string, TrieNode*> children;
    TrieNode() {
        marked = false;
    }
    void insert(vector<vector<string>>& paths) {
        for (auto& path : paths) {
            TrieNode* temp = this; // use `this` as root
            for (auto& dir : path) {
                if (!temp->children.count(dir)) {
                    temp->children[dir] = new TrieNode();
                }
                temp = temp->children[dir];
            }
        }
    }
    void traverse(TrieNode* node,vector<string>& path,vector<vector<string>>& ans){

        for(auto& it: node->children){
            if(it.second->marked)
                continue;
            path.push_back(it.first);
            ans.push_back(path);
            traverse(it.second,path,ans);
            path.pop_back();
        }
    }
};


class Solution {
public:

    string serialize(TrieNode* node,unordered_map<TrieNode*,string>& serialized_map){
        if(node==NULL){
            return "";
        }
        vector<string> curr_string_v;
        for(auto& it: node->children){
            string curr_string = "";
            if(it.second!=NULL){
                string child_str = serialize(it.second,serialized_map);
                if(child_str!=""){
                    curr_string +=  it.first + "("+child_str+")";
                }
                else{
                    curr_string += it.first;
                }
                curr_string_v.push_back(curr_string);
            }
        }
        sort(curr_string_v.begin(),curr_string_v.end());
        string complete_str = "";
        for(auto& s:curr_string_v){
            if(s!="")
            complete_str+= s;
        }
        if(complete_str!="")
        serialized_map[node] = complete_str;
        return complete_str;
    }


    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        // create a trie
        TrieNode* trie = new TrieNode();
        trie->insert(paths);

        // serialize the each node children in string
        unordered_map<TrieNode*,string> serialized_map;
        unordered_map<string,pair<int,vector<TrieNode*>>> count_map;

        serialize(trie,serialized_map);
        for(auto& it:serialized_map){
            string s= it.second;
            TrieNode* p = it.first;
            count_map[s].first +=1;
            count_map[s].second.push_back(p);
        }

        // mark for deletion if the hash value repeats or have count more than 1;
        for(auto& item:count_map){
            if(item.second.first>1){
                for(auto& n:item.second.second){
                    n->marked = true;
                }
            }
        }

        // delete the values from path.
        vector<vector<string>>ans;
        vector<string>path;
        trie->traverse(trie,path,ans);

        return ans;

    }
};
