import java.io.File;
import java.io.IOException;
import java.util.Scanner;

/**
 * The type Read text file.
 */
public class ReadTextFile {
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

            if (file.createNewFile()) {
                System.out.println("New file created! File has no message to encrypt currently.");
                return null;
            }
            else {
                while(scan.hasNextLine())
                {
                    fullFile.append(scan.nextLine()).append("\n");
                }
            }

            scan.close();
        } catch(IOException e) {
            System.err.println("Error: " + e.getMessage());
        }

        return fullFile.toString();
    }
}
