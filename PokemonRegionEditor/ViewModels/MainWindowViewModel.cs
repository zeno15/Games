using PokemonRegionEditor.Presentation.Interfaces;
using PokemonRegionEditor.Presentation;
using PokemonRegionEditor.Services.Interfaces;
using System.Collections.ObjectModel;
using PokemonRegionEditor.EventArguments;
using System.Windows.Input;
using System;

namespace PokemonRegionEditor.ViewModels {
    class MainWindowViewModel : ViewModel {
        #region Fields
        private int selectedIndex;
        private ObservableCollection<ITabItem> viewModels;
        private ICommand saveRegionCommand;
        private ICommand closeRegionCommand;
        #endregion

        #region Constructors
        public MainWindowViewModel() {
            selectedIndex = 0;
            viewModels = new ObservableCollection<ITabItem>();
            viewModels.Add(new HomeScreenViewModel());

            ServiceContainer.Current.GetService<INotificationService>().NotifyCreateNewRegion += MainWindowViewModel_NotifyCreateNewRegion;
            ServiceContainer.Current.GetService<INotificationService>().NotifyLoadExistingRegion += MainWindowViewModel_NotifyLoadExistingRegion;
        }

        private void MainWindowViewModel_NotifyLoadExistingRegion(object sender, LoadExistingRegionEventArgs e) {
            var loaded = EditRegionViewModel.LoadFromFile(e.RegionName);

            if (loaded == null) {
                System.Windows.MessageBox.Show("Failed to load " + e.RegionName);
                throw new InvalidOperationException();
            }

            viewModels.Add(loaded);
            SelectedIndex = viewModels.Count - 1;
            NotifyPropertyChanged(nameof(Items));
        }

        #endregion

        #region Methods
        private void MainWindowViewModel_NotifyCreateNewRegion(object sender, CreateNewRegionEventArgs e) {
            viewModels.Add(new EditRegionViewModel(e.RegionName, e.Width, e.Height));
            SelectedIndex = viewModels.Count - 1;
            NotifyPropertyChanged(nameof(Items));
        }


        

    private void SaveRegion(object obj) {
            (SelectedItem as EditRegionViewModel)?.TrySave();
        }

        private bool SaveRegionCanExecute(object obj) {
            return SelectedItem is EditRegionViewModel;
        }

        private void CloseRegion(object obj) {
            viewModels.Remove(SelectedItem);
            SelectedIndex = 0;
        }

        private bool CloseRegionCanExecute(object obj) {
            return SelectedItem is EditRegionViewModel;
        }

        #endregion

        #region Commands
        public ICommand SaveRegionCommand {
            get { return saveRegionCommand ?? (saveRegionCommand = new DelegateCommand(SaveRegion, SaveRegionCanExecute)); }
        }
        public ICommand CloseRegionCommand {
            get { return closeRegionCommand ?? (closeRegionCommand = new DelegateCommand(CloseRegion, CloseRegionCanExecute)); }
        }
        #endregion

        #region Properties
        public ObservableCollection<ITabItem> Items {
            get { return viewModels; }
        }
        public ITabItem SelectedItem {
            get { return viewModels[SelectedIndex]; }
        }
        public int SelectedIndex {
            get { return selectedIndex; }
            set {
                selectedIndex = value;
                NotifyPropertyChanged(nameof(SelectedIndex));
                NotifyPropertyChanged(nameof(SelectedItem));
                (SaveRegionCommand as DelegateCommand)?.RaiseCanExecuteChanged();
                (CloseRegionCommand as DelegateCommand)?.RaiseCanExecuteChanged();
            }
        }
        #endregion
    }
}
