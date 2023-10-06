/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists = function(list1, list2) {


    if(list1===null){
        return list2;
    }
    if(list2===null){
        return list1;
    }

    let head = null;

    if(list1.val<list2.val){
        head = list1;
        list1 = list1.next;
    }else{
        head = list2;
        list2 = list2.next;
    }
    let head_backup = head;
    let h1 =list1;
    let h2 = list2;
    while(h1!==null && h2!==null){
        if(h1.val<h2.val){
            head.next = h1;
            h1 = h1.next;
        }
        else{
            head.next = h2;
            h2 = h2.next;
        }
           head = head.next;
    }
    if(h1!==null){
        head.next = h1;
    }else{
        head.next = h2;
    }

return head_backup;

};
