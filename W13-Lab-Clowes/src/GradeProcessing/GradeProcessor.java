package GradeProcessing;

import java.io.*;
import java.util.ArrayList;

/**
 * GradeProcessor
 * class that processes text file information and throws exceptions / validates typed errors that are not valid information
 *
 */
public class GradeProcessor {

    /**
     * Grade Processor Constructor
     * @param InputFile
     * @throws IOException
     * @throws InvalidPointsEarnedException
     * @throws InvalidPointsPossibleException
     */
    public GradeProcessor(String InputFile) throws IOException, InvalidPointsEarnedException, InvalidPointsPossibleException {
        ArrayList<Assignment> assignments = new ArrayList<Assignment>();
        File f = new File(InputFile);
        FileReader fr = new FileReader(f);
        BufferedReader br = new BufferedReader(fr);


        String line = " ";
        int index = 0;
        while ((line = br.readLine()) != null) {

            // Skip empty lines
            if (line.isEmpty()) {
                line = br.readLine();
                continue;
            }

            // Read next line (points possible)
            String pointsPossibleLine = br.readLine();
            if (pointsPossibleLine == null) {
                break;
            }

            // Read next line (points earned)
            String pointsEarnedLine = br.readLine();
            if (pointsEarnedLine == null) {
                break;
            }

            double pointsPossible = 0;
            double pointsEarned = 0;

            try {
                pointsPossible = Double.parseDouble(pointsPossibleLine);
            } catch (NumberFormatException e) {
                System.err.println("\nThere was a problem converting to double, see below for details:");
                System.err.println("For input string: " + pointsPossibleLine);
                continue;
            } // I do believe that the InvalidPointsPossibleException will be thrown when Assignment object is made, as defined in its constructor


            try {
                pointsEarned = Double.parseDouble(pointsEarnedLine.trim());
            } catch (NumberFormatException e) {
                System.out.println("\nThere was a problem converting to double, see below for details:");
                System.out.println("For input string: " + pointsEarnedLine);
                continue;
            }

            // Calculate percentage
            double percentage;
            if (pointsPossible != 0) {
                percentage = (pointsEarned / pointsPossible) * 100;
            } else {
                percentage = 0;
            }

            // Create assignment object
            Assignment a;
            try {
                a = new Assignment(index, line, pointsPossible, pointsEarned, (int) percentage);
                assignments.add(a);
                index++;
            } catch (InvalidPointsPossibleException | InvalidPointsEarnedException e) {
                System.out.println("\nYour Points are not valid, see below for details:");
                System.out.println(e.getMessage());
                continue;
            }


        }

        for (Assignment a : assignments) {
            System.out.println(a);
            System.out.println();
        }

        br.close();


    }

}

