import java.util.Scanner;

/**
 * Lab14
 * runner class for lab14, which is a lab implementing the use of multithreading
 *
 * @author Ian Clowes
 */
public class Lab14 {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {

            //read file
            System.out.print("Enter full file path: ");
            String filePath = scanner.nextLine();

            //create shared queue
            WordQueue sharedQueue = new WordQueue();

            //create threads
            ProducerThread producer = new ProducerThread(filePath, sharedQueue);
            ConsumerThread consumer = new ConsumerThread(sharedQueue);

            //start threads
            producer.start();
            consumer.start();

            //wait for both threads to finish using join
            try {
                producer.join();
                consumer.join();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                System.err.println("Main thread interrupted while waiting for child threads.");
            }

            //print completed message
            System.out.println("Processing complete.");

        } catch (Exception e) {
            System.err.println("An unexpected error occurred in main: " + e.getMessage());
        }
    }
}
