using PokemonRegionEditor.Presentation;
using System.Windows;

namespace PokemonRegionEditor.Models {
    public class Tile : ViewModel {
        #region Fields
        private bool entityCanEnter = true;
        private bool isRegionJumper;
        private string targetRegionName;
        private int targetRegionX;
        private int targetRegionY;
        private int spriteSheetIndexX;
        private int spriteSheetIndexY;
        #endregion

        #region Constructors
        public Tile(int x, int y) {
            RegionX = x;
            RegionY = y;
        }
        #endregion

        #region Methods


        public bool ShouldSerializeTargetRegionName() {
            return IsRegionJumper;
        }
        public bool ShouldSerializeTargetRegionX() {
            return IsRegionJumper;
        }
        public bool ShouldSerializeTargetRegionY() {
            return IsRegionJumper;
        }

        #endregion

        #region Commands
        #endregion

        #region Properties
        public int RegionX { get; private set; }
        public int RegionY { get; private set; }
        public int SpriteSheetIndexX {
            get { return spriteSheetIndexX; }
            set {
                spriteSheetIndexX = value;
                NotifyPropertyChanged(nameof(SpriteSheetIndexX));
                NotifyPropertyChanged(nameof(ViewPort));
            }
        }
        public int SpriteSheetIndexY {
            get { return spriteSheetIndexY; }
            set {
                spriteSheetIndexY = value;
                NotifyPropertyChanged(nameof(SpriteSheetIndexY));
                NotifyPropertyChanged(nameof(ViewPort));
            }
        }
        public bool EntityCanEnter {
            get { return entityCanEnter; }
            set {
                entityCanEnter = value;
                NotifyPropertyChanged(nameof(EntityCanEnter));
            }
        }
        public bool IsRegionJumper {
            get { return isRegionJumper; }
            set {
                isRegionJumper = value;
                if (isRegionJumper) {
                    EntityCanEnter = true;
                }
                NotifyPropertyChanged(nameof(IsRegionJumper));
            }
        }

        public Rect ViewPort => new Rect(-(double)SpriteSheetIndexX, -(double)SpriteSheetIndexY, 32.0, 32.0);

        public string TargetRegionName {
            get { return targetRegionName; }
            set {
                targetRegionName = value;
                NotifyPropertyChanged(nameof(TargetRegionName));
            }
        }

        public int TargetRegionX {
            get { return targetRegionX; }
            set {
                targetRegionX = value;
                NotifyPropertyChanged(nameof(TargetRegionX));
            }
        }

        public int TargetRegionY {
            get { return targetRegionY; }
            set {
                targetRegionY = value;
                NotifyPropertyChanged(nameof(TargetRegionY));
            }
        }


        #endregion
    }
}
