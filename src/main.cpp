#include <cstdio>
#include <string.h>
struct Estudante
{
    int RGA;
    char nome[101];
    double media;
};
// bool compara(bool condition)
// {
//     if (condition)
//     {
//         return true;
//     }
//     return false;
// }
void merge(Estudante v[], int inicio, int meio, int fim, char op)
{
    int p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    Estudante temp[tamanho];

    if (temp != NULL)
    {
        for (i = 0; i < tamanho; i++)
        {
            if (!fim1 && !fim2)
            {
                if (op == 'r')
                {
                    if ((v[p1].RGA < v[p2].RGA))
                    {
                        temp[i] = v[p1++];
                    }
                    else
                    {
                        temp[i] = v[p2++];
                    }
                }
                else if (op == 'n')
                {
                    if ((strcmp(v[p1].nome, v[p2].nome) < 0))
                    {
                        temp[i] = v[p1++];
                    }
                    else
                    {
                        temp[i] = v[p2++];
                    }
                }
                else if (op == 'm')
                {
                    if ((v[p1].media < v[p2].media))
                    {
                        temp[i] = v[p1++];
                    }
                    else
                    {
                        temp[i] = v[p2++];
                    }
                }

                if (p1 > meio)
                {
                    fim1 = 1; // Verifico se  o vetor acabou
                }
                if (p2 > fim)
                {
                    fim2 = 1; // Verifico se o vetor acabou
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
}

void mergeSort(Estudante v[], int inicio, int fim, char op)
{
    int meio;
    if (inicio < fim)
    {
        meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio, op);  // Percorre a primeira metade
        mergeSort(v, meio + 1, fim, op); // Percorre a segunda metade
        merge(v, inicio, meio, fim, op); // combina as 2 metades de forma ordenada
    }
}

void ordenaEstudantes(Estudante v[], int n, char op)
{
    int inicio, fim;
    inicio = 0;
    fim = n - 1;
    mergeSort(v, inicio, fim, op);
}
void imprimeEstudante(Estudante v[], int k)

{
    if (k != -1)
        printf("RGA: %d\nNome: %s\nMedia: %.2f\n------------\n", v[k].RGA, v[k].nome, v[k].media);
    else
        printf("RGA: null\nNome: null\nMedia: null\n------------\n");
}
void imprimeEstudantes(Estudante v[], int n)
{

    for (int i = 0; i < n; i++)
    {
        imprimeEstudante(v, i);
    }
}

int buscaRGA(Estudante v[], int n, int RGA)
{
    int inicio = 0;
    int fim = n - 1;
    int meio;
    /*Na busca binária precisamos de 3 coisas
        o  vetor , o tamanho do vetor e o elemento a ser encontrado que nesse caso eh o RGA
        */
    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (RGA < v[meio].RGA)
        {
            fim = meio - 1;
        }
        else if (RGA > v[meio].RGA)
        {
            inicio = meio + 1;
        }
        else
        {
            return meio;
        }
    }
    return -1;
}
int buscaNome(Estudante v[], int n, char nome[])
{
    int inicio = 0;
    int fim = n - 1;
    int meio;

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;

        if (strcmp(nome, v[meio].nome) < 0)
        {
            fim = meio - 1;
        }
        else if (strcmp(nome, v[meio].nome) > 0)
        {
            inicio = meio + 1;
        }
        else
        {
            return meio;
        }
    }
    return -1;
}
int buscaMedia(Estudante v[], int n, double Media)
{
    int inicio = 0;
    int fim = n - 1;
    int meio;
    /*Na busca binária precisamos de 3 coisas
        o  vetor , o tamanho do vetor e o elemento a ser encontrado que nesse caso eh o RGA
        */
    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (Media < v[meio].media)
        {
            fim = meio - 1;
        }
        else if (Media > v[meio].media)
        {
            inicio = meio + 1;
        }
        else
        {
            return meio;
        }
    }
    return -1;
}

int main()
{
    int n, qtdBuscas;
    char op;
    scanf("%d", &n);
    Estudante estudantes[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &estudantes[i].RGA);
        scanf(" %[^\n]", estudantes[i].nome);
        scanf("%lf", &estudantes[i].media);
    }
    scanf(" %c", &op);
    ordenaEstudantes(estudantes, n, op);

    scanf("%d", &qtdBuscas);

    for (int i = 0; i < qtdBuscas; i++)
    {
        int rga;
        double media;
        char nome[101];
        if (op == 'r')
        {
            scanf("%d", &rga);
            int posicao = buscaRGA(estudantes, n, rga);
            imprimeEstudante(estudantes, posicao);
        }
        else if (op == 'n')
        {
            scanf(" %[^\n]", nome);
            int posicao = buscaNome(estudantes, n, nome);
            imprimeEstudante(estudantes, posicao);
        }
        else if (op == 'm')
        {
            scanf("%lf", &media);
            int posicao = buscaMedia(estudantes, n, media);
            imprimeEstudante(estudantes, posicao);
        }
    }
    imprimeEstudantes(estudantes, n);
}