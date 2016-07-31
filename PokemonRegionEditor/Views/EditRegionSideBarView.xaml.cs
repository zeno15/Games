using System.Text.RegularExpressions;
using System.Windows.Controls;
using System.Windows.Input;

namespace PokemonRegionEditor.Views {
    /// <summary>
    /// Interaction logic for EditRegionSideBarView.xaml
    /// </summary>
    public partial class EditRegionSideBarView : UserControl {
        public EditRegionSideBarView() {
            InitializeComponent();
        }
        
        private void TextBox_PreviewTextInput(object sender, TextCompositionEventArgs e) {
            Regex regex = new Regex("[^0-9]+");
            e.Handled = regex.IsMatch(e.Text);
        }
    }
}
