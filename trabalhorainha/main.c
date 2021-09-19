#include <stdio.h>
#include <stdlib.h>

void menu ()
{
    printf("----------------------------------------------------------------------------------------------------------------\n");
    printf("                                        DESAFIO DAS N RAINHAS     \n");
    printf("----------------------------------------------------------------------------------------------------------------\n");
    printf("                                           INSTRUCOES:\n");
    printf("Aloque as rainhas de modo que nenhuma possa atacar a outra!\n");
    printf("Use o teclado numerico para movimentar a rainha\n");
    printf("Aperte 0 para alocar uma rainha\n");
    printf("Aperte espaco para remover uma rainha\n");
    printf("Aperte S para sair do jogo\n");
    printf("----------------------------------------------------------------------------------------------------------------\n");
}
int contrainhas(char tabu[][32], int lin,int  col){
    int i, j, rainhas = 0;
    for(i = 0; i<lin; i++){
        for(j = 0; j<col; j++){
            if(tabu[i][j] == '0'){
                rainhas++;
            }
        }
    }
    return rainhas;
}
int verificaAtaque(char tabu[][32], int lin,int  col)
{
    int i, j,m, l, ataque = 0;
    for(i = 0; i < lin; i++)
    {
        for(j = 0; j<col; j++)
        {
            if(tabu[i][j] == '0')
            {
                for(l = 0; l<lin; l++)
                {
                    if(tabu[l][j]=='0' && l != i)
                    {
                        ataque++;
                    }
                }
                //verifica coluna
                    for(m = 0; m<col; m++)
                    {
                        if(tabu[i][m] == '0' && m != j)
                        {
                            ataque++;
                        }
                    }

                //verifica diagonal para baixo
                    for(l = i + 1, m = j + 1; l<lin && m<col ; l++, m++ )
                    {
                        if(tabu[l][m] == '0' )
                        {
                            ataque++;
                        }
                    }
                //verifica diagonal para cima
                    for(l = i - 1, m = j - 1; l>=0 && m>=0; l--, m--)
                    {
                        if(tabu[l][m] == '0')
                        {
                            ataque++;
                        }
                    }
            }
        }
    }
    return ataque;
}
void preenche1vez(char tabu[][32], int lin,int  col)
{
    int i, j;
    for(i = 0; i <lin; i++)
    {
        for(j = 0; j< col; j++)
        {
            if (i == 0 && j == 0)
            {
                tabu[i][j] = 'X';
            }
            else
            {
                tabu[i][j] = ' ';
            }
        }
    }
}
void imprimeTabu(char tabu[][32],int lin,int col, int ataque, int a)
{
    int i, j,k;

    system("cls");
    if ( ataque  != 0)
    {
        printf("posicao de ataque!\n");
    }
    if ( a == 1)
    {
        printf("caracter invalido!\n");
    }
    for(k=0; k<lin; k++)
        printf("----");
    for (int i = 0; i < lin; i++)
    {
        printf("\n");
        for(j=0; j < col; j++)
        {
            printf("| ");
            printf("%c ",tabu[i][j]);
        }
        printf("|");  //quando terminar...
        printf("\n");
        for(k=0; k<lin; k++)
            printf("----");
    }
}

void MudeX(char tab[][32], int lin,int col)
{
    int i=0,j=0, k, r = 0, c=0, n,rainhas = 0, l, m, aux, a,ataque;
    char pos[100], x;
    printf("Informe a posicao que deseja mudar(1,2,3,4,6,7,8,9,0): ");
    scanf("%*c%c", &x);

    while (x != 's')
    {
        system("cls");
        switch (x)
        {

        case '1':
            if(j!=0&&i!=lin-1)
            {
                if (tab[i][j]=='X' )
                    tab[i][j] = ' ';
                if(tab[i][j] == '@')
                    tab[i][j] = '0';
                i++;
                j--;
                if(tab[i][j] == '0')
                    tab[i][j] = '@';
                else
                tab[i][j] = 'X';
            }
            break;
        case '2':
            if(i!=lin-1)
            {
                if (tab[i][j]=='X')
                    tab[i][j] = ' ';
                if(tab[i][j] == '@')
                    tab[i][j] = '0';
                i++;
                if(tab[i][j] == '0')
                    tab[i][j] = '@';
                else
                tab[i][j] = 'X';
            }
            break;
        case '3':
            if(j!=lin-1&&i!=lin-1)
            {
                if (tab[i][j]=='X')
                    tab[i][j] = ' ';
                if(tab[i][j] == '@')
                    tab[i][j] = '0';
                i++;
                j=j+1;
                if(tab[i][j] == '0')
                    tab[i][j] = '@';
                else
                tab[i][j] = 'X';
            }
            break;
        case '4':
            if(j!=0)
            {
                if (tab[i][j]=='X')
                    tab[i][j] = ' ';
                if(tab[i][j] == '@')
                    tab[i][j] = '0';
                j--;
                if(tab[i][j] == '0')
                    tab[i][j] = '@';
                else
                tab[i][j] = 'X';
            }
            break;
        case '6':
            if(j!= lin-1)
            {
                if (tab[i][j]=='X')
                    tab[i][j] = ' ';
                if(tab[i][j] == '@')
                    tab[i][j] = '0';
                j++;
                if(tab[i][j] == '0')
                    tab[i][j] = '@';
                else
                tab[i][j] = 'X';
            }
            break;
        case '7':
            if(j!=0 && i!=0)
            {
                if (tab[i][j]=='X')
                    tab[i][j] = ' ';
                if(tab[i][j] == '@')
                    tab[i][j] = '0';
                i--;
                j--;
                if(tab[i][j] == '0')
                    tab[i][j] = '@';
                else
                tab[i][j] = 'X';
            }
            break;
        case '8':
            if(i!=0 && col!=0)
            {
                if (tab[i][j]=='X')
                    tab[i][j] = ' ';
                if(tab[i][j] == '@')
                    tab[i][j] = '0';
                i--;
                if(tab[i][j] == '0')
                    tab[i][j] = '@';
                else
                tab[i][j] = 'X';
            }
            break;
        case '9':
            if(i!=0 && j!=lin-1)
            {
                if (tab[i][j]=='X')
                    tab[i][j] = ' ';
                if(tab[i][j] == '@')
                    tab[i][j] = '0';
                i--;
                j++;
                if(tab[i][j] == '0')
                    tab[i][j] = '@';
                else
                tab[i][j] = 'X';
            }
            break;
        case '0':
            tab[i][j] = '0';
            break;
        case ' ':
            if(tab[i][j] == '@')
            {
                tab[i][j]='X';
            }
            break;
        default:
            a = 1;
        }
        rainhas = contrainhas(tab,lin, col);
        ataque = verificaAtaque(tab, lin, col);
        imprimeTabu(tab, lin, col, ataque, a);
        a = 0;
        if(rainhas == lin && ataque == 0)
        {
            printf("--------------------------------------------------------\n");
            printf("                     PARABENS!\n");
            printf("                 DESAFIO CONCLUIDO!\n");
            printf("------------------------------------------------------------------------\n");
            return 0;
        }
        printf("\nInforme a posicao que deseja mudar(1,2,3,4,6,7,8,9,0):");
        scanf("%*c%c", &x);
    }

}
int main()
{
    menu();
    int tamL,tamC, k;
    char tabuleiro[32][32];
    printf("Informe o tamanho do tabuleiro: ");
    scanf("%d%d",&tamC,&tamL);

    while((tamC!=4 || tamL!=4) && (tamC!=8 || tamL!=8) && (tamC!=16 || tamL!=16) && (tamC!=32 || tamL!=32))
    {
        printf("Informe o tamanho do tabuleiro(4x4,8x8,16x16,32x32): ");
        scanf("%d%d",&tamC,&tamL);
    }
    preenche1vez(tabuleiro, tamL, tamC);
    imprimeTabu(tabuleiro,tamL,tamC,0,0 );

    MudeX(tabuleiro,tamL,tamC);
    return 0;

}
