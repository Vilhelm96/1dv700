package workshop2.model;

import java.util.ArrayList;
import java.util.List;

/**
 * The type Member register.
 */
public class MemberRegister {
    private int indexCounter = 0;
    private final List<Member> memberList;

    /**
     * Instantiates a new Member register.
     *
     * @param allMembers the all members
     */
    public MemberRegister(List<Member> allMembers) {
        memberList = allMembers;
        this.indexCounter = memberList.size();
    }

    /**
     * Get the list with members.
     *
     * @return the all members
     */
    public List<Member> getAllMembers() {
        return new ArrayList<>(memberList);
    }

    /**
     * Add member to the list.
     *
     * @param member the member
     */
    public void createMember(Member member) {
        this.memberList.add(member);
    }

    /**
     * Generate id.
     * @return id
     */
    public int generateId() {
        return ++indexCounter;
    }

    /**
     * Gets member from the list.
     *
     * @param id the id
     * @return the member
     */
    public Member getMember(int id) {
        for (int i = 0; i < memberList.size(); i++) {
            Member member = memberList.get(i);
            if (member.getMemID() == (id))
            {
                return member;
            }
        }
        return null;
    }

    /**
     * Remove member from the list.
     *
     * @param member the member
     */
    public void removeMember(Member member) {
        this.memberList.remove(member);
    }
}
