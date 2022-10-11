import java.util.Arrays;

/*
This code was largely gotten from Algorithms 4th Edition
by Sedgewick and Wayne. I tried implementing it on my own,
but given I'm not a java programmer I had to look at the book's
implementation every now and then to make sure I'm getting it right.
*/

public class BinarySearch
{
    public static int rank(int key, int[] a)
    {
        int lo = 0;
        int hi = a.length - 1;
        while (lo <= hi) 
        {
            int mid = lo + (lo + hi) / 2;
            if      (a[mid] > key)   hi = mid - 1;
            else if (a[mid] < key)   lo = mid + 1;
            else return mid;
        }
        return -1;
    }
}
