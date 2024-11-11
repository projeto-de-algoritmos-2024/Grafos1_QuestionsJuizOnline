class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
         map<int,int> m;
         //grafo direcionado.
         //as confiança sao as arestas enquanto as pessoas os vertices ou nós
         //aqui percorre M verificando as pessoas que sao confiadas e que confiam em alguém
        for(int i=0;i<trust.size();i++)
        {
           m[trust[i][0]]=-1;
           m[trust[i][1]]++; 
        }
        //variavel pra armazenar o numero da pessoa que é o juiz , caso n tenha retorna -1
        int pa=-1;
     
        //procura o juiz verificando se a pessoa é confiada n-1 vezes 
        for(int i=1;i<=n;i++)
        {
            if(m[i]==n-1)
            pa=i;
        }
        return pa;
    }
};