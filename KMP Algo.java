import java.util.*;
class KMP
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        String txt = sc.nextLine();
        String pat = sc.nextLine();
        KMP(pat, txt);
    }
    static int[] LPS(String pat)
    {
        int[] lps = new int[pat.length()];
        int j = 0;
        lps[0] = 0;
        for(int i = 1; i < pat.length();)
        {
            if(pat.charAt(i)==pat.charAt(j))
            {
                j++;
                lps[i] = j;
                i++;
            }
            else
            {
                if(j!=0)
                j = lps[j-1];
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    static void KMP(String pat, String txt)
    {
        int lps[] = LPS(pat);
        boolean status = false;
        int tP = 0;
        int pP = 0;
        while(tP < txt.length())
        {
            if(pat.charAt(pP)==txt.charAt(tP))
            {
                pP++;
                tP++;
            }
            if(pP==pat.length())
            {
                status = true;
                System.out.println("Pattern is found at index " + (tP - pP));
                tP++;
                pP = 0;
            }
            else if(pat.charAt(pP) != txt.charAt(tP))
            {
                status = false;
                if(pP != 0)
                pP = lps[pP-1];
                else
                tP++;
            }
        }
    }
}