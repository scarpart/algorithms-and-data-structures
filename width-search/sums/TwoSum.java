import java.util.Arrays;
import java.util.Scanner;
import java.io.File;

/*
The code below was taken from Algorithms 4th edition
by Sedgewick & Wayne. It's a wonderful book, go check it out

I'm implementing this following that good old mindset:
"I'll try to code this on my own, if I get stuck I look at the book"
*/

public class TwoSum
{
    public static int count(int[] a)
    {
        /* counts pairs that sum to 0 using
        binary search and merge sort. */
        Arrays.sort(a); // merge sort
        int n = a.length;
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (BinarySearch.rank(-a[i], a) > 1)
                cnt++;
        return cnt;
    }

    public static void main(String[] args)
    {
        File file = new File(args[0]);
        Scanner scannerLines = new Scanner(file);
        int nlines = 0;
        while (scannerLines.hasNextLine())
        {
            scannerLines.nextLine();
            nlines++;
        }
        scannerLines.close();

        int[] a = new int[nlines];
        Scanner scanner = new Scanner(file);
        int i = 0;
        while (scanner.hasNextInt())
            a[i++] = scanner.nextInt();

        System.out.println(count(a));
        scanner.close();
    }
}
