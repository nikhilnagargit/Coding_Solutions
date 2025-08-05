class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        q.push(beginWord);
        int sq = 1;
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                string curr = q.front();q.pop();
                for(int idx=0;idx<curr.size();idx++){
                    string temp = curr;
                    for(int c=0;c<=25;c++){
                        temp[idx]='a'+c;
                        if(wordSet.count(temp)){
                            if(temp==endWord){
                            return sq+1;
                            }
                            q.push(temp);
                            wordSet.erase(temp);
                        }
                    }
                }
            }
            sq++;
        }
        return 0;
    }
};
