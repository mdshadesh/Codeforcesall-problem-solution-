import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class TheLakes {
	
	static Scanner sc = new Scanner(System.in);
	
	static int a[][] = new int[1005][1005];
	
	static int n,m;
	
	static boolean visited[][] = new boolean[1005][1005];

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int t = sc.nextInt();
		
		while(t-- > 0) {
			solve();
		}
	}
	
	static class Point{
		int x,y;
		public Point(int a , int b) {
			x = a;
			y = b;
		}
	}
	
	static int dx[] = new int[] {0,0,-1,1}; 
	static int dy[] = new int[] {-1,1,0,0}; 
	
	static boolean check(Point p) {
		if(p.x <= 0 || p.x > n || p.y <= 0 || p.y > m) return false;
		else return true;
	}
	
	static int ans = 0;
	static int sum = 0;
	
	static void bfs(int s1,int s2){
		sum = 0;
		sum += a[s1][s2];
		boolean f1 = false;
		visited[s1][s2] = true;
		Queue<Point> q = new LinkedList<>();
		q.add(new Point(s1, s2));
		while(!q.isEmpty()) {
			Point curP = q.poll();
			for(int i = 0 ; i < 4 ; i++) {
				Point newP = new Point(curP.x + dx[i] , curP.y + dy[i]);
				if(check(newP) && !visited[newP.x][newP.y] && a[newP.x][newP.y] != 0) {
					q.add(newP);
					visited[newP.x][newP.y] = true;
					sum += a[newP.x][newP.y];
				}
			}
		}
		ans = Math.max(ans, sum);
	}

    static void solve() {
		// TODO Auto-generated method stub
    	n = sc.nextInt();
    	m = sc.nextInt();
    	
    	for(int i = 1 ; i <= n ; i++) {
    		for(int j = 1; j <= m ;j++) {
    			a[i][j] = 0;
    			visited[i][j] = false;
    		}
    	}
    	ans = 0;
    	
    	for(int i = 1 ; i <= n ; i++) {
    		for(int j = 1; j <= m ;j++) {
    			a[i][j] = sc.nextInt();
    		}
    	}
    	
    	for(int i = 1 ; i <= n ; i++) {
    		for(int j = 1; j <= m ;j++) {
    			if(a[i][j] != 0 && !visited[i][j]) {
    				bfs(i, j);
    			}
    		}
    	}
    	System.out.println(ans);
		
	}

}