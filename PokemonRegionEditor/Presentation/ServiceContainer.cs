using System;
using System.Collections.Generic;

namespace PokemonRegionEditor.Presentation {
    public class ServiceContainer {
        #region Fields
        private static ServiceContainer serviceContainer;
        private Dictionary<Type, object> services;
        #endregion

        #region Constructors
        private ServiceContainer() {
            services = new Dictionary<Type, object>();
        }
        #endregion

        #region Methods
        public void RegisterService<T>(T _service) where T : class {
            if (!services.ContainsKey(typeof(T))) {
                services.Add(typeof(T), _service);
            }
        }

        public T GetService<T>() where T : class {
            var s = services[typeof(T)];

            return s as T;
        }

        public void ClearServices() {
            services.Clear();
        }

        #endregion

        #region Commands
        #endregion

        #region Properties
        public static ServiceContainer Current {
            get {
                return serviceContainer ?? (serviceContainer = new ServiceContainer());
            }
        }
        #endregion
    }
}
