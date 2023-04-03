/**
 * The type Encrypt substitution.
 */
public class EncryptSubstitution {
    private final char [] alphabetLowerCase =  {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
                                                'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    private final char [] alphabetUpperCase =  {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
                                                'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    /**
     * Encrypt substitution string.
     *
     * @param content the content
     * @return the string
     */
    public String encryptSubstitution(String content, int key)
    {
        int index;
        StringBuilder cipherString = new StringBuilder();
        boolean isLetterLowerCase;

        for(int counter = 0; counter < content.length(); counter++) {
            isLetterLowerCase = Character.isLowerCase(content.charAt(counter));

            if (isLetterLowerCase) {
                index = checkLetterLowerCaseAlphabet(content.charAt(counter));
            } else{
                index = checkLetterUpperCaseAlphabet(content.charAt(counter));
            }

            if(index  < 0) {
                cipherString.append(content.charAt(counter));
            }
            else{
                if(isLetterLowerCase) {
                    cipherString.append(cipherOfCharacterLowerCase(index, key));
                }
                else {
                    cipherString.append(cipherOfCharacterUpperCase(index, key));
                }
            }
        }

        return cipherString.toString();
    }
    //Checks in what index the character is in the upper case alphabet array.
    private int checkLetterUpperCaseAlphabet(char currentCharacter)
    {
        for(int counter = 0; counter < alphabetUpperCase.length; counter++) {
            if(currentCharacter == alphabetUpperCase[counter]) {
                return counter;
            }
        }

        return -1;
    }
    //Checks in what index the character is in the lower case alphabet array.
    private int checkLetterLowerCaseAlphabet(char currentCharacter)
    {
        for(int counter = 0; counter < alphabetLowerCase.length; counter++) {
            if(currentCharacter == alphabetLowerCase[counter]) {
                return counter;
            }
        }

        return -1;
    }
    //Get the cipher for upper and lower case using index = letter + key mod 26.
    private char cipherOfCharacterUpperCase(int index, int key) { return alphabetUpperCase[(index + key) % 26]; }
    private char cipherOfCharacterLowerCase(int index, int key) { return alphabetLowerCase[(index + key) % 26]; }
}
