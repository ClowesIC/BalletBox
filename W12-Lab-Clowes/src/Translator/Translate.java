
package Translator;

import Translator.Cypher.CypherIF;
import com.sun.java.accessibility.util.Translator;

import java.io.*;

public class Translate{
    public String readFromFile(String path) {
        String text = "";
        try (DataInputStream dis = new DataInputStream(new BufferedInputStream(new FileInputStream(path)))) {
            text = dis.readUTF();
        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }
        return text;
    }
    public void writeToFile(String path, String text) {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(path))) {
            bw.write(text);
        } catch (IOException e) {
            System.out.println("Error writing file: " + e.getMessage());
        }
    }
    public void display(String original, String encrypted){
        System.out.println("Original Text: " + original);
        System.out.println("Translated Text: " + encrypted);
    }


}
