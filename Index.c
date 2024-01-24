#include <stdio.h>
#include <stdlib.h>

void Ajouter(int Q, int code, int T[][2], int *taille) {
    int produit_existe = 0;
    for (int i = 0; i < *taille; i++) {
        if (code == T[i][0]) {
            T[i][1] += Q;
            produit_existe = 1;
            break;
        }
    }
    if (!produit_existe) {
        T[*taille][0] = code;
        T[*taille][1] = Q;
        (*taille)++;
    }
}

void Remove(int Q, int code, int T[][2], int *taille) {
    int produit_existe = 0;
    for (int i = 0; i < *taille; i++) {
        if (code == T[i][0]) {
            if (T[i][1] >= Q) {
                T[i][1] -= Q;
                produit_existe = 1;
                break;
            } else {
                printf("Erreur : La quantite a retirer est superieure a la quantite en stock.\n");
                break;  
            }
        }
    }
    if (!produit_existe) {
        printf("Erreur : Le produit avec le code %d n'existe pas.\n", code);
    }
}

void Affichage(int T[][2], int *taille) {
    printf("Le tableau :\n");
    for (int i = 0; i < *taille; i++) {
        printf("Produit %d : Quantite %d\n", T[i][0], T[i][1]);
    }
}

int main() {
    int T[3][2] = {{1234, 10}, {4444, 10}, {5555, 10}};
    int taille = 3;
    int choice;

    do {
        int Q, code;  

        printf("=========== Menu ===========\n");
        printf("1. Ajouter un produit\n");
        printf("2. Retirer un produit\n");
        printf("3. Afficher le stock\n");
        printf("4. Quitter\n");
        printf("============================\n");
        printf("Choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Entrer le code du produit : ");
                scanf("%d", &code);
                printf("Entrer la quantite du produit : ");
                scanf("%d", &Q);
                Ajouter(Q, code, T, &taille);
                break;
            case 2:
                printf("Entrer le code du produit : ");
                scanf("%d", &code);
                printf("Entrer la quantite du produit a retirer : ");
                scanf("%d", &Q);
                Remove(Q, code, T, &taille);
                break;
            case 3:
                Affichage(T, &taille);
                break;
            case 4:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
