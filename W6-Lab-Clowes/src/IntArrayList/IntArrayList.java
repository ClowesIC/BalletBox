/**
 * intArrayList.java
 * package that holds IntArrayList class
 *
 * @author Ian Clowes
 */
package IntArrayList;

/**
 * IntArrayList
 * class that develops a minimal, resizable list for primitive int
 */
public class IntArrayList {

    private int[] arrayList;

    /**
     * add method that appends one or more integers to the end of the list
     * @param values
     */
    public void add(int ...values){

        if(arrayList == null){
            int[] newArray = new int[values.length];
            for(int i = 0; i < values.length; i++){
                newArray[i] = values[i];
            }
            this.arrayList = newArray;
        }
        else { //if array list size is not zero
            //allocate new array
            int[] newArray = new int[arrayList.length + values.length];

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
     * size method
     * determines size of array
     */
    public int size(){
        return (arrayList == null) ? 0 : arrayList.length;
    }

    /**
     * remove the element at the specific index if it is valid. Shift the other elements down and reduce the array size by one.
     * Invalid indices should be ignored.
     * @param index
     */
    public void remove(int index){

        if(index < 0 || index > arrayList.length - 1){
            return;
        }
        else {

            //allocate new array
            int[] newArray = new int[arrayList.length - 1];

            //copy existing elements into new array
            for (int i = 0; i < index; i++) {
                newArray[i] = arrayList[i];
            }
            //shift array
            for (int i = index; i < arrayList.length - 1; i++) {
                newArray[i] = arrayList[i + 1];
            }

            this.arrayList = newArray;
        }
    }

    /**
     * get element at specified index
     * @param index
     * @return value at index
     */
    public int get(int index){
        return arrayList[index];
    }
}
