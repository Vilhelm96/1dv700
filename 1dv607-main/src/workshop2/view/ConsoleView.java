package workshop2.view;

import workshop2.controller.Choice;
import workshop2.model.Boat;
import workshop2.model.Member;

import java.util.List;
import java.util.Scanner;

/**
 * The type Console view.
 */
public class ConsoleView {
    private final Scanner sc = new Scanner(System.in);

    /**
     * First menu.
     */
    public void firstMenu() {
        print("++++++++++++++++++++++++++" + "\n" + "|Welcome to the boat club!|" + "\n"
                + "++++++++++++++++++++++++++" + "\n" + "Enter a option of your choice" + "\n"
                + "1. Create a new member." + "\n" + "2. Delete a member." + "\n" + "3. Change a members information."
                + "\n" + "4. Register a new boat." + "\n" + "5. Delete a boat." + "\n" + "6. Edit a boat." + "\n"
                + "7. View a member." + "\n" + "8. Show Verbose list." + "\n" + "9. Show Compact list." + "\n"
                + "10. Exit program." + "\n" + "Enter choice: ");
    }

    /**
     * Gets action.
     *
     * @return the action
     */
    public Choice getAction() {
        while (true) {
            var action = sc.nextLine();
            if (action.isEmpty() || Integer.parseInt(action) < 10 || Integer.parseInt(action) > 1) {
                if (action.equals("1")) {
                    return Choice.CREATE_MEMBER;
                }
                if (action.equals("2")) {
                    return Choice.DELETE_MEMBER;
                }
                if (action.equals("3")) {
                    return Choice.CHANGE_MEMBER;
                }
                if (action.equals("4")) {
                    return Choice.CREATE_MEMBER_BOAT;
                }
                if (action.equals("5")) {
                    return Choice.DELETE_MEMBER_BOAT;
                }
                if (action.equals("6")) {
                    return Choice.CHANGE_MEMBER_BOAT;
                }
                if (action.equals("7")) {
                    return Choice.VIEW_MEMBER;
                }
                if (action.equals("8")) {
                    return Choice.VIEW_VERBOSE_LIST;
                }
                if (action.equals("9")) {
                    return Choice.VIEW_COMPACT_LIST;
                }
                if (action.equals("10")) {
                    return Choice.QUIT_APP;
                }
            }
        }
    }

    /**
     * Print a string and prints a new line.
     *
     * @param string the string
     */
    public void println(String string) {
        System.out.println(string);
    }

    /**
     * Prints a string.
     *
     * @param string the string
     */
    public void print(String string) {
        System.out.print(string);
    }

    /**
     * Print error and goes to a new line.
     *
     * @param string the string
     */
    public void printError(String string) {
        System.err.println(string);
    }

    //Try to read a integer input and catch and prints the exception if there is a issue.
    private int readIntegerInput() {
        int input;
        while (true) {
            try {
                input = sc.nextInt();
                break;
            } catch (Exception exception) {
                printError(exception.getMessage());
                sc.nextLine();
            }
        }
        sc.nextLine();
        return input;
    }

    private double readDoubleInput() {
        double input;
        while (true) {
            try {
                input = sc.nextDouble();
                break;
            } catch (Exception exception) {
                printError(exception.getMessage());
                sc.nextLine();
            }
        }
        sc.nextLine();
        return input;
    }

    /**
     * Prints all members in a verbose list.
     *
     * @param memberList the member list
     */
// View the verbose list for all members
    public void viewVerbose(List<Member> memberList) {
        println("You have chosen verbose list.");

        for (Member member : memberList) {
            List<Boat> bList = member.getBoatList();
            print("Name: " + member.getName() + " PersonalNr: " + member.getPersonNr()
                    + " MemberID: " + member.getMemID() + " ");

            if (member.getBoats() == 0) { // If no boats
                print("No boats");
            } else { // If boats show all boats
                for (int j = 0; j < member.getBoats(); j++) {
                    Boat b = bList.get(j);
                    print(b.getType() + " " + b.getLength() + " ");
                }
            }
            print("\n");
        }
    }

    /**
     * Prints all members in a compact list.
     *
     * @param memberList the member list
     */
    public void viewCompact(List<Member> memberList) {
        println("You have chosen compact list.");
        for (Member member : memberList) {
            print("Name: " + member.getName() + " MemberID: " + member.getMemID() + " Boats: " + member.getBoats() + "\n");
        }
    }

    /**
     * Prints a member if the member exist.
     *
     * @param member the member
     */
    public void viewMember(Member member) {
        if (member == null) {
            printError("Member does not exist");
            return;
        }
        printMember(member); // Show member
    }

    /**
     * Register a member.
     *
     * @return the member
     */
    public Member registerMember(int id) {
        Member member = new Member(id);
        print("Whats your name? Enter both first and last name."
                + "\n" + "Full name: ");
        member.setName(sc.nextLine());
        setMemberPersonalNumber(member);
        return member;
    }

    //Tries to set a personal number on a member if it fails catch the exception and print it.
    private void setMemberPersonalNumber(Member member) {
        while (true) {
            try
            {
                print("Whats your personal number? Enter 10 digits YYMMDDXXXX"
                        + "\n" + "Enter personal number: ");
                member.setPersonNr(sc.nextLine());
                break;
            } catch (Exception exception) {
                printError(exception.getMessage());
            }
        }
    }

    /**
     * Print a member.
     *
     * @param member the member
     */
    public void printMember(Member member) {
        print("Member: " + member.getMemID() + " " + member.getName() + " " + member.getPersonNr() + " "
                + member.getBoats() + " " );
        print("\n");
    }

    /**
     * Return a member id that the user wants to delete.
     *
     * @return the int
     */
    public int deleteMember() {
        print("Type in the MemberID of the member you want to delete."
                + "\n" + "MemberID: ");
        return readIntegerInput();
    }

    /**
     * Return the member id you want to get.
     *
     * @return the int
     */
    public int readMemberId() {
        print("Type in the MemberID of the member you want to get."
                + "\n" + "MemberID: ");
        return readIntegerInput();
    }

    /**
     * Change member information depending on what the user wants to change.
     *
     * @param member the member
     */
    public void changeMember(Member member) {
        if (member == null) {
            printError("Member does not exist");
            return;
        }
        int choice = changeChoice();
        if (choice == 1) {
            print("You choose to change your name.\nWrite new name: ");
            member.setName(sc.nextLine());
        } else if (choice == 2) {
            print("You choose to change your personal number.\n");
            setMemberPersonalNumber(member);
        } else {
            print("You choose to change nothing. Returning to main menu.");
        }
    }

    /**
     * Return the alternative the user wants to change.
     *
     * @return the int
     */
    public int changeChoice() {
        print("Do you want to change member ? \n" +
                "Press 1 to change name, 2 to change personal number and 3 to go back to main menu: ");
        int choiceToInt = readIntegerInput();
        while (choiceToInt != 1 && choiceToInt != 2 && choiceToInt != 3) {
            printError("Input a choice between 1-3. ");
            print("Do you want to change this member ? \n" +
                    "Press 1 to change name, 2 to changePress 1 to change name, 2 to change personal number and 3 to go back to main menu: ");
            choiceToInt = readIntegerInput();
        }
        return choiceToInt;
    }

    /**
     * Register a boat.
     *
     * @param member the member
     */
    public void registerBoat(Member member) {
        if (member == null) {
            printError("Member does not exist");
            return;
        }
        Boat boat = new Boat();
        boat.setType(boatType());
        boat.setLength(boatLength());
        member.addBoat(boat);
    }

    //Return the boat type the user wants to set on a boat.
    private Boat.BoatType boatType() {
        print("What type of boat?\nOptions 0 for Sailboat, 1 for Motorsailer, 2 for Kayak, 3 for " +
                "Canoe and 4 for Other.\nWhat type (0-4): ");
        int choice = readIntegerInput();
        while (choice < 0 || choice > 4) {
            printError("You can only choose between option 0-4. Try again!");
            print("\nWhat type of boat?\nOptions 0 for Sailboat, 1 for Motorsailer, 2 for Kayak, 3 for Canoe and 4 for Other.\nWhat type (0-4): ");
            choice = readIntegerInput();
        }
        if (choice == 0) {
            return Boat.BoatType.Sailboat;
        } else if (choice == 1) {
            return Boat.BoatType.Motorsailer;
        } else if (choice == 2) {
            return Boat.BoatType.Kayak;
        } else if (choice == 3) {
            return Boat.BoatType.Canoe;
        } else {
            return Boat.BoatType.Other;
        }
    }

    //Return the boat length the user wants to set on a boat.
    private double boatLength() {
        print("How long is your boat?" + "\n"
                + "How long (cm): ");
        double boatLength = readDoubleInput();
        while (boatLength <= 0 || boatLength >= 50000) {
            printError("Your boat can't be zero or negative length, your boat can" +
                    " also not be 500 meter of length. Try again!");
            print("\nHow long is your boat?\nHow long (cm): ");
            boatLength = readDoubleInput();
        }
        return boatLength;
    }

    /**
     * Delete a boat from the member as long as the member owns any.
     *
     * @param member the member
     */
    public void deleteBoat(Member member) {
        if (member.getBoats() == 0) {
            println("This member does not own any boats.");
        } else {
            member.removeBoat(whichBoat(member.getBoatList()));
        }
    }

    //Show what boats the member owns and return what boat the user wants to change or delete.
    private int whichBoat(List<Boat> boatList) {
        for (int counter = 0; counter < boatList.size(); counter++) {
            Boat boat = boatList.get(counter);
            println(counter  + ". Boat type: " + boat.getType() + " boat length(cm): " + boat.getLength());
        }
        print("Which boat do you want to delete/change?" + "\n" + "Choose which boat: ");
        return readIntegerInput();
    }

    /**
     * Change a boat.
     *
     * @param member the member
     */
    public void changeBoat(Member member) {
        List<Boat> boatList = member.getBoatList();
        Boat boat = boatList.get(whichBoat(boatList));
        boatChanges(boat, boatChangeChoice());
        member.setBoatList(boatList);
    }

    //Options of possible changes to a boat and return what option user choose.
    private int boatChangeChoice() {
        print("Press 1 to change boat type, 2 to change boat length and 3 to go back to main menu: ");
        int choice = readIntegerInput();
        while (choice < 0 || choice > 3) {
            printError("You need to make a choice between 1-3. Try again!\n");
            print("Press 1 to change boat type, 2 to change boat length and 3 to go back to main menu: ");
            choice = readIntegerInput();
        }
        return choice;
    }

    //Change the boat information user has choosen.
    private void boatChanges(Boat boat, int choice) {
        if (choice == 1) {
            boat.setType(boatType());
        } else if (choice == 2) {
            boat.setLength(boatLength());
        } else {
            println("Returns to main menu.");
        }
    }

    /**
     * Close scanner.
     */
    public void closeScanner() {
        sc.close();
    }
}
