#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_VECT 1000

void randomize(int, float []); // numero, vector
void numeroast (int, float[], int, int[]); // n, vect, k, vetor retorno, min, largura
void imprimehist(int, int[]); //k, vect ocor,
void fmin_max (float [], int, float *, float *); // vect, n, min, max

int main(void)
{
    float vect[MAX_VECT] = {0};
    int ocor[MAX_VECT] = {0};
    int n = 0, k = 0;

    printf("Insira o numero de valores que pretende gerar: ");
    scanf("%d", &n);

    printf("Introduza o numero de classes que pretende [0;10]: ");
    scanf("%d",&k);

    while(k<0 || k>10)
    {
        printf("Numero invalido. Introduza um valor [0;10]");
        scanf("%d",&k);
    }

    randomize(n, vect);
    numeroast(n, vect, k, ocor);
    printf("\n");
    imprimehist(k, ocor);


    return EXIT_SUCCESS;
}

void randomize(int _n, float _vect[])
{
    int i;
    srand(time(NULL));

    for(i=0; i < _n; i++)
    {
        _vect[i] = (rand()%1000)*0.001;
        printf("%d valor : %.3f\n",i, _vect[i]);
    }
    return;
}

void numeroast (int _n, float _vect[], int _k, int _ocor[])
{
    int i=0, classe = 0;
    float l = 0.0f;
    float min = 0, max = 0;

    fmin_max(_vect, _n, &min, &max);

    l = (max-min)/_k;

    for(classe = 0; classe < _k; classe ++)
    {
        for(i=0; i < _n; i++)
        {
            if(_vect[i] >= min + (classe * l) && _vect[i] <= min +((classe + 1)*l))
                _ocor[classe]++;
        }
        printf("[%d] : %d\n",classe, _ocor[classe]);
    }

    printf("%f %f\n", min, max);

    return;
}

void imprimehist(int _k, int _ocor[])
{
    int i = 0, linha = 0;

    int maxast = 0;
    int max = 0;

    for(i=0; i < _k; i++)
    {
        if(_ocor[i] > max){

            max = _ocor[i];
        }
    }
    maxast = max;

    for(linha = maxast; linha>0 ; linha--)
    {
        for(i= 0; i < _k; i++)
        {
            if(_ocor[i] >= linha)
            {
                printf("*    ");
            }
            else
                printf("     ");
        }
        printf("\n");
    }

    for(i=0 ; i< _k ; i++)
        printf("[%d]  ", i+1);
}

void fmin_max(float _vect[], int _n, float *_min, float *_max)
{
    int i = 0;
    float min = 1.0f, max = 0.0f;


    for(i=0; i < _n; i++)
    {
        if(_vect[i] > max){

            max = _vect[i];
        }

        if(_vect[i] < min){

            min = _vect[i];
        }
    }

    *_min = min;
    *_max= max;

    return;
}
