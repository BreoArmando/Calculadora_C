#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "Funciones.c"

int main()
{
    //DECLARACIÓN E INICIALIZACIÓN DE VARIABLES
    int n1 = 0;
    int n2 = 0;
    int operacion = 0;
    int resultado = 0;
    int resto = 0;
    bool isOperacionValida = true;
    int numOperacionesSuma = 2;
    int numOperacionesResta = 1;
    int numOperacionesMultiplicacion = 4;
    int numOperacionesDivision = 3;
    bool isContadorDeOperacionesMayorQue0;

    do
    {
        isContadorDeOperacionesMayorQue0 = true;

        //SOLICITAR OPERACIÓN:
        menu(numOperacionesSuma, numOperacionesResta, numOperacionesMultiplicacion, numOperacionesDivision);
        scanf("%i", &operacion);

        if (operacion != 0)
        {
            //SOLICITAR DOS VALORES:
            printf("Escribe el primer número: \n");
            scanf("%i", &n1);

            printf("Escribe el segundo número: \n");
            scanf("%i", &n2);

            //MOSTRAR VARIABLES:
            muestraValores(n1, n2);
        }

        //REALIZAR OPERACIÓN:
        switch (operacion)
        {
            case 1:
                resultado = hazSuma(n1, n2);

                numOperacionesSuma--;
                isContadorDeOperacionesMayorQue0 = compruebaQueIsContadorDeOperacionesMayorQueCero(numOperacionesSuma);

                break;

            case 2:
                resultado = hazResta(n1, n2);

                numOperacionesResta--;
                isContadorDeOperacionesMayorQue0 = compruebaQueIsContadorDeOperacionesMayorQueCero(numOperacionesResta);

                break;

            case 3:
                resultado = hazMultiplicacion(n1, n2);

                numOperacionesMultiplicacion--;
                isContadorDeOperacionesMayorQue0 = compruebaQueIsContadorDeOperacionesMayorQueCero(numOperacionesMultiplicacion);

                break;

            case 4:
                int dividendo = fabs(n1);
                int divisor = fabs(n2);
                isOperacionValida = true;

                printf("ATENCIÓN: Se dividirá siempre el número mayor entre el menor.\n");

                if (divisor > dividendo)
                {
                    divisor = intercambiaValor(dividendo);
                    dividendo = intercambiaValor(fabs(n2));
                }
                
                isOperacionValida = isDivisorMayorQue0(divisor);

                if (isOperacionValida)
                {
                    hazDivisionEnteraConResto(dividendo, divisor, &resultado, &resto);
                }

                numOperacionesDivision--;
                isContadorDeOperacionesMayorQue0 = compruebaQueIsContadorDeOperacionesMayorQueCero(numOperacionesDivision);

                break;

            case 0:
                resultado = -1;
        
            default:
                isOperacionValida = false;

                break;
        }

        if (numOperacionesSuma <= 0 && numOperacionesResta <= 0 && numOperacionesMultiplicacion <= 0 && numOperacionesDivision <= 0)
        {
            break;
        }
        
        if (isOperacionValida && isContadorDeOperacionesMayorQue0)
        {
            if (operacion == 4)
            {
                muestraResultadoDivision(resultado, resto);
            }

            if (operacion != 0 && operacion != 4)
            {
                printf("El resultado es %i.\n", resultado);
            }
        }
        else
        {
            printf("La operación no es correcta.\n");
        }
    } while (operacion != 0);

    return 0;
}