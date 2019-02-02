import java.util.*;

public class Book {
	//Initialising variables
	private String title;
	private String author;
	private ArrayList<Book> bookList;
	
	//Constructor
	public Book() {
		title = null;
		author = null;
		bookList = new ArrayList<Book>();
	}
	
	//Getters
	public ArrayList<Book> getBookList() {
		return bookList;
	}
	
	public String getTitle() {
		return title;
	}
	
	public String getAuthor() {
		return author;
	}
	
	//Setters
	public void setBookList(ArrayList<Book> bookList) {
		this.bookList = bookList;
	}
	
	public void setTitle(String title) {
		this.title = title;
	}
	
	public void setAuthor(String author) {
		this.author = author;
	}
	
	/*Add & Remove function bookList
	public void addBook(Book tome) {
		bookList.add(tome);
	}
	
	public void removeBook(Book tome) {
		bookList.remove(tome);
	}
	*/
	
	//toString Method
	public String toString() {
		return "Title: " + title + " Author: " + author;
	}

}