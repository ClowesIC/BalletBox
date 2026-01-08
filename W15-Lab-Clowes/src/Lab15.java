import CustomArrayList.CustomArrayList;

/**
 * Lab15
 * Runner class to test generics class (CustomArrayList.java_
 * @author Ian Clowes
 */
public class Lab15 {
    public static <T> void main(String[]args){
        CustomArrayList<T> customArrayList = new CustomArrayList<T>();

        //add stuff to array
        customArrayList.add((T) "Hello");
        customArrayList.add((T) "World");
        customArrayList.add((T) "!");
        customArrayList.add((T) "Nice");
        customArrayList.add((T) "to");
        customArrayList.add((T) "meet");
        customArrayList.add((T) "you");
        customArrayList.add((T) "!");
        customArrayList.add((T) "good");
        customArrayList.add((T) "luck!");

        //display array
        print(customArrayList);
        System.out.println();

        // Remove elements (some indices invalid)
        int[] indicesToRemove = {0, -5, 100, 5,};
        for (int index : indicesToRemove) { //AI was used to help me with this for loop, however, the try and catch block I use for my exceptions in CustomArrayList
            try {
                customArrayList.remove(index);
            } catch (IndexOutOfBoundsException e) {
                System.out.println(e.getMessage());
            }
        }

        //display new arraylist
        print(customArrayList);
        System.out.println();

    }

    /**
     * print
     * method that prints CustomArrayList with commas
     * @param customArrayList
     */
    private static void print(CustomArrayList customArrayList)
    {
        // Iterate over the IntArrayList and display its contents.
        for (int i = 0; i < customArrayList.size(); i++)
        {
            // Retrieve each element from the IntArrayList.
            System.out.print(customArrayList.get(i));

            // Append a comma unless this is the last element.
            if ((i + 1) != customArrayList.size())
            {
                System.out.print(", ");
            }
        }
    }
}

