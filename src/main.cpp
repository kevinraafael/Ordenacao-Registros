#include <cstdio>

struct Estudante
{
    int RGA;
    char nome[100];
    double media;
};
void imprimeEstudantes(Estudante v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("RGA: %d\n", v[i].RGA);
        printf("Nome: %s\n", v[i].nome);
        printf("Media: %d\n", v[i].media);
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
        scanf("%s", &estudantes[i].nome);
        scanf("%d", &estudantes[i].media);
    }

    imprimeEstudantes(estudantes, n);
}