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
                String user_password = " ";
                Random random = new Random();
                const string lower_case = "";
            }
            else
            {
                MessageBox.Show("Wyplenij prawidlowo!");
            }
        }
    }
}
