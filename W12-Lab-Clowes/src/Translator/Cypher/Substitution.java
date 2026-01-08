package Translator.Cypher;

import Translator.Translate;

public class Substitution extends Translate implements CypherIF {

    /**
     * Substitution
     * used to pass substitution encryption
     */
    public Substitution(){
        //no arg constructor
    }
    @Override
    /**
     * Encrypts text using a shift (like Caesar)
     * @param text the plaintext
     * @param shift the number of letters to shift
     * @return encrypted string
     */
    public String encrypt(String text, int shift) {
        StringBuilder result = new StringBuilder();

        for (char c : text.toCharArray()) {
            if (Character.isUpperCase(c)) {
                char ch = (char)(((c - 'A' + shift) % 26) + 'A');
                result.append(ch);
            } else if (Character.isLowerCase(c)) {
                char ch = (char)(((c - 'a' + shift) % 26) + 'a');
                result.append(ch);
            } else {
                result.append(c);
            }
        }
        return result.toString();
    }

    @Override
    /**
     * Decrypts text using a shift (like Caesar)
     * @param text the ciphertext
     * @param shift the number of letters to shift
     * @return decrypted string
     */
    public String decrypt(String text, int shift) {
        StringBuilder result = new StringBuilder();

        for (char c : text.toCharArray()) {
            if (Character.isUpperCase(c)) {
                char ch = (char)(((c - 'A' - shift + 26) % 26) + 'A');
                result.append(ch);
            } else if (Character.isLowerCase(c)) {
                char ch = (char)(((c - 'a' - shift + 26) % 26) + 'a');
                result.append(ch);
            } else {
                result.append(c);
            }
        }
        return result.toString();
    }
}
