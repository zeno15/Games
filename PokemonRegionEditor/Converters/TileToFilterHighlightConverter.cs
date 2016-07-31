using PokemonRegionEditor.Enumerations;
using PokemonRegionEditor.Models;
using System;
using System.Globalization;
using System.Windows.Data;
using MColor = System.Windows.Media.Color;
using DColor = System.Drawing.Color;
using System.Windows.Media;

namespace PokemonRegionEditor.Converters {
    public class TileToFilterHighlightConverter : IMultiValueConverter {
        #region Fields
        private static SolidColorBrush YesColor = new SolidColorBrush(ToMediaColor(DColor.Green));
        private static SolidColorBrush NoColor = new SolidColorBrush(ToMediaColor(DColor.Red));
        private static SolidColorBrush NoneColor = new SolidColorBrush(ToMediaColor(DColor.Transparent));
        #endregion

        #region Constructors
        #endregion

        #region Methods

        public static MColor ToMediaColor(DColor color) {
            return MColor.FromArgb(color.A, color.R, color.G, color.B);
        }

        public object Convert(object[] values, Type targetType, object parameter, CultureInfo culture) {
            if (values.Length != 2) {
                return NoneColor;
            }

            TileFilter? filterValue = values[0] as TileFilter?;
            Tile tile = values[1] as Tile;

            if (tile == null || filterValue == null) {
                return NoneColor;
            }

            switch (filterValue) {
                case TileFilter.RegionJumper:
                    return tile.IsRegionJumper ? YesColor : NoColor;
                case TileFilter.EntityCanEnter:
                    return tile.EntityCanEnter ? YesColor : NoColor;
                default:
                    return NoneColor;
            }
        }

        public object[] ConvertBack(object value, Type[] targetTypes, object parameter, CultureInfo culture) {
            throw new NotImplementedException();
        }
        #endregion

        #region Commands
        #endregion

        #region Properties
        #endregion
    }
}
