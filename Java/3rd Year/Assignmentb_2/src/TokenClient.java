import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class TokenClient {
	private static final int PORT_NUMBER = 4444;
	private Socket socket;
	private InputStream inStream;
	private OutputStream outStream;
	private Scanner inStreamScanner;
	private PrintWriter outStreamPrinter;
	
	public static void main(String[] args) {
		new TokenClient().go();
	}
	
	void go() {
		try {
			System.out.println(
					"Enter commands of the form \"CONNECT IP-address\", \"SUBMIT <token>\", \"REMOVE <token>\" or \"BYE\"\n where <token> stands for an arbitrary word.");
			Scanner consoleScanner = new Scanner(System.in);
			// java.io.BufferedReader consoleInputReader = new
			// BufferedReader(new InputStreamReader(System.in));

			String command = "";

			while (!command.equals("BYE") && consoleScanner.hasNextLine()) {
				command = consoleScanner.nextLine(); // consoleInputReader.readLine();
				processCommand(command);
			}

			System.out.println("Goodbye!");
			
			consoleScanner.close();
			
		} catch (IOException e) {
			System.out.println("An exception occurred: " + e);
			e.printStackTrace();
		}

	}
	
	//This block of code reads in the command the user inputs, and runs said command
	//If an invalid command is input, then an invalid command string is thrown up
	void processCommand(String userCommand) throws IOException {
		if (userCommand.startsWith("SUBMIT"))
			sendMessageToServer(userCommand);

		else if (userCommand.startsWith("REMOVE"))
			sendMessageToServer(userCommand);

		else if (userCommand.equals("BYE"))
			closeConnectionToServer();

		else if (userCommand.startsWith("CONNECT")) {
			closeConnectionToServer();
			connectToServer(userCommand);
		} else
			System.out.println("Invalid user command: " + userCommand);
	}

	void closeConnectionToServer() {
		if (socket != null && !socket.isClosed()) {
			try {
				System.out.println("Disconnecting from server...");
				sendMessageToServer("QUIT");
				socket.close();
				System.out.println("Connection to server closed.");
			} 
			catch (IOException e) {
				System.out.println("An exception occurred: " + e);
				e.printStackTrace();
			}
		}
	}
	
	void connectToServer(String connectCommand) throws IOException {
		String ipAddress = connectCommand.substring(8).trim();
		System.out.println("Connecting to server at " + ipAddress + ", port " + PORT_NUMBER + "...");
		socket = new Socket(ipAddress, PORT_NUMBER);
		inStream = socket.getInputStream();
		outStream = socket.getOutputStream();
		inStreamScanner = new Scanner(inStream);
		outStreamPrinter = new PrintWriter(outStream);
		System.out.println("Connected to server.");
	}

	void sendMessageToServer(String command) {
		System.out.println("Sending message to server: " + command + "...");
		if (socket == null || socket.isClosed())
			System.out.println("Not possible - not connected to a server");
		else {
			outStreamPrinter.println(command); // send the message to the server
			//To replace with 'OK'
			System.out.println("Message \"" + command + "\" Sent.");
			outStreamPrinter.flush(); // do so immediately
			
			// Receive response from server:
			if (!command.equals("BYE") && inStreamScanner.hasNextLine()) {
				String response = inStreamScanner.nextLine();
				System.out.println("Response from server: " + response);
			}
		}
	}
}