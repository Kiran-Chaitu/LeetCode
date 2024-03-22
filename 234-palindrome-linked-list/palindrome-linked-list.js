/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
    var fast = head, slow = head;
    while(fast!=null && fast.next!=null){
        slow = slow.next;
        fast = fast.next.next;
    }
    var temp = null;
    while(slow!=null){
        var nextNode = slow.next ;
        slow.next = temp;
        temp = slow;
        slow = nextNode;
    }
    while(temp!=null){
        if(temp.val != head.val) return false;
        temp = temp.next;
        head = head.next;
    }
    return true;
};