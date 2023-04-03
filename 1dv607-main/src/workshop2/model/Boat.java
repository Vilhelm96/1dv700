package workshop2.model;

/**
 * The type Boat.
 */
public class Boat {

    private double length;

    public enum BoatType {
        /**
         * Sailboat boat type.
         */
        Sailboat,
        /**
         * Motorsailer boat type.
         */
        Motorsailer,
        /**
         * Kayak boat type.
         */
        Kayak,
        /**
         * Canoe boat type.
         */
        Canoe,
        /**
         * Other boat type.
         */
        Other
    }

    private BoatType type;

    /**
     * Instantiates a new Boat.
     */
    public Boat() {

    }

    /**
     * Instantiates a new Boat.
     *
     * @param l  the l
     * @param bt the bt
     */
    public Boat(double l, String bt) {
        length = l;
        type = BoatType.valueOf(bt);
    }

    /**
     * Sets length of the boat.
     *
     * @param l the l
     */
    public void setLength(double l) {
        this.length = l;
    }

    /**
     * Sets the boat type.
     *
     * @param type the
     */
    public void setType(BoatType type) {
        this.type = type;
    }

    /**
     * Gets the boats length.
     *
     * @return the length
     */
    public double getLength() {
        return length;
    }

    /**
     * Gets the boat type.
     *
     * @return the type
     */
    public BoatType getType() {
        return type;
    }

}
