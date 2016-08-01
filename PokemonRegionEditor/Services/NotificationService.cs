using PokemonRegionEditor.EventArguments;
using PokemonRegionEditor.Services.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PokemonRegionEditor.Services {
    public class NotificationService : INotificationService {
        #region Fields
        #endregion

        #region Constructors
        #endregion

        #region Methods
        public void CreateNewRegion(CreateNewRegionEventArgs args) {
            NotifyCreateNewRegion?.Invoke(this, args);
        }

        public void LoadExistingRegion(LoadExistingRegionEventArgs args) {
            NotifyLoadExistingRegion?.Invoke(this, args);
        }
        #endregion

        #region Commands
        #endregion

        #region Properties
        public event EventHandler<CreateNewRegionEventArgs> NotifyCreateNewRegion;
        public event EventHandler<LoadExistingRegionEventArgs> NotifyLoadExistingRegion;
        #endregion

    }
}
