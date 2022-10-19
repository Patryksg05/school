public sealed class Teacher extends Person implements  OnDuty permits ClassTeacher{
    // tylko jedna klasa moze dziedzicyc nauczyciela - permits
    // nauczyciel ma to samo co osoba
    private String subject;
    public Teacher(String name, int age, String subject) {
        super(name, age); // SUPER => wywolanie konstruktora w klasie bazowej (Person)
        this.subject = subject;
    }
    @Override
    public void makeDuty() {
        System.out.println("Protect (walking) the hall!");
    }
}
