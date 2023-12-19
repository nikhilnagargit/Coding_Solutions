    class Node{
        public:
            bool isEnd;
            vector<Node*> children;
            Node(){
                isEnd = false;
                children = vector<Node*>(26,nullptr);
            }
    };
class Solution {
public:
    Node* root;

    Solution() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(auto c:word){
            if(curr->children[c-'a']==nullptr){
                curr->children[c-'a'] = new Node();
            }
            curr = curr->children[c-'a'];
        }
        curr->isEnd = true;
        
    }
    


    void solve(vector<string>& allWords,string word,Node* curr){
        if(curr==nullptr){
            return;
        }
        if(allWords.size()==3){
            return;
        }
        if(curr->isEnd==true){
            allWords.push_back(word);
        }
        for(int i=0;i<26;i++){
            if(curr->children[i]!=nullptr){
                solve(allWords,word+char(i+'a'),curr->children[i]);
            }
        }
        
    }
    void fillSuggestions(vector<string>& v,string word){
        Node* curr = root;
        for(auto c:word){
            if(curr->children[c-'a']==nullptr){
                return;
            }
            curr = curr->children[c-'a'];
        }
        solve(v,word,curr);

    }
    vector<vector<string>>ans;
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        for(auto s:products){
            insert(s);
        }
        string searchstring = "";
        for(auto c:searchWord){
            searchstring+= c;
            vector<string>v;
            fillSuggestions(v,searchstring);
            ans.push_back(v);
        }
        return ans;
    }
};
