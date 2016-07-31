using PokemonRegionEditor.Presentation;
using System.Windows;

namespace PokemonRegionEditor.Views {
    /// <summary>
    /// Interaction logic for Dialog.xaml
    /// </summary>
    public partial class Dialog : Window {
        private DialogViewModel dialogViewModel;
        public Dialog(DialogViewModel dialog) {
            InitializeComponent();
            dialogViewModel = dialog;
            DataContext = dialogViewModel;
            dialogViewModel.PropertyChanged += Dialog_PropertyChanged;
        }

        private void Dialog_PropertyChanged(object sender, System.ComponentModel.PropertyChangedEventArgs e) {
            if (e.PropertyName == "Result") {
                dialogViewModel.PropertyChanged -= Dialog_PropertyChanged;
                DialogResult = true;
            }
        }
    }
}
