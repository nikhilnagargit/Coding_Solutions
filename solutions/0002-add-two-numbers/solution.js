/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */

var findLength= function(l){
    let len = 0;
    while(l!=null)
    {
    l = l.next;
    len +=1;
    }  
    return len;
}

var addTwoNumbers = function(l1, l2) {

// set bigger linked list to l1
    if(findLength(l1)<findLength(l2)){
        let temp = l1;
        l1 = l2;
        l2 = temp;
    }

    let rem = 0;
    let head = l1;
    let sum = 0;
    let last = null;
// process until l1 ends
    while(l1!==null){
        if(l2!==null){
            sum = l1.val+l2.val+rem;
        }
        else{
            sum = l1.val + rem;
        }
        rem = Math.floor(sum/10);
        l1.val = sum%10;


        if(l1!==null){
        if(l1.next==null){
            last = l1;
        }
        }
                l1 = l1.next;
                        if(l2!==null){
            l2 = l2.next;
        }
    } 
    if(last!==null){
    if(rem!==0){
        last.next = new ListNode(rem,null);
    }
    }

   return head;
};
