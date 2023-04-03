import java.util.Arrays;

/**
 * The type Order.
 */
public class Order {
    private final char [] alphabetUpperCase =  {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
            'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    private final String key;
    private final int [] order;

    /**
     * Instantiates a new Order.
     *
     * @param key the key
     */
    public Order (String key) {
        this.key = key;
        this.order = new int[key.length()];
    }

    /**
     * Determine order int [ ].
     * Use the positions we have gotten and the copy that is sorted to get the order of the columns.
     * Example         LOWER
     * Positions       12 15 23 5 18
     * Sorted          5 12 15 18 23
     * Column order    3  0  1  4  2
     * So we have the order for the encryption.
     *
     * @return the int [ ]
     */
    public int [] deterMineOrder() {
        int [] orderInAlphabet = new int[key.length()];

        for(int counter = 0; counter < key.length(); counter++) {
            orderInAlphabet[counter] = checkLetterUpperCaseAlphabet(key.charAt(counter));

            if(orderInAlphabet[counter] == -1) {
                System.err.println("The key needs to be uppercase and can only be letters, try again!");
                System.exit(0);
            }
        }

        int [] orderInAlphabetCopy = Arrays.copyOf(orderInAlphabet, key.length());
        Arrays.sort(orderInAlphabetCopy);

        for(int counter2 = 0; counter2 < orderInAlphabet.length; counter2++) {
            for(int counter3 = 0; counter3 < orderInAlphabetCopy.length; counter3++) {
                if(orderInAlphabetCopy[counter2] == orderInAlphabet[counter3]) {
                    order[counter2] = counter3;
                    break;
                }
            }
        }

        return order;
    }

    private int checkLetterUpperCaseAlphabet(char currentCharacter) {
        for(int counter = 0; counter < alphabetUpperCase.length; counter++) {
            if(currentCharacter == alphabetUpperCase[counter]) {
                return counter;
            }
        }

        return -1;
    }
}
