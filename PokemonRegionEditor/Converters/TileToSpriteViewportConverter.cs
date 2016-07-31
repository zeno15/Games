using PokemonRegionEditor.Models;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Media;

namespace PokemonRegionEditor.Converters {
    public class TileToSpriteViewportConverter : IMultiValueConverter {
        #region Fields
        #endregion

        #region Constructors
        #endregion

        #region Methods
        public object Convert(object[] values, Type targetType, object parameter, CultureInfo culture) {
            int? x = values[0] as int?;
            int? y = values[1] as int?;

            Rect viewport = new Rect(0.0, 0.0, 32.0, 32.0);

            if (x != null && y != null) {
                viewport = new Rect(-(double)x, -(double)y, 32.0, 32.0);
            }

            return viewport;
        }

        object[] IMultiValueConverter.ConvertBack(object value, Type[] targetTypes, object parameter, CultureInfo culture) {
            throw new NotImplementedException();
        }
        #endregion

        #region Commands
        #endregion

        #region Properties
        #endregion
    }
}
