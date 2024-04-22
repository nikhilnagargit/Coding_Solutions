class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> set_deadends(deadends.begin(),deadends.end());
        queue<string> q;
        unordered_set<string> set_visited;
        q.push("0000");
        string temp = "0000";
        // edge cases
        if(set_deadends.find(target)!=set_deadends.end()){
            return -1;
        }
        if(set_deadends.count("0000"))
            return -1;

        if(target=="0000"){
            return 0;
        }
        // pick items from queue and do until we find the target
        int level = 1;

        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                string current = q.front();
                q.pop();
                // do all possible eight changes with this string and push in queue if already not visited
                if(set_visited.find(current)==set_visited.end()){
                    // mark current as visited
                    set_visited.insert(current);

                    // increase first index
                    string updated = to_string((stoi(current.substr(0,1))+1)%10) + current.substr(1);
                    // check if updated is the target
                    if(updated==target)return level;
                    // insert the updated in q if it does not exists in deadlock set
                    if(set_deadends.find(updated)==set_deadends.end())
                        q.push(updated);

                    // increase second index
                    updated = current.substr(0,1) +to_string((stoi(current.substr(1,1))+1)%10) + current.substr(2);
                    // check if updated is the target
                    if(updated==target)return level;
                    // insert the updated in q if it does not exists in deadlock set
                    if(set_deadends.find(updated)==set_deadends.end())
                        q.push(updated);

                    // increase third index
                    updated = current.substr(0,2) +to_string((stoi(current.substr(1,2))+1)%10) + current.substr(3);
                    // check if updated is the target
                    if(updated==target)return level;
                    // insert the updated in q if it does not exists in deadlock set
                    if(set_deadends.find(updated)==set_deadends.end())
                        q.push(updated);

                    // increase forth index
                    updated = current.substr(0,3) +to_string((stoi(current.substr(1,3))+1)%10);
                    // check if updated is the target
                    if(updated==target)return level;
                    // insert the updated in q if it does not exists in deadlock set
                    if(set_deadends.find(updated)==set_deadends.end())
                        q.push(updated);


                    // decrease first index
                    updated = to_string((stoi(current.substr(0,1))+9)%10) + current.substr(1);
                    // check if updated is the target
                    if(updated==target)return level;
                    // insert the updated in q if it does not exists in deadlock set
                    if(set_deadends.find(updated)==set_deadends.end())
                        q.push(updated);

                    // decrease second index
                    updated = current.substr(0,1) +to_string((stoi(current.substr(1,1))+9)%10) + current.substr(2);
                    // check if updated is the target
                    if(updated==target)return level;
                    // insert the updated in q if it does not exists in deadlock set
                    if(set_deadends.find(updated)==set_deadends.end())
                        q.push(updated);

                    // decrease third index
                    updated = current.substr(0,2) +to_string((stoi(current.substr(1,2))+9)%10) + current.substr(3);
                    // check if updated is the target
                    if(updated==target)return level;
                    // insert the updated in q if it does not exists in deadlock set
                    if(set_deadends.find(updated)==set_deadends.end())
                        q.push(updated);

                    // decrease forth index
                    updated = current.substr(0,3) +to_string((stoi(current.substr(1,3))+9)%10);
                    // check if updated is the target
                    if(updated==target)return level;
                    // insert the updated in q if it does not exists in deadlock set
                    if(set_deadends.find(updated)==set_deadends.end())
                        q.push(updated);

                }
            }
            level++;
        }

        return -1;
    }
};
