#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <locale.h>

/**     ---------------                 ESTRUCTURA de PELICULA         -----------------       **/
typedef struct
{
    int numPila;
    char nombre[30];
    char director[30];
    char duracion [10];
    char genero[20];
    int altaBaja;

} stPelicula;



/**     ---------------                 FUNCION de PELICULA         -----------------       **/

//FUNCION CREA UNA NUEVA PELICULA
void nuevaPelicula()
{
    stPelicula film;
    FILE * archivo;

    archivo = fopen ("Peliculas.bin", "a+b");
    if(archivo)
    {
        frontNuevaPelicula();
        film.numPila = numeroPilaPelicula();
        gotoxy(34,3);
        printf("[ %i ]",film.numPila);
        gotoxy(34,5);
        printf("Titulo Film: \n");
        gotoxy(34,10);
        printf("Director: \n");
        gotoxy(64,10);
        printf("Duracion: \n");
        gotoxy(34,15);
        printf("Genero: \n");
        fflush(stdin);
        gotoxy(34,7);
        gets(film.nombre);
        fflush(stdin);
        gotoxy(34,12);
        gets(film.director);
        fflush(stdin);
        gotoxy(64,12);
        gets(film.duracion);
        fflush(stdin);
        gotoxy(34,17);
        gets(film.genero);
        film.altaBaja = 1;
        fwrite(&film,sizeof(stPelicula),1,archivo);
        fclose(archivo);
    }
}

// ASIGA UN NUMERO DE PILA
int numeroPilaPelicula()
{
    stPelicula film;
    FILE*archivo = fopen( "Peliculas.bin","rb");
    int contador = 0 ;
    if(archivo!=NULL)
    {
        while(fread(&film,sizeof(stPelicula),1,archivo)>0)
        {
            contador++;
        }
    }
    return contador;
}


//-------------------------------------------------------------------------------






/**     ---------------                 FRONT MENUS DE PELICULAS         -----------------       **/

// - FRONT MENU CARGA NUEVA PELICULA
void frontNuevaPelicula()
{
    dibujarCuadro(33,6,77,8);   // CUADRO TITULO
        dibujarCuadro(33,11,60,13); // CUADRO DIRECTOR
        dibujarCuadro(63,11,77,13); // CUADRO DURACION
        dibujarCuadro(33,16,55,18); // CUADRO GENERO
        dibujarLinea(34,7,76,176);
        dibujarLinea(34,12,59,176);
        dibujarLinea(64,12,76,176);
        dibujarLinea(34,17,54,176);
}

// - FRONT DEL MENU DE INFORMACION DE  PELICULAS
void frontmenuVerInfoPelicula()
{
    dibujarCuadro(0,1,30,24); // CUADRADO PRINCIPAL
    dibujarCuadro(31,1,79,24); // CUADRADO PRINCIPAL MUESTRA
    dibujarCuadro(1,3,29,23); // CUADRADO BAJO T1
    dibujarCuadro(32,3,78,23); // CUADRADO MUESTRA
    dibujarCuadro(4,0,27,2); // TITULO PRINCIPAL
    dibujarCuadro(33,0,43,2); // TITULO SECUNDARIO
    dibujarLinea(5,1,26,32);
    printf("\033[1;34m");
    dibujarLinea(33,8,77,196); // SEPARADOR 1
    dibujarLinea(33,13,77,196); // SEPARADOR 2
    dibujarLinea(33,18,77,196); // SEPARADOR 3
    printf("\033[0m");
    gotoxy(9,1);
    printf("MENU PELICULAS");
    gotoxy(34,1);
    printf("PELICULAS");
    gotoxy(3,5);
    printf("[1] Cargar Pelicula.");
    gotoxy(3,7);
    printf("[2] Editar Pelicula.");
    gotoxy(3,9);
    printf("[3] Habilitar Pelicula.");
    gotoxy(3,11);
    printf("[4] Deshabilitar Pelicula.");
    gotoxy(3,13);
    printf("[5] Sig. Pagina Peliculas.");
    gotoxy(3,15);
    printf("[6] Volver Principio Pag.");
    gotoxy(3,21);
    printf("[0] \033[0;31mEXIT\033[0m.");
    gotoxy(45,2);
    printf("[\033[1;32m%c\033[0m] HABILITADO",254);
    gotoxy(60,2);
    printf("[\033[0;31m%c\033[0m] DESAHABILITADO",254);
}

// - FRONT DEL EDITOR DE INFORMACION DE PELICULA
void frontEditarInfoPelicula()
{
    dibujarCuadro(33,6,77,8);   // CUADRO TITULO
    dibujarCuadro(33,11,60,13); // CUADRO DIRECTOR
    dibujarCuadro(63,11,77,13); // CUADRO DURACION
    dibujarCuadro(33,16,55,18); // CUADRO GENERO
    dibujarLinea(34,7,76,176);
    dibujarLinea(34,12,59,176);
    dibujarLinea(64,12,76,176);
    dibujarLinea(34,17,54,176);
}

// - FRONT DE SECCION DE FILTROS PELICULAS:
void frontFiltroPelicula()
{
    dibujarLinea(20,5,60,32); //RELLENO BUSQUEDA
    dibujarLinea(20,6,60,32); //RELLENO BUSQUEDA
    dibujarLinea(20,7,60,32); //RELLENO BUSQUEDA
    dibujarLinea(20,8,60,32); //RELLENO BUSQUEDA
    dibujarLinea(20,9,60,32); //RELLENO BUSQUEDA
    dibujarLinea(20,10,60,32); //RELLENO BUSQUEDA
    dibujarLinea(20,11,60,32); //RELLENO BUSQUEDA
    dibujarLinea(22,9,58,176); //RELLENO BUSQUEDA
    dibujarCuadro(20,5,60,11); //CUADRADO 1
    dibujarCuadro(21,4,29,6); //TITULO 1
    dibujarCuadro(21,8,59,10); //CUADRADO BUSQUEDA 1
    gotoxy(22,5);
    printf("FILTRO:");
    gotoxy(22,7);
    printf("Ingrese lo que BUSCA:");
}







//--------------------------------------------------------------------------------------------------------------



/**     ---------------                 MENUS DE PELICULAS         -----------------       **/



// - FUNCION MENU PELICULAS
int menuVerInfoPelicula(int *posicion)
{
    int opcion = 0;
    int condCorte = 0;
    do
    {
        system("cls");
        frontmenuVerInfoPelicula();
        posicion = muestraListaPeliculas(posicion);

        gotoxy(3,22);
        printf("[ ] Opcion Seleccionada.");
        fflush(stdin);
        gotoxy(4,22);
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            menuCargarPelicula();
            condCorte = menuVerInfoPelicula(0);
            break;
        case 2:
            validacionPelicula();
            condCorte = menuVerInfoPelicula(0);
            break;
        case 3:
            validacionAltaPelicula();
            condCorte = menuVerInfoPelicula(0);
            break;
        case 4:
            validacionBajaPelicula();
            condCorte = menuVerInfoPelicula(0);
            break;
        case 5:
            condCorte = menuVerInfoPelicula(posicion);
            break;
        case 6:
            condCorte =menuVerInfoPelicula(0);
            break;
        case 0:
            condCorte =1;
            break;
        }
    }
    while(condCorte == 0);
}

// - MENU CARGADO DE PELICULA
void menuCargarPelicula()
{
    fondoBlanco(31,79,24);
    logo2(62);
    dibujarCuadro(31,1,79,24); // CUADRADO PRINCIPAL MUESTRA
    dibujarCuadro(33,0,49,2); // TITULO SECUNDARIO
    dibujarCuadro(32,3,78,23); // CUADRADO MUESTRA
    gotoxy(34,1);
    printf("CARGAR PELICULA");
    nuevaPelicula();
}

// - MENU EDITA PELICULA:
void menuEditarPelicula(char arreglo[])
{
    fondoBlanco(31,79,24);
    logo2(62);
    dibujarCuadro(31,1,79,24); // CUADRADO PRINCIPAL MUESTRA
    dibujarCuadro(33,0,49,2); // TITULO SECUNDARIO
    dibujarCuadro(32,3,78,23); // CUADRADO MUESTRA
    gotoxy(34,1);
    printf("EDITAR PELICULA");
    editarInfoPelicula(arreglo);
}

// - MENU PARA PODER VER EL CATALOGO DE PELICULAS FILTRADAS:
int menuVerCatalogoFiltro(int*posicion, char arreglo[])
{
    int condCorte = 0;
    int opcion;
    do
    {
        system("cls");
        frontVerCatalogoFiltro();
        posicion = muestraListaFiltroPeliculas(posicion,arreglo);
        fflush(stdin);
        gotoxy(4,22);
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            condCorte = filtroPelicula();
            break;
        case 2:
            condCorte = menuVerCatalogoFiltro(posicion,arreglo);
            break;
        case 3:
            condCorte = menuVerCatalogoFiltro(0,arreglo);
            break;
        case 4:

            break;
        case 0:
            condCorte = 1;
            break;
        }
    }
    while(condCorte == 0);
    return condCorte;
}

// - FUNCION QUE ENTRA AL MENU DE FILTROS DE PELICULAS
int filtroPelicula()
{
    int condCorte = 0;
        frontFiltroPelicula();
        char filtro[30];  // <--------------- GUARDA DATO INGRESADO POR USUARIO.
        fflush(stdin);
        gotoxy(22,9);
        gets(filtro);
        int valor = existenciaFiltroPelicula(filtro); // <--------------- COMPRUBA SI LO INGRESADO EXISTE O NO.
        if(valor == 1)
        {
            condCorte = menuVerCatalogoFiltro(0,filtro); // <--------------- ENTRA AL MENU DE CARTALOGOS FILTROS , SI TERMINA EL BUCLE SALE.
        }
        else
        {
            noExisteFiltro(); // <--------------- MUESTRA CARTEL DE NO EXISTE LO QUE BUSCAS

        }
    return condCorte;
}


//--------------------------------------------------------------------------------------------------------------


/**     ---------------                 FUNCIONES CAMBIA ESTADO DEL USUARIO EN ALTA Y BAJA         -----------------       **/


// - FUNCION DA DE BAJA A LA PELICULA

void darBajaPelicula(char arreglo[])
{
    stPelicula film;
    FILE *archivo;
    archivo = fopen("Peliculas.bin", "r+b");
    if(archivo != NULL)
    {
        while(fread(&film,sizeof(stPelicula),1,archivo)>0)
        {
            if(strcmpi(arreglo,film.nombre)==0)
            {
                int valor = confirmacionBaja();
                if(valor == 1)
                {
                    fseek(archivo,sizeof(stPelicula) * -1,SEEK_CUR);
                    film.altaBaja = 0;
                    fwrite(&film,sizeof(stPelicula),1,archivo);
                    fclose(archivo);
                }
            }
        }
        fclose(archivo);
    }
}

// - FUNCION DA DE ALTA A LA PELICULA

void darAltaPelicula(char arreglo[])
{
    stPelicula film;
    FILE *archivo;
    archivo = fopen("Peliculas.bin", "r+b");
    if(archivo != NULL)
    {
        while(fread(&film,sizeof(stPelicula),1,archivo)>0)
        {
            if(strcmpi(arreglo,film.nombre)==0)
            {
                int valor = confirmacionBaja();
                if(valor == 1)
                {
                    fseek(archivo,sizeof(stPelicula) * -1,SEEK_CUR);
                    film.altaBaja = 1;
                    fwrite(&film,sizeof(stPelicula),1,archivo);
                    fclose(archivo);
                }
            }
        }
        fclose(archivo);
    }
}

// - PREGUNTA SI ESTAS SEGURO DE DAR DE BAJA LA PELICULA, SI SÍ DA DE BAJA SINO SALE.

void validacionBajaPelicula()
{
    dibujarLinea(34,9,77,32); // <-------  LINEA BLANCA
    dibujarLinea(34,10,77,32); // <-------  LINEA BLANCA
    dibujarLinea(34,11,77,32); // <-------  LINEA BLANCA
    dibujarLinea(34,12,77,32); // <-------  LINEA BLANCA
    dibujarCuadro(33,9,77,14);  // <------- CUADRADO MENU
    dibujarCuadro(34,11,76,13); // <------- MENU 3
    dibujarLinea(35,12,75,176); // <-------  LINEA DE RELLENO 2
    int buscado = 0;
    gotoxy(42,10);
    printf("Ingrese Titulo Pelicula:",248,47);
    char nomPelicula[30];
    fflush(stdin);
    gotoxy(35,12);
    gets(nomPelicula);
    int valor = existenciaPelicula(nomPelicula);
    if(valor == 1)
    {
        darBajaPelicula(nomPelicula);
    }
    else
    {
        noExistePelicula();
    }
}

// - PREGUNTA SI ESTAS SEGURO DE DAR DE ALTA LA PELICULA, SI SÍ DA DE ALTA SINO SALE.

void validacionAltaPelicula()
{
    dibujarLinea(34,9,77,32); // <-------  LINEA BLANCA
    dibujarLinea(34,10,77,32); // <-------  LINEA BLANCA
    dibujarLinea(34,11,77,32); // <-------  LINEA BLANCA
    dibujarLinea(34,12,77,32); // <-------  LINEA BLANCA
    dibujarCuadro(33,9,77,14);  // <------- CUADRADO MENU
    dibujarCuadro(34,11,76,13); // <------- MENU 3
    dibujarLinea(35,12,75,176); // <-------  LINEA DE RELLENO 2
    int buscado = 0;
    gotoxy(42,10);
    printf("Ingrese Titulo Pelicula:");
    char nomPelicula[30];
    fflush(stdin);
    gotoxy(35,12);
    gets(nomPelicula);
    int valor = existenciaPelicula(nomPelicula);
    if(valor == 1)
    {
        darAltaPelicula(nomPelicula);
    }
    else
    {
        noExistePelicula();
    }
}




//--------------------------------------------------------------------------------------------------------------



/**     ---------------------         FUNCIONES QUE MUESTRAN ALGO EN PANTALLLA           ----------------      **/




//MUESTRA LISTADO DE PELICULAS HABILITADAS Y NO  NO HABILITADAS.
int muestraListaPeliculas(int*posicion)
{
    int y = 4;
    int i =0;
    stPelicula film;
    FILE*archivo;
    archivo = fopen("Peliculas.bin","rb"); /**  <-------------------   ABRE EL ARCHIVO Y REALIZA LA ACCION DESIGNADA **/

    if(archivo)  /**        <-----------------------------   SI EL ARCHIVO EXISTE REALIZA EL CODIGO **/
    {
        fseek(archivo,posicion,SEEK_SET);
        while(fread(&film, sizeof(stPelicula ),1, archivo)>0 && i<4)  /**     <-------------------------   MIENTRAS NO LLEGUE EL FINAL DEL ARCHIVO  **/
        {

            gotoxy(33,y);
            printf("[   ]%s", film.nombre);
            gotoxy(35,y+1);
            printf("%c> Director: %s",204,film.director);
            gotoxy(35,y+2);
            printf("%c> Duracion: %s",204,film.duracion);
            gotoxy(35,y+3);
            printf("%c> Genero: %s",200,film.genero);
            gotoxy(35,y);
            printf("%d",film.numPila);
            if(film.altaBaja == 1)
            {
                gotoxy(74,y);
                printf("[\033[1;32m%c\033[0m]",254);
            }
            else
            {
                gotoxy(74,y);
                printf("[\033[0;31m%c\033[0m]",254);
            }
            y++;
            y++;
            y++;
            y++;
            y++;
            i++;
        }
        posicion = ftell(archivo)-sizeof(film);
        fclose(archivo);/**              <-----------------------   CIERRA EL ARCHIVO **/
    }
    return posicion;
}

// - FUNCION QUE MUESTRA DE UN ARCHIVO LAS PELICULAS QUE SE FILTRAN :
int muestraListaFiltroPeliculas(int *posicion, char arreglo[])
{
    int y = 4;
    int i =0;
    stPelicula film;
    FILE*archivo;
    archivo = fopen("Peliculas.bin","rb"); /**  <-------------------   ABRE EL ARCHIVO Y REALIZA LA ACCION DESIGNADA **/

    if(archivo)  /**        <-----------------------------   SI EL ARCHIVO EXISTE REALIZA EL CODIGO **/
    {
        while(fread(&film, sizeof(stPelicula ),1, archivo)>0)  /**     <-------------------------   MIENTRAS NO LLEGUE EL FINAL DEL ARCHIVO  **/
        {
            if(strcmpi(arreglo,film.nombre) == 0|| strcmpi(arreglo,film.director) == 0 || strcmpi(arreglo,film.genero) == 0)
            {
                if(i<4)
                {
                    if(film.altaBaja == 1)
                    {
                        gotoxy(33,y);
                        printf("[   ]%s", film.nombre);
                        gotoxy(35,y+1);
                        printf("%c> Director: %s",204,film.director);
                        gotoxy(35,y+2);
                        printf("%c> Duracion: %s",204,film.duracion);
                        gotoxy(35,y+3);
                        printf("%c> Genero: %s",200,film.genero);
                        gotoxy(35,y);
                        printf("%d",film.numPila);
                        y++;
                        y++;
                        y++;
                        y++;
                        y++;
                        i++;
                    }
                }
            }
        }
        posicion = ftell(archivo)-sizeof(film);
        fclose(archivo);/**              <-----------------------   CIERRA EL ARCHIVO **/
    }
    return posicion;
}

// - FUNCION QUE MUESTRA DE UN ARCHIVO LAS PELICULAS QUE ESTAN HABILITADAS PARA EL USUARIO.
int muestraListaHabiliadoPeliculas(int*posicion)
{
    int y = 4;
    int i =0;
    stPelicula film;
    FILE*archivo;
    archivo = fopen("Peliculas.bin","rb"); /**  <-------------------   ABRE EL ARCHIVO Y REALIZA LA ACCION DESIGNADA **/

    if(archivo)  /**        <-----------------------------   SI EL ARCHIVO EXISTE REALIZA EL CODIGO **/
    {
        fseek(archivo,posicion,SEEK_SET);
        while(fread(&film, sizeof(stPelicula ),1, archivo)>0 && i<4)  /**     <-------------------------   MIENTRAS NO LLEGUE EL FINAL DEL ARCHIVO  **/
        {
            if(film.altaBaja == 1)
            {
                gotoxy(33,y);
                printf("[   ]%s", film.nombre);
                gotoxy(35,y+1);
                printf("%c> Director: %s",204,film.director);
                gotoxy(35,y+2);
                printf("%c> Duracion: %s",204,film.duracion);
                gotoxy(35,y+3);
                printf("%c> Genero: %s",200,film.genero);
                gotoxy(35,y);
                printf("%d",film.numPila);
                y++;
                y++;
                y++;
                y++;
                y++;
                i++;
            }
        }
        posicion = ftell(archivo)-sizeof(film);
        fclose(archivo);/**              <-----------------------   CIERRA EL ARCHIVO **/
    }
    return posicion;
}

// - FUNCION COMPARA UN NUMERO CON DE LISTA PELICULA Y LO DEVUELVE, EN POSICION X y Y(  MUESTRA 1 FAVORITO  )
int muestraListaPeliculasFavoritas(int numPeli, int y, int x)
{
    int contMuestra =0;
    stPelicula film;
    FILE*archivo;
    archivo = fopen("Peliculas.bin","rb"); /**  <-------------------   ABRE EL ARCHIVO Y REALIZA LA ACCION DESIGNADA **/

    if(archivo)  /**        <-----------------------------   SI EL ARCHIVO EXISTE REALIZA EL CODIGO **/
    {
        while(fread(&film, sizeof(stPelicula ),1, archivo)>0)  /**     <-------------------------   MIENTRAS NO LLEGUE EL FINAL DEL ARCHIVO  **/
        {
            if (film.numPila == numPeli)
            {
                gotoxy(x,y);
                printf("[   ]%s", film.nombre);
                gotoxy(x+2,y);
                printf("%d",film.numPila);
                gotoxy(x+2,y+1);
                printf("\033[1;32m%c>\033[0m Director: %s",204,film.director);
                gotoxy(x+2,y+2);
                printf("\033[1;32m%c>\033[0m Duracion: %s",204,film.duracion);
                gotoxy(x+2,y+3);
                printf("\033[1;32m%c>\033[0m Genero: %s",200,film.genero);
            }
        }
        fclose(archivo);/**              <-----------------------   CIERRA EL ARCHIVO **/
    }
}





//--------------------------------------------------------------------------------------------------------------


/**     ---------------------         FUNCIONES QUE VALIDAN Y EDITAN LAS PELICULAS          ----------------      **/



//EDITA LA INFORMACION DE LA PELICULA
void editarInfoPelicula(char arreglo[])
{
    stPelicula film;
    FILE * archivo;

    archivo = fopen ("Peliculas.bin", "r+b");
    if(archivo)
    {
        while(fread(&film,sizeof(stPelicula),1,archivo)>0)
        {
            if(strcmpi(arreglo,film.nombre)==0)
            {
                fseek(archivo,sizeof(stPelicula) * -1,SEEK_CUR);
                frontEditarInfoPelicula();
                gotoxy(34,3);
                printf("[ %i ]",film.numPila);
                gotoxy(34,5);
                printf("Titulo Film: \n");
                gotoxy(34,10);
                printf("Director: \n");
                gotoxy(64,10);
                printf("Duracion: \n");
                gotoxy(34,15);
                printf("Genero: \n");
                fflush(stdin);
                gotoxy(34,7);
                gets(film.nombre);
                fflush(stdin);
                gotoxy(34,12);
                gets(film.director);
                fflush(stdin);
                gotoxy(64,12);
                gets(film.duracion);
                fflush(stdin);
                gotoxy(34,17);
                gets(film.genero);
                fwrite(&film,sizeof(stPelicula),1,archivo);
                fclose(archivo);
            }
        }
    }
}


//VALIDA SI LA PELICULA EXISTE Y MUESTRA MENU EDITAR PELICULA O MARCA QUE NO EXISTE
void validacionPelicula()
{
    dibujarLinea(34,9,77,32); // <-------  LINEA BLANCA
    dibujarLinea(34,10,77,32); // <-------  LINEA BLANCA
    dibujarLinea(34,11,77,32); // <-------  LINEA BLANCA
    dibujarLinea(34,12,77,32); // <-------  LINEA BLANCA
    dibujarCuadro(33,9,77,14);  // <------- CUADRADO MENU
    dibujarCuadro(34,11,76,13); // <------- MENU 3
    dibujarLinea(35,12,75,176); // <-------  LINEA DE RELLENO 2
    gotoxy(42,10);
    printf("Ingrese Titulo Pelicula:",248,47);
    char nomPelicula[30];
    fflush(stdin);
    gotoxy(35,12);
    gets(nomPelicula);
    int valor = existenciaPelicula(nomPelicula);
    if(valor == 1)
    {
        menuEditarPelicula(nomPelicula);
    }
    else
    {
        noExistePelicula();
    }
}

//FUNCION VALIDA EL NUMERO DE PILA EXISTE DENTRO DEL ARCHIVO O NO;

int validacioneNumeroPila(int num)
{
    int flag = 0;
    stPelicula film;
    FILE *archivo;
    archivo = fopen("Peliculas.bin", "rb");
    if(archivo)
    {
        while(fread(&film, sizeof(stPelicula),1, archivo)>0 && flag == 0)
        {
            if(num == film.numPila )
            {
                if(film.altaBaja = 1)
                {
                    flag=1;
                }
            }
        }
        fclose(archivo);
    }
    return flag;
}

// COMPRUEBA SI LA PELICULA EXISTE: DEVUELVE 1 SI EXISTE, 0 SI NO EXISTE.
int existenciaPelicula(char arreglo[])
{
    int flag = 0;
    stPelicula film;
    FILE *archivo;
    archivo = fopen("Peliculas.bin", "rb");
    if(archivo)
    {
        while(fread(&film, sizeof(stPelicula),1, archivo)>0 && flag == 0)
        {
            if(strcmpi(arreglo,film.nombre) == 0)
            {
                flag=1;
            }
        }
        fclose(archivo);
    }
    return flag;
}


// - FUNCION QUE COMPRUEBA SI LA PELICULA EXISTE, TENIENDO EN CUENTA NOMBRE,DIRECTOR, GENERO.
int existenciaFiltroPelicula(char arreglo[])
{
    int flag = 0;
    stPelicula film;
    FILE *archivo;
    archivo = fopen("Peliculas.bin", "rb");
    if(archivo)
    {
        while(fread(&film, sizeof(stPelicula),1, archivo)>0 && flag == 0)
        {
            if(strcmpi(arreglo,film.nombre) == 0 || strcmpi(arreglo,film.director) == 0 || strcmpi(arreglo,film.genero) == 0)
            {
                flag=1;
                fclose(archivo);
            }
        }
        fclose(archivo);
    }
    return flag;
}








