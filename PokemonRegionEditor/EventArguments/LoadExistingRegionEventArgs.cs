using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PokemonRegionEditor.EventArguments {
    public class LoadExistingRegionEventArgs : EventArgs{
        #region Fields
        #endregion

        #region Constructors
        public LoadExistingRegionEventArgs(string regionName) {
            RegionName = regionName;
        }
        #endregion

        #region Methods
        #endregion

        #region Commands
        #endregion

        #region Properties
        public string RegionName { get; private set; }
        #endregion
    }
}
