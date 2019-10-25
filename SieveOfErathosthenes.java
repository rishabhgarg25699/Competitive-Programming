public class SieveOfErathosthenes {

    public static void main(String[] args) {
        // Accepts a command line argument for the range
        // until while the no of primes must be counted
        int N = Integer.parseInt(args[0]);
        boolean[] primeNos = new boolean[N+1];
        // Initialising the array with true values
        for(int i=2;i<=N;i++) {
            primeNos[i] = true;
        }
        for(int i=2;i<=N/i;i++) {
            if (primeNos[i] == false) continue;
            if (isPrime(i)) {
                for (int j = 2; j * i <= N; j++) {
                    primeNos[j * i] = false;
                }
            }
        }
        int noOfPrimes = 0;
        for (boolean b : primeNos) {
            if (b) noOfPrimes++;
        }
        System.out.println(noOfPrimes);
    }

    public static boolean isPrime(int x) {
        for (int i = 2; i<=x; i++) {
            if ((x % i == 0) && (i != x)) {
                return false;
            }
        }
        return true;
    }
}