class ListNode(object):

    def __init__(self,x):

        self.val = x
        self.next = None

    def printListNode(self):
        ret = str(self.val)
        node = self.next
        while node:
            ret += ("->" + str(node.val))
            node = node.next

        print ret

class Solution(object):

    def addTwoNumbers(self, l1,l2):
        ret = ListNode(-1)
        tmp = ret
        ten_flag = 0
        while l1 or l2:
            num1 = l1.val if None != l1 else 0 #(None != l1 ? l1.val : 0)
            num2 = l2.val if None != l2 else 0 #(None != l2 ? l2.val : 0)
            tmp_sum = num1 + num2 + ten_flag

            if -1 == ret.val:
                tmp = ret
            else:
                tmp.next = ListNode(-1)
                tmp = tmp.next

            tmp.val = tmp_sum % 10
            ten_flag = 1 if (tmp_sum >= 10) else 0# ? 1 : 0)

            l1 = l1.next if None != l1 else None #(None != l1 ? l1.next : None)
            l2 = l2.next if None != l2 else None #(None != l2 ? l2.next : None)

        if ten_flag:
            tmp.nex = printListNode(ten_flag)

        return ret

if __name__ == "__main__":
    l1 = ListNode(2)
    l1.next = ListNode(4)
    l1.next.next = ListNode(3)
    l2 = ListNode(5)
    l2.next = ListNode(6)
    l2.next.next = ListNode(4)
    Solution().addTwoNumbers(l1,l2).printListNode()
