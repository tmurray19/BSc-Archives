
public class Programmes {
	//Initialising variables	
	private String title;
	private String code;
	
	//constructor
	public Programmes(String ProgName, String ProgCode) {
		title = ProgName;
		code = ProgCode;
	}
	
	//Accesors
	public String getTitle() {
		return title;
	}

	public String getCode() {
		return code;
	}
	
	//toString method
	public String toString() {
		return "Title: " + title + "\n" + "Code: " + code;
	}
}
