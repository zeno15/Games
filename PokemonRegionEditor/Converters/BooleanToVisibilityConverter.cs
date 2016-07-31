using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Data;

namespace PokemonRegionEditor.Converters {
    public class BooleanToVisibilityConverter : IValueConverter {
        #region Fields
        #endregion

        #region Constructors
        #endregion

        #region Methods
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture) {
            if (value is bool) {
                bool v = (bool)value;
                if (Invert) {
                    v = !v;
                }
                return v ? TrueVisibility : FalseVisibility;
            }

            return FalseVisibility;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture) {
            throw new NotImplementedException();
        }
        #endregion

        #region Commands
        #endregion

        #region Properties
        public Visibility TrueVisibility { get; set; } = Visibility.Visible;
        public Visibility FalseVisibility { get; set; } = Visibility.Collapsed;
        public bool Invert { get; set; } = false;
        #endregion
    }
}
