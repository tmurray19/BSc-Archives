import java.io.*;
import java.util.List;

public class SerialDriverClass {
	public static void main(String[] args) {
		
		//intialising variables
		SerialLibrary1 library = new SerialLibrary1("Local Library");
		SerialBook1 bookA = new SerialBook1("Book A", "Bookie Masterson");
		SerialBook1 bookB = new SerialBook1("Book B", "Bookenstein Bear");
		SerialBook1 bookC = new SerialBook1("Book C", "Stupid Name");
		
		
		//Adding book instances to library instance ArrayList
		library.addBook(bookA);
		library.addBook(bookB);
		library.addBook(bookC);
		
		
		//calling the functions below
		writeToFile(library.bookList);
		readFromFile(library.bookList);
		serialise(library.bookList);
		deserialise(library.bookList);
		
	}
    public static void serialise(List<SerialBook1> list){
    	System.out.println("Serialising... \n");
        try {
        	// create a connection stream (to write bytes) 
        	FileOutputStream fileStream = new FileOutputStream("LibraryBookList.dat");
            // create a chain stream (turns objects into data that can be written to a stream)
        	ObjectOutputStream os = new ObjectOutputStream(fileStream);
        	// call writeObject() on the Object stream
        	os.writeObject(list);
			
        	os.close();
	}catch (Exception e) {
	    e.printStackTrace();
		}
			
    }
	
	@SuppressWarnings("unchecked")
	
    public static void deserialise(List<SerialBook1> list){
	System.out.println("Deserialising... \n");
	try{	
	    FileInputStream fileStream = new FileInputStream("LibraryBookList.dat");
	
	    ObjectInputStream os = new ObjectInputStream(fileStream);
			
	    List<SerialBook1> emp = (List<SerialBook1>)os.readObject();
			    
		for (SerialBook1 element:emp){
		    System.out.println(element.toString());	
		}
		os.close();
			
	} catch (Exception e) {
		e.printStackTrace();
	}
		
    }  // end deserialise method
	
		
	public static void writeToFile(List<SerialBook1> list) {
		//writes the content of the bookList to the LibraryBookList.txt file
		System.out.println("Printing to file... \n");
		try {
			FileWriter fileWriter = new FileWriter("LibraryBookList.txt");
			BufferedWriter writer = new BufferedWriter(fileWriter);
			
			writer.write("Library Book List: \n");
			
			//writes each elemet of list into the file
			for(SerialBook1 element:list) {
				writer.write("Book Name: " + element.getTitle() + "\n");
				writer.write("Author Name: " + element.getAuthor() + "\n");
			}
			
			
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println("Done.");

		
	}
	
	public static void readFromFile(List<SerialBook1> list) {
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





