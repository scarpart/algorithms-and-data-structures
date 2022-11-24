import java.util.Scanner;

public class SemesterGraph {
    
    public void main(String[] args) {
        // preparing scanner for input
        Scanner sc = new Scanner(System.in);
        
        // instantiating objects and variables
        int n = sc.nextInt();
        var graph = new Graph(n);
        int visited[] = new int[n];
        var queue = new Queue();

        // getting integers from stdin
        int from;
        while ((from = sc.nextInt()) != -1) {
            int to = sc.nextInt();
            graph.insert(from, to);
        }

        // closing scanner to avoid memory leaks
        sc.close();

        // initializing queue with neighbours of first element
        for (int val : graph.getNeighbours(1)) {
            queue.enqueue(val);
        }

        // main algorithm loop
        while (!queue.isEmpty()) {
            int current = queue.dequeue();
            visited[current-1] = 
        }




    }

}
