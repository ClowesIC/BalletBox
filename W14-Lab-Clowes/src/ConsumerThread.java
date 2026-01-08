import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

/**
 * ConsumerThread.java
 * Thread that removes words from the buffer, tallies their frequencies, and reports summary stats
 *
 * @author Ian Clowes
 */
public class ConsumerThread extends Thread{
    public WordQueue queue;
    public HashMap<String,Integer> wordCount;

    /**
     * Consumer Thread
     * constructor
     * @param queue
     */
    public ConsumerThread(WordQueue queue){
        this.queue = queue;
        this.wordCount = new HashMap<String,Integer>();
    }

    /**
     * run
     * the run method for the ConsumerThread
     */
    @Override
    public void run(){
        try{
            String word;
            while((word = queue.dequeue()) != null){
                wordCount.merge(word, 1, Integer::sum);
            }
            //report stats
            reportStatistics();
        } catch (InterruptedException e) {
            System.err.println("Consumer Interrupted: " + e.getMessage());
            Thread.currentThread().interrupt();
        }
    }

    /**
     * reportStatistics
     * method that calculates and displays specific stats regarding the text file
     */
    private void reportStatistics() {
        //Total Distinct Words
        System.out.println("Total unique words: " + wordCount.size());

        //most frequent word
        // Find the entry with the maximum value (frequency)
        Map.Entry<String, Integer> mostFrequent = //Gemini AI was used to help me with this part of the code as I am unfamiliar with this part of java.util library
                Collections.max(wordCount.entrySet(), Comparator.comparingInt(Map.Entry::getValue));

        if (mostFrequent != null) {
            String word = mostFrequent.getKey();
            int count = mostFrequent.getValue();
            System.out.println("Most frequent word: \"" + word + "\" (" + count + " occurrences)");
        } else {
            System.out.println("No words were processed.");
        }
    }
}
