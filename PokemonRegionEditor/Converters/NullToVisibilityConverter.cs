using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Data;

namespace PokemonRegionEditor.Converters {
    public class NullToVisibilityConverter : IValueConverter {
        #region Fields
        #endregion

        #region Constructors
        #endregion

        #region Methods
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture) {
            bool isNull = value == null;

            if (Invert) {
                return isNull ? Visibility.Visible : Visibility.Collapsed;
            } else {
                return isNull ? Visibility.Collapsed : Visibility.Visible;
            }
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture) {
            throw new NotImplementedException();
        }
        #endregion

        #region Commands
        #endregion

        #region Properties
        public bool Invert { get; set; } = false;
        #endregion
    }
}
