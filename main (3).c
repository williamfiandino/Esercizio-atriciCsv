#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void caricaMatriceDaCsv(int dim, int m[dim][dim]) {

  FILE *fp = fopen("matrice.csv", "w");
  if (fp == NULL) {
    printf("Errore nell'apertura del file.\n");
  } else {
    char line[100];
    int num_rows;
    while (fgets(line, sizeof(line), fp) != NULL) {
      int indexNewLine = strcspn(line, "\n");
      line[indexNewLine] = 0;

      for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
          sscanf(line, "%d,", m[i][j]);
        }
      }
    }
  }
  fclose(fp);
  
}

void scriviMatriceSuCsv(int dim, int m[dim][dim]) {
  FILE *fp = fopen("matrice.csv", "w");
  if (fp == NULL) {
    printf("Errore nell'apertura del file.\n");
  } else {
    for (int i = 0; i < dim; i++) {
      for (int j = 0; j < dim; j++) {
        fprintf("%d,", m[i][j]);
      }
      printf("\n");
    }
  }
  fclose(fp);
}

void creaMatrice(int dim, int v[dim][dim]) {
  srand(time(NULL));
  int i, j, n;
  for (i = 0; i < dim; i++) {
    for (j = 0; j < dim; j++) {
      v[i][j] = (rand() % (999));
    }
  }
}

void stampaMatrice(int dim, int mat[dim][dim]) {
  printf("\nMatrice");
  int i, j;
  for (i = 0; i < dim; i++) {
    printf("\t%d", i);
  }
  printf("\n");
  for (i = 0; i < dim; i++) {

    printf("\n");
    printf("%d\t", i);
    for (j = 0; j < dim; j++) {
      printf("\t%d", mat[i][j]);
    }
  }
}

int main(void) {
  int dim, c;

  printf("\nInserisci il numero di righe e colonne");
  scanf("%d", &dim);
  int mat[dim][dim];
  do {
    printf("\nInserisci 1 per generare una matrice\nInserisci 2 per caricarla "
           "nel file csv\nInserisci 3 per caricare la matrice dal csv e "
           "stamparla\nInserisci zero per terminare il programma");
    scanf("%d", &c);
    switch (c) {
    case '1':
      creaMatrice(dim, mat);
      break;
    case '2':
      scriviMatriceSuCsv(dim, mat);
      break;
    case '3':
      caricaMatriceDaCsv(dim, mat);
      break;
    }

  } while (c != 0);
  printf("\t\t\t...Programma terminato...");
  return 0;
}