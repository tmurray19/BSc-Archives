import java.io.Serializable;

public class SerialBook1 implements Serializable{

	private static final long serialVersionUID = 1L;
	//variables initialisation
	private String title;
	private String author;
	
	//constructor
	public SerialBook1(String title, String author) {
		this.title = title;
		this.author = author;
	}
	
	//accessors
	public String getTitle() {
		return title;
	}
	public String getAuthor() {
		return author;
	}
	
	//mutators
	public void setTitle(String title) {
		this.title= title;
	}
	public void setAuthor(String author) {
		this.author = author;
	}
	
	//toString method
	public String toString() {
		return "Title: " + title + ", Author: " + author +"\n";
	}
}
