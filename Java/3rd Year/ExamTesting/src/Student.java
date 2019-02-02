
public class Student {

	private String name;
	private long ID;
	
	public Student(String name, long ID) {
		this.name = name;
		this.ID = ID;
	}

	public String getName() {
		return this.name;
	}
	
	public long getID() {
		return this.ID;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public void setID(long ID) {
		this.ID = ID;
	}
	
	public String toString() {
		return "Name: " + this.name +  "\nID: " + this.ID;
	}
	
	public int compareTo(Student s) {
		if(this.getName().length()<s.getName().length()) {
			return -1;
		}
		else if(this.getName().length()>s.getName().length()){
			return 1;
		}
		else {
			return 0;
		}
	}
}
