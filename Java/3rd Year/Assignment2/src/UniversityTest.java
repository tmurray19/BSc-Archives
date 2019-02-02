import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Ignore;
import org.junit.Test;

public class UniversityTest {

	//variable setup
	University u;
	Modules m;
	Programmes p;
	University.Venue v;
	
	@Ignore
	@Test
	public void test() {
		fail("Not yet implemented");
	}

	//Before
	@Before
	public void setUp() {
		u = new University();
		m = new Modules("OOP", "CT3535");
		p = new Programmes("Bachelor of Science", "GY301");
		v = u.newVenue("Theatre", 50);
	}
	
	//Constructor and accessors test
	@Test
	public void testConstructor() {
		assertNotNull(u);
		assertEquals(0, u.getModules().size());
		assertEquals(0, u.getVenues().size());
		assertEquals(0, u.getProgrammes().size());
	}
	
	@Test
	public void testVenues() {
		//testing add function
		u.addVenues(v);
		assertEquals(1, u.getVenues().size());
		
		//testing accessors
		assertEquals("Theatre", v.getName());
		assertEquals(50, v.getCapacity());
		
		//testing remove function
		u.removeVenues(v);
		assertEquals(0, u.getVenues().size());
	}
	
	@Test
	public void testModules(){
		//testing addfunction
		u.addModules(m);
		assertEquals(1, u.getModules().size());
		
		//testing accessors
		assertEquals("OOP", m.getName());
		assertEquals("CT3535", m.getCode());
		
		//testing remove function
		u.removeModules(m);
		assertEquals(0, u.getModules().size());
	}
	@Test
	public void testProgrammes() {
		u.addProgrammes(p);
		assertEquals(1, u.getProgrammes().size());
		
		//testing accessors
		assertEquals("Bachelor of Science", p.getTitle());
		assertEquals("GY301" ,p.getCode());
		
		//testing remove function
		u.removeProgrammes(p);
		assertEquals(0, u.getProgrammes().size());
	}
	
	//ToString Test
	@Test
	public void testToString(){
		assertEquals(u.toString(), "Venues: " + "[]" + "\n" + "Modules: " +  "[]" + "\n" + "Programmes: " + "[]" + "\n");
	}
	//After
	@After
	public void tearDown() {
		u = null;
		m = null;
		p = null;
		v = null;
	}
	

}
