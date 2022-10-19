// dziedziczenie wszystkich cech od klasy Osoby
public class Student extends Person implements OnDuty{
    private int studentNumber;
    // zliaczanie wszystkich obiektow naszej klasy => zmienna S T A T Y C Z N A
    public static int numberOfStudents;

    public Student(String name, int age) {
        super(name, age); // SUPER => wywolanie konstruktora w klasie bazowej (Person)
        numberOfStudents++;
        this.studentNumber = numberOfStudents;
    }

    @Override // nadpisuje klase Person
    public String toString() {
        return "\tStudent {" +
                " Name = " + getName() +
                " age = " + getAge() +
                " studentNumber = " + studentNumber +
                '}';
    }
    @Override
    public void makeDuty() {
        System.out.println("Clean the board!");
    }
}
