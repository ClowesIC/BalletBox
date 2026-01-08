package Translator.Cypher;

import Translator.Translate;

/**
 * Ceasar Cypher Class
 * Cypher that encrypts a string using Ceasar Cypher technique (using a shift from char value).
 * @author Ian Clowes
 */
public class Caesar extends Translate implements CypherIF{

    /**
     * Caesar
     * used to pass Caesar encryption
     */
    public Caesar(){
            //no argument constructor
        }

        @Override
        /**
         * encrypt
         * Encrypt method that implements the Ceasar Cipher
         * method derived from resources given at https://www.geeksforgeeks.org/ethical-hacking/caesar-cipher-in-cryptography/
         * @param text,s
         * @return encrypted String
         */
        public String encrypt(String text, int s)
        {
            StringBuffer result = new StringBuffer();

            for (int i=0; i<text.length(); i++)
            {
                if (Character.isUpperCase(text.charAt(i)))
                {
                    char ch = (char)(((int)text.charAt(i) +
                            s - 65) % 26 + 65);
                    result.append(ch);
                }
                else
                {
                    char ch = (char)(((int)text.charAt(i) +
                            s - 97) % 26 + 97);
                    result.append(ch);
                }
            }
            return result.toString();
        }

        @Override
        /**
         * decrypt
         * decrypt method for Caesar cipher
         */
    public String decrypt(String text, int s) {
        StringBuffer result = new StringBuffer();

        for (int i = 0; i < text.length(); i++) {
            char c = text.charAt(i);

            if (Character.isUpperCase(c)) {
                // Shift backwards and wrap around
                char ch = (char)(((c - 65 - s + 26) % 26) + 65);
                result.append(ch);
            } else if (Character.isLowerCase(c)) {
                char ch = (char)(((c - 97 - s + 26) % 26) + 97);
                result.append(ch);
            } else {
                // Keep non-alphabetic characters unchanged
                result.append(c);
            }
        }

        return result.toString();
    }


}

