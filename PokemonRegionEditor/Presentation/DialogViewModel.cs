using PokemonRegionEditor.Enumerations;
using PokemonRegionEditor.Presentation.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace PokemonRegionEditor.Presentation {
    public class DialogViewModel : ViewModel, IDialog {
        #region Fields
        private DialogResult result;
        private ICommand okButtonCommand;
        private ICommand cancelButtonCommand;
        private ICommand yesButtonCommand;
        private ICommand noButtonCommand;
        #endregion

        #region Constructors
        public DialogViewModel(DialogButtons buttons) {
            result = DialogResult.Cancel;
            ShowOkButton = buttons.HasFlag(DialogButtons.Ok);
            ShowCancelButton = buttons.HasFlag(DialogButtons.Cancel);
            ShowYesButton = buttons.HasFlag(DialogButtons.Yes);
            ShowNoButton = buttons.HasFlag(DialogButtons.No);
        }
        #endregion

        #region Methods
        public virtual void ExecuteOk(object parameter) {
            Result = DialogResult.Ok;
        }
        public virtual void ExecuteCancel(object parameter) {
            Result = DialogResult.Cancel;
        }
        public virtual void ExecuteYes(object parameter) {
            Result = DialogResult.Yes;
        }
        public virtual void ExecuteNo(object parameter) {
            Result = DialogResult.No;
        }

        public virtual bool CanExecuteOk(object parameter) {
            return true;
        }
        public virtual bool CanExecuteCancel(object parameter) {
            return true;
        }
        public virtual bool CanExecuteYes(object parameter) {
            return true;
        }
        public virtual bool CanExecuteNo(object parameter) {
            return true;
        }

        protected void UpdateCanExecute() {
            (OkButtonCommand as DelegateCommand)?.RaiseCanExecuteChanged();
            (CancelButtonCommand as DelegateCommand)?.RaiseCanExecuteChanged();
            (YesButtonCommand as DelegateCommand)?.RaiseCanExecuteChanged();
            (NoButtonCommand as DelegateCommand)?.RaiseCanExecuteChanged();
        }
        #endregion

        #region Commands
        public ICommand OkButtonCommand {
            get { return okButtonCommand ?? (okButtonCommand = new DelegateCommand(ExecuteOk, CanExecuteOk)); }
        }
        public ICommand CancelButtonCommand {
            get { return cancelButtonCommand ?? (cancelButtonCommand = new DelegateCommand(ExecuteCancel, CanExecuteCancel)); }
        }
        public ICommand YesButtonCommand {
            get { return yesButtonCommand ?? (yesButtonCommand = new DelegateCommand(ExecuteYes, CanExecuteYes)); }
        }
        public ICommand NoButtonCommand {
            get { return noButtonCommand ?? (noButtonCommand = new DelegateCommand(ExecuteNo, CanExecuteNo)); }
        }
        #endregion

        #region Properties
        public bool ShowOkButton { get; set; }
        public bool ShowCancelButton { get; set; }
        public bool ShowYesButton { get; set; }
        public bool ShowNoButton { get; set; }
        public DialogResult Result {
            get { return result; }
            set {
                result = value;
                NotifyPropertyChanged(nameof(Result));
            }
        }
        #endregion
    }
}
