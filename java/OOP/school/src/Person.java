public abstract class Person {
    // abstarct = brak mozliwosci wywolania konstruktora
    // brak modyfikatora dostepu = zmienna w pakiecie
    // protected => klasa bazowa, dziedziczona i w pakiecie
    /**
     *  - w CONSTRUCTOR w klasie nadrzednej musi byc w pierwszej lini !!!
     *  - SUPER W PIERWSZEJ LINI KONTRSUKTORA
     **/

    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

//    public Person() {
//    }

    @Override
    public String toString() {
        return "\tPerson {" +
                "name = " + name +
                ", age = " + age +
                '}';
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public void setName(String name)
    {
        // toDo: sprawdzic czy imie zlozone
        //  jest z samych liter i pierwsza duza
        this.name = name;
    }

    public void setAge(int age) {
        this.age = age;
    }
}
