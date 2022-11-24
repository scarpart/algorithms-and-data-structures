
public class Graph {
    
    private Node head = null;
    private Node created[] = null;
    
    private class Node {
        public LinkedList list = null;
        public int val;

        public Node(int val) {
            this.val = val;
        }
    }

    Graph(int n) {
        this.created = new Node[n];
    }

    public void insert(int from, int to) {
        Node pivot = null;

        if (created[from-1] == null) {
            pivot = new Node(from);
            created[from-1] = pivot;
        } else pivot = created[from-1];
        
        created[to-1] = new Node(to);
        pivot.list.insert(to);
    }   
    
    public boolean isEmpty() {
        return head == null;
    }

    public int[] getNeighbours(int val) {
        var ref = created[val-1];
        return ref.list.getAll();
    }

}
