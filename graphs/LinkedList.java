
public class LinkedList {

    /**
     * @apiNote this LinkedList does not support
     * removal operations as it's not required for the 
     * given exercise. 
     */

    private Node head = null;
    private Node tail = null; 
    private int size = 0;

    private class Node {       
        public int val;
        public Node next = null;
        
        public Node(int val) {
            this.val = val;
        }
    }

    public void insert(int val) {
        var node = new Node(val);
        if (isEmpty()) {
            head = node;
            tail = head;
        } else {
            tail.next = node;
            tail = tail.next;
        }
        size++;
    }

    public void print() {
        for (Node pivot = head; pivot != tail; pivot = pivot.next) 
            System.out.printf("%d ", pivot.val);
        System.out.println(tail.val);
    }

    public boolean isEmpty() {
        return head == null;
    }

    public int[] getAll() {
        int i = 0;
        int all[] = new int[size];
        
        for (Node pivot = head; pivot != tail; pivot = pivot.next) 
            all[i++] = pivot.val;
        all[i] = tail.val;

        return all;
    }

}