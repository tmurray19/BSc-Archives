import static org.junit.Assert.*;

import org.junit.*;


public class BookJUnitTest {

	@Ignore
	@Test
	public void test() {
		fail("Not yet implemented");
	}
	
	Book b;
	
	
	@Before
	public void SetUp() {
		b = new Book();
	}
	
	@Test
	public void testConstructor() {
		assertNotNull(b);
		assertEquals(null, b.getTitle());
		assertEquals(null, b.getAuthor());
	}
	
	@Test
	public void testToString() {
		assertNotNull(b);
		assertEquals("Author: null\nTitle: null", b.toString());
	}
	
	@Test
	public void testAdd() {
		assertNotNull(b);
		assertEquals(true, b.addToList(b));
	}
	
	@Test
	public void testRemove() {
		assertNotNull(b);
		assertEquals(true,b.removeFromList(b));
	}
	
	@After
	public void TearDown() {
		b = null;
	}

}
