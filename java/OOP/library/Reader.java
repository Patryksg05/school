import java.lang.invoke.CallSite;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;

public class Reader extends Person{
    /**
     * zmienne: nrCzytlenika, wypozyczoneKsiazki
     */
    private int readerId;
    private static int countOfReader;
    private ArrayList<Book> borrowedBooks = new ArrayList<Book>();

    public Reader(String firstName, String lastName, String birthdayDate) {
        super(firstName, lastName, birthdayDate);
        countOfReader++;
        this.readerId = countOfReader;
    }

    public int getReaderId() {
        return readerId;
    }

    public void setReaderId(int readerId) {
        this.readerId = readerId;
    }

    public static int getCountOfReader() {
        return countOfReader;
    }

    // ile uzytkownik ma ksiazek
    public List<Book> getBorrowedBooks() {
        return borrowedBooks;
    }

    // user ma ksiazke, zmiana na false
    public void addBookToBorrowBooks(Book book){
        this.borrowedBooks.add(book);
    }

    @Override
    public String toString() {
        return "Reader{" +
                "firstName = " + getFirstName() +
                " lastName = " + getLastName() +
                " birthdayDate = " + getBirthdayDate() +
                " readerId=" + readerId +
                '}';
    }
}
