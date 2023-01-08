public class Main {
    public static void main(String[] args) {
        Person person1 = new Person();
        Person person2 = new Person(1, "Philips");
        Person person3 = new Person(person2.getId(), person2.getName());

        person1.toStringOwnMethod("John");
        person2.toStringOwnMethod("Steve");
        person3.toStringOwnMethod("Koby");

        System.out.println("T O T A L => " + person1.getTotalPersons());
    }
}
