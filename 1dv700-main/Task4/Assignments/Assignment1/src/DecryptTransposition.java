/**
 * The type Decrypt transposition.
 */
public class DecryptTransposition {
    /**
     * Decrypt transposition string.
     *
     * @param content the content
     * @param key     the key
     * @return the string
     */
    public String decryptTransposition(String content, String key) {
        Order order = new Order(key);
        int [] orderArray = order.deterMineOrder();
        int maxRow = (int) Math.ceil(((content.length() + 0.0) / (key.length() + 0.0))); //Get the correct size of the rows
        int maxColumn = key.length();
        char[][] cipher = new char[maxRow][maxColumn]; // Initialize the two dimensional array.
        int currentIndex;
        int counter = 0;

        for(int counterColumn = 0; counterColumn < maxColumn; counterColumn++) {
            currentIndex = orderArray[counterColumn]; //Get the correct index to put a row of characters into.
            for(int counterRow = 0; counterRow < maxRow; counterRow++) {
                if(content.length() <= counter) {
                    break;
                }

                cipher[counterRow][currentIndex] = content.charAt(counter++);
            }
        }

        return charToString(cipher, maxRow, maxColumn);
    }
    //Turns the two dimensional char array into a string which will be put into a text file.
    private String charToString(char[][] cipher, int maxRow, int maxColumn) {
        StringBuilder content = new StringBuilder();

        for(int counterRow = 0; counterRow < maxRow; counterRow++) {
            for(int counterColumn = 0; counterColumn < maxColumn; counterColumn++) {
                content.append(cipher[counterRow][counterColumn]);
            }
        }

        return content.toString();
    }
}
