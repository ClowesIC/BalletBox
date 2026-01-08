package Translator.Cypher;

import Translator.Translate;

/**
 * Vigenere.java
 *class that implements the Vigenere Cipher for file encrytion
 */
public class Vigenere implements CypherIF {

    @Override
    /**
     * encrypt
     * encrypt method for Vigenere Cypher
     *
     */
    public String encrypt(String str, int s) {
        String result = "";
        int x = str.length();

        for (int i = 0; i < x; i++) {
            char ch = str.charAt(i);

            if (Character.isLetter(ch)) {
                char base = Character.isUpperCase(ch) ? 'A' : 'a';
                int shift = (s + i) % 26;
                ch = (char) ((ch - base + shift) % 26 + base);
            }
            result += ch;
        }
        return result;

    }

    @Override
    /**
     * decrypt
     * Overriden decrypt method to decrypt Vigenere cipher
     * @param text, s
     */
    public String decrypt(String text, int s) { // s ignored for Vigenere
        StringBuilder result = new StringBuilder();
        int keyIndex = 0;

        for (char c : text.toCharArray()) {
            int shift = text.charAt(keyIndex % text.length()) - 'a';

            if (Character.isUpperCase(c)) {
                char ch = (char)(((c - 'A' - shift + 26) % 26) + 'A');
                result.append(ch);
                keyIndex++;
            } else if (Character.isLowerCase(c)) {
                char ch = (char)(((c - 'a' - shift + 26) % 26) + 'a');
                result.append(ch);
                keyIndex++;
            } else {
                result.append(c);
            }
        }

        return result.toString();
    }
}
