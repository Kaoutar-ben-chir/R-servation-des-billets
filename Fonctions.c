#include "Structures.h"
#include "Fonctions.h"
#include "../conio2.h"

#define TEXT_COLOR BLUE
#define BACKGROUND_COLOR WHITE
#define MENU_BORDER_COLOR RED


void afficher_menu_principal() {
    system("cls");
    textcolor(TEXT_COLOR);
    textbackground(BACKGROUND_COLOR);

    printf("\n%c", 201);
    for (int i = 0; i < 58; i++)
        printf("%c", 205);
    printf("%c\n", 187);

    printf("%c\t\tReservation de billets de cinema\t\t%c\n", 186, 186);

    printf("%c", 200);
    for (int i = 0; i < 58; i++)
        printf("%c", 205);
    printf("%c\n", 188);
    printf("\nAppuyez sur 1 pour acceder au Menu Employe\n");
    printf("Appuyez sur 2 pour acceder au Menu Client\n");
    printf("Appuyez sur 0 pour Quitter\n");
    printf("Votre choix : ");
}

void afficher_menu_employe() {
    system("cls");
    textcolor(TEXT_COLOR);
    textbackground(BACKGROUND_COLOR);

    printf("\n%c", 201);
    for (int i = 0; i < 58; i++)
        printf("%c", 205);
    printf("%c\n", 187);

    printf("%c\t\t\tMenu Employe\t\t\t\t%c\n", 186, 186);

    printf("%c", 200);
    for (int i = 0; i < 58; i++)
        printf("%c", 205);
    printf("%c\n", 188);

    printf("\nAppuyez sur 1 pour Ajouter un film\n");
    printf("Appuyez sur 2 pour Ajouter une seance\n");
    printf("Appuyez sur 3 pour Afficher la liste des films\n");
    printf("Appuyez sur 4 pour Rechercher un film\n");
    printf("Appuyez sur 5 pour Afficher les seances disponibles\n");
    printf("Appuyez sur 6 pour Afficher les anciens reservations\n");
    printf("Appuyez sur 0 pour Retourner au menu principal\n");
    printf("Votre choix : ");
}

void afficher_menu_client() {
    system("cls");
    textcolor(TEXT_COLOR);
    textbackground(BACKGROUND_COLOR);

    printf("\n%c", 201);
    for (int i = 0; i < 58; i++)
        printf("%c", 205);
    printf("%c\n", 187);

    printf("%c\t\t\tMenu Client\t\t\t\t%c\n", 186, 186);

    printf("%c", 200);
    for (int i = 0; i < 58; i++)
        printf("%c", 205);
    printf("%c\n", 188);

    printf("\nAppuyez sur 1 pour Reserver un billet\n");
    printf("Appuyez sur 2 pour Afficher la liste des films\n");
    printf("Appuyez sur 3 pour Rechercher un film\n");
    printf("Appuyez sur 4 pour Modifier une reservation\n");
    printf("Appuyez sur 0 pour Retourner au menu principal\n");
    printf("Votre choix : ");
}
void attendre_entree() {
    printf("\nAppuyez sur Entree pour continuer...");
    while (getchar() != '\n');
    getchar();
}

void menu() {
    int choix_principal;
    do {
        afficher_menu_principal();
        scanf("%d", &choix_principal);

        switch (choix_principal) {
            case 1:
                menu_employe();
                break;
            case 2:
                menu_client();
                break;
            case 0:
                printf("Au revoir");
                exit(0);
                break;
            default:
                printf("Choix incorrect !\n");
                attendre_entree();
                break;
        }
    } while (choix_principal != 0);
}

void menu_employe() {
    int choix_employe;
    do {
        afficher_menu_employe();
        scanf("%d", &choix_employe);

        switch (choix_employe) {
            case 1:
                Ajouter_film();
                attendre_entree();
                break;
            case 2:
                Ajouter_Seance();
                attendre_entree();
                break;
            case 3:
                Afficher_films();
                attendre_entree();
                break;
            case 4:
                trouver_film();
                attendre_entree();
                break;
            case 5:
                Afficher_seance();
                attendre_entree();
                break;
            case 6:
                liste_des_reservations();
                attendre_entree();
                break;
            case 0:
                menu();
                break;
            default:
                printf("Choix incorrect !\n");
                attendre_entree();
                break;
        }
    } while (choix_employe != 0);
}

void menu_client() {
    int choix_client;
    do {
        afficher_menu_client();
        scanf("%d", &choix_client);

        switch (choix_client) {
            case 1:
                reserver_billet();
                attendre_entree();
                break;
            case 2:
                Afficher_films();
                attendre_entree();
                break;
            case 3:
                trouver_film();
                attendre_entree();
                break;
            case 4:
                modifier_reservation();
                attendre_entree();
                break;
            case 0:
                menu();
                break;
            default:
                printf("Choix incorrect !\n");
                attendre_entree();
                break;
        }
    } while (choix_client != 0);
}

void afficher_genres() {
    printf("\nListe des genres de films :\n");
    printf("1. Aventure\n");
    printf("2. Action\n");
    printf("3. Comedie\n");
    printf("4. Drame\n");
    printf("5. Romance\n");
    printf("6. Science-Fiction\n");
    printf("7. Documentaire\n");
    printf("8. Mystere\n");
    printf("9. Horreur\n");
    printf("10. Autre\n");
}

void Ajouter_film() {
    FILE *fp;
    film f;
    int choix_genre;

    printf("Entrez le code du film: ");
    scanf("%s", f.code);
    printf("Entrez le nom : ");
    scanf("%s", f.nom);
    printf("Choisissez le genre du film:");
    afficher_genres();
    printf("Entrez le numero correspondant : ");
    scanf("%d", &choix_genre);

    switch(choix_genre) {
        case 1:
            strcpy(f.genre, "Aventure");
            break;
        case 2:
            strcpy(f.genre, "Action");
            break;
        case 3:
            strcpy(f.genre, "Comedie");
            break;
        case 4:
            strcpy(f.genre, "Drame");
            break;
        case 5:
            strcpy(f.genre, "Romance");
            break;
        case 6:
            strcpy(f.genre, "Science-Fiction");
            break;
        case 7:
            strcpy(f.genre, "Documentaire");
            break;
        case 8:
            strcpy(f.genre, "Mystere");
            break;
        case 9:
            strcpy(f.genre, "Horreur");
            break;
        case 10:
            strcpy(f.genre, "Autre");
            break;
        default:
            printf("Genre non valide !");
            return;
    }

    printf("Entrez le prix du billet: ");
    scanf("%d", &f.prix);

    fp = fopen("data.txt", "a+");
    if (fp == NULL) {
        printf("Fichier non trouve");
    } else {
        fprintf(fp, "%s %s %s %d\n", f.code, f.nom, f.genre, f.prix);
        printf("Enregistrement insere avec succes");
    }
    printf("\n");
    fclose(fp);
}

void Ajouter_Seance() {
    FILE *fp;
    Seance S;

    printf("Entrez le code du film pour cette seance: ");
    scanf("%s", S.code_film);
    printf("Entrez le numero de seance : ");
    scanf("%d", &S.Num);
    printf("Choisissez l'horaire de cette seance (jour heure) : ");
    scanf("%s", S.horaire);
    printf("Entrez le numero de salle : ");
    scanf("%d", &S.salle);
    printf("Entrez le nombre de places disponibles : ");
    scanf("%d", &S.nombre_places_disponibles);

    fp = fopen("Seances.txt", "a+");
    if (fp == NULL) {
        printf("Fichier non trouve");
        return;
    } else {
        fprintf(fp, "%s %d %s %d %d\n", S.code_film, S.Num, S.horaire, S.salle, S.nombre_places_disponibles);
        printf("Enregistrement insere avec succes");
    }
    printf("\n");
    fclose(fp);
}

void Afficher_films() {
     film f;
    FILE *fp;
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Fichier introuvable !");
        exit(1);
    } else {
        printf("\nListe de tous les films :\n");
        while (fscanf(fp, "%s %s %s %d", f.code, f.nom, f.genre, &f.prix) != EOF) {
            printf("\n\tCode : %s", f.code);
            printf("\n\tNom du film : %s", f.nom);
            printf("\n\tGenre : %s", f.genre);
            printf("\n\tPrix du billet : %d$\n", f.prix);
        }
    }
    fclose(fp);
}
void Afficher_seance() {
    Seance S;
    FILE *fp;
    fp = fopen("Seances.txt", "r");
    if (fp == NULL) {
        printf("Fichier introuvable !");
        exit(1);
    } else {
        printf("\nListe de tous les seances :\n");
        while (fscanf(fp, "%s %d %s %d %d", S.code_film, &S.Num, S.horaire, &S.salle, &S.nombre_places_disponibles) != EOF) {
            printf("\n\tCode de film : %s", S.code_film);
            printf("\n\tNumero de seance : %d", S.Num);
            printf("\n\tL'horaire : %s", S.horaire);
            printf("\n\tLa salle : %d", S.salle);
            printf("\n\tLa nombre des places diponibles : %d\n", S.nombre_places_disponibles);
        }
    }
    fclose(fp);
}

void trouver_film()
{
    film f;
    FILE *fp;
    char code_film[20];
    char ch;
    printf("Entrez le code du film : ");
    scanf("%s", code_film);

    fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("Fichier introuvable !");
        exit(1);
    }
    else
    {
        while (fscanf(fp, "%s %s %s %d", f.code, f.nom, f.genre, &f.prix) != EOF)
        {
            if (strcmp(f.code, code_film) == 0)
            {
                printf("\n Enregistrement trouve\n");
                printf("\n\t\tCode : %s", f.code);
                printf("\n\t\tNom du film : %s",f.nom);
                printf("\n\t\tGenre : %s", f.genre);
                printf("\n\t\tPrix du billet : %d $", f.prix);
                break;
            }
        }
        fclose(fp);
    }
}

void trouver_seance(char code_film[20]) {
    Seance S;
    FILE *fp;

    fp = fopen("Seances.txt", "r");
    if (fp == NULL) {
        printf("Fichier introuvable !");
        exit(1);
    }
    else {
        int found = 0;
        while (fscanf(fp, "%s %d %s %d %d", S.code_film, &S.Num, S.horaire, &S.salle, &S.nombre_places_disponibles) != EOF) {
            if (strcmp(S.code_film, code_film) == 0) {
                found = 1;
                printf("\nLes seances disponibles pour ce film:\n");
                printf("\n\tCode de film : %s", S.code_film);
                printf("\n\tNumero de seance : %d", S.Num);
                printf("\n\tL'horaire : %s", S.horaire);
                printf("\n\tLa salle : %d", S.salle);
                printf("\n\tLa nombre des places disponibles : %d\n", S.nombre_places_disponibles);
            }
        }
        if (!found) {
            printf("Aucune seance correspondant au film selectionne !\n");
        }
        fclose(fp);
    }
}
void reserver_billet()
{
    film f;
    Seance S;
    Client C;
    FILE *fp;
    FILE *ufp;
    FILE *sfp;
    int numero_ticket;
    char code_film[20];
    char num_seance[10];
    char ch;

    fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("Fichier introuvable !");
        exit(1);
    }

    printf("\n Pour Reserver un billet, Choisissez un film \n");
    Afficher_films();
    printf("\n Entrez le code du film que vous voulez : ");
    scanf("%s", code_film);
    printf("\n Voici les seances disponibles pour ce film: ");
    trouver_seance(code_film);
    printf("\n Entrez le numero de la seance que vous voulez : ");
    scanf("%d", &C.Num);

    sfp = fopen("Seances.txt", "r+");
    if (sfp == NULL)
    {
        printf("Fichier introuvable !");
        exit(1);
    }
    else
    {
        int trouve = 0;
        while (fscanf(sfp, "%s %d %s %d %d", S.code_film, &S.Num, S.horaire, &S.salle, &S.nombre_places_disponibles) != EOF)
        {
            if (S.Num == C.Num && strcmp(S.code_film, code_film) == 0)
            {
                if (S.nombre_places_disponibles <= 0) {
                    printf("Desole, il n'y a plus de places disponibles pour cette seance.\n");
                    return;
                }
                printf("Remplissez les informations pour reserver\n");
                printf("Votre nom : ");
                scanf("%s", C.nom);
                printf("Votre age: ");
                scanf("%d", &C.age);
                printf("Numero de telephone : ");
                scanf("%d", &C.telephone);
                S.nombre_places_disponibles--;
                fseek(sfp, -1 * sizeof(Seance), SEEK_CUR);
                fprintf(sfp, "%s %d %s %d %d\n", S.code_film, S.Num, S.horaire, S.salle, S.nombre_places_disponibles);
                break;
            }
        }
    }

    while (fscanf(fp, "%s %s %s %d", f.code, f.nom, f.genre, &f.prix) != EOF)
    {
        if (strcmp(f.code, code_film) == 0)
        {
            break;
        }
    }
    fclose(fp);
   if (C.age < 15) {
    printf("Reduction de 30%% est applique !\n");
    f.prix = f.prix - (30 * f.prix / 100);
}
    C.montant = f.prix;
    numero_ticket++;
    C.Numero_ticket = numero_ticket;
    strcpy(C.nom_film, f.nom);

    printf("Votre reservation est enregistre avec succes\n\n");
    printf("\n******************************************");
    printf("\n************ Ticket de reservation ************");
    printf("\n Numero de ticket : %d", C.Numero_ticket);
    printf("\n Nom : %s", C.nom);
    printf("\n Age : %d", C.age);
    printf("\n Numero de telephone : %d", C.telephone);
    printf("\n Nom du film : %s", C.nom_film);
    printf("\n Prix par billet : %d $\n", C.montant);
    printf("\n******************************************");

    ufp = fopen("oldTransection.txt", "a");
    if (ufp == NULL)
    {
        printf("Fichier non trouve");
    }
    else
    {
        fprintf(ufp, "%d %s %d %d %s  %d \n", C.Numero_ticket, C.nom, C.age, C.telephone, C.nom_film, C.montant);
    }
    printf("\n");
    fclose(ufp);
    fclose(sfp);
}

void liste_des_reservations()
{
    char ch;
    FILE *fp;

    system("cls");

    fp = fopen("oldTransection.txt", "r");
    if (fp == NULL)
    {
        printf("Il n y a aucune reservation !");
        exit(1);
    }
    else
    {
        while ((ch = fgetc(fp)) != EOF)
            printf("%c", ch);
    }
    fclose(fp);
}

void modifier_reservation() {
    FILE *ufp, *tfp;
    Client C;
    int numero_ticket;
    int choix;

    printf("Entrez le numero de ticket de la reservation a modifier : ");
    scanf("%d", &numero_ticket);

    ufp = fopen("oldTransection.txt", "r");
    if (ufp == NULL) {
        printf("Fichier introuvable !");
        return;
    }

    tfp = fopen("tempTransection.txt", "w");
    if (tfp == NULL) {
        printf("Erreur lors de l'ouverture du fichier temporaire !");
        fclose(ufp);
        return;
    }

    while (fscanf(ufp, "%d %s %d %d %s %d \n", &C.Numero_ticket, C.nom, &C.age, &C.telephone, C.nom_film, &C.montant) != EOF){
        if (numero_ticket == C.Numero_ticket) {
            printf("\n\n*********** Details de la reservation ***********\n");
            printf("\n Numero de ticket : %d", C.Numero_ticket);
            printf("\n 1. Nom : %s", C.nom);
            printf("\n 2. Age : %d", C.age);
            printf("\n 3. Numero de telephone : %d", C.telephone);
            printf("\n 4. Nom du film : %s", C.nom_film);
            printf("\n 5. Prix par billet : %d $", C.montant);
            printf("\n\n*********** Modification de la reservation ***********\n");
            printf("Entrez le numero de l'information a modifier : ");
            scanf("%d", &choix);

            switch (choix) {
                case 1:
                    printf("Entrez le nouveau nom : ");
                    scanf("%s", C.nom);
                    break;
                case 2:
                    printf("Entrez le nouvel age : ");
                    scanf("%d", &C.age);
                    break;
                case 3:
                    printf("Entrez le nouveau numero de telephone : ");
                    scanf("%d", &C.telephone);
                    break;
                case 4:
                    printf("Entrez le nouveau nom du film : ");
                    scanf("%s", C.nom_film);
                    break;
                case 5:
                    printf("Entrez le nouveau prix par billet : ");
                    scanf("%d", &C.montant);
                    break;
                default:
                    printf("Choix incorrect !");
                    break;
            }

            fprintf(tfp, "%d %s %d %d %s %d \n", C.Numero_ticket, C.nom, C.age, C.telephone, C.nom_film,C.montant);
            printf("\nLa reservation a ete mise a jour avec succes !");
        } else {
             printf("\nAucune reservation trouvee avec le numero de ticket fourni !");
        }
    }
    fclose(ufp);
    fclose(tfp);

    remove("oldTransection.txt");
    rename("tempTransection.txt", "oldTransection.txt");
}
