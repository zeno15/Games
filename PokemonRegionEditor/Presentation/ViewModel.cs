using System.ComponentModel;

namespace PokemonRegionEditor.Presentation {
    public class ViewModel : INotifyPropertyChanged {
        public event PropertyChangedEventHandler PropertyChanged;

        protected void NotifyPropertyChanged(string info) {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(info));
        }
    }
}
