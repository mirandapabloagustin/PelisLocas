#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include "pila.h"
#define PIN "asdf"

/**     ---------------                 ESTRUCTURA de USUARIO         -----------------       **/

typedef struct
{
    char datosUsuarios [40];
    char email [30];
    char nick [30];
    char pass [30];
    char pin[10];
    int favoritos [30];
    int cantFavoritos;
    int altaBaja;
    int numPila;

} stUser;



/**     ---------------                 FUNCIONES QUE CARGAN USUARIOS         -----------------       **/



// CREA UN NUEVO USUARIO
void nuevoUsuario()
{
    stUser user;
    FILE *archi;
    int op = 0;

    archi = fopen("Usuario.bin", "ab");

    if(archi != NULL)
    {
        system("cls");
        fflush(stdin);
        gotoxy(10,2);
        printf("Registro Usuario");
        dibujarCuadro(8,1,27,3);
        dibujarLinea(3,4,33,61);
        dibujarCuadro(1,5,35,23);
        dibujarCuadro(0,0,36,24);

        gotoxy(3,7);
        printf("Ingrese su Nombre y Apellido: ");
        dibujarCuadro(3,8,33,10);
        dibujarLinea(4,9,32,176);
        gotoxy(3,11);
        printf ("Nick:");
        dibujarCuadro(3,12,33,14);
        dibujarLinea(4,13,32,176);
        gotoxy(3,15);
        printf("Email:");
        dibujarCuadro(3,16,33,18);
        dibujarLinea(4,17,32,176);
        gotoxy(3,19);
        printf("Contrase%ca: ",164);
        dibujarCuadro(3,20,33,22);
        dibujarLinea(4,21,32,176);

        gotoxy(4,9);
        gets(user.datosUsuarios);
        gotoxy(4,13);
        gets(user.nick);
        gotoxy(4,17);
        gets(user.email);
        gotoxy(4,21);
        gets(user.pass);
        user.altaBaja=1;
        user.numPila = numeroPilaUsuario();
        user.cantFavoritos = 0;

        fwrite(&user, sizeof(stUser),1,archi);
        confirmacion();
        fclose(archi);
    }
}
// CREA UN NUEVO USUARIO ADMINISTRADOR
void nuevoUsuarioAdministrador()
{
    stUser user;
    FILE *archi;
    int op = 0;

    archi = fopen("Usuario.bin", "ab");

    if(archi != NULL)
    {
        system("cls");
        fflush(stdin);
        gotoxy(11,2);
        printf("Registrar ADMIN");
        dibujarCuadro(9,1,27,3);
        dibujarCuadro(1,4,35,24);
        dibujarCuadro(0,0,36,25);

        gotoxy(3,5);
        printf("Ingrese su Nombre y Apellido: ");
        dibujarCuadro(3,6,33,8);
        dibujarLinea(4,7,32,176);
        gotoxy(3,9);
        printf ("Nick:");
        dibujarCuadro(3,10,33,12);
        dibujarLinea(4,11,32,176);
        gotoxy(3,13);
        printf("Email:");
        dibujarCuadro(3,14,33,16);
        dibujarLinea(4,15,32,176);
        gotoxy(3,17);
        printf("Contrase%ca: ",164);
        dibujarCuadro(3,18,33,20);
        dibujarLinea(4,19,32,176);
        gotoxy(4,22);
        printf("PIN seguridad:");
        dibujarCuadro(20,21,33,23);
        dibujarLinea(21,22,32,176);

        gotoxy(4,7);
        gets(user.datosUsuarios);
        gotoxy(4,11);
        gets(user.nick);
        gotoxy(4,15);
        gets(user.email);
        gotoxy(4,19);
        gets(user.pass);
        user.altaBaja=1;
        gotoxy(21,22);
        gets(user.pin);
        user.numPila = numeroPilaUsuario(archi);
        if(stricmp(PIN, user.pin)==0)
        {
            fwrite(&user, sizeof(stUser),1,archi);
            confirmacion();
        }
        fclose(archi);
    }
}




//------------------------------------------------------------------------------------------------------------


/**     ---------------                 FUNCIONES MENUS DE USUARIOS Y ADMINISTRADORES         -----------------       **/


// MENU QUE PIDE DATOS DEL USUARIO PARA CORROBORRAR:
void login()
{
    char usuario[30];
    char pass[30];
    int condicionCorte = 0;
    int flag = 0;
    int intentos = 3;
    int estado;
    char caracter;
    while(condicionCorte == 0)
    {
        fflush(stdin);
        frontLogin();
        gotoxy (4,20);
        printf("INTENTOS: %c%d%c", 91,intentos,93);
        gotoxy (4,9);
        gets(usuario);
        gotoxy (4,13);
        gets(pass);
        flag = validacion(usuario,pass);
        estado = validacioneEstado(usuario);
        if(flag == 1 && estado == 1)
        {
            gotoxy (4,22);
            printf("\033[1;32mUSUARIO CORRECTO\033[0m");
            Sleep(1000);
            menuUsuario(usuario);
            condicionCorte = 1;
        }
        else
        {
            gotoxy (4,22);
            printf("\033[0;31mUsuario INCORRECTO\033[0m o \033[0;31mDado de BAJA\033[0m");
            Sleep(1500);
            intentos--;
        }
        if(intentos == 0)
        {
            condicionCorte = 1;
        }

    }
}

// MENU QUE PIDE DATOS DEL USUARIO ADMINISTRADOR PARA CORROBORRAR:
void loginAdmin()
{
    fflush(stdin);
    char usuario[30];
    char pass[30];
    char pin[10];
    int flag = 0;
    int condicionCorte = 0;
    int intentos = 3;

    while(condicionCorte == 0)
    {
        fflush(stdin);
        frontLoginAdmin();
        gotoxy (4,20);
        printf("INTENTOS: %c%d%c", 91,intentos,93);
        gotoxy (4,9);
        gets(usuario);
        gotoxy (4,13);
        gets(pass);
        gotoxy (4,17);
        gets(pin);
        flag = validacionAdmin(usuario,pass,pin);

        if(flag == 1 && strcmpi(PIN,pin)==0)
        {
            gotoxy (4,22);
            printf("\033[1;32mUSUARIO CORRECTO\033[0m");
            Sleep(1500);
            menuAdministrador(usuario);
            condicionCorte = 1;
        }
        else
        {
            gotoxy (4,22);
            printf("\033[0;31mUSUARIO INCORRECTO\033[0m");
            Sleep(1000);
            intentos --;

        }
        if(intentos == 0)
        {
            condicionCorte = 1;
        }
    }
}

// MENU DEL ADMINISTRADOR:
void menuAdministrador(char email[])
{
    int opcion=0;
    int condCorte = 0;
    do
    {
        system("cls");
        fflush(stdin);
        frontMenuAdministrador();
        muestraNick(email);
        fflush(stdin);
        gotoxy(4,22);
        scanf("%d",&opcion);
        if(opcion < 0 || opcion > 6)
        {
            gotoxy(3,22);
            printf("\033[0;31mSU OPCION NO CORRESPONDE.\033[0m     ");
            Sleep(1000);
        }
        switch (opcion)
        {
        case 1:
            menuListaUsuarios(0);
            break;
        case 2:
            menuVerInfoPelicula(0);
            break;
        case 0:
            condCorte =1;
            break;
        }
    }
    while(condCorte == 0 );
}

// MENU DEL USUARIO:
void menuUsuario(char email[])
{
    int valor = 0;
    int opcion = 0;
    int condicionCorte =0;
    while(condicionCorte ==0)
    {
        system("cls");
        frontMenuUsuario();
        muestraNick(email);
        fflush(stdin);
        gotoxy(4,22);
        scanf("%d",&opcion);
        if(opcion < 0 || opcion > 6)
        {
            gotoxy(3,22);
            printf("\033[0;31mSU OPCION NO CORRESPONDE\033[0m.     ");
            Sleep(1000);
        }
        switch (opcion)
        {
        case 1:
            condicionCorte = menuPerfilUsuario(email,0);
            if(condicionCorte==2)
            {
                condicionCorte = 0;
            }
            break;
        case 2:
            menuVerCatalogoEnUsuario(0,email);
            break;
        case 3:
            menuFavoritosUsuario(email,0);
            break;
        case 5:
            darBaja(email);
            condicionCorte=1;
            break;
        case 0:
            condicionCorte=1;
            break;
        }
    }
}

// MENU DONDE SE SELECCIONA USUARIO COMUN O ADMINISTRADOR:
void seleccionSesion()
{
    int condCorte = 0;
    while(condCorte ==0)
    {
        int opcion = 0;
        system("cls");
        frontSeleccionSesion();
        gotoxy(4,22);
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            nuevoUsuario();
            break;
        case 2:
            nuevoUsuarioAdministrador();
            break;
        case 0:
            condCorte = 1;
            break;
        }
    }
}

// - MENU PERFIL DEL USUARIO
int menuPerfilUsuario(char email[], int *posicion)
{
    int opcion=0;
    int condicionCorte = 0;

    while(condicionCorte == 0)
    {

        system("cls");
        frontMenuPerfilUsuario();
        muestraDatosUsuarios(email);
        posicion = muestraListaFavoritosUsuarioDatos(email, posicion);
        gotoxy(4,22);
        fflush(stdin);
        scanf("%d",&opcion);

        if(opcion < 0 || opcion > 3)
        {
            gotoxy(3,22);
            printf("\033[0;31mSU OPCION NO CORRESPONDE.     \033[0m");
            Sleep(1000);
        }

        switch(opcion)
        {
        case 1:
            condicionCorte = editarInfoUsuario(email);
            break;
        case 2:
            condicionCorte = menuPerfilUsuario(email,posicion);
            break;
        case 3:
            condicionCorte = menuPerfilUsuario(email,0);
            condicionCorte = 2;
            break;
        case 0:
            condicionCorte = 2;
            break;
        }
    }
    return condicionCorte;
}

// - MENU DE VER EL CATALOGO EN LA SECCION DE USUARIOS:
int menuVerCatalogoEnUsuario(int*posicion, char *email)
{
    int condCorte = 0;
    int opcion;
    do
    {
        system("cls");
        frontVerCatalogoEnUsuario();
        posicion = muestraListaHabiliadoPeliculas(posicion);
        fflush(stdin);
        gotoxy(4,22);
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            filtroPelicula();
            condCorte = menuVerCatalogoEnUsuario(0, email);
            break;
        case 2:
            condCorte = menuVerCatalogoEnUsuario(posicion, email);
            break;
        case 3:
            condCorte = menuVerCatalogoEnUsuario(0, email);
            break;
        case 4:
            agregarFavorito(email);
            condCorte = menuVerCatalogoEnUsuario(0, email);
            break;
        case 0:
            condCorte = 1;
            break;
        }
    }
    while(condCorte == 0);
}

// - MENU LISTA DE USUARIOS
int menuListaUsuarios(int *posicion)
{
    int condCorte =0;
    int opcion=0;
    do
    {
        system("cls");
        frontMenuListaUsuarios();
        posicion = muestraUsuarios(posicion);
        gotoxy(4,22);
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            validacionUsuario();
            condCorte = menuListaUsuarios(0);
            break;
        case 2:
            validacionBajaUsuario();
            condCorte = menuListaUsuarios(0);
            break;
        case 3:
            validacionAltaUsuario();
            condCorte = menuListaUsuarios(0);
            break;
        case 4:
            condCorte = menuListaUsuarios(posicion);
            break;
        case 5:
            condCorte = menuListaUsuarios(0);
            break;
        case 0:
            condCorte =1;
            break;
        }
    }
    while (condCorte == 0);
    return condCorte;
}

// - FUNCION QUE MUESTRA LA LISTA DE FAVORITOS DE UN USUARIO Y MUESTRA ESPECIFICACIONES DE LAS PELICULAS
int menuFavoritosUsuario(char email[],int *punteroArreglo)
{
    int condCorte =0;
    int opcion = 0;
    do
    {
        system("cls");
        frontAgregarFavorito();
        punteroArreglo = muestraListaFavoritos(email, punteroArreglo);
        fflush(stdin);
        gotoxy(4,22);
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            condCorte = menuFavoritosUsuario(email,punteroArreglo);
            break;
        case 2:
            condCorte = menuFavoritosUsuario(email,0);
            break;
        case 3:
            eliminarFavorito(email);
            condCorte = menuFavoritosUsuario(email,0);
            break;
        case 0:
            condCorte = 1;
            break;
        }
    }
    while(condCorte == 0);
    return condCorte;
}




//------------------------------------------------------------------------------------------------------------


/**     ---------------                 FRONT MENUS DE PELICULAS         -----------------       **/

// - FRONT DEL MENU LOGIN
void frontLogin()
{
            logo(56);
        gotoxy(45,13);
        printf("Sabias que pagando la Membrecia");
        gotoxy(45,14);
        printf("podras interactuar con otros");
        gotoxy(45,15);
        printf("Usuarios dejando tus comentarios");
        gotoxy(45,16);
        printf("en las Peliculas.");
        gotoxy(45,17);
        printf("Tambien podras votar por tus");
        gotoxy(45,18);
        printf("PELICULAS FAVORITAS.");
        gotoxy(45,19);
        printf("Habla con el Administrador mas");
        gotoxy(45,20);
        printf("cercano para que habilite esta ");
        gotoxy(45,21);
        printf("Fantastica opcion, NOTE LA PIERDAS");
        gotoxy(45,23);
        printf("  %cPELIS LOCAS TU MEJOR LUGAR%c",173,33);
        dibujarCuadro(0,0,41,24);
        dibujarCuadro(43,0,79,24);
        dibujarCuadro(1,1,40,3);
        gotoxy(14,2);
        printf("Inicio Sesion");
        gotoxy(2,4);
        puts("======================================");
        dibujarCuadro(1,5,40,23);
        gotoxy (3,7);
        printf("Ingrese Email",91,93);
        dibujarCuadro(3,8,34,10);
        dibujarLinea(4,9,33,176);
        gotoxy (3,11);
        printf("Ingresar Contrase%ca:",164);
        dibujarCuadro(3,12,34,14);
        dibujarLinea(4,13,33,176);
}

// - FRON DEL MENU LOGIN ADMINISTRADOR
void frontLoginAdmin()
{
    logo(56);
        gotoxy(45,13);
        printf("Recuerden Aministradores:");
        gotoxy(45,14);
        printf("No pierdan su PIN de seguridad%c", 46);
        gotoxy(45,15);
        printf("Si sos nuevo y no contas con uno");
        gotoxy(45,16);
        printf("comunicate con tu Patron y te lo");
        gotoxy(45,17);
        printf("brindara%c de lo contrario no", 44);
        gotoxy(45,18);
        printf("podras acceder.");
        gotoxy(45,23);
        printf("  %cPELIS LOCAS TU MEJOR LUGAR%c",173,33);
        dibujarCuadro(0,0,41,24);
        dibujarCuadro(43,0,79,24);
        dibujarCuadro(1,1,40,3);
        gotoxy(7,2);
        printf("Inicio Sesion Administrador");
        gotoxy(2,4);
        puts("======================================");
        dibujarCuadro(1,5,40,23);
        gotoxy (3,7);
        printf("Ingrese Email:",91,93);
        dibujarCuadro(3,8,34,10);
        dibujarLinea(4,9,33,176);
        gotoxy (3,11);
        printf("Ingresar Contrase%ca:",164);
        dibujarCuadro(3,12,34,14);
        dibujarLinea(4,13,33,176);
        gotoxy (3,15);
        printf("PIN seguridad:");
        dibujarCuadro(3,16,15,18);
        dibujarLinea(4,17,14,176);
}

// - FRONT DEL MENU DE ADMINISTRADOR
void frontMenuAdministrador()
{
    dibujarCuadro(0,1,41,24);//   <-------   MENU 1
        dibujarCuadro(1,0,40,2);//   <-------   TITULO
        dibujarLinea(2,1,39,32);//   <-------   SEPARADOR
        dibujarLinea(2,3,39,61);//   <-------   OCULTA LINEA
        dibujarCuadro(1,4,40,23);//   <-------   MENU 2
        gotoxy(4,1);
        gotoxy (3,5);
        printf("%c1%c. Ver Lista Usuarios.",91,93);
        gotoxy (3,6);
        printf("%c2%c. Ver Lista Pelicula.",91,93);
        gotoxy (3,21);
        printf("%c0%c. \033[0;31mCerrar sesion\033[0m.",91,93);
        gotoxy (3,22);
        printf("%c %c. Opcion Selecionada.",91,93);
}

// - FRONT DEL MENU DEL USUARIO
void frontMenuUsuario()
{
    logo(56);
        gotoxy(45,13);
        printf("En Pelis Locas divertite con las");
        gotoxy(45,14);
        printf("mejores peliculas sin cortes.");
        gotoxy(45,15);
        printf("Estrenos en HD libre de anuncios");
        gotoxy(45,16);
        printf("publicitarios.");
        gotoxy(45,17);
        printf("A todos nuestros usuarios");
        gotoxy(45,18);
        printf("les ahorramos el tiempo de estar");
        gotoxy(45,19);
        printf("descargando peliculas ilegalmente");
        gotoxy(45,20);
        printf("sin SEGURIDAD, ya que lo hacemos");
        gotoxy(45,21);
        printf("por ustedes. MAS LOCOS QUE NUNCA.");
        gotoxy(45,23);
        printf("  %cPELIS LOCAS TU MEJOR LUGAR%c",173,33);
        dibujarCuadro(43,0,79,24);
        dibujarCuadro(0,1,41,24);//   <-------   MENU 1
        dibujarCuadro(1,0,40,2);//   <-------   TITULO
        dibujarLinea(2,1,39,32);//   <-------   SEPARADOR
        dibujarLinea(2,3,39,61);//   <-------   OCULTA LINEA
        dibujarCuadro(1,4,40,23);//   <-------   MENU 2
        gotoxy (3,5);
        printf("%c1%c. Ver Perfil.",91,93);
        gotoxy (3,6);
        printf("%c2%c. Ver Catalogo.",91,93);
        gotoxy (3,7);
        printf("%c3%c. Ver Favoritos.",91,93);
        gotoxy (3,21);
        printf("%c0%c. Cerrar Sesion.",91,93);
        gotoxy (3,20);
        printf("%c5%c. \033[0;31mDar de baja\033[0m.",91,93);
        gotoxy (3,22);
        printf("%c %c. Opcion Selecionada.",91,93);
}

// - FRONT SELECCION SESION
void frontSeleccionSesion()
{
    gotoxy(10,2);
        printf("Registro Usuario");
        dibujarCuadro(8,1,27,3);
        dibujarLinea(3,4,33,61);
        dibujarCuadro(1,5,35,23);
        dibujarCuadro(0,0,36,24);
        gotoxy (3,7);
        printf("%c1%c. Registrarse como Usuario.",91,93);
        gotoxy (3,9);
        printf("%c2%c. Registrarse como Admin.",91,93);
        gotoxy (3,21);
        printf("%c0%c. \033[0;31mEXIT\033[0m.",91,93);
        gotoxy (3,22);
        printf("%c %c. Opcion Selecionada.",91,93);
}

// - FRONT MENU PERFIL USUARIO
void frontMenuPerfilUsuario()
{
    dibujarCuadro(0,1,35,24);//   <-------   CUADRADO Principal
        dibujarCuadro(1,3,34,23);//   <-------   CUADRADO secundario
        dibujarCuadro(36,1,79,24); // <------- CUADRADO PRINCIPAL MUESTRA
        dibujarCuadro(37,3,78,23); // <------- CUADRADO MUESTRA
        dibujarCuadro(1,0,9,2);//   <-------   TITULO Principal
        dibujarCuadro(37,0,60,2); // <------- TITULO Secundario
        printf("\033[1;34m");
        dibujarLinea(38,8,77,196); // SEPARADOR 1
        dibujarLinea(38,13,77,196); // SEPARADOR 2
        dibujarLinea(38,18,77,196); // SEPARADOR 3
        printf("\033[0m");
        dibujarCuadro(2,5,33,7);
        dibujarCuadro(2,9,33,11);
        dibujarCuadro(2,13,33,15);
        dibujarCuadro(2,17,33,19);
        gotoxy(38,1);
        printf("PELICULAS FAV. USUARIO");
        gotoxy(2,1);
        printf("USUARIO");
        gotoxy(3,20);
        printf("[1] Editar.");
        gotoxy(15,20);
        printf("[2] Sig.Pag.Fav.");
        gotoxy(15,21);
        printf("[3] Volver Inc.");
        gotoxy(3,21);
        printf("[0] \033[0;31mEXIT.\033[0m");
        gotoxy(3,22);
        printf("[ ] Opcion Seleccionada.");
}

// - FRONT DEL MENU DE PELICULAS FILTRADAS DEL CATALOGO
void frontVerCatalogoFiltro()
{
    dibujarCuadro(0,1,30,24); // CUADRADO PRINCIPAL
    dibujarCuadro(31,1,79,24); // CUADRADO PRINCIPAL MUESTRA
    dibujarCuadro(1,3,29,23); // CUADRADO BAJO T1
    dibujarCuadro(32,3,78,23); // CUADRADO MUESTRA
    dibujarCuadro(1,0,20,2); // TITULO PRINCIPAL
    dibujarCuadro(33,0,43,2); // TITULO SECUNDARIO
    printf("\033[1;34m");
    dibujarLinea(33,8,77,196); // SEPARADOR 1
    dibujarLinea(33,13,77,196); // SEPARADOR 2
    dibujarLinea(33,18,77,196); // SEPARADOR 3
    printf("\033[0m");
    gotoxy(2,1);
    printf("CATALOGO PELICULAS");
    gotoxy(34,1);
    printf("PELICULAS");
    gotoxy(3,5);
    printf("[1] Filtrar Peliculas.");
    gotoxy(3,7);
    printf("[2] Sig. Pagina Peliculas.");
    gotoxy(3,9);
    printf("[3] Volver Principio Pag.");
    gotoxy(3,11);
    printf("[4] Agregar a Favoritos.");
    gotoxy(3,21);
    printf("[0] \033[0;31mEXIT FILTRO\033[0m.");
    gotoxy(3,22);
    printf("[ ] Opcion Seleccionada.");
}

// - FRONT DEL MENU LISTA USUARIOS
void frontMenuListaUsuarios()
{
    dibujarCuadro(0,1,33,24);//   <-------   CUADRADO PRINCIPAL
        dibujarCuadro(34,1,78,24);//   <-------   CUADRADO PRINCIPAL LISTA
        dibujarCuadro(35,3,77,24);//   <-------   CUADRADO LISTA
        dibujarCuadro(1,3,32,23);//   <-------   CUADRADO OPCIONES
        dibujarCuadro(1,0,21,2);//   <-------   TITULO "opciones usuario"
        dibujarCuadro(35,0,44,2);//   <-------   TITULO "usuario"
        printf("\033[1;34m");
        dibujarLinea(36,6,76,196); // SEPARADOR 1
        dibujarLinea(36,9,76,196); // SEPARADOR 2
        dibujarLinea(36,12,76,196); // SEPARADOR 3
        dibujarLinea(36,15,76,196); // SEPARADOR 4
        dibujarLinea(36,18,76,196); // SEPARADOR 5
        dibujarLinea(36,21,76,196); // SEPARADOR 6
        printf("\033[0m");
        gotoxy(36,1);
        printf("USUARIOS");
        gotoxy(2,1);
        printf(" Opciones Usuarios ");
        gotoxy (3,5);
        printf("[1]. Ver Info. Usuario.");
        gotoxy (3,7);
        printf("[2]. Dar de Baja a Usuario.");
        gotoxy (3,9);
        printf("[3]. Dar de Alta a Usuario.");
        gotoxy (3,11);
        printf("[4]. Sig. Lista Usuarios.");
        gotoxy (3,13);
        printf("[5]. Volver inic. Lista.");
        gotoxy (3,21);
        printf("[0]. \033[0;31mEXIT\033[0m.");
        gotoxy (3,22);
        printf("[ ]. Opcion Selecionada.");
        gotoxy(45,2);
        printf("[\033[1;32m%c\033[0m] HABILITADO",254);
        gotoxy(60,2);
        printf("[\033[0;31m%c\033[0m] DESAHABILITADO",254);
}

//- FRONT DEL MENU AGREGAR FAVORITOS
void frontAgregarFavorito()
{
    dibujarCuadro(0,1,30,24); // CUADRADO PRINCIPAL
    dibujarCuadro(31,1,79,24); // CUADRADO PRINCIPAL MUESTRA
    dibujarCuadro(1,3,29,23); // CUADRADO BAJO T1
    dibujarCuadro(32,3,78,23); // CUADRADO MUESTRA
    dibujarCuadro(1,0,11,2); // TITULO PRINCIPAL
    dibujarCuadro(33,0,43,2); // TITULO SECUNDARIO
    printf("\033[1;34m");
    dibujarLinea(33,8,77,196); // SEPARADOR 1
    dibujarLinea(33,13,77,196); // SEPARADOR 2
    dibujarLinea(33,18,77,196); // SEPARADOR 3
    printf("\033[0m");
    gotoxy(2,1);
    printf("FAVORITOS");
    gotoxy(34,1);
    printf("PELICULAS");
    gotoxy(3,5);
    printf("[1] Sig. Pagina Peliculas.");
    gotoxy(3,7);
    printf("[2] Volver Pag. Inicio.");
    gotoxy(3,9);
    printf("[3] Sacar de Favoritos.");
    gotoxy(3,20);
    printf("[0] \033[0;31mEXIT\033[0m.");
    gotoxy(3,22);
    printf("[ ] Opcion Seleccionada.");
}


//- FRONT DE VER CATALOGO EN USUARIO:

void frontVerCatalogoEnUsuario()
{
    dibujarCuadro(0,1,30,24); // CUADRADO PRINCIPAL
    dibujarCuadro(31,1,79,24); // CUADRADO PRINCIPAL MUESTRA
    dibujarCuadro(1,3,29,23); // CUADRADO BAJO T1
    dibujarCuadro(32,3,78,23); // CUADRADO MUESTRA
    dibujarCuadro(1,0,20,2); // TITULO PRINCIPAL
    dibujarCuadro(33,0,43,2); // TITULO SECUNDARIO
    printf("\033[1;34m");
    dibujarLinea(33,8,77,196); // SEPARADOR 1
    dibujarLinea(33,13,77,196); // SEPARADOR 2
    dibujarLinea(33,18,77,196); // SEPARADOR 3
    printf("\033[0m");
    gotoxy(2,1);
    printf("CATALOGO PELICULAS");
    gotoxy(34,1);
    printf("PELICULAS");
    gotoxy(3,5);
    printf("[1] Filtrar Peliculas.");
    gotoxy(3,7);
    printf("[2] Sig. Pagina Peliculas.");
    gotoxy(3,9);
    printf("[3] Volver Principio Pag.");
    gotoxy(3,11);
    printf("[4] Agregar a Favoritos.");
    gotoxy(3,21);
    printf("[0] \033[0;31mEXIT\033[0m.");
    gotoxy(3,22);
    printf("[ ] Opcion Seleccionada.");
}







//------------------------------------------------------------------------------------------------------------



/**     ---------------                 FUNCIONES QUE VALIDAN LA INFORMACION DE LOS USUARIOS         -----------------       **/


//VALIDACION USUARIO ADMINISTRADOR:
int validacionAdmin(char email[], char pass[], char pin[])
{
    int flag = 0;
    stUser user;
    FILE *archivo;
    archivo = fopen("Usuario.bin", "rb");
    if(archivo != NULL)
    {
        while(!feof(archivo) && flag == 0)
        {
            fread(&user, sizeof(stUser),1, archivo);
            if(strcmp(email,&user.email)==0 && strcmp(pass,&user.pass)==0 && strcmp(pin,&user.pin)== 0)
            {
                flag=1;
            }
        }
        fclose(archivo);
    }
    return flag;
}

//VERICA SI EL USUARIO YA ESTA EN LOS ARCHIVOS
int validacion(char email[], char pass[])
{
    int flag = 0;
    stUser user;
    FILE *archivo;
    archivo = fopen("Usuario.bin", "rb");
    if(archivo != NULL)
    {
        while(!feof(archivo) && flag == 0)
        {
            fread(&user, sizeof(stUser),1, archivo);
            if(strcmp(email,&user.email)==0 && strcmp(pass,&user.pass)==0)
            {
                flag=1;
            }
        }
        fclose(archivo);
    }
    return flag;
}

//VERICA EL ESTADO DE ALTA / BAJA DEL USUARIO
int validacioneEstado(char email[])
{
    int flag = 0;
    stUser user;
    FILE *archivo;
    archivo = fopen("Usuario.bin", "rb");
    if(archivo != NULL)
    {
        while(!feof(archivo) && flag == 0)
        {
            fread(&user, sizeof(stUser),1, archivo);
            if(strcmp(email,&user.email)==0 && user.altaBaja == 1)
            {
                flag=1;
            }
        }
        fclose(archivo);
    }
    return flag;
}

void validacionUsuario()
{
    dibujarCuadro(20,9,59,14);  // <------- CUADRADO MENU
    dibujarLinea(21,10,58,32);  // <------- LINEA VACIA
    dibujarLinea(21,11,58,32);  // <------- LINEA VACIA
    dibujarLinea(21,12,58,32); // <------- LINEA VACIA
    dibujarLinea(21,13,58,32);  // <------- LINEA VACIA
    dibujarCuadro(25,11,54,13); // <------- MENU 2
    dibujarLinea(26,12,53,176); // <-------  LINEA DE RELLENO
    char email[30];
    centrarTexto("Ingrese Email Usuario:",10);
    fflush(stdin);
    gotoxy(26,12);
    gets(email);
    int valor = existenciaUsuario(email);
    if(valor == 1)
    {
        menuPerfilUsuario(email,0);
    }
    else
    {
        noExisteUsuario();
    }
}

int existenciaUsuario(char email[])
{
    int flag = 0;
    stUser user;
    FILE *archivo;
    archivo = fopen("Usuario.bin", "rb");
    if(archivo != NULL)
    {
        while(!feof(archivo) && flag == 0)
        {
            fread(&user, sizeof(stUser),1, archivo);
            if(strcmp(email,&user.email)==0)
            {
                flag=1;
            }
        }
        fclose(archivo);
    }
    return flag;
}


//------------------------------------------------------------------------------------------------------------




/**     ---------------                 FUNCIONES CAMBIA ESTADO DEL USUARIO EN ALTA Y BAJA          -----------------       **/

// DA DE BAJA AL USUARIO
void darBaja(char email[])
{
    stUser usuario;
    FILE *archivo;
    archivo = fopen("Usuario.bin", "r+b");
    if(archivo != NULL)
    {
        while(fread(&usuario,sizeof(stUser),1,archivo)>0)
        {
            if(strcmpi(email,usuario.email)==0)
            {
                int valor = confirmacionBaja();
                if(valor == 1)
                {
                    fseek(archivo,sizeof(stUser) * -1,SEEK_CUR);
                    usuario.altaBaja = 0;
                    fwrite(&usuario,sizeof(stUser),1,archivo);
                    fclose(archivo);
                }
                fclose(archivo);
            }
        }
    }
}

// DA DE ALTA AL USUARIO
void darAlta(char email[])
{
    int flag = 0;
    stUser usuario;
    FILE *archivo;
    archivo = fopen("Usuario.bin", "r+b");
    if(archivo != NULL)
    {
        while(fread(&usuario,sizeof(stUser),1,archivo)>0)
        {
            if(strcmpi(email,usuario.email)==0)
            {
                fseek(archivo,sizeof(stUser) * -1,SEEK_CUR);
                usuario.altaBaja = 1;
                fwrite(&usuario,sizeof(stUser),1,archivo);
                fclose(archivo);
            }
        }
        fclose(archivo);
    }
}

// - FUNCION QUE RECIBE UN EMAIL ELEJIDO, COMPRUEBA SI EXISTE Y LO DA DE BAJA
void validacionBajaUsuario()
{
    dibujarCuadro(20,9,59,14);  // <------- CUADRADO MENU
    dibujarLinea(21,10,58,32);  // <------- LINEA VACIA
    dibujarLinea(21,11,58,32);  // <------- LINEA VACIA
    dibujarLinea(21,12,58,32); // <------- LINEA VACIA
    dibujarLinea(21,13,58,32);  // <------- LINEA VACIA
    dibujarCuadro(25,11,54,13); // <------- MENU 2
    dibujarLinea(26,12,53,176); // <-------  LINEA DE RELLENO
    char email[30];
    centrarTexto("Ingrese Email Usuario:",10);
    fflush(stdin);
    gotoxy(26,12);
    gets(email);
    int valor = existenciaUsuario(email);
    if(valor == 1)
    {
        darBaja(email);
    }
    else
    {
        noExisteUsuario();
    }
}

// - FUNCION QUE RECIBE UN EMAIL ELEJIDO, COMPRUEBA SI EXISTE Y LO DA DE ALTA
void validacionAltaUsuario()
{
    dibujarCuadro(20,9,59,14);  // <------- CUADRADO MENU
    dibujarLinea(21,10,58,32);  // <------- LINEA VACIA
    dibujarLinea(21,11,58,32);  // <------- LINEA VACIA
    dibujarLinea(21,12,58,32); // <------- LINEA VACIA
    dibujarLinea(21,13,58,32);  // <------- LINEA VACIA
    dibujarCuadro(25,11,54,13); // <------- MENU 2
    dibujarLinea(26,12,53,176); // <-------  LINEA DE RELLENO
    char email[30];
    centrarTexto("Ingrese Email Usuario:",10);
    fflush(stdin);
    gotoxy(26,12);
    gets(email);
    int valor = existenciaUsuario(email);
    if(valor == 1)
    {
        darAlta(email);
    }
    else
    {
        noExisteUsuario();
    }
}



//------------------------------------------------------------------------------------------------------------




/**     ---------------                 FUNCIONES QUE MUESTRAN INFORMACION DE USUARIOS          -----------------       **/





// FUNCION IMPRIME DATOS DEL USUARIO
void muestraDatosUsuarios(char email[])
{
    stUser usuario;
    FILE*archivo;
    archivo = fopen("Usuario.bin","rb");
    if(archivo != NULL)
    {
        while(fread(&usuario,sizeof(stUser),1,archivo)>0)
        {
            if(strcmpi(email,usuario.email)==0)
            {
                gotoxy(3,4);
                printf("Nombre y Apellido: ");
                gotoxy(3,8);
                printf ("Nick:");
                gotoxy(3,12);
                printf("Email:");
                gotoxy(3,16);
                printf("Contrase%ca: ",164);
                gotoxy(4,6);
                printf("%s",usuario.datosUsuarios);
                gotoxy(4,10);
                printf("%s",usuario.nick);
                gotoxy(4,14);
                printf("%s",usuario.email);
                gotoxy(4,18);
                printf("%s",usuario.pass);
            }
        }
    }
    fclose(archivo);
}

// FUNCION QUE LE ASIGNA UN NUMERO DE USUARIO ACORDE A LA CANTIDAD CARGADA EN EL ARCHIVO:
int numeroPilaUsuario()
{
    stUser usuario;
    FILE * archivo;
    archivo = fopen("Usuario.bin","rb");
    int contador = 0 ;
    if(archivo!=NULL)
    {
        while(fread(&usuario,sizeof(stUser),1,archivo)>0)
        {
            contador++;
        }
    }
    return contador;
}

// FUNCION QUE IMPRIME NICK DEL USUARIO EN UN POSICION:
void muestraNick(char email[])
{
    stUser usuario;
    FILE*archivo;
    archivo = fopen("Usuario.bin","rb");
    if(archivo != NULL)
    {
        while(fread(&usuario,sizeof(stUser),1,archivo)>0)
        {
            if(strcmpi(email,usuario.email)==0)
            {
                gotoxy(3,1);
                printf("Nick: %s", usuario.nick);
            }
        }
    }
    fclose(archivo);
}

int muestraUsuarios(int *posicion)
{
    FILE*archivo;
    int y = 4;
    int i =0;
    stUser usuario;
    archivo = fopen("Usuario.bin","rb"); /**  <-------------------   ABRE EL ARCHIVO Y REALIZA LA ACCION DESIGNADA **/

    if(archivo)  /**        <-----------------------------   SI EL ARCHIVO EXISTE REALIZA EL CODIGO **/
    {
        fseek(archivo,posicion,SEEK_SET);

        while(fread(&usuario, sizeof(stUser ),1, archivo)>0 && i < 7)  /**     <-------------------------   MIENTRAS NO LLEGUE EL FINAL DEL ARCHIVO  **/
        {

            gotoxy(37,y);
            printf("[   ]");
            gotoxy(39,y);
            printf("%d", usuario.numPila);
            gotoxy(43,y);
            printf("%s", usuario.datosUsuarios);
            gotoxy(39,y+1);
            printf("\033[1;32m%c>\033[0m Email: %s",192,usuario.email);
            if(usuario.altaBaja == 1)
            {
                gotoxy(73,y);
                printf("[\033[1;32m%c\033[0m]",254);
            }
            else
            {
                gotoxy(73,y);
                printf("[\033[0;31m%c\033[0m]",254);
            }
            y++;
            y++;
            y++;
            i++;
        }
        posicion = ftell(archivo)-sizeof(usuario);
        fclose(archivo);/**              <-----------------------   CIERRA EL ARCHIVO **/
    }
    return posicion;
}

// - FUNCION QUE MUESTRA LA LISTA DE FAVORITOS
int muestraListaFavoritos(char email[],int punteroArreglo)
{
    int x = 33;
    int y = 4;
    int i= punteroArreglo;
    int contador = 0;
    stUser usuario;
    FILE*archivoUsuario;
    archivoUsuario = fopen("Usuario.bin", "r+b");
    if(archivoUsuario)
    {
        while(fread(&usuario,sizeof(stUser),1,archivoUsuario)>0)
        {
            if(strcmpi(email,usuario.email))
            {
                for(i; i< usuario.cantFavoritos && contador < 4; i++)
                {
                    muestraListaPeliculasFavoritas(usuario.favoritos[i], y,x);
                    y++;
                    y++;
                    y++;
                    y++;
                    y++;
                    contador++;
                }
            }
        }
        punteroArreglo += contador;
        fclose(archivoUsuario);
    }
    else
    {
        printf("ARCHIVO NO ENCONTRADO.");
    }
    return punteroArreglo;
}

// - MUESTRA EN EL MENU DE INFORMACION DEL USUARIO LA LISTA DE FAVORITOS:
int muestraListaFavoritosUsuarioDatos(char email[],int punteroArreglo)
{
    int x = 39;
    int y = 4;
    int i= punteroArreglo;
    int contador = 0;
    stUser usuario;
    FILE*archivoUsuario;
    archivoUsuario = fopen("Usuario.bin", "r+b");
    if(archivoUsuario)
    {
        while(fread(&usuario,sizeof(stUser),1,archivoUsuario)>0)
        {
            if(strcmpi(email,usuario.email))
            {
                for(i; i< usuario.cantFavoritos && contador < 4; i++)
                {
                    muestraListaPeliculasFavoritas(usuario.favoritos[i], y,x);
                    y++;
                    y++;
                    y++;
                    y++;
                    y++;
                    contador++;
                }
            }
        }
        punteroArreglo += contador;
        fclose(archivoUsuario);
    }
    else
    {
        printf("ARCHIVO NO ENCONTRADO.");
    }
    return punteroArreglo;
}




//------------------------------------------------------------------------------------------------------------





/**     ---------------                 FUNCIONES ADICIONALES          -----------------       **/





// FUNCION QUE EDITA INFORMACION DE USUARIO
int editarInfoUsuario (char email[])
{
    int flag = 0;
    stUser usuario;                //         <-----------       SE CREA UNA VARIABLE TIPO ESTRUCTURA
    FILE*archivo;                  //         <-----------       CREA UN ARCHIVO
    archivo = fopen("Usuario.bin","r+b");      //         <-----------       SE ABRE ARCHIVO Y R+B SIG: SE LEE EN BINARIO
    if(archivo != NULL)      //         <-----------       SI ES DIFERENTE QUE NULL(NADA) SE ABRE
    {
        while(fread(&usuario,sizeof(stUser),1,archivo) > 0 ) //         <-----------       SI NO TIENE MAS USUARIOS TERMINA EL WHILE
        {
            if(strcmpi(email,usuario.email) == 0 )      //         <-----------       SI EN LA COMPARACION LO ENCONTRO VA A EJECUTAR EL CODIGO.
            {
                system("cls");
                dibujarCuadro(0,1,41,24);//   <-------   MENU 1
                dibujarCuadro(1,0,40,2);//   <-------   TITULO
                dibujarLinea(2,1,39,32);//   <-------   OCULTA LINEA
                dibujarCuadro(1,3,40,23);//   <-------   MENU 2
                gotoxy(8,1);
                printf("Nuevos Datos Usuario");
                fflush(stdin);

                fseek(archivo,sizeof(stUser) * -1,SEEK_CUR); //         <-----------       VUELVE UNO PARA ATRAS PARA SOBRE ESCRIBIRLO

                gotoxy(3,4);
                printf("Nuevo Nombre y Apellido: ");
                dibujarCuadro(3,5,33,7);
                dibujarLinea(4,6,32,176);
                gotoxy(3,8);
                printf ("Nuevo Nick:");
                dibujarCuadro(3,9,33,11);
                dibujarLinea(4,10,32,176);
                gotoxy(3,12);
                printf("Nuevo Email:");
                dibujarCuadro(3,13,33,15);
                dibujarLinea(4,14,32,176);
                gotoxy(3,16);
                printf("Nueva Contrase%ca: ",164);
                dibujarCuadro(3,17,33,19);
                dibujarLinea(4,18,32,176);
                gotoxy(4,6);
                gets(usuario.datosUsuarios);
                gotoxy(4,10);
                gets(usuario.nick);
                gotoxy(4,14);
                gets(usuario.email);
                gotoxy(4,18);
                gets(usuario.pass);
                flag =1;
                fwrite(&usuario,sizeof(stUser),1,archivo);     //         <-----------       LO VA A ESCRIBIR EN LA POSICION
                fclose(archivo); //         <-----------       CIERRA EL ARCHIVO ASI NO SE PIERDE LA INFO
            }
        }
    }
    return flag;
}

// - FUNCION QUE RECIBE UN FAV ELEJIDO, VERIFICA SI EXISTE Y LO AGREGA
void agregarFavorito(char email[])
{
    stUser usuario;
    FILE*archivoUsuario;
    archivoUsuario = fopen("Usuario.bin", "r+b");
    if(archivoUsuario)
    {
        while(fread(&usuario,sizeof(stUser),1,archivoUsuario)>0)
        {
            if(strcmpi(email,usuario.email))
            {
                int fav = 0;
                cartelFavoritoAgregado();
                gotoxy(50,10);
                fflush(stdin);
                scanf("%d",&fav);
                int valor =validacioneNumeroPila(fav);
                if(valor == 1)
                {
                    fseek(archivoUsuario,sizeof(usuario)*-1,SEEK_CUR);
                    usuario.favoritos[usuario.cantFavoritos] = fav;
                    usuario.cantFavoritos++;
                    guardadoFavorito();
                    fwrite(&usuario,sizeof(stUser),1,archivoUsuario);
                    fclose(archivoUsuario);
                }
                else
                {
                    noExisteFavorito();
                }
            }
        }
    }
    else
    {
        printf("ARCHIVO NO ENCONTRADO.");
    }
}

// - FUNCION MUESTRA UN CARTEL QUE EL FAV. ELEGIDO FUE AGREGADO
void cartelFavoritoAgregado()
{
    dibujarLinea(23,8,53,32);
    dibujarLinea(23,9,53,32);
    dibujarLinea(23,10,53,32);
    dibujarLinea(23,11,53,32);
    dibujarLinea(23,11,53,32);
    dibujarCuadro(22,8,54,12);
    dibujarCuadro(49,9,53,11);
    dibujarLinea(50,10,52,176);
    gotoxy(24,10);
    printf("N%c Pelicula para Agregar:", 248);

}

// - FUNCION QUE RECIBE UN FAV ELEJIDO Y LO ELIMINA DE LA LISTA
void eliminarFavorito(char email[])
{
    Pila pilaaux;
    inicpila (&pilaaux);

    int flag = 0;

    stUser usuario;
    FILE*archivoUsuario;
    archivoUsuario = fopen("Usuario.bin", "r+b");
    if(archivoUsuario)
    {
        int favEliminado = 0;
        cartelFavoritoEliminado();
        gotoxy(50,10);
        fflush(stdin);
        scanf("%d",&favEliminado);

        while(flag == 0 && fread(&usuario,sizeof(stUser),1,archivoUsuario)>0)
        {
            if(strcmpi(email,usuario.email))
            {
                fseek(archivoUsuario,sizeof(usuario)*-1,SEEK_CUR);
                int i=0;
                while(i < usuario.cantFavoritos)
                {
                    if(favEliminado != usuario.favoritos[i])
                    {
                        apilar(&pilaaux, usuario.favoritos[i]);
                    }
                    i++;
                }
                flag = 1;
            }
        }
        int i = 0;
        while(!pilavacia(&pilaaux))
        {
            usuario.favoritos[i]= desapilar(&pilaaux);
            i++;
        }
        usuario.cantFavoritos--;
        fwrite(&usuario,sizeof(stUser),1,archivoUsuario);
        fclose(archivoUsuario);
    }
    else
    {
        printf("ARCHIVO NO ENCONTRADO.");
    }
}


// - FUNCION MUESTRA CARTEL QUE EL FAV. ELEGIDO FUE ELIMINADO
void cartelFavoritoEliminado()
{
    dibujarLinea(23,8,53,32);
    dibujarLinea(23,9,53,32);
    dibujarLinea(23,10,53,32);
    dibujarLinea(23,11,53,32);
    dibujarLinea(23,11,53,32);
    dibujarCuadro(22,8,54,12);
    dibujarCuadro(49,9,53,11);
    dibujarLinea(50,10,52,176);
    gotoxy(24,10);
    printf("N%c Pelicula a Eliminar:", 248);

}





//------------------------------------------------------------------------------------------------------------
















