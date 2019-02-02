public class Dog extends Animal{
	private static final long serialVersionUID = 1L;
	public Dog(String name, String surname, int size) {
			super(name, surname, size);
	}
	
	public String sound() {
		return "Woof!";
	}
}
