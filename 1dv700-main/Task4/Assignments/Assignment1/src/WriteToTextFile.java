import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

/**
 * The type Write to text file.
 */
public class WriteToTextFile {
    /**
     * Write to text file.
     *
     * @param fileContent      the file content
     * @param stringOutputFile the string output file
     */
    public void writeToTextFile(String fileContent, String stringOutputFile) {
        try {
            File file = new File(stringOutputFile);

            if(file.createNewFile()) {
                System.out.println("Created a new file.");
            }

            FileWriter fileWriter = new FileWriter(file);
            System.out.println("The message\n" + fileContent);
            fileWriter.write(fileContent);
            fileWriter.close();
            System.out.println("\nThe encrypted/decrypted message can be found in the text file " + file);
        }catch (IOException e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
}
