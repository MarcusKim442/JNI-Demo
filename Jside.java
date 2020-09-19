public class Jside {
	
	private String line = "DemoChars";
	private char[] chars;
	
	static {
		//Load Demo.dll file from folder)
        System.loadLibrary("Demo");
    }
	
	private void start() {
		//Strings are not compatible with C, must convert to character array
		chars = strConvert(line);
		
		//Return ASCII values into array, values[]
		int[] values = cFunctionName(chars);
		
		//Print results
		System.out.println("ASCII values from C, printed from Java:");
		int i=0;
		while (i<values.length) {
			System.out.println(values[i]);
			i++;
		}
	}

	//This is the C JNI function
    public native int[] cFunctionName(char[] mapdata);

    public static void main(String[] args) {
        new Jside().start();
    }
	
	//String > Char function
	private char[] strConvert(String line) {
		char[] chars = new char[line.length()];
		for (int i = 0; i < line.length(); i++) {
			chars[i] = line.charAt(i);
		}
		return chars;
	}
}