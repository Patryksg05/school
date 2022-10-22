public class Main {
    public static void main(String[] args) {

        Reader reader1 = new Reader("Steve", "Ryan", "1999.06.27");
        Reader reader2 = new Reader("Luck", "Madison", "2004.02.12");

        Librarier librarier = new Librarier("Emily", "Pocket",
                "2000.02.02", "2022.01.10");
        Librarier librarier2 = new Librarier("Emily", "Pocket",
                "2000.02.02", "2022.01.10");

        Book book = new Book("Pingwiny wodki nie pija", "Dawid fazowski", false);

        Library library = new Library();

        library.addReaderToLibrary(reader1);
        library.addReaderToLibrary(reader2);

        library.addLibrarierToLibrary(librarier);
        library.addLibrarierToLibrary(librarier2);

        library.addBookToLibrary(book);
        library.borrowBook(reader1, "Pingwiny wodki nie pija");
        library.howManyBooksBorrowReader(reader1.getLastName());

        System.out.println(library);
    }
}
