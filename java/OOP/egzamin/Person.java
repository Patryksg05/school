public final class Person {
    private int id;
    private String Name;

    public static int totalPersons = 0;

    public Person()
    {
        this.id = 0;
        this.Name = null;
        totalPersons++;
    }

    public Person(int id, String name) {
        this.id = id;
        this.Name = name;
        totalPersons++;
    }

    public Person(Person person)
    {
        this.id = person.id;
        this.Name = person.Name;
        totalPersons++;
    }

    public void toStringOwnMethod(String userName)
    {
        if(this.Name != null)
            System.out.println("Cześć "+userName+", mam na imię "+ this.Name);
        else
            System.out.println("Brak danych");
    }

    public int getTotalPersons() {
        return totalPersons;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return Name;
    }
}
