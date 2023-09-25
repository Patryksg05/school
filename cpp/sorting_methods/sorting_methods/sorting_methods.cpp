#include <iostream>

#define SIZE 10

class Tab{
private:
    int* tab;

public:
    Tab() {
        tab = new int[SIZE];
    }
    void generateTab()
    {
        for (int i = 0; i < SIZE; i++) {
            tab[i] = rand() % 100 + 1;
        }
    }
    void displayTab()
    {
        for (int i = 0; i < SIZE; i++)
            std::cout << tab[i] << " ";
    }
    void deafult_method()
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = SIZE - 1; j > i; j--)
            {
                if (tab[i] > tab[j])
                {
                    int temp = tab[i];
                    tab[i] = tab[j];
                    tab[j] = temp;
                }
            }
        }
    }

    void merge_sort(int left, int right) {
        if (left < right) {
            int middle = (left + right) / 2;
            merge_sort(left, middle);
            merge_sort(middle + 1, right);
            merge(left, middle, right);
        }
    }

    void merge(int left, int middle, int right) {
        int n1 = middle - left + 1;
        int n2 = right - middle;

        int* left_site = new int[n1];
        int* right_site = new int[n2];

        for (int i = 0; i < n1; i++) {
            left_site[i] = tab[left + i];
        }
        for (int j = 0; j < n2; j++) {
            right_site[j] = tab[middle + 1 + j];
        }

        int i = 0;
        int j = 0;
        int k = left;

        while (i < n1 && j < n2) {
            if (left_site[i] <= right_site[j]) {
                tab[k] = left_site[i];
                i++;
            }
            else {
                tab[k] = right_site[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            tab[k] = left_site[i];
            i++;
            k++;
        }

        while (j < n2) {
            tab[k] = right_site[j];
            j++;
            k++;
        }

        delete[] left_site;
        delete[] right_site;
    }

    ~Tab() {
        delete[] tab;
    }
};

int main() {
    srand(time(NULL)); 

    Tab tab, tab2;

    tab.generateTab();
    tab2.generateTab();

    std::cout << "DEFUALT METHOD:\nGenerated tab:" << std::endl;
    tab.displayTab();
        
    std::cout << "\nAfter sort:" << std::endl;
    tab.deafult_method();
    tab.displayTab();

    std::cout << "\nMERGE-SORT: \nGenerated tab: " << std::endl;
    tab2.displayTab();
    tab2.merge_sort(0, SIZE - 1);
    std::cout << "\nAfter sort:" << std::endl;
    tab2.displayTab();

    return 0;
}
