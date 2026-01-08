import Translator.Cypher.Caesar;
import Translator.Cypher.Substitution;
import Translator.Cypher.Vigenere;
import Translator.Translate;
import Translator.Cypher.CypherIF;
import java.util.Scanner;

public class Lab12 {
    public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);

            // Input file
            System.out.println("Please enter your input file path:");
            String inputPath = sc.nextLine();

            // Output file
            System.out.println("\nPlease enter your output file path:");
            String outputPath = sc.nextLine();

            // Cipher selection
            System.out.println("Please select the cypher you would like to use:");
            System.out.println("1. Caesar Cypher");
            System.out.println("2. Substitution Cypher");
            System.out.println("3. Vigenere Cypher");
            int choice = sc.nextInt();
            sc.nextLine(); // consume newline

            CypherIF cipher = null;
            int shift = 0;

            // Create cipher based on choice
            switch (choice) {
                case 1:
                    System.out.print("\nPlease enter the shift: ");
                    shift = sc.nextInt();
                    sc.nextLine();
                    cipher = new Caesar();
                    break;

                case 2:
                    System.out.print("\nPlease enter the shift: ");
                    shift = sc.nextInt();
                    sc.nextLine();
                    cipher = new Substitution();
                    break;

                case 3:
                    cipher = new Vigenere();
                    break;

                default:
                    System.out.println("Invalid choice. Exiting...");
                    System.exit(0);
            }

            // Use Translate to read file
            Translate translator = new Translate();
            String originalText = translator.readFromFile(inputPath);

            // Display initial text
            System.out.println("\nInitial Text:");
            System.out.println(originalText);


            String encryptedText = cipher.encrypt(originalText, shift);


            // Display translated text
            System.out.println("\nTranslated Text:");
            System.out.println(encryptedText);

            // Write to output file
            translator.writeToFile(outputPath, encryptedText);

            sc.close();
        }

}
