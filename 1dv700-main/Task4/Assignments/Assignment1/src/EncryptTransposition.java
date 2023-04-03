/**
 * The type Encrypt transposition.
 */
public class EncryptTransposition {
    /**
     * Encrypt transposition string.
     *
     * @param content the content
     * @param key     the key
     * @return the string
     */
    public String encryptTransposition (String content, String key) {
        Order order = new Order(key);
        int maxRow = (int) Math.ceil(((content.length() + 0.0) / (key.length() + 0.0))); // Get amount of rows
        int maxColumn = key.length(); //Get column the same size of the key
        int[] orderArray = new int [key.length()];
        int counter = 0;
        char[][] cipher = new char[maxRow][maxColumn]; // Initialize cipher
        orderArray = order.deterMineOrder(); // Get order for the key

        for(int counterRow = 0; counterRow < maxRow; counterRow++) {
            for(int counterColumn = 0; counterColumn < maxColumn; counterColumn++) {
                //Have a counter that makes sure that we stop when there is no more content in the string.
                if(content.length() <= counter) {
                    cipher[counterRow][counterColumn] = '.';
                }
                else {
                    cipher[counterRow][counterColumn] = content.charAt(counter++);
                }
            }
        }

        return charToString(cipher, maxRow, orderArray); // Make the cipher into a string.
    }
    //Turns the two dimensional char array into a string which will be put into a text file.
    private String charToString(char[][] cipher, int maxRow, int[] columnOrder) {
        int order;
        StringBuilder content = new StringBuilder();

        for (int counterOrder = 0; counterOrder < columnOrder.length; counterOrder++) {
            order = columnOrder[counterOrder];
            for (int counterRow = 0; counterRow < maxRow; counterRow++) {
                //Append character to the string builder
                content.append(cipher[counterRow][order]);
            }
        }

        return content.toString();
    }
}
