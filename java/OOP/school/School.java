import java.util.ArrayList;

public class School {

    // SINGLETON => wywolanie jednego obiektu
    private static School school = new School();
    private ArrayList<SchoolClass> schoolClass;

    private School(){
    }

    public static School getSchool() {
        return school;
    }

    public void addStudentToClass(Student student, SchoolClass schoolClass)
    {
        schoolClass.addStudentToClass(student);
    }
}
