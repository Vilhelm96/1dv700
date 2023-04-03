/**
 * The type Decrypt substitution.
 */
public class DecryptSubstitution {
    private final char [] alphabetLowerCase =  {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
                                                'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    private final char [] alphabetUpperCase =  {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
                                                'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    /**
     * Decrypt substitution string.
     *
     * @param content the content
     * @return the string
     */
    public String decryptSubstitution(String content, int key) {
        int index;
        StringBuilder cipherString = new StringBuilder();
        boolean isLetterLowerCase;

        for(int counter = 0; counter < content.length(); counter++) {
            isLetterLowerCase = Character.isLowerCase(content.charAt(counter));

            if (isLetterLowerCase) {
                index = checkLetterLowerCaseCipher(content.charAt(counter));
            } else{
                index = checkLetterUpperCaseCipher(content.charAt(counter));
            }

            if(index == -1) {
                cipherString.append(content.charAt(counter));
            }
            else {
                //Put the cipher for the character in the string.
                if(isLetterLowerCase) {
                    cipherString.append(alphabetOfCharacterLowerCase(index, key));
                }
                else {
                    cipherString.append(alphabetOfCharacterUpperCase(index, key));
                }
            }
        }

        return cipherString.toString();
    }

    private int checkLetterUpperCaseCipher(char currentCharacter)
    {
        for(int counter = 0; counter < alphabetUpperCase.length; counter++) {
            if(currentCharacter == alphabetUpperCase[counter]) {
                return counter;
            }
        }

        return -1;
    }
    private int checkLetterLowerCaseCipher(char currentCharacter)
    {
        for(int counter = 0; counter < alphabetLowerCase.length; counter++) {
            if(currentCharacter == alphabetLowerCase[counter]) {
                return counter;
            }
        }

        return -1;
    }

    //To get correct index when deciphering the method Math.floorMod was needed since there is a chance we get negative values when
    // we have index - key, with floorMod we get correct modulo even if it is negative, if it was done normally it would had resulted
    // in the negative value it had and that would had been the end.
    private char alphabetOfCharacterLowerCase(int index, int key) { return alphabetLowerCase[Math.floorMod((index - key), 26)]; }

    private char alphabetOfCharacterUpperCase(int index, int key) { return alphabetUpperCase[Math.floorMod((index - key), 26)]; }
}
