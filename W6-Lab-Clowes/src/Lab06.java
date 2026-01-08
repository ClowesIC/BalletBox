import IntArrayList.IntArrayList;

/**
 * Lab06.java
 * The Lab06 class serves as the driver for this lab assignment.
 * You are responsible for implementing the IntArrayList class
 * and defining its add, size, and get methods.
 *
 * @author Professor Lanham
 */
public class Lab06
{
    /**
     * The main entry point for program execution.
     * @param args Command-line arguments (not used in this lab).
     */
    public static void main(String[] args)
    {
        // Instantiate our IntArrayList object
        IntArrayList intArrayList = new IntArrayList();

        // Add numbers to the IntArrayList using variable-length arguments (varargs).
        intArrayList.add(1);
        intArrayList.add(2, 3);
        intArrayList.add(4, 5, 6);
        intArrayList.add(7, 8, 9, 10);

        // Display the IntArrayList
        print(intArrayList);
        System.out.println();

        // Testing of the remove method for the IntArrayList.
        intArrayList.remove(0);
        intArrayList.remove(-5);
        intArrayList.remove(100);
        intArrayList.remove(5);

        // Display the IntArrayList
        print(intArrayList);
        System.out.println();
    }

    /**
     * The print method is a private helper method to display the IntArrayList to the user.
     * @param intArrayList the IntArrayList we wish to display.
     */
    private static void print(IntArrayList intArrayList)
    {
        // Iterate over the IntArrayList and display its contents.
        for (int i = 0; i < intArrayList.size(); i++)
        {
            // Retrieve each element from the IntArrayList.
            System.out.print(intArrayList.get(i));

            // Append a comma unless this is the last element.
            if ((i + 1) != intArrayList.size())
            {
                System.out.print(", ");
            }
        }
    }
}
