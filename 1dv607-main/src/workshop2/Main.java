package workshop2;

import workshop2.controller.BoatClub;
import workshop2.model.MemberRegister;
import workshop2.model.RegisterHandler;
import workshop2.view.ConsoleView;

/**
 * The type Main.
 */
public class Main {

    /**
     * The start of the application.
     *
     * @param args the input arguments
     */
    public static void main(String[] args) {
        var memberHandler = new RegisterHandler();
        var memberRegister = new MemberRegister(memberHandler.readMembers());
        var consoleView = new ConsoleView();
        BoatClub boatClub = new BoatClub(consoleView, memberRegister);
        boatClub.start();
        memberHandler.saveMembers(memberRegister.getAllMembers());
        consoleView.closeScanner();
    }
}
