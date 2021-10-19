#include <cstdio>
#include <stdlib.h> // Pra usar o Malloc

struct Estudante
{
    int RGA;
    char nome[100];
    double media;
};
void merge(Estudante v[], int inicio, int meio, int fim)
{
    int p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    Estudante temp[tamanho];
    //temp = (Estudante *)malloc(tamanho * sizeof(int)); // alocando espaço para meu vetor auxiliar

    if (temp != NULL)
    {
        for (i = 0; i < tamanho; i++)
        {
            if (!fim1 && !fim2)
            {
                if (v[p1].RGA < v[p2].RGA)
                {
                    temp[i] = v[p1++];
                }
                else
                {
                    temp[i] = v[p2++];
                }
                if (p1 > meio)
                {
                    fim1 = 1; // Verifico se  o vetor acabou
                }
                if (p2 > fim)
                {
                    fim2 = 1; //Verifico se o vetor acabou
                }
            }
            else
            {
                if (!fim1)
                {
                    temp[i] = v[p1++]; // Copio o que sobrou para o meu vetor auxiliar
                }
                else
                {
                    temp[i] = v[p2++]; // Copio o que sobrou para o meu vetor auxiliar
                }
            }
        }
        for (j = 0, k = inicio; j < tamanho; j++, k++) // Copio o conteúdo ordenado do vetor auxiliar para o meu original
        {
            v[k] = temp[j];
        }
    }
    free(temp);
}
void mergeSort(Estudante v[], int inicio, int fim)
{
    int meio;
    if (inicio < fim)
    {
        meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio);  //Percorre a primeira metade
        mergeSort(v, meio + 1, fim); //Percorre a segunda metade
        merge(v, inicio, meio, fim); // combina as 2 metades de forma ordenada
    }
}

void ordenaEstudantes(Estudante v[], int n, char op)
{
    int inicio, fim;
    inicio = 0;
    fim = n - 1;
    mergeSort(v, inicio, fim);
}

void imprimeEstudantes(Estudante v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("RGA: %d\n", v[i].RGA);
        printf("Nome: %s\n", v[i].nome);
        printf("Media: %.2f\n", v[i].media);
        printf("------------\n");
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    Estudante estudantes[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &estudantes[i].RGA);
        scanf(" %[^\n]", &estudantes[i].nome);
        scanf("%lf", &estudantes[i].media);
    }

    imprimeEstudantes(estudantes, n);
    printf("\n----ORDENADO COM RGA-------\n");
    ordenaEstudantes(estudantes, n, 'r');
    imprimeEstudantes(estudantes, n);
}