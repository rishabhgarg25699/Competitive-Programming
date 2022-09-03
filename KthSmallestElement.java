import java.util.HashMap;

public class KthSmallestElement {

    int getSmallest(int[] arr, int n, int k) {
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > max)
                max = arr[i];
        }
        HashMap<Integer, Integer> counter = new HashMap<>();
        int smallest = 0;
        for (int i = 0; i < n; i++) {
            if (counter.containsKey(arr[i])) {
                int temp = counter.get(arr[i]);
                temp++;
                counter.put(arr[i], temp);
            } else {
                counter.put(arr[i], 1);
            }
        }
        for (int num = 1; num <= max; num++) {
            if (counter.containsKey(num) && counter.get(num) > 0) {
                smallest += counter.get(num);
            }
            if (smallest >= k) {
                return num;
            }
        }

        return -1;
    }

    public static void main(String args[]) {
        KthSmallestElement obj = new KthSmallestElement();
        int arr[] = { 7, 1, 4, 4, 20, 15, 8 };
        int k = 5;
        System.out.println(obj.getSmallest(arr, arr.length, k));
    }

}