import java.util.Scanner;
public class ex08 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x;
		while((x = sc.nextInt()) != -1){
			for(int i = 0; i < 10; ++i){
				System.out.println(x + "*" + i + "=" + (x*i));
			}
		}
		sc.close();
	}
}
