import java.util.ArrayList;
import java.util.Random;

public class Seller extends Person{
    private ArrayList<String> workingDays = new ArrayList<>();
    private String dateOfHiring;
    private int salary;

    public Seller(String firstName, String lastName, String dateOfBirthdayDate, String dateOfHiring, int salary) {
        super(firstName, lastName, dateOfBirthdayDate);
        this.dateOfHiring = dateOfHiring;
        this.salary = salary;
        ArrayList<String> days = new ArrayList<String>();
        days.add("Monday");
        days.add("Tuesday");
        days.add("Wednesday");
        days.add("Thursday");
        days.add("Friday");
        days.add("Saturday");
        days.add("Sunday");
        int i=0;
        while(i<=3) {
            String day = days.get(new Random().nextInt(days.size()));
            while(this.workingDays.contains(day))
                day = days.get(new Random().nextInt(days.size()));
            this.workingDays.add(day);
            i++;
        }
    }

    public ArrayList<String> getWorkingDays() {
        return workingDays;
    }

    public String getDateOfHiring() {
        return dateOfHiring;
    }

    public int getSalary() {
        return salary;
    }

    public void setWorkingDays(ArrayList<String> workingDays) {
        this.workingDays = workingDays;
    }

    public void setDateOfHiring(String dateOfHiring) {
        this.dateOfHiring = dateOfHiring;
    }

    public void setSalary(int salary) {
        this.salary = salary;
    }

    @Override
    public String toString() {
        return "Seller {" +
                "nameOfSeller= " + getLastName() +
                "/workingDays=" + workingDays +
                "/dateOfHiring='" + dateOfHiring + '\'' +
                "/salary=" + salary +
                '}';
    }
}
