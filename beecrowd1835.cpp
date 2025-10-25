#include <vector>
#include <iostream>
#include <queue>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // numero de casos
    int T;
    cin >> T; 

    int contador = 0;
    int V, E;

    while(contador < T){

        cin >> V >> E; // lendo numero de vertices e arestas

        // lendo o atual e a ligacao do atual
        int atual;
        int ligadoAoAtual;

        vector<vector<int>> grafo(V+1);

        for(int i = 0; i < E; i++){
            cin >> atual >> ligadoAoAtual;
            grafo[atual].push_back(ligadoAoAtual);
            grafo[ligadoAoAtual].push_back(atual); // grafo não direcionado
        }

        vector<bool> visitado(V+1, false);
        vector<vector<int>> componentes;

        for(int i = 1; i < V+1; i++){
            if(!visitado[i]){

                vector<int> comp;
                queue<int> q;
                q.push(i);
                visitado[i] = true;

                while(!q.empty()){
                    int u = q.front(); q.pop();
                    comp.push_back(u);
                    
                    for (int v : grafo[u]) {
                        if (!visitado[v]) {
                            visitado[v] = true;
                            q.push(v);
                        }
                    }
                }

                componentes.push_back(comp);
         
            }
        }

        cout << "Caso #" << contador+1 << ": ";

        if(componentes.size() <= 1){
            cout << "a promessa foi cumprida" << endl;
        }else{
            cout << "ainda falta(m) " << componentes.size() - 1 << " estrada(s)" << endl;
        }

        contador++;
    }
    

    return 0;
}