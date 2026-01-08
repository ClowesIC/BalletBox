package CustomArrayList;

/**
 * CustomArrayList.java
 * class used to create an Array List that uses generics
 * @author Ian Clowes
 * @param <E>
 */
public class CustomArrayList<E> {
    private Object[] arrayList;

    /**
     * CustomArrayList
     * Constructor
     */
    public CustomArrayList() {
        arrayList = new Object[0];
    }

    /**
     * add
     * method that adds elements to array
     * @param values
     */
    public void add(E... values) {
        if(arrayList == null){
            Object[] newArray = new Object[values.length];
            for(int i = 0; i < values.length; i++){
                newArray[i] = values[i];
            }
            this.arrayList = newArray;
        }
        else { //if array list size is not zero
            //allocate new array
            Object[] newArray = new Object[arrayList.length + values.length];

            //copy existing elements into new array
            for (int i = 0; i < arrayList.length; i++) {
                newArray[i] = arrayList[i];
            }

            //copy incoming values to tail of array
            for(int i = 0; i < values.length; i++){
                newArray[arrayList.length + i] = values[i];
            }
            this.arrayList = newArray;
        }
    }

    /**
     * remove
     * method that should remove items from array
     * @param index
     */
    public void remove(int index) throws IndexOutOfBoundsException{
        if (index < 0 || index >= arrayList.length) {
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size());
        }

        Object[] newArray = new Object[arrayList.length -1];

        // Copy elements before the index
        for (int i = 0; i < index; i++) {
            newArray[i] = arrayList[i];
        }

        // Copy elements after the index (shift left)
        for (int i = index; i < newArray.length; i++) {
            newArray[i] = arrayList[i + 1];
        }

        arrayList = newArray;

    }

    /**
     * get
     * method that retrieves the element at a given index
     * @param index
     * @return
     * @throws IndexOutOfBoundsException
     */
    public E get(int index) throws IndexOutOfBoundsException {
        if (index < 0 || index >= arrayList.length) {
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size());
        }
        return (E) arrayList[index];
    }
    /**
     * size
     * returns size of current number of elements stored in list
     * @return
     */
    public int size(){
        return arrayList.length;
    }

}
