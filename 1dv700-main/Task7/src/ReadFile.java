import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class ReadFile {
        /**
         * Read text file string.
         *
         * @param stringFile the string file
         * @return the string
         */
        public long readTextFile(String stringFile) {
            long hash = 0;
            int unique = 11;

            try {
                File file = new File(stringFile);
                Scanner scan = new Scanner(file);
                StringBuilder stringBuilder = new StringBuilder();

                if (file.createNewFile()) {
                    System.out.println("New file created! File has no message to encrypt currently.");
                    return 0;
                }
                else {
                    while(scan.hasNextLine())
                    {
                        stringBuilder.append( scan.nextLine());
                    }
                }

                for(int i = 0; i < stringBuilder.toString().length(); i++) {
                    hash = unique * hash + stringBuilder.toString().charAt(i);
                }

                scan.close();
            } catch(IOException e) {
                System.err.println("Error: " + e.getMessage());
            }

            return hash % 255;
        }
}
