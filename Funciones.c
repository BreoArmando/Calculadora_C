#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

//FIRMAS FUNCIONES
void muestraOperacionesDisponibles (int numOperaciones);
void muestraOpcionNoDisponible();
void muestraOperacionNoDisponible();
void muestraOpcionUOperacion (int numOperaciones);
int menu (int numOperacionesSuma, int numOperacionesResta, int numOperacionesMultiplicacion, int numOperacionesDivision);
int intercambiaValor (int num);
bool compruebaQueIsContadorDeOperacionesMayorQueCero (int numOperaciones);
void muestraValores (int n1, int n2);
int hazSuma (int num1, int num2);
int hazResta (int num1, int num2);
int hazMultiplicacion (int num1, int num2);
bool isDivisorMayorQue0 (int divisor);
int obtenCocienteDeDivision (unsigned int dividendo, unsigned int divisor);
int obtenRestoDeDivision (unsigned int dividendo, unsigned int divisor);
void muestraResultadoDivision(int resultado, int resto);
void hazDivisionEnteraConResto (int Dividendo, int Divisor, int *Cociente, int *Resto);


//IMPLEMENTACIÓN FUNCIONES
void muestraOperacionesDisponibles (int numOperaciones)
{
    printf("--> %i operaciones disponibles.\n", numOperaciones);
}

void muestraOpcionNoDisponible()
{
    printf("--> Opción no disponible.\n");
}

void muestraOperacionNoDisponible()
{
    printf("--> Operación no disponible !! Puede suscribirse para disfrutar de las funcionalidades ampliadas.\n");
}

void muestraOpcionUOperacion (int numOperaciones)
{
    if (numOperaciones > 0)
    {
        muestraOperacionesDisponibles(numOperaciones);
    }
    else
    {
        if (numOperaciones < 0)
        {
            muestraOperacionNoDisponible();
        }
        else
        {
            muestraOpcionNoDisponible();
        }
    }
}

int menu (int numOperacionesSuma, int numOperacionesResta, int numOperacionesMultiplicacion, int numOperacionesDivision)
{
    printf("-----------------------------------\n");
    printf("-----------------------------------\n");

    printf("Pulsa 1 para sumar "); 
    muestraOpcionUOperacion(numOperacionesSuma);

    printf("Pulsa 2 para restar ");
    muestraOpcionUOperacion(numOperacionesResta);

    printf("Pulsa 3 para multiplicar "); 
    muestraOpcionUOperacion(numOperacionesMultiplicacion);

    printf("Pulsa 4 para dividir "); 
    muestraOpcionUOperacion(numOperacionesDivision);

    printf("Pulsa 0 para salir \n");
}

int intercambiaValor (int num)
{
    int numCambiado = num;

    return numCambiado;
}

bool compruebaQueIsContadorDeOperacionesMayorQueCero (int numOperaciones)
{
    bool isContadorDeOperacionesMayorQue0 = true;

    if (numOperaciones < 0)
    {
        isContadorDeOperacionesMayorQue0 = false;
    }

    return isContadorDeOperacionesMayorQue0;
}

void muestraValores (int n1, int n2)
{
    printf("El primer valor es %i y el segundo, %i. \n", n1, n2);
}

int hazSuma (int num1, int num2)
{
    int resultado = 0;

    resultado = num1 + num2;
    return resultado;
}

int hazResta (int num1, int num2)
{
    int resultado = 0;

    resultado = num1 - num2;
    return resultado;
}

int hazMultiplicacion (int num1, int num2)
{
    int multiplo1 = fabs(num1);
    int multiplo2 = fabs(num2);
    bool isResultadoPositivo = false;
    int temp = 0;
    int resultado = 0;

    if (num1 < 0 && num2 < 0)
    {
        isResultadoPositivo = true;
    }
    else if (num1 >= 0 && num2 >= 0)
    {
        isResultadoPositivo = true;
    }

    if (multiplo2 > multiplo1)
    {
        temp = multiplo1;
        multiplo1 = multiplo2;
        multiplo2 = temp;
    }

    for (unsigned short int i = 1; i <= multiplo2; i++)
    {
        resultado = resultado + multiplo1;
    }

    if (isResultadoPositivo)
    {
        return resultado;
    }
    
    return - resultado;
}

bool isDivisorMayorQue0 (int divisor)
{
    bool isOperacionValida = true;

    if (divisor == 0)
    {
        isOperacionValida = false;
    }

    return isOperacionValida;
}

int obtenCocienteDeDivision (unsigned int dividendo, unsigned int divisor)
{
    int cociente = 0;

    while (dividendo >= divisor)
    {
        dividendo = dividendo - divisor;
        cociente = cociente + 1;
    }

    return cociente;
}

int obtenRestoDeDivision (unsigned int dividendo, unsigned int divisor)
{
    int cociente = 0;
    int resto = dividendo;

    while (resto >= divisor)
    {
        resto = resto - divisor;
        cociente = cociente + 1;
    }

    return resto;
}

void muestraResultadoDivision(int resultado, int resto)
{
    printf("El cociente es %i y el resto es %i.\n", resultado, resto);
}

void hazDivisionEnteraConResto (int Dividendo, int Divisor, int *Cociente, int *Resto)
{
    int cocient = obtenCocienteDeDivision(Dividendo, Divisor);
    int rest = obtenRestoDeDivision(Dividendo, Divisor);

    *Cociente = cocient;
    *Resto = rest;
}
