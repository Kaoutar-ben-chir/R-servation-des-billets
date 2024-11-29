#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char code[20];
    char nom[20];
    char genre[20];
    int prix;
}film;

typedef struct {
    char code_film[20];
    int Num;
    char horaire[20];
    int salle;
    int nombre_places_disponibles;
} Seance;

typedef struct{
    int Numero_ticket;
    char nom_film[20];
    char nom[20];
    int age;
    int telephone;
    int Num;
    int montant;
}Client;

#endif
