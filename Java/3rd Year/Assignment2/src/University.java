import java.util.ArrayList;

public class University {
	private ArrayList<Venue> venues;
	private ArrayList<Modules> modules;
	private ArrayList<Programmes> programmes;
	
	//Venue subclass
	class Venue{
		//Declaring variables
		private String name;
		private int capacity;
		
		//Venue Class costructor
		public Venue(String VenName, int Amount) {
			name = VenName;
			capacity = Amount;
		}
		
		//Accessors
		public String getName(){
			return name;
		}
		
		public int getCapacity() {
			return capacity;
		}
	
		//toString method
		public String toString() {
			return "Name: " + name + "\n" + "Capacity: " + capacity;
		}
		
	}
	//Subclass end
	
	public Venue newVenue(String name, int capacity){
		return new Venue(name, capacity);
	}
	
	//Constructor
	
	public University() {
		venues = new ArrayList<Venue>();
		modules = new ArrayList<Modules>();
		programmes = new ArrayList<Programmes>();
	}
	
	//addVenues function, which adds a venue to the list venues
	public void addVenues(Venue place) {
		venues.add(place);
	}
	
	//removeVenues function, removes a venue from the venues list
	public void removeVenues(Venue place) {
		venues.remove(place);
	}
	
	//getVenues function, returns the venues list
	public ArrayList<Venue> getVenues(){
		return venues;
	}
	
	//addModules, adds a module to the modules list
	public void addModules (Modules mod) {
		modules.add(mod);
	}
	
	//removeModules, remove a module from the module list
	public void removeModules (Modules mod) {
		modules.remove(mod);
	}
	
	//getModules, returns modules list
	public ArrayList<Modules> getModules(){
		return modules;
	}
	
	//addProgrammes, adds a program to the programmes list
	public void addProgrammes(Programmes prog){
		programmes.add(prog);
	}
	
	//removeProgrammes, removes a program from the programmes list
	public void removeProgrammes(Programmes prog) {
		programmes.remove(prog);
	}
	
	//getProgrammes, returns programmes list
	public ArrayList<Programmes> getProgrammes(){
		return programmes;
	}
	
	//toString method
	public String toString() {
		return "Venues: " + getVenues() + "\n" + "Modules: " + getModules() + "\n" + "Programmes: " + getProgrammes() + "\n";
	}
}//University end
