#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enumeración para los distintos tipos de instrucción
enum Instruction {
    SET,
    LDR,
    ADD,
    INC,
    DEC,
    STR,
    SHW,
    PAUSE,
    END,
};

// Estructura para almacenar las instrucciones
struct InstructionData {
    enum Instruction instruction;
    char * data1;
    char * data2;
    char * data3;
    char * data4;
};

struct Registers {
    int D1;
    int D2;
    int D3;
    int D4;
    int D5;
    int D6;
    int D7;
    int D8;
    int D9;
    int D10;
};


int getRegisterValue(struct Registers registers, char * registerName){

    int value = -1;

    if (registerName == "D1"){
        value = registers.D1;
    }
    else if (registerName == "D2")
    {
        value = registers.D2;
    }
      else if (registerName == "D3")
    {
        value = registers.D3;
    }
      else if (registerName == "D4")
    {
        value = registers.D4;
    }
      else if (registerName == "D5")
    {
        value = registers.D5;
    }
      else if (registerName == "D6")
    {
        value = registers.D6;
    }
      else if (registerName == "D7")
    {
        value = registers.D7;
    }
      else if (registerName == "D8")
    {
        value = registers.D8;
    }
      else if (registerName == "D9")
    {
        value = registers.D9;
    }
      else if (registerName == "D10")
    {
        value = registers.D10;
    }

    return value
}

// Función para leer las instrucciones desde un archivo de texto
void readInstructions(char *filename, struct InstructionData *instructions, int *instructionCount) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    char line[256];
    *instructionCount = 0;

    while (fgets(line, sizeof(line), file)) {
        char *token;
        //obtengo la linea
        char *remaining = line;
        int data1 = 0, data2 = 0, data3 = 0,data4 = 0;

        // Se obtiene la instrucción, divido la linea para obtener la primera parte de la instruccion
        token = strtok_r(remaining, " ", &remaining);


        if (strcmp(token, "SET") == 0) {
            instructions[*instructionCount].instruction = SET;
        } else if (strcmp(token, "LDR") == 0) {
            instructions[*instructionCount].instruction = LDR;
        } else if (strcmp(token, "ADD") == 0) {
            instructions[*instructionCount].instruction = ADD;
        } else if (strcmp(token, "INC") == 0) {
            instructions[*instructionCount].instruction = INC;
        } else if (strcmp(token, "DEC") == 0) {
            instructions[*instructionCount].instruction = DEC;
        } else if (strcmp(token, "STR") == 0) {
            instructions[*instructionCount].instruction = STR;
        } else if (strcmp(token, "SHW") == 0) {
            instructions[*instructionCount].instruction = SHW;
        } else if (strcmp(token, "PAUSE") == 0) {
            instructions[*instructionCount].instruction = PAUSE;
        } else if (strcmp(token, "END") == 0) {
            instructions[*instructionCount].instruction = END;
        }

        // Se obtienen los datos adicionales, nuevamente dividiendo con el delimitador de espacio

            data1 = strtok_r(remaining, " ", &remaining);

            data2 = strtok_r(remaining, " ", &remaining);
            
            data3 = strtok_r(remaining, " ", &remaining);
      
            data4 = strtok_r(remaining, " ", &remaining);
     



        // Se almacenan los datos en la estructura
        //Todo se almacena en formato char *, luego se convertiran a int si es algun valor entero o immediate, pero
        //en cualquier otro caso data1,data2,data3,data4 seran nombres de registros
        instructions[*instructionCount].data1 = data1;
        instructions[*instructionCount].data2 = data2;
        instructions[*instructionCount].data3 = data3;
        instructions[*instructionCount].data4 = data4;

        (*instructionCount)++;
    }

    fclose(file);
}

// Función para imprimir la memoria y los registros
void showMemoryAndRegisters(int *memory, int accumulator) {
    printf("Memoria:\n");

    for (int i = 0; i < 10; i++) {
        printf("D%d: %d\n", i, memory[i]);
    }

    printf("Registro acumulador: %d\n", accumulator);
}

// Función que ejecuta una instrucción
void executeInstruction(struct InstructionData instruction, int *memory, struct Registers registers, int *accumulator) {

    switch (instruction.instruction) {
        case SET:
            int address = getRegisterValue(registers,instruction.data1);
            int value = atoi(instruction.data2);
            if (value != -1){memory[address] = value}
            break;
            /*
        case LDR:
            *accumulator = memory[instruction.data1];
            break;
        case ADD:
            if (instruction.data3 == 0) {
                *accumulator += memory[instruction.data1];
            } else {
                memory[instruction.data3] = *accumulator + memory[instruction.data1];
            }
            break;
        case INC:
            memory[instruction.data1]++;
            break;
        case DEC:
            memory[instruction.data1]--;
            break;
        case STR:
            memory[instruction.data1] = *accumulator;
            break;
        case SHW:
            if (instruction.data1 == 8) {
                printf("Memoria[%d]: %d\n", instruction.data2, memory[instruction.data2]);
            } else {
                printf("D%d: %d\n", instruction.data1, memory[instruction.data1]);
            }
            break;
            */
        case PAUSE:
            break;
        case END:
            break;
    }
}

int main() {
    //aceptaremos programas con menos de 100 lines
    struct InstructionData instructions[100];
    int instructionCount;
    //Este arreglo sera como la memoria principal
    int memory[30];
    //Aqui inicializo mis registros
    struct Registers registers = { .D1 = 1, .D2 = 2, .D3 = 3, .D4 = 4, .D5 = 5, .D6 = 6, .D7 = 7, .D8 = 8, .D9 = 9, .D10 = 10};
    int accumulator = 0;

    //inicializamos la memoria 
    for (int i = 0; i < 10; i++) {
        memory[i] = 0;
    }

    //voy a leer todas las lineas del archivo
    readInstructions("programa1.txt", instructions, &instructionCount);




    for (int i = 0; i < instructionCount; i++) {
        executeInstruction(instructions[i], memory, registers, &accumulator);
    }

    showMemoryAndRegisters(memory, accumulator);

    return 0;
}