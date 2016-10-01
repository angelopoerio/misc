import java.util.ArrayList;

/*
	Print matching parenthesis of given lenght - Angelo Poerio <angelo.poerio@gmail.com>
*/

public class Parenthesis {
	
	public static void printParenthesis(String out, int open,int close) {
		if(open > close)
			return;
		if(open == close) {
			System.out.println(out);
		}

		if(open > 0) {
			printParenthesis(out + "(",open-1,close);
		}

		if(close > 0) {
			printParenthesis(out + ")",open,close-1);
		}

	}
	
	public static void main(String args[]) {
		printParenthesis("",3,3);
	}
}
