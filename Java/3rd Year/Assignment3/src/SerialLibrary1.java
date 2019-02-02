import java.io.Serializable;
import java.util.ArrayList;

public class SerialLibrary1 implements Serializable{
	
	private static final long serialVersionUID = 1L;
	//initialising variables
	String name;
	ArrayList<SerialBook1> bookList = new ArrayList<SerialBook1>();
	
	//constructor
	public SerialLibrary1(String name) {
		this.name = name;
	}
	
	//accesors
	public String getName() {
		return name;
	}
	
	public ArrayList<SerialBook1> getBooks(){
		return bookList;
	}
	
	
	//add & remove functions
	public void addBook(SerialBook1 tome) {
		bookList.add(tome);
	}
	
	public void removeBook(SerialBook1 tome) {
		bookList.remove(tome);
	}
	
	//toString method
	public String toString() {
		return "Name: " + name + "\n" + "Book List: " + bookList + "\n";
	}
	
}