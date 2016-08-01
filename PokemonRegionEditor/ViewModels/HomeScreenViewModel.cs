using Microsoft.Win32;
using PokemonRegionEditor.EventArguments;
using PokemonRegionEditor.Presentation;
using PokemonRegionEditor.Presentation.Interfaces;
using PokemonRegionEditor.Services.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace PokemonRegionEditor.ViewModels {
    public class HomeScreenViewModel : ViewModel, ITabItem {
        #region Fields
        private ICommand createNewRegionCommand;
        private ICommand editExistingRegionCommand;
        #endregion

        #region Constructors
        #endregion

        #region Methods
        private void EditExistingRegion(object obj) {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "Pokemon Region Files (*.json)|*.json";
            if (openFileDialog.ShowDialog() == true) {
                ServiceContainer.Current.GetService<INotificationService>()?.LoadExistingRegion(new LoadExistingRegionEventArgs(openFileDialog.FileName));

            }
        }
        private void CreateNewRegion(object obj) {
            var dialog = new EnterNewRegionNameDialogViewModel();
            if (ServiceContainer.Current.GetService<IDialogService>().Show(dialog) == Enumerations.DialogResult.Ok) {
                ServiceContainer.Current.GetService<INotificationService>()?.CreateNewRegion(new CreateNewRegionEventArgs(
                    dialog.RegionName, 
                    dialog.Width, 
                    dialog.Height));
            }
        }
        #endregion

        #region Commands
        public ICommand CreateNewRegionCommand {
            get { return createNewRegionCommand ?? (createNewRegionCommand = new DelegateCommand(CreateNewRegion)); }
        }
        public ICommand EditExistingRegionCommand {
            get { return editExistingRegionCommand ?? (editExistingRegionCommand = new DelegateCommand(EditExistingRegion)); }
        }


        #endregion

        #region Properties
        public string TabHeaderText => "Home";
        #endregion
    }
}
