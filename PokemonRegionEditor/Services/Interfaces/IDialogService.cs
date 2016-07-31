using PokemonRegionEditor.Enumerations;
using PokemonRegionEditor.Presentation;

namespace PokemonRegionEditor.Services.Interfaces {
    interface IDialogService {
        DialogResult Show(DialogViewModel dialog);
    }
}
