using PokemonRegionEditor.Services.Interfaces;
using PokemonRegionEditor.Enumerations;
using PokemonRegionEditor.Presentation;
using System.Windows;
using PokemonRegionEditor.Views;

namespace PokemonRegionEditor.Services {
    public class DialogService : IDialogService {
        #region Fields
        #endregion

        #region Constructors
        #endregion

        #region Methods
        public DialogResult Show(DialogViewModel dialog) {            
            var d = new Dialog(dialog);

            d.ShowDialog();

            return dialog.Result;
        }
        #endregion

        #region Methods
        #endregion

        #region Commands
        #endregion

        #region Properties        
        #endregion
    }
}
