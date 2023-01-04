#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <locale.h>

/**  -------------            MENUS PROGRAMA           ------------------         **/

// - FUNCION QUE MUESTRA MENU DE OPCIONES
void menuPrincipal()
{
    int op = 0;
    int condicionCorte = 0;
    while ( condicionCorte == 0 )
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
        dibujarCuadro(0,0,41,24);
        dibujarCuadro(43,0,79,24);
        dibujarCuadro(1,1,40,3);
        gotoxy(14,2);
        printf("Menu Principal");
        gotoxy(2,4);
        puts("======================================");
        dibujarCuadro(1,5,40,23);
        gotoxy (3,7);
        printf("%c1%c. Iniciar Sesion.",91,93);
        gotoxy (3,9);
        printf("%c2%c. Registrarse.",91,93);
        gotoxy (3,19);
        printf("%c4%c. Inciar Sesion como Admin.",91,93);
        gotoxy (3,21);
        printf("%c0%c. \033[0;31mEXIT\033[0m.",91,93);
        gotoxy (3,22);
        printf("%c %c. Opcion Selecionada.",91,93);
        fflush(stdin);
        gotoxy(4,22);
        scanf("%i",&op);
        if( op<0 ||op>=6 )
        {
            gotoxy(3,22);
            printf("       \033[0;31mSU OPCION NO CORRESPONDE\033[0m.     ");
            Sleep(1500);
        }
        switch (op)
        {
        case 1:
            login();
            break;
        case 2:
            seleccionSesion();
            break;
        case 4:
            loginAdmin();
            break;
        case 0:
            condicionCorte++;
            break;
        }
    }
    finalPrograma();
}

// - FUNCION FINAL DE PROYECTO
void proyectoFinal()
{
    system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
    pantallaCarga();
    menuPrincipal();
}

// - FUNCION QUE HACE BARRA DE CARGA
void barraCarga()
{
    centrarTexto("Cargando....", 20);
    for(int i =3 ; i<76 ; i++ )
    {
        gotoxy (i, 22);
        printf("%c",176);
    }
    for(int i =3 ; i<76 ; i++ )
    {
        gotoxy (i, 22);
        printf("%c",219);
        Sleep(35);
    }

}

// - FUNCION QUE MUESTRA PANTALLA DE CARGA
void pantallaCarga()
{
    dibujarCuadro(0,0,79,24);
    logoFacultad(36);
    barraCarga();
}

// - FUNCION QUE MUESTRA PANTALLA DE FINALIZACION DEL PROGRAMA :

void finalPrograma()
{
    hidecursor(0);
    system("cls");
    dibujarCuadro(0,0,78,24);
    dibujarCuadro(24,9,56,11);
    gotoxy(26,10);
    printf("\033[1;32mMUCHAS GRACIAS POR VISITARNOS.\033[0m");
    Sleep(1500);
}

// - LOGO DE LA TV DEL PROGRAMA EN ASCII
void logo(int x)
{
    system("cls");
    dibujarCuadro( x-3, 1,x+12,7 );
    printf("\033[1;32m");
    gotoxy(x,2);
    printf(" %c%c  %c%c  \n",223,220,220,223);
    gotoxy(x,3);
    printf("%c%c%c%c%c%c%c%c%c%c\n",220,220,220,219,219,220,220,220,220,220);
    gotoxy(x,4);
    printf("\033[0m");
    printf("\033[1;32m%c\033[0m%c%c%c%c%c%c\033[1;32m%c%c%c\n",219,178,177,178,177,178,177,219,223,219);
    gotoxy(x,5);
    printf("\033[1;32m%c\033[0m%c%c%c%c%c%c\033[1;32m%c%c%c\n",219,178,177,178,177,178,177,219,223,219);
    gotoxy(x,6);
    printf("\033[1;32m%c%c%c%c%c%c%c%c%c%c\033[0m\n",219,220,220,220,220,220,220,219,219,219);
    dibujarCuadro(x-3,8,x+12,10);
    gotoxy(x-1,9);
    printf("Pelis  Locas");
    hidecursor(0);

}

// - LOGO 2 DE LA TV DEL PROGRAMA EN ASCII
void logo2(int x)
{
    dibujarCuadro( x-3,14,x+12,22 );
    printf("\033[1;32m");
    gotoxy(x,16);
    printf(" %c%c  %c%c  \n",223,220,220,223);
    gotoxy(x,17);
    printf("%c%c%c%c%c%c%c%c%c%c\n",220,220,220,219,219,220,220,220,220,220);
    gotoxy(x,18);
    printf("\033[0m");
    printf("\033[1;32m%c\033[0m%c%c%c%c%c%c\033[1;32m%c%c%c\n",219,178,177,178,177,178,177,219,223,219);
    gotoxy(x,19);
    printf("\033[1;32m%c\033[0m%c%c%c%c%c%c\033[1;32m%c%c%c\n",219,178,177,178,177,178,177,219,223,219);
    gotoxy(x,20);
    printf("\033[1;32m%c%c%c%c%c%c%c%c%c%c\033[0m\n",219,220,220,220,220,220,220,219,219,219);

}

// - LOGO DE CARTEL EN LA CONFIRMACION
void logoPibe(x)
{
    gotoxy(x,4);printf("       %c%c%c%c%c%c%c%c",220,223,223,223,223,223,223,220);
    gotoxy(x,5);printf("      %c %c%c  %c%c %c",219,254,254,254,254,219);
    dibujarLinea(x,6,x+21,223);
    dibujarLinea(x,7,x+21,223);
    dibujarLinea(x,8,x+21,223);
}

// - FUNCION LOGO UTN
void logoFacultad(int x)
{
    dibujarCuadro(x-2,4,x+10,10);
    gotoxy(x,5);
    printf("%c   %c   %c\n",186,186,186);
    gotoxy(x,6);
    printf("%c%c%c%c%c%c%c%c%c\n",200,205,205,205,206,205,205,205,188);
    gotoxy(x,7);
    printf("%c%c%c%c%c%c%c%c%c\n",205,205,205,205,206,205,205,205,205);
    gotoxy(x,8);
    printf("%c%c%c%c%c%c%c%c%c\n",201,205,205,205,206,205,205,205,187);
    gotoxy(x,9);
    printf("%c   %c   %c\n",186,186,186);
    dibujarCuadro(27,12,53,15);
    centrarTexto("Univercidad Tecnologica",13);
    centrarTexto("Mar del Plata",14);
    hidecursor(0);
}



//-------------------------------------------------------------------------------------


/**  -------------            FUNCIONES QUE AYUDAN PARA HACER FRONT           ------------------         **/

// - FUNCION QUE DIBIJA UN CUADRADO
void dibujarCuadro(int x1,int y1,int x2,int y2)
{
    printf("\033[1;34m");
    int i;

    for (i=x1; i<x2; i++)
    {
        gotoxy(i,y1);
        printf("\304"); //linea horizontal superior
        gotoxy(i,y2);
        printf("\304"); //linea horizontal inferior
    }

    for (i=y1; i<y2; i++)
    {
        gotoxy(x1,i);
        printf("\263"); //linea vertical izquierda
        gotoxy(x2,i);
        printf("\263"); //linea vertical derecha
    }

    gotoxy(x1,y1);
    printf("\332");
    gotoxy(x1,y2);
    printf("\300");
    gotoxy(x2,y1);
    printf("\277");
    gotoxy(x2,y2);
    printf("\331");
    printf("\033[0m");
}

// - FUNCION QUE CENTRA UN TEXTO
void centrarTexto(char *texto, int y)
{
    int longitud = strlen(texto);
    gotoxy(40-(longitud/2),y);
    printf(texto);
}

// - FUNCION QUE HACE UN FONDO BLANCO
void fondoBlanco(int x, int xfin,int limite)
{
    for(int i = 0; i< limite;i++)
    {
        dibujarLinea(x,i,xfin,32);
    }
}

//- FUNCION DIBUJA UNA LINEA DE CUALQUIER CARACTER
void dibujarLinea(int x, int y,int fin, int ascii)
{
    for(int i = x ; i<=fin ; i++ )
    {
        gotoxy (i,y);
        printf("%c",ascii);
    }
}


//-------------------------------------------------------------------------------------



/**  -------------            FUNCIONES QUE MUESTRAN CARTELES           ------------------         **/

// - FUNCION QUE MUESTRA CARTEL QUE NO EXISTE PELICULA PARA EL FILTRO
void noExisteFiltro()
{
    hidecursor(0);
    dibujarLinea(21,4,29,32); //RELLENO BLANCO
    dibujarLinea(20,5,60,32); //RELLENO BLANCO
    dibujarLinea(20,6,60,32); //RELLENO BLANCO
    dibujarLinea(20,7,60,32); //RELLENO BLANCO
    dibujarLinea(20,8,60,32); //RELLENO BLANCO
    dibujarLinea(20,9,60,32); //RELLENO BLANCO
    dibujarLinea(20,10,60,32); //RELLENO BLANCO
    dibujarLinea(20,11,60,32); //RELLENO BLANCO
    dibujarCuadro(20,5,60,11); //CUADRADO 1
    gotoxy(34,8);
    printf("\033[0;31mNO ENCONTRADO.\033[0m");
    Sleep(1500);
}

// - FUNCION MUESTRA UN CARTEL QUE NO EXISTE EL FAVORITO
void noExisteFavorito()
{
    hidecursor(0);
    dibujarLinea(23,9,53,32);
    dibujarLinea(23,10,53,32);
    dibujarLinea(23,11,53,32);
    dibujarCuadro(22,8,54,12);
    gotoxy(32,10);
    printf("\033[0;31mNO ENCONTRADO.\033[0m");
    Sleep(1500);
}

// - FUNCION MUESTRA UN CARTEL QUE NO EXISTE EL USUARIO
void noExisteUsuario()
{
    hidecursor(0);
    dibujarCuadro(20,9,59,14);  // <------- CUADRADO MENU
    dibujarLinea(21,10,58,32);  // <------- LINEA VACIA
    dibujarLinea(21,11,58,32);  // <------- LINEA VACIA
    dibujarLinea(21,12,58,32); // <------- LINEA VACIA
    dibujarLinea(21,13,58,32);  // <------- LINEA VACIA
    gotoxy(31,11);
    printf("\033[0;31mUSUARIO NO EXISTE\033[0m");
    Sleep(1500);
}

// - FUNCION MUESTRA UN CARTEL QUE NO EXISTE LA PELICULA
void noExistePelicula()
{
    dibujarLinea(34,9,77,32); // <-------  LINEA BLANCA
    dibujarLinea(34,10,77,32); // <-------  LINEA BLANCA
    dibujarLinea(34,11,77,32); // <-------  LINEA BLANCA
    dibujarLinea(34,12,77,32); // <-------  LINEA BLANCA
    dibujarLinea(34,13,77,32); // <-------  LINEA BLANCA
    dibujarCuadro(33,9,77,14);  // <------- CUADRADO MENU
    gotoxy(47,11);
    printf("\033[0;31mPELICULA NO EXISTE\033[0m");
    Sleep(1500);
}

// - FUNCION MUESTRA UN CARTEL QUE FAVORITO FUE GUARDADO
void guardadoFavorito()
{
    hidecursor(0);
    dibujarLinea(22,9,53,32);
    dibujarLinea(22,10,53,32);
    dibujarLinea(22,11,53,32);
    dibujarCuadro(22,8,54,12);
    gotoxy(32,10);
    printf("\033[1;32mFAV GUARDADO.\033[0m");
    Sleep(1500);
}

// - FUNCION CORROBORA SI EL USUARIO VA A ESTAR DADO DE BAJA
int confirmacionBaja()
{
    int op=0;
    do
    {
        system("cls");
        logoPibe(28);
        dibujarCuadro(0,0,78,24);
        dibujarCuadro(19,9,59,13);
        gotoxy(21,10);
        printf("%cEsta Seguro de Realizar esta ACCION%c",168,63);
        gotoxy(24,12);
        printf("[1]\033[1;32m CONFIRMAR.\033[0m"); // <---------- "" \033[1;32M ""   COLOCA COLOR EN EL TEXTO Y \033[0m TERMINA.
        gotoxy(44,12);
        printf("[2]\033[0;31m SALIR.\033[0m");
        centrarTexto("[ ] Opcion ELEGIDA.", 15);
        gotoxy(32,15);
        fflush(stdin);
        scanf("%d",&op);
        if(op==0||op>2)
        {
            gotoxy(31,18);printf("\033[0;31mOPCION INCORRECTA...\033[0m");
            Sleep(1500);
        }
    }
    while(op==0||op>2);
    return op;
}

// - FUNCION QUE MUESTRA CARTEL QUE USUARIO DADO DE BAJA
void bajaUsuario()
{
    hidecursor(0);
    dibujarCuadro(0,0,78,24);
    dibujarCuadro(24,9,56,11);
    centrarTexto("\033[0;31mUSUARIO DADO DE BAJ\033[0m", 10);
    Sleep(1500);
}

// - FUNCION QUE CONFIRMA LA CREACION DEL USUARIO :
void confirmacion()
{
    hidecursor(0);
    system("cls");
    dibujarCuadro(0,0,78,24);
    dibujarCuadro(24,9,55,11);
    centrarTexto("USUARIO CREADO CORRECTAMENTE", 10);
    Sleep(1500);
}




































