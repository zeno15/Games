using PokemonRegionEditor.Enumerations;
using PokemonRegionEditor.Models;
using PokemonRegionEditor.Presentation;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Windows;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace PokemonRegionEditor.ViewModels {
    public class EditRegionSideBarViewModel : ViewModel {
        #region Fields
        private Tile selectedTile;
        private TileFilter tileFilter;
        private Rect selectedRect;
        private ICommand spriteClickedCommand;
        #endregion

        #region Constructors
        public EditRegionSideBarViewModel() {
            SpriteSheetViewPorts = new List<List<Rect>>();

            int tilesheetWidth = 1024 / 32;
            int tilesheetHeight = 1024 / 32;
            int spacing = 4;
            int sidebarwidth = 400 - 20;
            int tilePerRowOnSideBar = (int)((double)sidebarwidth / (double)(32 + spacing));

            int totalCells = tilesheetWidth * tilesheetHeight;
            
            for (int index = 0; index < totalCells / 4; index++) {
                int x = index % tilesheetWidth;
                int y = index / tilesheetWidth;

                if (SpriteSheetViewPorts.Count < y + 1) {
                    SpriteSheetViewPorts.Add(new List<Rect>());
                }

                SpriteSheetViewPorts[y].Add(new Rect(-x, -y, 32, 32));
            }

            SelectedRect = SpriteSheetViewPorts[0][0];
        }
        #endregion

        #region Methods
        private void SpriteClicked(object obj) {
            Rect? r = obj as Rect?;
            if (r != null) {
                int x = (int)Math.Abs(r.Value.X);
                int y = (int)Math.Abs(r.Value.Y);

                SelectedRect = SpriteSheetViewPorts[y][x];
            }
        }
        #endregion

        #region Commands
        public ICommand SpriteClickedCommand {
            get { return spriteClickedCommand ?? (spriteClickedCommand = new DelegateCommand(SpriteClicked)); }
        }
        #endregion

        #region Properties
        public Tile SelectedTile {
            get { return selectedTile; }
            set {
                selectedTile = value;
                NotifyPropertyChanged(nameof(SelectedTile));
            }
        }

        public Rect SelectedRect {
            get { return selectedRect; }
            set {
                selectedRect = value;
                NotifyPropertyChanged(nameof(SelectedRect));
            }
        }

        public TileFilter TileFilter {
            get { return tileFilter; }
            set {
                tileFilter = value;
                NotifyPropertyChanged(nameof(TileFilter));
            }
        }

        public Vector SpriteCoordinates => new Vector((int)Math.Abs(SelectedRect.X), (int)Math.Abs(SelectedRect.Y));
        
        public List<List<Rect>> SpriteSheetViewPorts { get; private set; }

        #endregion
    }
}
