import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Ignore;
import org.junit.Test;

public class BookJUnitTest {

	//default test
	@Ignore
	@Test
	public void test() {
		fail("Not yet implemented");
	}
	
	//set up variables
	Book b;
	
	//setup function
	@Before
	public void setUp() {
		b = new Book();
	}
	
	//teardown function
	@After
	public void tearDown() {
		b = null;
	}
	
	//test Constructor
	@Test
	public void testConstructor() {
		assertNotNull(b);
		assertEquals(null, b.getAuthor());
		assertEquals(null, b.getTitle());
	}
	
	//Test Get/Set Author
	@Test
	public void testSetGetAuthor() {
		b.setAuthor("John Doe");
		assertEquals("John Doe", b.getAuthor());
	}
	
	//Test Get/Set Title
	@Test
	public void testSetGetTitle(){
		b.setTitle("BookName");
		assertEquals("BookName", b.getTitle());
	}
	
	//Test toString
	@Test
	public void testToString() {
		b.setTitle("BookTitle");
		b.setAuthor("John Doe");
		assertEquals("Title: BookTitle Author: John Doe", b.toString());
	}
	
	//Test Add ArrayList
	@Test
	public void testAdd() {
		b.getBookList().add(b);
		assertEquals(1, b.getBookList().size());
	}
	
	//Test Remove ArrayList
	@Test
	public void testRemove() {
		b.getBookList().remove(b);
		assertEquals(0, b.getBookList().size());
	}

}
