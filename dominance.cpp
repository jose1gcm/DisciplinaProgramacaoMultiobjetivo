# include<iostream>
# include<stdlib.h>
using namespace std;

void imprimir(int vetor[6][2])
{
    cout<<"Print Vector"<<endl;
    for(int x=0;x<6;x++)
    {
        for(int y=0;y<2;y++)
        {
            cout<<vetor[x][y]<<((y<1)?", ":"\n");
        }
    }
}

void dominance(int d[6])
{
    for(int x=0;x<6;x++)
    {
        cout<<d[x]<<((x<5)?", ":"\n");;
    }
}

void calcula_dr(int vetor[6][2], int dr[6])
{
    for(int x=0;x<6;x++)
    {
        for(int x1=0;x1<6;x1++)
        {
            if(!(vetor[x][0]==vetor[x1][0]&&vetor[x][1]==vetor[x1][1]))
            {
                if(vetor[x][0]>=vetor[x1][0]&&vetor[x][1]>=vetor[x1][1])
                {
                    //cout<<"(vetor[x][0]:"<<vetor[x][0]<<" vetor[x][1]:"<<vetor[x][1]<<"); (vetor[x1][0]:"<<vetor[x1][0]<<" vetor[x1][1]:"<<vetor[x1][1]<<")"<<"dr[x]:"<<dr[x]<<endl;
                    dr[x]+=1;
                }
            }
        }
    }
}

void calcula_dc(int vetor[6][2],int dc[6])
{
    for(int x=0;x<6;x++)
    {
        for(int x1=0;x1<6;x1++)
        {
            if(!(vetor[x][0]==vetor[x1][0]&&vetor[x][1]==vetor[x1][1]))
            {
                if(vetor[x1][0]>=vetor[x][0]&&vetor[x1][1]>=vetor[x][1])
                {
                    dc[x]+=1;
                }
            }
        }
    }
}

void calcula_dd(int vetor[6][2], int dd[6])
{
    int nivel=1;
    bool aumentar=false;
    int qtde_elem=0, tam=6;
    while(qtde_elem<tam){
        int dr1[6]={};
        calcula_dr(vetor,dr1);
       /* for(int x=0;x<6;x++)
        {
            if(dr1[x]==0){
                vetor[x][0]=-1;
                vetor[x][1]=-1;
            }
        }*/

        for(int x=0;x<6;x++){
            if(dd[x]==0&&dr1[x]==0){
                dd[x]=nivel;
                qtde_elem+=1;
            }
        }
        nivel+=1;
    }

}

int main()
{
    int vetor[6][2] = {{2,2},{3,1},{5,2},{3,4},{1,4},{6,4}};
    int dr[6]={};
    int dc[6]={};
    int dd[6]={};
    imprimir(vetor);

    /*for(int x=0;x<6;x++)
    {
        for(int x1=0;x1<6;x1++)
        {
            if(!(vetor[x][0]==vetor[x1][0]&&vetor[x][1]==vetor[x1][1]))
            {
                if(vetor[x][0]>=vetor[x1][0]&&vetor[x][1]>=vetor[x1][1])
                {
                    //cout<<"(vetor[x][0]:"<<vetor[x][0]<<" vetor[x][1]:"<<vetor[x][1]<<"); (vetor[x1][0]:"<<vetor[x1][0]<<" vetor[x1][1]:"<<vetor[x1][1]<<")"<<"dr[x]:"<<dr[x]<<endl;
                    dr[x]+=1;
                }
                if(vetor[x1][0]>=vetor[x][0]&&vetor[x1][1]>=vetor[x][1])
                {
                    dc[x]+=1;
                }
            }
        }
    }*/
    calcula_dr(vetor,dr);
    calcula_dc(vetor,dc);

    int nivel=1;
    bool aumentar=false;
    int qtde_elem=0, tam=6;
    while(qtde_elem<tam){
        int dr1[6]={};
        for(int x=0;x<6;x++)
        {
            for(int x1=0;x1<6;x1++)
            {
                if(!(vetor[x][0]==vetor[x1][0]&&vetor[x][1]==vetor[x1][1]))
                {
                    if(vetor[x][0]>=vetor[x1][0]&&vetor[x][1]>=vetor[x1][1])
                    {
                        //if(dd[x]==0)
                        //{
                            if(vetor[x][0]>=vetor[x1][0]&&vetor[x][1]>=vetor[x1][1])
                            {
                                //cout<<"(vetor[x][0]:"<<vetor[x][0]<<" vetor[x][1]:"<<vetor[x][1]<<"); (vetor[x1][0]:"<<vetor[x1][0]<<" vetor[x1][1]:"<<vetor[x1][1]<<")"<<"dr[x]:"<<dr[x]<<endl;
                                dr1[x]+=1;
                            }
                        //}
                    }
                }
            }
        }
        for(int x=0;x<6;x++)
        {
            if(dr1[x]==0){
                vetor[x][0]=1000;
                vetor[x][1]=1000;
            }
        }

        for(int x=0;x<6;x++){
            if(dd[x]==0&&dr1[x]==0){
                dd[x]=nivel;
                qtde_elem+=1;
            }
        }
        nivel+=1;
    }
    /*for(int x=0;x<6;x++)
    {
        for(int x1=0;x1<6;x1++)
        {
            if(dr[x1]==x){
                dd[x1]=nivel;
                aumentar=true;
            }
        }
        if(aumentar){
            nivel+=1;
            aumentar=false;
        }
    }
    */


    cout<<"dominance rank :";
    dominance(dr);

    cout<<"dominance count:";
    dominance(dc);

    cout<<"dominance depth:";
    dominance(dd);

    //system("pause");
    return 0;
}

