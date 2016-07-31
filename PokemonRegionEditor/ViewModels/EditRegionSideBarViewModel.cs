using PokemonRegionEditor.Enumerations;
using PokemonRegionEditor.Models;
using PokemonRegionEditor.Presentation;
using System;
using System.Drawing;
using System.IO;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace PokemonRegionEditor.ViewModels {
    public class EditRegionSideBarViewModel : ViewModel {
        #region Fields
        private Tile selectedTile;
        private TileFilter tileFilter;
        #endregion

        #region Constructors
        public EditRegionSideBarViewModel() {
        }
        #endregion

        #region Methods
        #endregion

        #region Commands
        #endregion

        #region Properties
        public Tile SelectedTile {
            get { return selectedTile; }
            set {
                selectedTile = value;
                NotifyPropertyChanged(nameof(SelectedTile));
            }
        }

        public TileFilter TileFilter {
            get { return tileFilter; }
            set {
                tileFilter = value;
                NotifyPropertyChanged(nameof(TileFilter));
            }
        }

        #endregion
    }
}
