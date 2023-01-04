#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED


/**  -- FUNCIONES QUE CARGAN USUARIOS --  **/
void nuevoUsuario();
void nuevoUsuarioAdministrador();

/**  -- FUNCIONES QUE VALIDAN LA INFORMACION DE LOS USUARIOS --  **/
int validacioneEstado(char email[])
void validacionUsuario();
int validacionAdmin(char email[], char pass[], char pin[]);
int validacion(char email[], char pass[]);
int existenciaUsuario(char email[]);


/**  -- FUNCIONES MENUS DE USUARIOS Y ADMINISTRADORES -- **/
void loginUsuario();
void loginAdmin();
void menuUsuario(char email[]);
void menuAdministrador();
void seleccionSesion();
int menuPerfilUsuario(char email[], int *posicion)
int menuListaUsuarios(int *posicion);
int menuVerCatalogoEnUsuario(int*posicion,char email);
int menuFavoritosUsuario(char email[], int *punteroArreglo);

/**  -- FUNCIONES FRONT DE LOS MENUS -- **/
void frontLogin();
void frontLoginAdmin();
void frontMenuAdministrador();
void frontMenuUsuario();
void frontSeleccionSesion();
void frontMenuPerfilUsuario();
void frontMenuListaUsuarios();
void frontVerCatalogoEnUsuario();

/**  -- CAMBIA ESTADO DEL USUARIO EN ALTA Y BAJA -- **/
void darAlta(char email[]);
void darBaja(char email[]);
void validacionBajaUsuario();
void validacionAltaUsuario();


/**  -- FUNCIONES QUE MUESTRAN INFORMACION DE USUARIOS --  **/
int numeroPilaUsuario(FILE*archivo);
void muestraNick(char email[]);
void muestraDatosUsuarios(char email[]);
void muestraUsuarios(int *posicion);
int muestraListaFavoritos(char emial[], int punteroArreglo);
int muestraListaFavoritosUsuarioDatos(char email[],int punteroArreglo);

/**  -- FUNCIONES ADICIONALES -- **/
int editarInfoUsuario (char email[]);
void insertaElementoFav(stUser usuario);
void agregarFavorito(char email[]);
void eliminarFavorito(char email[]);
void cartelFavoritoEliminado();
void cartelFavoritoAgregado();


#endif // USUARIO_H_INCLUDED
