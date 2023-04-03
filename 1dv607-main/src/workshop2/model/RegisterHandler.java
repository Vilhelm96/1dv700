package workshop2.model;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * The type Register handler.
 */
public class RegisterHandler {
    private final File memberFile = new File("Member.txt");

    /**
     * Read members from the text file and put in a list.
     *
     * @return the list
     */
    public List<Member> readMembers() {
        List<Member> allMembers = new ArrayList<>();
        if (!memberFile.exists()) {
            return allMembers;
        } else {
            Scanner scan;
            try {
                scan = new Scanner(memberFile);
            } catch (FileNotFoundException e) {
                return allMembers;
            }

            //While the text file has more rows add rows to the arraylist
            while (scan.hasNext()) {

                String tempStr = scan.nextLine();
                String[] tempArr = tempStr.split(",");
                Member member = new Member(Integer.parseInt(tempArr[0]));
                member.setName(tempArr[1]);
                member.setPersonNr(tempArr[2]);

                for (int i = 4; i < tempArr.length; i += 2) {
                    Boat b = new Boat();
                    b.setType(Boat.BoatType.valueOf(tempArr[i]));
                    b.setLength(Double.parseDouble(tempArr[i + 1]));
                    member.addBoat(b);
                }
                allMembers.add(member);
            }

            scan.close();
        }
        return allMembers;
    }

    /**
     * Save members that are stored in the list.
     *
     * @param allMembers the all members
     */
    public void saveMembers(List<Member> allMembers) {
        PrintWriter pw;
        try {
            pw = new PrintWriter(memberFile);
        } catch (FileNotFoundException e) {
            return;
        }
        String temp;
        if (!memberFile.exists()) {
            try {
                memberFile.createNewFile();
            } catch (IOException e) {
                return;
            }
        }
        for (Member member : allMembers) {
            temp = convertMemberToString(member);
            pw.append(temp);
        }
        pw.close();
    }

    /**
     * Convert member to a string.
     *
     * @param member the member
     * @return the string
     */
    private String convertMemberToString(Member member) {
        StringBuilder sb = new StringBuilder();
        List<Boat> bList = member.getBoatList();
        String aMember;
        sb.append(member.getMemID()).append(",");
        sb.append(member.getName()).append(",");
        sb.append(member.getPersonNr()).append(",");

        if (member.getBoats() == 0) {
            sb.append(member.getBoats());
        } else {
            sb.append(member.getBoats()).append(",");

            for (int i = 0; i < bList.size(); i++) {

                if (i == bList.size() - 1) {
                    Boat b = bList.get(i);
                    sb.append(b.getType()).append(",");
                    sb.append(b.getLength());
                } else {
                    Boat b = bList.get(i);
                    sb.append(b.getType()).append(",");
                    sb.append(b.getLength()).append(",");
                }
            }
        }
        sb.append("\n");
        aMember = sb.toString();
        return aMember;
    }
}
