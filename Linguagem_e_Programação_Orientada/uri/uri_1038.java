import java.util.Scanner;
class uri_1038{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double v[] = {4.0, 4.50, 5.0, 2.0, 1.50};
		int i = sc.nextInt();
		int n = sc.nextInt();
		double soma = v[i-1] * n;
		System.out.printf("Total: R$ %.2f\n", soma);
	}
}