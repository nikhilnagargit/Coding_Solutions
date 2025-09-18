class TaskManager {
public:
    priority_queue<pair<int,pair<int,int>>> max_heap;
    unordered_map<int,int> TP_map;
    unordered_map<int,int> TU_map;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto& t:tasks){
            TP_map[t[1]] = t[2];
            TU_map[t[1]] = t[0];
            //               priority  task   user
            max_heap.push({t[2],{t[1],t[0]}});
        }

    }
    
    void add(int userId, int taskId, int priority) {
            TP_map[taskId] = priority;
            TU_map[taskId] = userId;
            //               priority  task   user
            max_heap.push({priority,{taskId,userId}});
    }
    
    void edit(int taskId, int newPriority) {
        TP_map[taskId] = newPriority;
        max_heap.push({newPriority,{taskId,TU_map[taskId]}});
    }
    
    void rmv(int taskId) {
        TP_map.erase(taskId);
        TU_map.erase(taskId);
    }
    
    int execTop() {
        //check if the task at top has same priority and even it exisits
        while(!max_heap.empty() and (TP_map.count(max_heap.top().second.first)==0 or TP_map[max_heap.top().second.first]!=max_heap.top().first)){
            max_heap.pop();
        }
        if(max_heap.empty()){
            return -1;
        }
        auto uid = max_heap.top().second.second;
        auto tid = max_heap.top().second.first;
        max_heap.pop();
        TP_map.erase(tid);
        TU_map.erase(tid);
        return uid;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
