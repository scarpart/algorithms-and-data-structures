

public class Queue {
    
    private class Node {
        public int val;
        public Node next = null;

        Node(int val) {
            this.val = val;
        }
    }

    private Node head = null;

    public void enqueue(int val) {
        var pivot = new Node(val);
        if (isEmpty()) {
            head = pivot;
        } else {
            pivot.next = head.next;
            head.next = pivot;
            head = head.next;
        }
    }

    public int dequeue() {
        var pivot = head.next;
        head.next = pivot.next;
        return pivot.val;
    }

    public boolean isEmpty() {
        return head == null;
    }

}
