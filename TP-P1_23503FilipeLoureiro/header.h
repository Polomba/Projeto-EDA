#ifndef DATA
#define DATA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <errno.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#pragma region Structs 

//-------------------------------------------------------
typedef struct operation {
    int id;
    int quantMachines;
    int *machineTime;
    struct operation *next;
}operation;
//-------------------------------------------------------
typedef struct job {
    //int id;
    int nOperations;
    operation *op;
    //struct job *next;
}job;

#pragma endregion
//#####################################################################################################
//#####################################################################################################
#pragma region funcoes
job *inicializarJob();
operation *inicializarOperacao();
void verificarDadosNoFicheiro(operation *op, int *idCont, int *nOperations);
void menu(int *opcao);
void inserirNovaOperacao(operation *op, int *idCont);
void listOperation(operation *op, int nOperations);
void removerOperacao(job **jobList);
void editarOperacao(operation *op);
void determinaTempoMaisCurto(operation *op);
void determinaTempoMaisLongo(operation *op);
void determinaTempoMedio(operation *op);
#pragma endregion

#endif