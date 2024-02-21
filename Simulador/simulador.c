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
    int ICR;
    int MAR;
    int MDR;
    int UC;
};

void showRegisters(struct Registers * registers){

     
    printf("D1: %d\n",registers->D1);
    printf("D2: %d\n",registers->D2);
    printf("D3: %d\n",registers->D3);
    printf("D4: %d\n",registers->D4);
    printf("D5: %d\n",registers->D5);
    printf("D6: %d\n",registers->D6);
    printf("D7: %d\n",registers->D7);
    printf("D8: %d\n",registers->D8);
    printf("D9: %d\n",registers->D9);
    printf("D10: %d\n",registers->D10);
    printf("ICR: %d\n",registers->ICR);
    printf("MAR: %d\n",registers->MAR);
    printf("MDR: %d\n",registers->MDR);
    printf("UC: %d\n",registers->UC);


}


int getRegisterValue(struct Registers registers, char * registerName){

    int value = -1;

    if (!strcmp(registerName,"D1")){
        value = registers.D1;
    }
    else if (!strcmp(registerName,"D2"))
    {
        value = registers.D2;
    }
      else if (!strcmp(registerName,"D3"))
    {
        value = registers.D3;
    }
      else if (!strcmp(registerName,"D4"))
    {
        value = registers.D4;
    }
      else if (!strcmp(registerName,"D5"))
    {
        value = registers.D5;
    }
      else if (!strcmp(registerName,"D6"))
    {
        value = registers.D6;
    }
      else if (!strcmp(registerName,"D7"))
    {
        value = registers.D7;
    }
      else if (!strcmp(registerName,"D8"))
    {
        value = registers.D8;
    }
      else if (!strcmp(registerName,"D9"))
    {
        value = registers.D9;
    }
      else if (!strcmp(registerName,"D10"))
    {
        value = registers.D10;
    }
         else if (!strcmp(registerName,"ICR"))
    {
        value = registers.ICR;
    }
      else if (!strcmp(registerName,"MAR"))
    {
        value = registers.MAR;
    }
      else if (!strcmp(registerName,"MDR"))
    {
        value = registers.MDR;
    }
      else if (!strcmp(registerName,"UC"))
    {
        value = registers.UC;
    }


    return value;
}

// Función para leer las instrucciones desde un archivo de texto
void readInstructions(char *filename, struct InstructionData * instructions, int  * instructionCount) {
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
        char * remaining = line;
        char * data1; 
        char * data2; 
        char * data3;
        char * data4;

        // Se obtiene la instrucción, divido la linea para obtener la primera parte de la instruccion
        token = strtok(remaining, " ");

       //printf("------%s-------\n",token);
        
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

            data1 = strdup(strtok(NULL, " "));
            //printf("data 1: %s\n",data1);

            data2 = strdup(strtok(NULL, " "));
            //printf("data 2: %s\n",data2);
            
            data3 = strdup(strtok(NULL, " "));
            //printf("data 3: %s\n",data3);
      
            data4 = strdup(strtok(NULL, " "));
            //printf("data 4: %s\n",data4);
     
        // Se almacenan los datos en la estructura
        //Todo se almacena en formato char *, luego se convertiran a int si es algun valor entero o immediate, pero
        //en cualquier otro caso data1,data2,data3,data4 seran nombres de registros
        instructions[*instructionCount].data1 = data1;
        instructions[*instructionCount].data2 = data2;
        instructions[*instructionCount].data3 = data3;
        instructions[*instructionCount].data4 = data4;

        //printf("data1: %s\n",instructions[*instructionCount].data1);

        (*instructionCount)++;

    }



    fclose(file);
}

// Función para imprimir la memoria y los registros
void showMemoryandRegisters(int *memory, int accumulator, struct Registers * registers) {
    printf("------Memoria------\n");

    for (int i = 0; i < 31; i++) {
        printf("%d ",memory[i]);
    }

    printf("\n-----Registros-----\n");

    showRegisters(registers);

    printf("Registro acumulador: %d\n", accumulator);
}

// Función que ejecuta una instrucción
void executeInstruction(struct InstructionData instruction, int *memory, struct Registers registers, int *accumulator) {

    int address = -1;
    int address1 = -1;
    int address2 = -1;
    int address3 = -1;
    int value = -1;


    //printf("Executing: %d\n",instruction.instruction);
    switch (instruction.instruction) {
        case SET:
            address = getRegisterValue(registers,instruction.data1);
            value = atoi(instruction.data2);
            //printf("value: %d\n",value);
            if (address != -1){memory[address] = value;}
            break;
        
        case LDR:
            address = getRegisterValue(registers,instruction.data1);
            if (address != -1){
                *accumulator = memory[address];}
            break;

        case ADD:
            if (!strcmp(instruction.data2,"NULL") && !strcmp(instruction.data3,"NULL")) {
                int address = getRegisterValue(registers,instruction.data1);
                if (address != -1){*accumulator += memory[address];}
            } 
            else if (!strcmp(instruction.data3,"NULL")) {
                address1 = getRegisterValue(registers,instruction.data1);
                address2 = getRegisterValue(registers,instruction.data2);
                if (address1 != -1 && address2 != -1){
                    *accumulator += memory[address1];
                    *accumulator += memory[address2];
                }
            }
            else{
                address1 = getRegisterValue(registers,instruction.data1);
                address2 = getRegisterValue(registers,instruction.data2);
                address3 = getRegisterValue(registers,instruction.data3);
                if (address1 != -1 && address2 != -1 && address3 != -1){
                    *accumulator += memory[address1];
                    *accumulator += memory[address2];
                    memory[address3] = *accumulator;
            }
            }
            break;
                  
        case INC:
            address = getRegisterValue(registers,instruction.data1);
            if (address != -1){
                memory[address] += 1;}
            break;
           
        case DEC:
            address = getRegisterValue(registers,instruction.data1);
            if (address != -1){
                memory[address] -= 1;}
            break;
            
        case STR:
            address = getRegisterValue(registers,instruction.data1);
            if (address != -1){
                memory[address] = *accumulator;}
            break;
             
        case SHW:
            if (!strcmp(instruction.data1,"ACC")) {
                printf("[%s]: %d\n", instruction.data1, *accumulator);
            } else {
                value = getRegisterValue(registers,instruction.data1);
                if (value != -1){printf("[%s]: %d\n", instruction.data1, value);}
            }
            break;
            
        case PAUSE:
            break;
        case END:
            break;
    }
}

int main() {
    //aceptaremos programas con menos de 100 lines
    struct InstructionData instructions[100];
    //Cantidad de instrucciones
    int instructionCount;
    //Este arreglo sera como la memoria principal
    int memory[30];
    //Aqui inicializo mis registros
    struct Registers registers = { .D1 = 1, .D2 = 2, .D3 = 3, .D4 = 4, .D5 = 5, .D6 = 6, .D7 = 7, .D8 = 8, .D9 = 9, 
    .D10 = 10, .ICR = 12, .MAR = 13, .MDR = 14, .UC = 15};
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
 
    showMemoryandRegisters(memory, accumulator, &registers);

    return 0;
}