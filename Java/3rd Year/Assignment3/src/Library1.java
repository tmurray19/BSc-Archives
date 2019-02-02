import java.util.ArrayList;

public class Library1 {
	//initialising variables
	String name;
	ArrayList<Book1> bookList = new ArrayList<Book1>();
	
	//constructor
	public Library1(String name) {
		this.name = name;
	}
	
	//accesors
	public String getName() {
		return name;
	}
	
	public ArrayList<Book1> getBooks(){
		return bookList;
	}
	
	
	//add & remove functions
	public void addBook(Book1 tome) {
		bookList.add(tome);
	}
	
	public void removeBook(Book1 tome) {
		bookList.remove(tome);
	}
	
	//toString method
	public String toString() {
		return "Name: " + name + "\n" + "Book List: " + bookList + "\n";
	}
	
}
