using PokemonRegionEditor.Enumerations;
using PokemonRegionEditor.Presentation;

namespace PokemonRegionEditor.ViewModels {
    public class EnterNewRegionNameDialogViewModel : DialogViewModel {
        #region Fields
        private string regionName = "NewRegion";
        private int width = 10;
        private int height = 10;
        #endregion

        #region Constructors
        public EnterNewRegionNameDialogViewModel() :
            base(DialogButtons.OkCancel) {

        }
        #endregion

        #region Methods
        public override bool CanExecuteOk(object parameter) {
            return !string.IsNullOrWhiteSpace(RegionName);
        }
        #endregion

        #region Commands
        #endregion

        #region Properties
        public string RegionName {
            get { return regionName; }
            set {
                regionName = value;
                NotifyPropertyChanged(nameof(RegionName));
                UpdateCanExecute();
            }
        }

        public int Width {
            get { return width; }
            set {
                width = value;
                NotifyPropertyChanged(nameof(Width));
            }
        }

        public int Height {
            get { return height; }
            set {
                height = value;
                NotifyPropertyChanged(nameof(Height));
            }
        }
        #endregion
    }
}
