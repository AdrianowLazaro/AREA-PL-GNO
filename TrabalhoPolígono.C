#include<stdio.h>
#include<stdlib.h>


struct vertices{
    float x;
    float y;
};//armazena os pontos de vertice;

// Função area do poligono

float areatriangulo(struct vertices v[], int tamanho) {
    float areatr = 0;


    for (int i = 0; i < tamanho - 2; i++) {
        float M[3][3] = {
            {v[0].x, v[0].y, 1},
            {v[i + 1].x, v[i + 1].y, 1},
            {v[i + 2].x, v[i + 2].y, 1},
        };

        float dete = 0;

        // Cálculo do determinante
        dete = dete + (M[0][0] * M[1][1] * M[2][2]);
        dete = dete + (M[0][1] * M[1][2] * M[2][0]); 
        dete = dete + (M[0][2] * M[1][0] * M[2][1]);
        dete = dete - (M[2][0] * M[1][1] * M[0][2]);
        dete = dete - (M[2][1] * M[1][2] * M[0][0]);
        dete = dete - (M[2][2] * M[1][0] * M[0][1]);

        // Área do triângulo
        areatr += dete / 2;
    }

    if (areatr < 0) {
        areatr = -areatr;
    }

    return areatr; 
}

int main(void) {
    FILE *arquivo;
    float px, py;
    int vertices;

    arquivo = fopen("Poligono.txt", "r");
  
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1); 
    }

    fscanf(arquivo, "%d", &vertices); 
  
    struct vertices v[vertices];

    // armazenar os valores
    for (int i = 0; i < vertices; i++) {
        fscanf(arquivo, "%f %f", &v[i].x, &v[i].y);}

    float area = areatriangulo(v, vertices);

    printf("A area do poligono é: %.2f", area); 
    fclose(arquivo);

    return 0;
}
