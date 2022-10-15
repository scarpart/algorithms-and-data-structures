import java.util.Scanner;
import java.util.ArrayList;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Collections;

/**
Two Sum algorithm based on its description and implementation in Algorithms, 4th Edition.
I attempted to code it myself, but on the parts where I got stuck, I looked at the book's code.

@description The algorithm reads a file and prints out the number of integer pairs in said file that add to 0.
*/
public class ThreeSumFast
{
    /** Counts the number of pairs that add to zero in a List.
     * 
     * @param mylist ArrayList of integers, containing all of the numbers read from the txt file.
     * @return the count of pairs that add to 0.
     */
    public static int count(ArrayList<Integer> mylist)
    {
        Collections.sort(mylist);
        int n = mylist.size();
        int count = 0;
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                if (BinarySearch.search(-(mylist.get(i) + mylist.get(j)), mylist) > i)
                    count++;
        return count;
    }

    public static void main(String[] args)
    {
        Scanner in = null;
        
        try {
            in = new Scanner(new FileReader("1Mints.txt"));
        } catch (FileNotFoundException fnf) {
            System.out.println(fnf);
        } 
        
        ArrayList<Integer> list = new ArrayList<>();
        while (in.hasNextLine())
            list.add(Integer.parseInt(in.nextLine()));
        in.close();

        int count = count(list);
        System.out.printf("Result of vector sum is: %d\n", count);
    }

}
