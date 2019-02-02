public class Cat extends Animal{
	private static final long serialVersionUID = 1L;
	public Cat(String name, String surname, int size) {
		super(name, surname, size);
	}
	
	public String sound() {
		return "Meow!";
	}
}