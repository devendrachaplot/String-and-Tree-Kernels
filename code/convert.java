import java.io.File;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Set;
import java.util.Scanner;

public class convert {

    private static String classlist[] = new String[1024];
    private static int curr;

	public static void main(String[] args) throws Exception {
		String query;
        String data[];
        int convert;
        classlist[0] = "dummy";
        curr = 1;
		Scanner in = new Scanner(new File("./splice.data"));
        query = in.nextLine();
        while(!query.equals("")){
            // System.out.println(query);
            data = query.split(",");
            // convert = findstring(data[1]);
            // System.out.println(convert);
            // System.out.println(data[1] + " 1:" + data[0] + " 2:" + data[2].replaceAll("\\s",""));
            System.out.println(data[2].replaceAll("\\s",""));
            query = in.nextLine();
        }
    }
    
    private static int findstring(String str){
        int i=1;
        for(i=1; i<curr; i++){
            if(str.equals(classlist[i])){
                return i;
            }
        }
        classlist[i] = str;
        curr = i+1;
        return i;
    }

    private static String parse(String s) {
        char[] chars = s.toCharArray();
        StringBuilder sb = new StringBuilder();
        for(int j = 0; j < chars.length; j++) {
            if(Character.isDigit(chars[j]))
                sb.append(chars[j]);
        }
        return sb.toString();
    }
}