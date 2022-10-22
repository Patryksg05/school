import java.util.ArrayList;

public class Library {
    /**
     * kolekcje:
     *      - czytelnicy
     *      - bibliotekarze
     *      - ksiazki
     */

    private static Library library = new Library();
    private ArrayList<Reader> readers = new ArrayList<Reader>();
    private ArrayList<Librarier> librarians = new ArrayList<Librarier>();
    private ArrayList<Book> books = new ArrayList<Book>();

    public Library() {
    }

    public static Library getLibrary(){
        return library;
    }

    private boolean isReaderInLibrary(Reader reader){
        return readers.contains(reader);
    }

    public void addReaderToLibrary(Reader reader)
    {
        if(!isReaderInLibrary(reader))
            readers.add(reader);
        else
            System.out.println("Error!\n" + reader.getLastName() + " is in the library!");
    }

    private boolean isLibrarierInLibrary(Librarier librarier){
        return librarians.contains(librarier);
    }

    public void addLibrarierToLibrary(Librarier librarier){
        if(!isLibrarierInLibrary(librarier))
            librarians.add(librarier);
        else
            System.out.println("Error!\n" + librarier.getLastName() + " have already been as a librarier!");
    }

    private boolean isBookInLibrary(Book book){
        return books.contains(book);
    }

    public void addBookToLibrary(Book book)
    {
        if(!isBookInLibrary(book))
            books.add(book);
        else
            System.out.println(book.getTitle() + " is in our library!");
    }

    public boolean isBookAvaiable(Book book)
    {
        if(books.contains(book))
            return book.isBorrow();
        else
            return false;
    }

    public void borrowBook(Reader reader, String title)
    {
        for(Book book: books)
        {
            if(book.getTitle() == title && !isBookAvaiable(book)) {
                book.setBorrow(true);
                reader.addBookToBorrowBooks(book);
            }
            else
                System.out.println("Book is not avaiable!");
        }
    }

    public void howManyBooksBorrowReader(String lastName)
    {
        for(Reader reader : readers)
        {
            if(reader.getLastName() == lastName)
                System.out.println(reader.getBorrowedBooks().size());
        }
    }

    @Override
    public String toString() {
        return
                "readers: " + readers +
                "\nlibraries: " + librarians +
                "\nbooks" + books;
    }

    //    @Override
//    public String toString() {
//        StringBuilder result = new StringBuilder("Readers in library: [\n");
//        for(Reader reader: readers)
//        {
//            result.append("\t- ").append(reader.getLastName()).append(" ").
//                    append(reader.getFirstName()).append(" ").append("(")
//                    .append(reader.getBirthdayDate()).append(")\n");
//        }
//        result.append("]");
//        return result.toString();
//    }
}
