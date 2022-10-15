import java.util.Scanner;
import java.util.ArrayList;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Collections;
import java.util.List;
import java.lang.Math;

/**
Two Sum algorithm based on its description and implementation in Algorithms, 4th Edition.
I attempted to code it myself, but on the parts where I got stuck, I looked at the book's code.

@description The algorithm reads a file and prints out the number of integer pairs in said file that add to 0.
*/
public class ThreeSumRatio
{
    /** Counts the number of pairs that add to zero in a List.
     * 
     * @param mylist ArrayList of integers, containing all of the numbers read from the txt file.
     * @return the count of pairs that add to 0.
     */
    public static double timeTrial(ArrayList<Integer> mylist)
    {
        double start = System.nanoTime();
        int cnt = ThreeSumFast.count(mylist);
        double end = System.nanoTime();
        return (end - start)/1_000_000_000;
    }

    public static ArrayList<Integer> initializeList(String filename)
    {
        Scanner in = null;
        try {
            in = new Scanner(new FileReader(filename));
        } catch (FileNotFoundException fnf) {
            System.out.println(fnf);
        }

        ArrayList<Integer> list = new ArrayList<>();
        while (in.hasNextLine())
            list.add(Integer.parseInt(in.nextLine()));
        in.close();
        return list;
    }

    public static void main(String[] args)
    {
        List<String> txts = List.of("2Kints.txt", "4Kints.txt", "8Kints.txt",
                                    "16Kints.txt", "32Kints.txt");

        double prev = timeTrial(initializeList("1Kints.txt"));
        int i = 1;
        for (String element : txts)
        {
            double time = timeTrial(initializeList(element));
            System.out.printf("%6.0f %7.1f ", Math.pow(2, i)*1000, time);
            System.out.printf("%6.1f\n", time/prev);
            prev = time;
            i++;
        }
    }
}
