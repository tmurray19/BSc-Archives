import java.io.Serializable;

public abstract class Animal implements Serializable, Comparable<Animal>{

	//Serial UID
	private static final long serialVersionUID = 1L;
	
	
	//initialising variable
	private String FirstName;
	private String LastName;
	private int Size;
	
	
	//constructor
	public Animal(String name, String surname, int size) {
		this.FirstName = name;
		this.LastName = surname;
		this.Size = size;
	}

	
	//compareTo Function, deal with it later
	public int compareTo(Animal A) {
		return this.getFirstName().compareTo(A.getFirstName());
	}
	
	
	//accessors & mutators
	public void setFirstName(String name) {
		this.FirstName = name;
	}
	
	public String getFirstName() {
		return FirstName;
	}
	
	public void setLastName(String name) {
		this.LastName = name;
	}
	
	public String getLastName() {
		return LastName;
	}
	
	public int getSize() {
		return Size;
	}
	
	//abstract sound method
	public abstract String sound();

	//toString method
	public String toString() {
		return FirstName + " " + LastName + ", " + Size;
	}
}

