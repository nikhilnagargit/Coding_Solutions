struct ListNode1
{
    int val;
    ListNode1 *prev, *next;
    ListNode1() : val(0), prev(nullptr), next(nullptr) {}
    ListNode1(int x) : val(x), prev(nullptr), next(nullptr) {}
    ListNode1(int x, ListNode1 *prev, ListNode1 *next) : val(x), prev(prev), next(next) {}
};

class MyLinkedList {
public:
    ListNode1 *head = NULL;
    int size;
    /** Initialize your data structure here. */
    MyLinkedList() 
    {
        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) 
    {
        
           if(index>=size or index<0){
               return -1;
           }
        
           if(head == NULL){
               return -1;
           }
        
        ListNode1 * curr=this->head;
           while(index-- >0){
               
               curr = curr->next;
           }
          return curr->val;
           
        
//         if(head == NULL)  {return -1;}
//         if(index >= size) {return -1;}
        
//         ListNode1* current = head;
        
//         while(index != 0)
//         {
//             if(current != NULL)
//             {
//                 current = current->next;
//             }
//             index--;
//         }
        
//         if(current != NULL) {return(current->val);}
//         else {return NULL;}
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) 
    {
        
        ListNode1* newNode = new ListNode1;
        
        newNode->prev = NULL;
        newNode->next = this->head;
        newNode->val = val;
        
        if(this->head!=NULL){
            head->prev = newNode;
        }
        this->head = newNode;
    
        this->size++;
        
        
        
//         ListNode1* newNode = new ListNode1;

//         newNode->val  = val;
//         newNode->next = head;
//         newNode->prev = NULL;

//         if(head != NULL)
//         {
//             head->prev = newNode;
//         }
//         head = newNode;
//         size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) 
    {
        
        
        ListNode1* newNode = new ListNode1(val);
        
        if(this->head==NULL){
            this->head = newNode;
            size++;
            return;
        }
        
        ListNode1* curr = this->head;
        
        while(curr->next!=NULL){
            curr = curr->next;
        }
        
        curr->next = newNode;
        newNode->prev = curr;
        size++;
        
        
        
//         if(head == NULL) {addAtHead(val);return;}

//         ListNode1 *newNode = new ListNode1;
//         ListNode1 *current = head;
//         newNode->val  = val;
//         newNode->next = NULL;
        
//         // Go to end of list
//         while(current->next != NULL)
//         {
//             current  = current->next;
//         }
        
//         if(current != NULL)
//         {
//             current->next = newNode;
//         }
//         newNode->prev = current;
        
//         size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) 
    {
        
        if(index>size or index<0){
            return;
        }
        
        
        if(index==0){
            addAtHead(val) ;
            return;
        }
        
        if(index==size){
            addAtTail(val);
            return;
        }
        
        ListNode1* newNode =  new ListNode1(val);
        ListNode1* curr = head->next;
        ListNode1* prevNode = head;
        
        while(index>1){
            prevNode = curr;
            curr = curr->next;
            index--;
        }
        
        
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = curr;
        curr->prev = newNode;
 
        
        size++;
        
        
        
//         if(index > size)   {return;}
//         if(index == 0)      {addAtHead(val); return; }
//         if(index == size)   {addAtTail(val); return; }

//         ListNode1 *current = head;
//         ListNode1 *newNode = new ListNode1;
//         newNode->val = val;

//         while(index >= 1)
//         {
//             current = current->next;
//             index--;
//         }
        
//         current->prev->next = newNode;
//         newNode->prev = current->prev;
//         newNode->next = current;
//         current->prev = newNode;
        
//         size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) 
    {
        
        if(index<0 or index>=size){
            return;
        }
        
        if(head==NULL){
            return;
        }
        
        if(head->next==NULL){
            delete head;
            this->head = NULL;
            return;
        }
        
//         first node removal
        if(index==0){
            ListNode1* temp = head;
            this->head = head->next;
            head->prev = NULL;
            delete temp;
            size--;
            return;
        }
// last node removal
        if(index==size-1){
            ListNode1* curr = head;
            ListNode1* temp;
            while(curr->next->next!=NULL){
                curr = curr->next;
            }
            temp = curr->next;
            curr->next=NULL;
            size--;
            delete temp;
            
            return;
        }

        
        
            ListNode1* curr = head->next;
            ListNode1* prevNode = head;
            ListNode1* temp;
            while(index-->1){
                prevNode = curr;
                curr = curr->next;
            }
        
            prevNode->next = curr->next;
            curr->next->prev = prevNode;
            size--;
            delete curr;
   
        
        
        
        
        
        
        
        
        
        
        
        
//         ListNode1 *previous = head;
//         ListNode1 *current  = head;
        
//         if(head == NULL) {return;}
//         if(index >= size){return;}
        
//         if(index == 0)
//         {
//             if(head->next != NULL)
//             {
//                 head->next->prev = NULL;
//             }
//             ListNode1 *temp = head;
//             head = head->next;
//             delete temp;
//         }
//         else if(index == size)
//         {
//             while(current->next != NULL)
//             {
//                 previous = current;
//                 current  = current->next;
//             }
//             previous->next = NULL;
//             delete current;
//         }
//         else
//         {
//             while(index != 0)
//             {
//                 previous = current;
//                 current  = current->next;
//                 index--;
//             }
//             if(current->next != NULL)
//             {
//                 current->next->prev = previous;
//             }
//             previous->next = current->next;
            
//             delete current;
//         }
//         size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
