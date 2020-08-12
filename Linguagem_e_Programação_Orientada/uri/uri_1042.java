import java.util.*;
class uri_1042{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int v[] = new int[3];
		int u[] = new int[3];
		for (int i = 0; i < v.length; i++){
			v[i] = sc.nextInt();
			u[i] = v[i];
		}
		for(int j = 0; j < v.length-1; j++){
			for(int i = 0; i < v.length-1; i++){
				if((v[i]) > (v[i+1])){
					int aux = v[i];
					v[i] = v[i+1];
					v[i+1] = aux;
				}
			}
		}
		for (int i = 0; i < v.length; i++)
			System.out.printf("%d\n", v[i]);

		System.out.printf("\n");

		for (int i = 0; i < v.length; i++)
			System.out.printf("%d\n", u[i]);
	}
}