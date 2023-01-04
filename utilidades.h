#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED

/** -- MENU PROGRAMA -- **/

void menuPrincipal();
void finalPrograma();
void barraCarga();
void proyectoFinal();
void pantallaCarga();
void barraCarga();
void finalPrograma();
void logoPibe(x);
void logo(int x);
void logo2(int x);
void logoFacultad(int x);

/** -- FUNCIONES QUE AYUDAN PARA HACER FRONT -- **/

void dibujarCuadro(int x1,int y1,int x2,int y2);
void centrarTexto(char *texto, int y);
void dibujarLinea(int x, int y,int fin, int ascii);
void fondoBlanco(int x, int xfin);

/** -- FUNCIONES QUE MUESTRAN CARTELES -- **/

void confirmacion();
void bajaUsuario();
void confirmacionBaja();
void noExisteUsuario();
void noExistePelicula();
void noExisteFavorito();
void guardadoFavorito();
void noExisteFiltro();

#endif // UTILIDADES_H_INCLUDED
