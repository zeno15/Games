

using System;

namespace PokemonRegionEditor.EventArguments {
    public class CreateNewRegionEventArgs : EventArgs {
        #region Fields
        #endregion

        #region Constructors
        public CreateNewRegionEventArgs(string regionName, int width, int height) {
            RegionName = regionName;
            Width = width;
            Height = height;
        }
        #endregion

        #region Methods
        #endregion

        #region Commands
        #endregion

        #region Properties
        public string RegionName { get; private set; }
        public int Width { get; private set; }
        public int Height { get; private set; }
        #endregion
    }
}
