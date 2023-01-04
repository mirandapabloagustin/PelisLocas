#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED


/** -- FUNCIONES DE PELICULA -- **/
void nuevaPelicula();
int numeroPilaPelicula();


/** -- FUNCIONES FRONT DEL MENU -- **/
void frontNuevaPelicula();
void frontEditarInfoPelicula();
void frontmenuVerInfoPelicula();
void frontFiltroPelicula();

/** -- FUNCIONES MENU DE PELICULAS -- **/

int menuVerInfoPelicula(int *posicion);
void menuCargarPelicula();}
void menuEditarPelicula(char arreglo[]);
int menuVerCatalogoFiltro(int*posicion, char arreglo[]);
int filtroPelicula();

/** -- FUNCIONES CAMBIA ESTADO DEL USUARIO EN ALTA Y BAJA -- **/

void darBajaPelicula(char arreglo[]);
void darAltaPelicula(char arreglo[]);
void validacionBajaPelicula();
void validacionAltaPelicula();
int existenciaPelicula(char arreglo[]);

/** -- FUNCIONES QUE MUESTRAN ALGO EN PANTALLLA -- **/
int muestraListaFiltroPeliculas(char arreglo[]);
int muestraListaHabiliadoPeliculas(int*posicion);
int muestraListaPeliculas(int *posicion);
int muestraListaPeliculasFavoritas(int numPeli, int y, int x);

/** -- FUNCIONES QUE MUESTRAN ALGO EN PANTALLLA  -- **/
void editarInfoPelicula(char arreglo[]);
void validacionPelicula();
int existenciaFiltroPelicula(char arreglo[]);
int validacioneNumeroPila(int num);



#endif // PELICULAS_H_INCLUDED
