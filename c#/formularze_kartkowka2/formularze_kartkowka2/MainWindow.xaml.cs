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

namespace formularze_kartkowka2
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

        private void generate_random_login(object sender, RoutedEventArgs e)
        {
            string first_name = name_box.Text;
            string last_name = surname_box.Text;
            string pass1 = pass1_box.Text;
            string pass2 = pass2_box.Text;
            string generate_user_login = "";
            Random random = new Random();

            if (sub_metod(first_name) != "za krotkie!" && (sub_metod(last_name) != "za krotkie!"))
            {
                generate_user_login += sub_metod(first_name);
                generate_user_login += sub_metod(last_name);
                generate_user_login += random.Next(0, 9);
                generate_user_login += random.Next(0, 9);

                if (pass1 == pass2)
                    result_textBlock.Text = generate_user_login;
                else
                    MessageBox.Show("haslo musza byc jednakowe!");
            }
            else
            {
                if (sub_metod(first_name) == "za krotkie!")
                    MessageBox.Show("imie jest za krotkie!");
                else if (sub_metod(last_name) == "za krotkie!")
                    MessageBox.Show("nazwisko jest za krotkie!");
            }
        }

        private string sub_metod(string s)
        {
            if (s.Length <= 3)
                return "za krotkie!";
            return s.Substring(0, 3);
        }
    }
}
