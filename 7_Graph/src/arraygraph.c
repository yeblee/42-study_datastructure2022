# include "../include/arraygraph.h"

// 그래프 생성
ArrayGraph* createArrayGraph(int maxVertexCount){

}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount){
    ArrayGraph *pGraph = NULL;

    pGraph = createArrayGraph(maxVertexCount);
    if (pGraph != NULL) pGraph->graphType = GRAPH_DIRECTED;

    return pGraph;
}

// 공백 그래프 여부 판단
int isEmptyAG(ArrayGraph* pGraph){

}

// 노드 추가
int addVertexAG(ArrayGraph* pGraph, int vertexID){

}

// 간선 추가
int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID){

}

int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight){

}

// 노드의 유효성 검사
int checkVertexValid(ArrayGraph* pGraph, int vertexID){

}

// 노드 제거
int removeVertexAG(ArrayGraph* pGraph, int vertexID){

}

// 간선 제거
int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID){

}

// 그래프 삭제
void deleteArrayGraph(ArrayGraph* pGraph){

}

// 그래프 정보 출력
void displayArrayGraph(ArrayGraph* pGraph){
    if (pGraph != NULL) {
        for (int i = 0; i < pGraph->maxVertexCount; i++) {
            for (int j = 0; j < pGraph->maxVertexCount; j++) {
                printf(" [%d] ", pGraph->ppAdjEdge[i][j]);
            }
            printf("\n");
        }
    }
}