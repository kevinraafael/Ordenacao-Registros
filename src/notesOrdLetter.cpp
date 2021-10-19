if (op = 'n')
{
    if (!fim1 && !fim2)
    {
        if (strcmp(v[p1].nome, v[p2].nome) < 0)
        {
            temp[i] = v[p1++].RGA;
        }
        else
        {
            temp[i] = v[p2++].RGA;
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
            temp[i] = v[p1++].RGA; // Copio o que sobrou para o meu vetor auxiliar
        }
        else
        {
            temp[i] = v[p2++].RGA; // Copio o que sobrou para o meu vetor auxiliar
        }
    }
}