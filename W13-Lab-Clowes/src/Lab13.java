
import GradeProcessing.*;

import java.io.*;
import java.util.Scanner;

/**
 * Lab13.java
 *
 * Lab13 is a runner class to test my grade processing system lab
 * this labs purpose is to validate and analyze assignment data
 *
 * @author Ian Clowes
 */
public class Lab13 {

    /**
     * main
     * runner method
     * @param args
     * @throws InvalidPointsEarnedException
     * @throws IOException
     * @throws InvalidPointsPossibleException
     */
    public static void main(String[] args) throws InvalidPointsEarnedException, IOException, InvalidPointsPossibleException {
        Scanner scanner = new Scanner(System.in);
        String filePath;

        System.out.println("Enter the path of the file you want to load");
        filePath = scanner.nextLine();

        GradeProcessor gp = new GradeProcessor(filePath);



    }
}
