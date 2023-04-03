import java.io.File;
import java.util.Scanner;

public class Main {
    public static void main(String [] args) {
        ReadFile readFile = new ReadFile();
        Test test = new Test();
        /*Remove comments to get task 7 a) where you have a text file where you input the content and then get the hash.
        Scanner scanner = new Scanner(System.in);
        System.out.print("Choose file to get hash value from: ");
        String stringFile = scanner.nextLine();
        long hash = readFile.readTextFile(stringFile);
        System.out.println(hash);*/
        System.out.println("Now I will test how many collisions will occur with 1000 random words using my hash function.");
        System.out.println(test.testHash());
        System.out.println("Now I will test how many collisions occur when I only change one bit in the message!");
        System.out.println(test.testHashChangeOneBit());
    }
}
