/**
 * @file Main.c
 * @author Filipe Loureiro (a23503@alunos.ipca.pt)
 * @brief 
 * @version 1.0
 * @date 2022-04-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <errno.h>

#include "header.h"
#include "functions.c"

int main(int argc, char const *argv[]) {
    job *jobList;
    int opcao, idCont = 0;
    
    jobList = inicializarJob();
	verificarDadosNoFicheiro(jobList->op,&idCont,&(jobList->nOperations));

    do {
        menu(&opcao);

        switch(opcao) {
            case 0: printf("Goodbye...\n\n"); 
					break;
            case 1: inserirNovaOperacao(jobList->op,&idCont); 
					break;
            case 2: listarOperacao(jobList->op,jobList->nOperations); 
					break;
            case 3: removerOperacao(&jobList);
					break;
            case 4: editarOperacao(jobList->op);
					break;
            case 5: determinaTempoMaisCurto(jobList->op);
					break;
            case 6: determinaTempoMaisLongo(jobList->op);
					break;
            case 7: determinaTempoMedio(jobList->op);
            		break;
        }
    }while(opcao != 0);

    free(jobList->op); 
    free(jobList);
    return 0;
}