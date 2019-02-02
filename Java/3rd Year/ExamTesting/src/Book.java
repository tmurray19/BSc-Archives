import java.util.*;

public class Book {

	private String Title;
	private String Author;
	
	private ArrayList<Book> BookList = new ArrayList<Book>();
	
	public Book() {

	}
	
	public Book(String Title, String Author) {
		this.Author = Author;
		this.Title = Title;
	}
	
	public void setTitle(String Title) {
		this.Title = Title;
	}
	
	public String getTitle() {
		return this.Title;
	}
	
	public void setAuthor(String Author) {
		this.Author = Author;
	}
	
	public String getAuthor() {
		return this.Author;
	}
	
	public boolean addToList(Book b) {
		BookList.add(b);
		return true;
	}
	
	public boolean removeFromList(Book b) {
		BookList.remove(b);
		return true;
	}
	
	public String toString() {
		return "Author: " + this.getAuthor() + "\nTitle: " + this.getTitle();
	}
}
