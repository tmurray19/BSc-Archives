import java.io.*;
import java.util.List;

public class DriverClass {
	public static void main(String[] args) {
		
		//intialising variables
		Library1 library = new Library1("Local Library");
		Book1 bookA = new Book1("Book A", "Bookie Masterson");
		Book1 bookB = new Book1("Book B", "Bookenstein Bear");
		Book1 bookC = new Book1("Book C", "Stupid Name");
		
		
		//Adding book instances to library instance ArrayList
		library.addBook(bookA);
		library.addBook(bookB);
		library.addBook(bookC);
		
		
		//calling the functions below
		writeToFile(library.bookList);
		readFromFile(library.bookList);
		
	}
		
	public static void writeToFile(List<Book1> list) {
		//writes the content of the bookList to the LibraryBookList.txt file
		System.out.println("Printing to file...\n");
		try {
			FileWriter fileWriter = new FileWriter("LibraryBookList.txt");
			BufferedWriter writer = new BufferedWriter(fileWriter);
			
			writer.write("Library Book List: \n");
			
			//writes each elemet of list into the file
			for(Book1 element:list) {
				writer.write("Book Name: " + element.getTitle() + "\n");
				writer.write("Author Name: " + element.getAuthor() + "\n");
			}
			
			
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println("Done.");
	}
	
	public static void readFromFile(List<Book1> list) {
		//reads out the content of the .txt file
		System.out.println("Reading from file: \n");
		try {
			    File bookListFile = new File("LibraryBookList.txt");
					
			    FileReader fileReader = new FileReader(bookListFile);
					
			    BufferedReader reader = new BufferedReader(fileReader);
					
			    String line = null;
					
			    while ((line = reader.readLine()) != null){
				System.out.println(line);
			    }
					
			    reader.close();
					
			
		}catch (IOException e) {
			e.printStackTrace();
		}
		
	}
	
}

