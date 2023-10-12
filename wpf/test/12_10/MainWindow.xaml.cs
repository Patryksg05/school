using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics.Eventing.Reader;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace _12_10_quiz_Maciak
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public ObservableCollection<ComboBoxItem> comboItems { get; set; }
        public ComboBoxItem selectedComboBoxItem { get; set; }

        public string login {get; set;}
        public string pass {get; set;}
        public MainWindow()
        {
            InitializeComponent();
            DataContext = this;

            comboItems = new ObservableCollection<ComboBoxItem>();
            var cbItem = new ComboBoxItem { Content = "LENGTH" };
            selectedComboBoxItem = cbItem;
            comboItems.Add(cbItem);

            comboItems.Add(new ComboBoxItem { Content = "1" });
            comboItems.Add(new ComboBoxItem { Content = "2" });
            comboItems.Add(new ComboBoxItem { Content = "3" });
        }

        private void generuj_login(object sender, RoutedEventArgs e)
        {
            if(imie_text_box.Text != String.Empty && nazwisko_text_box.Text != String.Empty)
            {
                string result = substring_method(imie_text_box.Text) + substring_method(nazwisko_text_box.Text);
                MessageBox.Show(result);
                login = result;
            }
        }

        private string substring_method(string s)
        {
            return s.Substring(0, Int32.Parse(selectedComboBoxItem.Content.ToString()));
        }

        private void generuj_haslo(object sender, RoutedEventArgs e)
        {
            if(int.TryParse(dlugosc_haslo_text_box.Text, out int password_length) && password_length > 0)
            {
                const string lower_case = "abcdefgihijklmnoprstwuxyz";
                const string numbers = "0123456789";
                const string special_chars = "!@#$%&?";

                string result_password = string.Empty;
                string all_chars = string.Empty;
                string random_char = string.Empty;
                string first_chars = string.Empty;
                Random random = new Random();
                int char_random_index, checkbox_count = 0;

                if (specjalne.IsChecked == true)
                {
                    char_random_index = random.Next(0, special_chars.Length - 1);
                    random_char = special_chars.Substring(char_random_index, 1);
                    result_password += random_char;
                    checkbox_count++;
                }

                if (cyfry.IsChecked == true)
                {
                    char_random_index = random.Next(0, numbers.Length - 1);
                    random_char = numbers.Substring(char_random_index, 1);
                    first_chars += random_char;
                    result_password += first_chars;
                    checkbox_count++;
                }

                if (checkbox_count <= password_length)
                {
                    for (int i = 0; i < password_length - checkbox_count; i++)
                        result_password += lower_case[random.Next(0, lower_case.Length - 1)];
                    MessageBox.Show(result_password);
                    pass = result_password;
                }
                else
                {
                    MessageBox.Show("za duze wymagania! liczba zaznaczonych > dlugosc hasla");
                }

            }
        }

        private void sum(object sender, RoutedEventArgs e)
        {
            if(pass != null && login != null)
            {
                MessageBox.Show(login + pass);
            }
        }
    }
}
