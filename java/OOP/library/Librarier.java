public class Librarier extends Person{
    /**
     * zmienne: dataZatrudnienia
     */

    private String hiringDate;

    public Librarier(String firstName, String lastName, String birthdayDate, String hiringDate) {
        super(firstName, lastName, birthdayDate);
        this.hiringDate = hiringDate;
    }

    public String getHiringDate() {
        return hiringDate;
    }

    public void setHiringDate(String hiringDate) {
        this.hiringDate = hiringDate;
    }

    @Override
    public String toString() {
        return "Librarier{" +
                "hiringDate='" + hiringDate + '\'' +
                '}';
    }
}
