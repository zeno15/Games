using Microsoft.Win32;
using PokemonRegionEditor.Models;
using PokemonRegionEditor.Presentation;
using PokemonRegionEditor.Presentation.Interfaces;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace PokemonRegionEditor.ViewModels {
    public class EditRegionViewModel : ViewModel, ITabItem {
        #region Fields
        private ICommand buttonPressedCommand;
        private ICommand toggleSidebarVisibilityCommand;
        private bool rightPanelExtended = true;
        private EditRegionSideBarViewModel sideBar;
        #endregion

        #region Constructors
        public EditRegionViewModel(string regionName, int width, int height) {
            Name = regionName;
            Width = width;
            Height = height;

            Tiles = new List<List<Tile>>();

            for (int i = 0; i < Height; i++) {
                Tiles.Add(new List<Tile>());

                for (int j = 0; j < Width; j++) {
                    Tiles[i].Add(new Tile(j, i));
                }
            }

            sideBar = new EditRegionSideBarViewModel();
        }
        #endregion

        #region Methods
        public void TrySave() {
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.FileName = Name + ".json";
            if (saveFileDialog.ShowDialog() == true) {

                var actualName = saveFileDialog.FileName;

                bool first = true;

                var content = new StringBuilder();

                content.Append("{\"RegionName\": \"");
                content.Append(Name);
                content.Append("\",");
                content.Append(Environment.NewLine);

                content.Append("\"Width\": ");
                content.Append(Width);
                content.Append(",");
                content.Append(Environment.NewLine);

                content.Append("\"Height\": ");
                content.Append(Height);
                content.Append(",");
                content.Append(Environment.NewLine);

                content.Append("\"Entities\": ");


                content.Append("[");
                foreach (var tileList in Tiles) {
                    foreach (var tile in tileList) {
                        if (first) {
                            first = false;
                        } else {
                            content.Append(",");
                            content.Append(Environment.NewLine);
                        }
                        content.Append(Newtonsoft.Json.JsonConvert.SerializeObject(tile));
                    }
                }
                content.Append("]}");

                using (var file = new System.IO.StreamWriter(actualName)) {
                    file.Write(content.ToString());
                }
            }
        }
        #endregion

        #region Commands
        public ICommand ButtonPressedCommand {
            get { return buttonPressedCommand ?? (buttonPressedCommand = new DelegateCommand(ButtonPressed)); }
        }

        public ICommand ToggleSidebarVisibilityCommand {
            get { return toggleSidebarVisibilityCommand ?? (toggleSidebarVisibilityCommand = new DelegateCommand(ToggleSidebarVisibility)); }
        }

        private void ToggleSidebarVisibility(object obj) {
            RightPanelExtended = !RightPanelExtended;
        }

        private void ButtonPressed(object obj) {
            Tile t = obj as Tile;
            if (t == null) {
                throw new InvalidCastException();
            }
            EditRegionSideBarViewModel.SelectedTile = t;

            //System.Windows.MessageBox.Show(Newtonsoft.Json.JsonConvert.SerializeObject(t));
        }
        #endregion

        #region Properties
        public string Name { get; private set; }
        public int Width { get; private set; }
        public int Height { get; private set; }

        public List<List<Tile>> Tiles { get; private set; }

        public string TabHeaderText => Name;

        public bool RightPanelExtended {
            get { return rightPanelExtended; }
            set {
                rightPanelExtended = value;
                NotifyPropertyChanged(nameof(RightPanelExtended));
            }
        }

        public EditRegionSideBarViewModel EditRegionSideBarViewModel {
            get { return sideBar; }
        }
        #endregion
    }
}
