package workshop2.controller;

import workshop2.view.ConsoleView;
import workshop2.model.Member;
import workshop2.model.MemberRegister;

/**
 * The type Boat club.
 */
public class BoatClub {
    private final ConsoleView consoleView;
    private final MemberRegister memberRegister;

    /**
     * Instantiates a new Boat club.
     *
     * @param consoleView    the console view
     * @param memberRegister the member register
     */
    public BoatClub(ConsoleView consoleView, MemberRegister memberRegister) {
        this.consoleView = consoleView;
        this.memberRegister = memberRegister;
    }

    /**
     * Start. The main menu and all the options.
     */
    public void start() {
        boolean runWhileTrue = true;
        do {
            consoleView.firstMenu();
            Choice choice = consoleView.getAction();
            switch (choice) {
                case CREATE_MEMBER -> registerMember();
                case DELETE_MEMBER -> deleteMember();
                case CHANGE_MEMBER -> changeMember();
                case CREATE_MEMBER_BOAT -> registerBoat();
                case DELETE_MEMBER_BOAT -> deleteBoat();
                case CHANGE_MEMBER_BOAT -> changeBoat();
                case VIEW_MEMBER -> viewMember();
                case VIEW_VERBOSE_LIST -> viewVerboseList();
                case VIEW_COMPACT_LIST -> viewCompactList();
                case QUIT_APP -> runWhileTrue = false;
            }
        } while (runWhileTrue);
    }

    private void registerMember() {
        var member = consoleView.registerMember(memberRegister.generateId());
        memberRegister.createMember(member);
    }

    private void deleteMember() {
        int memberId = consoleView.deleteMember();
        memberRegister.removeMember(memberRegister.getMember(memberId));
    }

    private void changeMember() {
        int memberId = consoleView.readMemberId();
        Member member = memberRegister.getMember(memberId);
        consoleView.changeMember(member);
    }

    private void viewCompactList() {
        var memberList = memberRegister.getAllMembers();
        consoleView.viewCompact(memberList);
    }

    private void viewVerboseList() {
        var memberList = memberRegister.getAllMembers();
        consoleView.viewVerbose(memberList);
    }

    private void viewMember() {
        int memberId = consoleView.readMemberId();
        Member member = memberRegister.getMember(memberId);
        consoleView.viewMember(member);
    }

    private void registerBoat() {
        int memberId = consoleView.readMemberId();
        Member member = memberRegister.getMember(memberId);
        consoleView.registerBoat(member);
    }

    private void deleteBoat() {
        int memberId = consoleView.readMemberId();
        Member member = memberRegister.getMember(memberId);
        consoleView.deleteBoat(member);
    }

    private void changeBoat() {
        int memberId = consoleView.readMemberId();
        Member member = memberRegister.getMember(memberId);
        consoleView.changeBoat(member);
    }
}