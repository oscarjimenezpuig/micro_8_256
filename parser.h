/* Calculadora 23/4/26 */

#include "programa.h"

/* INSTRUCCIONES
 * LDA <valor>: Carga registro A
 * LDB <valor>: Carga registro B
 * LDI <valor>: Carga registro I
 * LDJ <valor>: Carga registro J
 * LAI: Carga registro A con el valor que apunta I
 * LIA: Inversa de LAI
 * MVA: Copia registro B en A
 * MVB: Inversa MVA
 * MVI: Copia registro J en I
 * MVJ: Inversa MVI
 * SWA: Intercambia A y B
 * SWI: Intercambia I y J
 * AND: Entre A y B
 * OR: Entre A y B
 * XOR: Entre A y B
 * NOT: De A
 * RGT: Desplazamiento derecho de A
 * LFT: Desplazamiento izquierdo de A
 * INC: Incremento de A
 * DEC: Decremento de A
 * OUV: Pasa un valor a imprimir del registro A
 * OUC: Pasa un caracter a imprimir del registro A
 * IPV: Valor entrada a registro A
 * IPC: Caracter entrado a registro A
 * CLR: Borrado buffer impresion
 * JMP <valor>: Salto a direccion
 * IFZ <valor>: Salto si cero
 * IFN <valor>: Salto si negativo
 * IFR <valor>: Salto si carry derecho
 * IFL <valor>: Salto si carry izquierdo
 * INZ <valor>: Salto si no cero
 * INN <valor>: Salto si no negativo
 * INR <valor>: Salto si no carry right
 * INL <valor>: Salto si no carry left
 * CLL <valor>: Llamada a subrutina
 * RET: Retorno de subrutina
 * STP: Final ejecucion
 */

void parse(char* filename);
/* funcion que abre el archivo, lo parsea y lo ejecuta */
