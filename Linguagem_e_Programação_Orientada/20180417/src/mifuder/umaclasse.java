package mifuder;

public class umaclasse {
	char a;
	public umaclasse(char x) {
		// TODO Auto-generated constructor stub
		this.a = x;
	}
	public void print_a(){
		System.out.println("a = " +a);
	}

	/*public boolean equals(umaclasse b)
	{
		return this.a == b.a;
	}*/
	
	public String toString()
	{
		return "a = '"+a+"'";
	}
}
