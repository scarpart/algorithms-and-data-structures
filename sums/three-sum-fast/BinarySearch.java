import java.util.ArrayList;

public class BinarySearch
{
    public static int search(int n, ArrayList<Integer> unsorted)
    {
        int lo = 0;
        int hi = unsorted.size()-1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if      (n > unsorted.get(mid))   lo = mid + 1;
            else if (n < unsorted.get(mid))   hi = mid - 1;
            else                              return mid;
        }        
        return -1;
    }
}