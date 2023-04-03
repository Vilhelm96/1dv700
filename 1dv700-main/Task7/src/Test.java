import java.util.ArrayList;
import java.util.Random;

public class Test {
    private ArrayList<Integer> arrayList = new ArrayList<Integer>();
    private int collisionCounter = 0;
    private int collisionCounterOneBit = 0;
    private final char [] alphabetLowerCase =  {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
            'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    private int unique = 11;


    public int testHash () {
        int hash = 0;
        StringBuilder randomString = new StringBuilder();
        Random random = new Random();

        for(int i = 0; i < 1000; i++) {
            //Get random length for the message
            int randomLength = random.nextInt(100);
            //System.out.println(randomLength + " " + i);
            for(int j = 0; j < randomLength; j++) {
                //Create a random message
                int randomIndex = random.nextInt(26);
                randomString.append(alphabetLowerCase[randomIndex]);
            }

            arrayList.add(stringToHash(randomString.toString())); //Add string to a array list.
            randomString.setLength(0); //Reset string
        }

        lookForCollision();
        return collisionCounter;
    }
    public int testHashChangeOneBit () {
        int hash = 0;
        StringBuilder randomString = new StringBuilder();
        Random random = new Random();
        int randomLength = random.nextInt(200);
        for(int j = 0; j < randomLength; j++) {
            //Create a random message
            int randomIndex = random.nextInt(26);
            randomString.append(alphabetLowerCase[randomIndex]);
        }

        int randomStringLength = randomString.toString().length();
        for(int i = 0; i < 1000; i++) {
            //Get random length for the message
            StringBuilder tempString = new StringBuilder();
            tempString.append(randomString.toString());
            int randomIndex = random.nextInt(randomStringLength);
            int charIntValue = tempString.toString().charAt(randomIndex);
            charIntValue =- 1;
            tempString.replace(randomIndex, randomIndex + 1, Character.toString((char) charIntValue));
            arrayList.add(stringToHash(tempString.toString())); //Add string to a array list.
        }

        lookForCollision();
        return collisionCounterOneBit;
    }
    //String to hash
    private int stringToHash (String randomString) {
        int hash = 0;
        for(int i = 0; i < randomString.length(); i++) {
            hash = unique * hash + randomString.charAt(i);
        }

        return hash % 255;
    }
    //Check how many collisions occur.
    private void lookForCollision () {
        for(int i = 0; i < arrayList.size(); i++) {
            //Check every hash if there is any other that were the same.
            int hash = arrayList.get(i);
            for(int j = 0; j < arrayList.size(); j++) {
                //If collision add to the counter.
                if(i != j) {
                    if(hash == arrayList.get(j)) {
                        collisionCounter++;
                    }
                }
            }
        }
    }
}
