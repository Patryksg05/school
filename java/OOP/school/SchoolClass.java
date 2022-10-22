import java.util.ArrayList;

public class SchoolClass {
    private ArrayList<Student> students = new ArrayList<>();
    private String className;
    private ClassTeacher classTeacher; // obiekt klasy wychowawca

    public SchoolClass(String className) {
        this.className = className;
    }

    public SchoolClass(ArrayList<Student> students, String className) {
        this.students = students;
        this.className = className;
    }

    public SchoolClass(ArrayList<Student> students, String className, ClassTeacher classTeacher) {
        this.students = students;
        this.className = className;
        this.classTeacher = classTeacher;
    }

    public SchoolClass(String className, ClassTeacher classTeacher) {
        this.className = className;
        this.classTeacher = classTeacher;
    }

    // czy uczen jest w klasie = sprawdzamy tylko w tej klasie wiec private
    private boolean isStudentInClass(Student student) {
        return students.contains(student); // contains = zwraca true || false
    }

    /**
     * JAVA D O C => prawy show content actions...
     * metoda dodaje ucznia do listy uczniow jezeli
     * jeszcze go nie ma
     * @param student - obiekt dodawany do listy uczniow
     * @return brak wartosci
     */

    public void addStudentToClass(Student student)
    {
        if(isStudentInClass(student))
            System.out.println("Cannot add the student, he has a class: " + className);
        else
            students.add(student);
    }

    @Override
    public String toString() {
        return "SchoolClass{" +
                "students = " + students +
                ", className = '" + className + '\'' +
                '}';
    }
}
