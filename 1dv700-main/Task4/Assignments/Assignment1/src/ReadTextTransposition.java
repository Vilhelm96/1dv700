import java.io.File;
import java.io.IOException;
import java.util.Scanner;

/**
 * The type Read text file.
 */
public class ReadTextTransposition {
    /**
     * Read text file string.
     *
     * @param stringFile the string file
     * @return the string
     */
    public String readTextFile(String stringFile) {
        StringBuilder fullFile = new StringBuilder();
        try {
            File file = new File(stringFile);
            Scanner scan = new Scanner(file);
            StringBuilder textWithSpace = new StringBuilder();

            if (file.createNewFile()) {
                System.out.println("New file created! File has no message to encrypt currently.");
                return null;
            }
            else {
                while(scan.hasNextLine())
                {
                    textWithSpace.append(scan.nextLine());
                }

                for(int counter = 0; counter < textWithSpace.length(); counter++) {
                    if(textWithSpace.charAt(counter) != ' ') {
                        fullFile.append(textWithSpace.charAt(counter));
                    }
                }
            }

            scan.close();
        } catch(IOException e) {
            System.err.println("Error: " + e.getMessage());
        }

        return fullFile.toString();
    }
}
