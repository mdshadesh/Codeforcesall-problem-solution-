import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) {
        System.out.println(new Solution().Solve());
    }
}
class Solution {
   static int count;
 
    public int getCount(){
        return count;
    }
public int Solve(){
    Scanner s = new Scanner(System.in);
    int n = s.nextInt(), h = s.nextInt();
    int[] arr = new int[n];
    for(int i = 0; i < n; i++){
        arr[i] = s.nextInt();
    }
 
    for (int value : arr) {
        if (value > h) {
            count += 2;
        } else count += 1;
    }
    return getCount();
}
}