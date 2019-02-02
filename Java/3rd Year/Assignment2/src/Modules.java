
public class Modules{
	//Variables
	private String name;
	private String code;
	
	//Constructor
	public Modules(String ModName, String ModCode) {
		name = ModName;
		code = ModCode;
	}
	
	//Accessors
	public String getName() {
		return name;
	}
	
	public String getCode() {
		return code;
	}
	
	//toString method
	public String toString() {
		return "Name: " + name + "\n" + "Code: " + code;
	}
}
