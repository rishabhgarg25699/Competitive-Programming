
 class KMP{

	public static void main(String[] args) {
		String txt = "AABAACAADAABAAABAA";
		String pat = "AABA";
		new  KMP().kmpSearch(pat, txt);
	}

	void kmpSearch(String pat,String txt) {
		int m = pat.length();
		int n = txt.length(); 
		
		int lps[] = new int[m];
		
		int j=0; // index for pat
		computeLpsArray(pat,m,lps);
		
		int i=0; // index for txt
		
		while(i<n) {
		if(pat.charAt(j)==txt.charAt(i)) {
			j++;
			i++;
		}
		if(j==m) {
			System.out.println("Found Pattern At " + (i-j));
			j=lps[j-1];
		}else if(i<n && pat.charAt(j)!= txt.charAt(i)) 
			if(j!=0)
				j=lps[j-1];
			else
				i=i+1;
		
		
		}
		
	}

	//lps --> longest proper prefix which is also suffix
	
	private void computeLpsArray(String pat, int m, int[] lps) {
			
		int len =0;
		int i=1;
		lps[0]=0;
		
		while(i<m) {
			if(pat.charAt(i)==pat.charAt(len)) {
				len++;
				lps[i]=len;
				i++;
			}else 
				if(len!=0) {
					len=lps[len-1];
				}else {
					lps[i]=len;
					i++;
				}
			
			
		}
		
	}
}
