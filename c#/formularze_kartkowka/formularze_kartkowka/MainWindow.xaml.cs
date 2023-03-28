using System;
using System.Collections.Generic;
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

namespace formularze_kartkowka
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void random_password_generator(object sender, RoutedEventArgs e)
        {
            if(int.TryParse(pass_length.Text, out int password_length) && 
                password_length > 0 && 
                !string.IsNullOrEmpty(pass_length.Text))
            {
                MessageBox.Show("Dlugosc hasla: " + password_length);
                String user_password = "";

                Random random = new Random();

                const string lower_case = "abcdefgihijklmnoprstwuxyz";
                const string upper_case = "ABCDEFGHIJKLMNOPRSTWUXYZ";
                const string numbers = "0123456789";
                const string s_chars = "!@#$%&?";
                string all_chars = "";
                int _char, checkbox_count = 0;

                if(small_caps.IsChecked == true)
                {
                    all_chars += lower_case;
                    _char = random.Next(0, lower_case.Length - 1);
                    user_password += lower_case.Substring(_char, 1); 
                    checkbox_count++;
                }

                if(upper_caps.IsChecked == true)
                {
                    all_chars += upper_case;
                    _char = random.Next(0, upper_case.Length - 1);
                    user_password += upper_case.Substring(_char, 1);
                    checkbox_count++;
                }

                if(digits.IsChecked == true)
                {
                    all_chars += numbers;
                    _char = random.Next(0, numbers.Length - 1);
                    user_password += numbers.Substring(_char, 1);
                    checkbox_count++;
                }

                if(special_chars.IsChecked == true)
                {
                    all_chars += s_chars;
                    _char = random.Next(0, s_chars.Length - 1);
                    user_password += s_chars.Substring(_char, 1);
                    checkbox_count++;
                }

                if((password_length - checkbox_count) >= 0)
                {
                    for(int i=0; i<(password_length - checkbox_count); i++)
                    {
                        user_password += all_chars[random.Next(0, all_chars.Length)];
                    }
                }

                MessageBox.Show("Wygenerowane haslo:" + user_password);
            }
            else
            {   
                MessageBox.Show("Wyplenij prawidlowo!");
            }
        }
    }
}
