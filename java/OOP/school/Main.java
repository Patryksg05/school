public class Main {
    public static void main(String[] args) {
//        Person person1 = new Person("Patryk", 17); => jest abstract nie tworzymy
//        System.out.println(person1.getName());
//        System.out.println(person1);
//        Person person2 = new Person("Patryk", 18);

        Student student1 = new Student("Patryk", 17); // liczba uczniow ++ == static
        Student student2 = new Student("Robert", 18); // liczba uczniow ++ == static
        Student student3 = new Student("Patryk", 17);
        System.out.println(student1); // wywolanie metody toString

        ClassTeacher classTeacher1 = new ClassTeacher("Robert", 40, "Math");
        System.out.println(classTeacher1);
//        student1.makeDuty();

        SchoolClass kl3P = new SchoolClass("3P");
//        kl3P.addStudentToClass(student1);

        School school = School.getSchool();
        school.addStudentToClass(student1, kl3P);
        school.addStudentToClass(student2, kl3P);
        school.addStudentToClass(student3, kl3P);

        System.out.println(kl3P);
    }
}
