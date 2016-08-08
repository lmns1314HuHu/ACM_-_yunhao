#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char str[30];
char _cube[110][6];
//�����Ŵ�0��ʼ��
#define MAXN 110
int uN,vN;//u,v��Ŀ
int g[MAXN][MAXN];
int linker[MAXN];
bool used[MAXN];

bool dfs(int u)//����߿�ʼ������·��
{
    for(int v=0; v<vN; v++){//��������Ŵ�0��ʼ����Ҫ��1��ʼ��Ҫ�޸�
        if(g[u][v]&&!used[v]){
            used[v]=true;
            if(linker[v]==-1||dfs(linker[v])){//������·������
                linker[v]=u;
                return true;
            }
        }
    }
    return false;//�����Ҫ���ˣ������������
}

int hungary()
{
    int res=0, u;
    memset(linker, -1, sizeof(linker));
    for(u=0; u<uN; u++){
        memset(used, 0, sizeof(used));
        if(dfs(u))res++;
    }
    return res;
}

int main()
{
    while(~scanf("%s %d", str, &vN)){
        uN = strlen(str);
        for (int i = 0; i < vN; i++){
            for (int j = 0; j < 6; j++){
                getchar();
                scanf("%c", &_cube[i][j]);
                for (int k = 0; k < uN; k++){
                    if(str[k] == _cube[i][j]){
                        g[k][i] = 1;
                    }
                }
            }
        }
        if(hungary() == uN)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
