abstract public class Person {
    private String firstName;
    private String lastName;
    private String dateOfBirthdayDate;

    public Person(String firstName, String lastName, String dateOfBirthdayDate) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.dateOfBirthdayDate = dateOfBirthdayDate;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getDateOfBirthdayDate() {
        return dateOfBirthdayDate;
    }

    public void setDateOfBirthdayDate(String dateOfBirthdayDate) {
        this.dateOfBirthdayDate = dateOfBirthdayDate;
    }

    @Override
    public String toString() {
        return "Person{" +
                "firstName='" + firstName + '\'' +
                ", lastName='" + lastName + '\'' +
                ", dateOfBirthdayDate='" + dateOfBirthdayDate + '\'' +
                '}';
    }
}
