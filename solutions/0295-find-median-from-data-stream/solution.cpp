class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;

    MedianFinder() {
    }
    
    void addNum(int num) {
            // if maxheap heap is empty
            if(maxheap.size()==0){
                maxheap.push(num);
                return;
            }
            // if both heaps have same size
            if(maxheap.size()==minheap.size()){
                if(minheap.top()>num){
                    maxheap.push(num);
                    return;
                }
                else{
                    maxheap.push(minheap.top());
                    minheap.pop();
                    minheap.push(num);
                    return;
                }
            }
            // if first heap is bigger
            if(maxheap.top()>num){
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(num);
                return;
            }
            else{
                minheap.push(num);
                return;
            }


        }
    
    
    double findMedian() {
        if(minheap.size()==maxheap.size()){
            return (minheap.top()+maxheap.top())/2.0;
        }
        else{
            return maxheap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
