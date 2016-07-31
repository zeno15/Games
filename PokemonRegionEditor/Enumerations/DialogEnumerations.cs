using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PokemonRegionEditor.Enumerations {
    public enum DialogResult {
        Yes,
        No,
        Ok,
        Cancel,
    }
    [Flags]
    public enum DialogButtons {
        Yes = 1 << 0,
        No = 1 << 1,
        Ok = 1 << 2,
        Cancel = 1 << 3,

        YesNo = Yes | No,
        OkCancel = Ok | Cancel
    }
}
