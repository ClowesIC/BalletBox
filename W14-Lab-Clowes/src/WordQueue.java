import java.util.LinkedList;

/**
 * WordQueue.java
 *
 * class that implements a shared queue
 * @author Ian Clowes
 */
public class WordQueue {
    private int bufferSize = 10;
    public LinkedList<String> queue;
    private boolean done = false;

    /**
     * wordQueue
     * constructor
     */
    public WordQueue(){
        queue = new LinkedList<String>();
    }

    /**
     * enqueue
     * adds elements to queue
     * @param s
     * @throws InterruptedException
     */
    synchronized void enqueue(String s) throws InterruptedException {
        while (queue.size() == bufferSize) {
            wait();
        }
        // Add the single word
        queue.addLast(s);

        // Notify other threads (Consumer)
        notifyAll();
    }

    /**
     * dequeue
     * removes elements from dequeue
     * @return
     * @throws InterruptedException
     */
    synchronized String dequeue() throws InterruptedException {
        while (queue.isEmpty() && !done) {
            wait();
        }
        if (queue.isEmpty() && done) {
            // Wake up any other consumers that might be waiting (important for multiple consumers)
            notifyAll();
            return null;
        }
        String word = queue.removeFirst();
        notifyAll();
        return word;
    }

    /**
     * markDone
     * marks whether a thread is complete.
     * @return boolean
     */
    synchronized boolean markDone(){
        done = true;
        notifyAll();
        return done;

    }

}
