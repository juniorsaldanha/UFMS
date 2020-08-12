
public class ex13 {
	public static void main(String[] args) {
		int i=1,j=1;
		externo: for (i = 1; i <= 5; i++) {
					for (j = 1; j <= 5; j++) {
						if (i+j==5) {
							break externo;
						}
					}
		}
		System.out.println(i+j);
	}
}
