import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Main {
	static char[][]arr;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		List<String>list=new ArrayList<>();
		for (int i = 0; i < t; i++) {
			int n=sc.nextInt();
			int[]a=new int[n];
			int[]b=new int[n+1];
			for (int j = 0; j < b.length-1; j++) 
            {
				a[j]=sc.nextInt();
			}
			for (int j = 0; j < b.length-1; j++) 
            {
				b[j]=sc.nextInt();
			}
			String anString="Yes";
			b[n]=b[0];
			for (int j = 0; j < b.length-1; j++) 
            {
				if (a[j]!=b[j]) {
					if (a[j]>b[j]) {
						anString="No";
						break;
					}else if (b[j]-b[j+1]>=2) {
						anString="No";
						break;
					}
				}
			}
			list.add(anString);
		}
		for (String strings : list) 
        {
			System.out.println(strings);
			
		}
	}
	
	
}