using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Data;

namespace PokemonRegionEditor.Converters {
    public class InverseBooleanConverter : IValueConverter {
        #region Fields
        #endregion

        #region Constructors
        #endregion

        #region Methods
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture) {
            if (value is bool) {
                return !(bool)value;
            }
            return value;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture) {
            if (value is bool) {
                return !(bool)value;
            }
            return value;
        }
        #endregion

        #region Commands
        #endregion

        #region Properties
        #endregion
    }
}
