#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

typedef struct  grafo
{
    int nro_vertices;
    bool eh_valorado;//
    bool eh_orientado;
    //char vertices[nro_vertices][100];
    char **vertices;
    //int matriz[nro_vertices][nro_vertices];
    int **matriz;
    int nulo; //representa o valor nulo para esse grafo
}Grafo;


Grafo cria_grafo(int nro_vertices, bool eh_orientado,bool eh_valorado, int nulo)
{
    Grafo g;
    int i, j;
    g.nro_vertices = nro_vertices;
    g.eh_orientado = eh_orientado;
    g.eh_valorado = eh_valorado;
    g.matriz = (int**)malloc(sizeof(int*)*nro_vertices);
    g.vertices = (char**)malloc(sizeof(char*)*nro_vertices);
    g.nulo = nulo;

    for(i=0; i<nro_vertices; i++)
    {
        g.matriz[i] = (int*)malloc(sizeof(int)*nro_vertices);
        g.vertices[i] = (char*)malloc(sizeof(char)*100);
    }

    for (i=0; i<nro_vertices; i++)
        for (j=0; j<nro_vertices; j++)
            g.matriz[i][j] = nulo;
    return g;
}

void prenche_vertices(Grafo g)
{
    int i;
    for (i=0; i<g.nro_vertices; i++)
    {
        printf("Informe o nome do vertice: ");
        fflush(stdin);
        scanf("%s", g.vertices[i]);
    }
}

void preenche_matriz(Grafo g)
{
    int i, j;
    for (i=0; i<g.nro_vertices; i++)
        for (j=0; j<g.nro_vertices; j++)
        {
            if (g.eh_valorado)
            {
                //printf("Qual o peso da aresta do vertice %s para %s: ", g.vertices[i],g.vertices[j]);
                scanf("%d", &g.matriz[i][j]);

            }
            else
            {
                //printf("Existe aresta do vertice %s para %s (1)Sim (%d)Não: ",g.vertices[i],g.vertices[j], g.nulo );
                scanf("%d", &g.matriz[i][j]);
                if (!g.eh_orientado)
                    g.matriz[j][i] = g.matriz[i][j];
            }
        }
}

// int grau_vertice (Grafo g,int vertice)
// {
//     for (int i = 0; i < g.nro_vertices; i++)
//     {
//         for (int j = 0; j < g.nro_vertices; j++)
//         {
            
//         }
        
//     }
    
// }

bool completo (Grafo g)
{
    for(int i = 0;i<g.nro_vertices;i++)
    {
        for(int j = 0;j < g.nro_vertices;j++)
        {
            if(i != j && g.matriz[i][j] == g.nulo)
            {
                return false;
            }
        }
    }
    return true;
}

// int grau_grafo(Grafo g,int vertice)
// {
//     int grau = 0;
//     for(int i = 0;i < g.nro_vertices;i++)
//     {
//         grau += g.matriz[vertice][i];
//     }    
//     return grau;
// }

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int vertices;
    scanf("%i",&vertices);
    Grafo g = cria_grafo(vertices,true,true,-1);
  //  prenche_vertices(g);
    preenche_matriz(g);
    bool comp = completo(g);
    printf("%s\n",comp == true?"sim":"nao");

    printf("\n");
    // for (int i = 0; i < g.nro_vertices; i++)
    // {
    //     printf("%s\n", g.vertices[i]);
    //     for (int j = 0; j < g.nro_vertices; j++)
    //     {
    //         printf("%i\t", g.matriz[i][j]);
    //     }
    // }   
    // printf("\n");
   

    /*
    dado um vertice, qual seu grau de saida 
    dado um grafo, ele � completo ou n�o ok
    dado um grafo, qual � o grau do grafo ok*/

    return 0;
}
