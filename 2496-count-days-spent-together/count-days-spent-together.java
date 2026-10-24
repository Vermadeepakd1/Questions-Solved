import java.util.*;

class Solution {
    // Returns the latest of the two dates (Max)
    private int[] findLatestArrive(int m1, int d1, int m2, int d2) {
        if (m1 == m2) {
            if (d1 < d2) return new int[]{m2, d2};
            return new int[]{m1, d1};
        } else if (m1 < m2) return new int[]{m2, d2};
        return new int[]{m1, d1};
    }

    // Returns the earliest of the two dates (Min)
    private int[] findEarliestLeave(int m1, int d1, int m2, int d2) {
        if (m1 == m2) {
            if (d1 > d2) return new int[]{m2, d2};
            return new int[]{m1, d1};
        } else if (m1 > m2) return new int[]{m2, d2};
        return new int[]{m1, d1};
    }

    public int countDaysTogether(String aa, String la, String ab, String lb) {
        int[] days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // alice arrive
        int aam = Integer.parseInt(aa.substring(0, 2));
        int aad = Integer.parseInt(aa.substring(3, 5));

        // alice leave
        int alm = Integer.parseInt(la.substring(0, 2));
        int ald = Integer.parseInt(la.substring(3, 5));

        // bob arrive
        int bam = Integer.parseInt(ab.substring(0, 2));
        int bad = Integer.parseInt(ab.substring(3, 5));

        // bob leave
        int blm = Integer.parseInt(lb.substring(0, 2));
        int bld = Integer.parseInt(lb.substring(3, 5));

        // To find intersection, take latest arrival and earliest departure
        int[] arr = findLatestArrive(aam, aad, bam, bad);
        int[] dep = findEarliestLeave(alm, ald, blm, bld);

        if (arr[0] > dep[0]) return 0;
        else if (arr[0] == dep[0]) {
            if (arr[1] > dep[1]) return 0;
            return dep[1] - arr[1] + 1;
        } else {
            int ans = 0;
            for (int i = arr[0]; i <= dep[0]; i++) {
                if (i == arr[0])
                    ans += days[i - 1] - arr[1] + 1;
                else if (i == dep[0]) 
                    ans += dep[1];
                else 
                    ans += days[i - 1];
            }
            return ans;
        }
    }
}
