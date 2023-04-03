package workshop2.model;

import workshop2.model.exceptions.InvalidPersonalNumberException;

import java.util.ArrayList;
import java.util.List;

/**
 * The type Member.
 */
public class Member {
    private String name;
    private int memberID;
    private String personNr;
    private List<Boat> boatList = new ArrayList<>();

    public Member(int memberId) {
        this.memberID = memberId;
    }

    /**
     * Gets members name.
     *
     * @return the name
     */
//All getters and setters
    public String getName() {
        return name;
    }

    /**
     * Gets the member id.
     *
     * @return the mem id
     */
//Get memberID
    public int getMemID() {
        return memberID;
    }

    /**
     * Gets the personal number of the member.
     *
     * @return the person nr
     */
//Get personal number
    public String getPersonNr() {
        return personNr;
    }

    /**
     * Sets the members name.
     *
     * @param strName the str name
     */
//Set name
    public void setName(String strName) {
        this.name = strName + "";
    }

    /**
     * Gets all boats the member owns.
     *
     * @return the boats
     */
    public int getBoats() {
        return this.boatList.size();
    }

    /**
     * Sets the boat list that the member owns.
     *
     * @param boatList the boat list
     */
    public void setBoatList(List<Boat> boatList) {
        this.boatList = boatList;
    }

    /**
     * Gets the list of boats the member owns.
     *
     * @return the boat list
     */
    public List<Boat> getBoatList() {
        return boatList;
    }

    /**
     * Add a boat to the list.
     *
     * @param b the b
     */
    public void addBoat(Boat b) {
        this.boatList.add(b);
    }

    /**
     * Remove boat from the boat list.
     *
     * @param boatId the boat id
     */
    public void removeBoat(int boatId) {
        this.boatList.remove(boatId);
    }

    /**
     * Sets the member personal number.
     *
     * @param newPersonNr the new person nr
     */
    public void setPersonNr(String newPersonNr) {
        if (checkPersonalNumber(newPersonNr))  {
            this.personNr = newPersonNr;
        } else {
            throw new InvalidPersonalNumberException();
        }
    }

    /**
     * Check the personal number so that it is correct, only numbers and the size is 10.
     *
     * @param str the str
     * @return the boolean
     */
    public boolean checkPersonalNumber(String str) {
        return str.matches("[0-9]+") && str.length() == 10;
    }
}