#include <iostream>
using namespace std;
#include <vector>
// En un archivo de implementación (por ejemplo, "constantes.cpp")
#include <climits>
#include <unordered_map>

const int INF = INT_MAX;

void imprimirM(const vector<vector<int>> matriz){
        cout<<" --- Representación del Grafo ---"<<endl;
        for(int i=0; i<7; i++){
                for(int j=0; j<7; j++){
                        if (matriz[i][j] == INF)
                                cout << "INF"<<"\t";
                        else
                                cout << matriz[i][j]<< "\t";
                }
        cout<<endl;        
        }

}
void dijkstra(const vector<vector<int>> grafoC){


     
}
int main(){

        //inicialización del grafo
        vector<vector<int>> grafo = {
                {INF,3,INF,INF,1,INF,INF},
                {3,INF,4,INF,5,INF,INF},
                {INF,4,INF,1,2,2,INF},
                {INF,INF,1,INF,INF,2,2},
                {1,5,2,INF,INF,5,INF},
                {INF,INF,2,2,5,INF,3},
                {INF,INF,INF,2,INF,3,INF }}; 
        imprimirM(grafo);
        unordered_map<int,char> diccionario;

        diccionario[0] = 'F';
        diccionario[1] = 'E';
        diccionario[2] = 'R';
        diccionario[3] = 'N';
        diccionario[4] = 'A';
        diccionario[5] = 'D';
        diccionario[6] = 'O';
}
