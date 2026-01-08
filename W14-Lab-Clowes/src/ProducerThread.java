import java.io.*;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;


/**
 * ProducerThread.java
 * class that creates a thread that's purpose is to read text from a file, extract normalized words, and place them into a shared synchronized buffer
 *
 * @author Ian Clowes
 */
public class ProducerThread extends Thread {
    public String file;
    public String[] words;
    public WordQueue queue;

    public ProducerThread(String file, WordQueue queue) {
        this.file = file;
        this.queue = queue;
    }

    /**
     * run
     * run Thread method for Producer Thread
     */
    @Override
    public void run(){
        //thread first reads file
        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
            String line;
            while ((line = reader.readLine()) != null) { //reads through all words
                line = line.replaceAll("[^a-zA-Z0-9 ]", " ").toLowerCase(); //normalize text
                words = line.split("\\s+");
                //enqueue word into shared queue
                for (String word : words) {
                    if (!word.isEmpty()) {
                        queue.enqueue(word);
                    }
                }
            }


        } catch (IOException | InterruptedException e) {
            System.err.println("Error reading file: " + e.getMessage());
        }

        queue.markDone();




    }
}
