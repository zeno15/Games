using PokemonRegionEditor.EventArguments;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PokemonRegionEditor.Services.Interfaces {
    interface INotificationService {
        event EventHandler<CreateNewRegionEventArgs> NotifyCreateNewRegion;

        void CreateNewRegion(CreateNewRegionEventArgs args);

        event EventHandler<LoadExistingRegionEventArgs> NotifyLoadExistingRegion;

        void LoadExistingRegion(LoadExistingRegionEventArgs args);
    }
}
