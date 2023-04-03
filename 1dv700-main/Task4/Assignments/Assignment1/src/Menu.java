import java.util.Scanner;

/**
 * The type Menu.
 */
public class Menu {
    private final ReadTextFile readTextFile = new ReadTextFile();
    private final ReadTextTransposition readTextTransposition = new ReadTextTransposition();
    private final WriteToTextFile writeToTextFile = new WriteToTextFile();
    private final Scanner scanner = new Scanner(System.in);

    /**
     * Main menu.
     * A menu that you can choose either substitution or transposition, then you can
     * choose between encrypting or decrypting a message from a text file.
     *
     */
    public void mainMenu() {
        String keyString;
        int key;

        while (true) {
            System.out.print(   "Main menu\n" +
                    "----------------\n" +
                    "1.Substitution\n" +
                    "2.Transposition\n" +
                    "3.Exit\n" +
                    "Option: ");
            int option = getInt();

            while (option < 1 || option > 3) {
                System.out.println("Input a option between 1-3, try again!");
                option = getInt();
            }

            switch (option) {
                case 1 -> {
                    int choice = encryptMenu();
                    if(choice == 1) {
                        System.out.print("Whats the key for the substitution, it can't be lower than 0 or higher than 255: ");
                        key = getInt();

                        System.out.print("Write what file you want to encrypt (path).\nFile: ");
                        String fileToEncrypt = scanner.nextLine();
                        String fileEncrypted = "./Assignment1/EncryptedFile.txt";
                        EncryptSubstitution encryptSubstitution = new EncryptSubstitution();
                        String contentInOriginalFile = readTextFile.readTextFile(fileToEncrypt);
                        String encryptedFileContent = encryptSubstitution.encryptSubstitution(contentInOriginalFile, key);
                        writeToTextFile.writeToTextFile(encryptedFileContent, fileEncrypted);
                    }
                    else if(choice == 2) {
                        System.out.print("Whats the key for the substitution, it can't be lower than 0 or higher than 255: ");
                        key = getInt();

                        System.out.print("Write what file you want to decrypt (path).\nFile: ");
                        String fileToEncrypt = scanner.nextLine();
                        String fileDecrypted = "./Assignment1/DecryptedFile.txt";
                        String contentInEncryptedFile = readTextFile.readTextFile(fileToEncrypt);
                        DecryptSubstitution decryptSubstitution = new DecryptSubstitution();
                        String decryptedFileContent = decryptSubstitution.decryptSubstitution(contentInEncryptedFile, key);
                        writeToTextFile.writeToTextFile(decryptedFileContent, fileDecrypted);
                    }
                    else {
                        System.out.println("Returning to main menu!");
                    }
                }
                case 2 -> {
                    int choice = encryptMenu();
                    if(choice == 1) {
                        System.out.print("Write a key that is purely letters from the english alphabet.\nKey: ");
                        keyString = scanner.nextLine();
                        keyString = keyString.toUpperCase();
                        System.out.print("Write what file you want to encrypt (path).\nFile: ");
                        String fileToEncrypt = scanner.nextLine();
                        String contentInFile = readTextTransposition.readTextFile(fileToEncrypt);

                        if(!contentInFile.equals(null)) {
                            EncryptTransposition encryptTransportation = new EncryptTransposition();
                            String encryptedMessage = encryptTransportation.encryptTransposition(contentInFile, keyString);
                            writeToTextFile.writeToTextFile(encryptedMessage, "./Assignment1/EncryptedTransposition.txt");
                        }
                    }
                    else if(choice == 2) {
                        System.out.print("Write the same key as the one used to encrypt.\nKey: ");
                        keyString = scanner.nextLine();
                        keyString = keyString.toUpperCase();
                        System.out.print("Write what file you want to decrypt (path).\nFile: ");
                        String fileToEncrypt = scanner.nextLine();
                        DecryptTransposition decryptTransposition = new DecryptTransposition();
                        String contentInEncryptedTransposition = readTextTransposition.readTextFile(fileToEncrypt);

                        if(!contentInEncryptedTransposition.equals(null)) {
                            String decryptedMessage = decryptTransposition.decryptTransposition(contentInEncryptedTransposition, keyString);
                            writeToTextFile.writeToTextFile(decryptedMessage, "./Assignment1/DecryptedTransposition.txt");
                        }
                    }
                    else {
                        System.out.println("Returning to main menu!");
                    }
                }
                case 3 -> {
                    System.out.println("Closing the application!");
                    scanner.close();
                    System.exit(0);
                }
            }
        }
    }
    private int encryptMenu() {
        System.out.print(   "\nWhat do you want to do?\n" +
                "----------------\n" +
                "1.Encrypt\n" +
                "2.Decrypt\n" +
                "3.Return to main menu\n" +
                "Option: ");
        int option = getInt();

        while (option < 1 || option > 3) {
            System.out.println("Input a option between 1-3, try again!");
            option = getInt();
        }

        return option;
    }

    private int getInt()
    {
        String keySuggestionString = scanner.nextLine();
        //While next input is not a int read input.
        while(Integer.parseInt(keySuggestionString) < 1 || Integer.parseInt(keySuggestionString) > 255)
        {
            keySuggestionString = scanner.nextLine();
        }
        return Integer.parseInt(keySuggestionString);
    }
}
