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
        printf("Media: %.2f\n", v[i].media);
        printf("------------\n");
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    Estudante estudantes[n];
    /*  char nome[100];
    scanf("%[^\n]", &nome);
    printf("\n O nome eh :%s", nome); */
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &estudantes[i].RGA);
        fflush(stdin);
        scanf("%[^\n]", &estudantes[i].nome);
        fflush(stdin);
        scanf("%lf", &estudantes[i].media);
        fflush(stdin);
    }

    imprimeEstudantes(estudantes, n);
}