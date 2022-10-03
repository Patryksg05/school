public class Book {
    /**
     * zmienne: tytul, autor, czyWypozyczona
     */

    private String title;
    private String author;
    private boolean isBorrow;

    public Book(String title, String author, boolean isBorrow) {
        this.title = title;
        this.author = author;
        this.isBorrow = isBorrow;
    }

    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public void setBorrow(boolean borrow) {
        isBorrow = borrow;
    }

    public boolean isBorrow() {
        return isBorrow;
    }

    @Override
    public String toString() {
        return "Book{" +
                "title='" + title + '\'' +
                ", author='" + author + '\'' +
                ", isBorrow=" + isBorrow +
                '}';
    }
}
