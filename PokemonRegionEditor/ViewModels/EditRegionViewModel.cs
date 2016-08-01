using Microsoft.Win32;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using PokemonRegionEditor.Models;
using PokemonRegionEditor.Presentation;
using PokemonRegionEditor.Presentation.Interfaces;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace PokemonRegionEditor.ViewModels {
    public class EditRegionViewModel : ViewModel, ITabItem {
        #region Fields
        private ICommand buttonPressedCommand;
        private ICommand buttonPressedRightCommand;
        private ICommand toggleSidebarVisibilityCommand;
        private bool rightPanelExtended = true;
        private EditRegionSideBarViewModel sideBar;
        #endregion

        #region Constructors
        private EditRegionViewModel() {
            Tiles = new List<List<Tile>>();
            sideBar = new EditRegionSideBarViewModel();
        }
        public EditRegionViewModel(string regionName, int width, int height) :
            this() {
            Name = regionName;
            Width = width;
            Height = height;


            for (int i = 0; i < Height; i++) {
                Tiles.Add(new List<Tile>());

                for (int j = 0; j < Width; j++) {
                    Tiles[i].Add(new Tile(j, i));
                }
            }

        }
        #endregion

        #region Methods
        public static EditRegionViewModel LoadFromFile(string filename) {
            EditRegionViewModel model = null;
            using (StreamReader file = File.OpenText(filename)) {
                using (JsonTextReader reader = new JsonTextReader(file)) {
                    JObject o2 = (JObject)JToken.ReadFrom(reader);

                    model = new EditRegionViewModel();
                    model.Name = o2["RegionName"].ToString();
                    model.Width = o2["Width"].ToObject<int>();
                    model.Height = o2["Height"].ToObject<int>();

                    var entities = o2["Entities"].ToList();

                    foreach (var t in entities) {
                        var x = t["RegionX"].ToObject<int>();
                        var y = t["RegionY"].ToObject<int>();
                        var entityCanEnter = t["EntityCanEnter"].ToObject<bool>();
                        var spriteX = t["SpriteSheetIndexX"].ToObject<int>();
                        var spriteY = t["SpriteSheetIndexY"].ToObject<int>();

                        var isRegionJumper = t["IsRegionJumper"].ToObject<bool>();

                        Tile tile = new Tile(x, y);
                        tile.EntityCanEnter = entityCanEnter;
                        tile.SpriteSheetIndexX = spriteX;
                        tile.SpriteSheetIndexY = spriteY;
                        tile.IsRegionJumper = isRegionJumper;

                        if (isRegionJumper) {
                            var targetRegionName = t["TargetRegionName"].ToString();
                            var targetX = t["TargetRegionX"].ToObject<int>();
                            var targetY = t["TargetRegionY"].ToObject<int>();

                            tile.TargetRegionName = targetRegionName;
                            tile.TargetRegionX = targetX;
                            tile.TargetRegionY = targetY;
                        }
                        if (model.Tiles.Count <= tile.RegionY) {
                            model.Tiles.Add(new List<Tile>());
                        }
                        
                        model.Tiles[tile.RegionY].Add(tile);
                    }
                }
            }

            return model;
        }


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

        public ICommand ButtonPressedRightCommand {
            get { return buttonPressedRightCommand ?? (buttonPressedRightCommand = new DelegateCommand(ButtonPressedRight)); }
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
        }

        private void ButtonPressedRight(object obj) {
            Tile t = obj as Tile;
            if (t != null) {
                var newCoords = EditRegionSideBarViewModel.SpriteCoordinates;
                t.SpriteSheetIndexX = (int)newCoords.X;
                t.SpriteSheetIndexY = (int)newCoords.Y;
            }
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
