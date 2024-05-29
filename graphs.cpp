#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

class Graph
{
private:
    std::map<int, std::vector<int>> m_graph;
public:
    void addVertex(int vertex)
    {
        m_graph[vertex] = {};
    }

    void addEdge(int v1, int v2)
    {
        m_graph[v1].push_back(v2);
        m_graph[v2].push_back(v1);
    }

    void printGraph()
    {
        for (const auto& element : m_graph)
        {
            std::cout << element.first << ": ";
            for(const auto& curEdge : element.second)
            {
                std::cout << curEdge << " ";
            }
            std::cout << std::endl;
        }
    }
    void removeVertex(int vertex)
    {
        if (m_graph.find(vertex) == m_graph.end())
        {
            std::cout << "Invalid vertex" << std::endl;
            return;
        }
        m_graph.erase(vertex);

        for(auto& element : m_graph)
        {
            auto& value = element.second;
            value.erase(std::remove(value.begin(), value.end(), vertex), value.end());
        }
        
    }
    std::vector<int> getVertices()
    {
        std::cout << "vertices: ";
        std::vector<int>vertices;
        
        for(const auto& element : m_graph)
        {
            vertices.push_back(element.first);
            std::cout << element.first << " ";
        }
        std::cout << std::endl;
        return vertices;
    }

    std::vector<int> getEdges(int vertex)
    {
        if (m_graph.find(vertex) == m_graph.end())
        {
            std::cout << "Invalid Vertex!" << std::endl;
            return {}; 
        }
        std::cout << "Edges: ";
        for(const auto& i : m_graph[vertex])
        {
            std::cout << i << std::endl;
        }
        std::cout << std::endl;
        return m_graph[vertex];
    }
};

int main(void)
{
    Graph myGraph;
    myGraph.addVertex(1);
    myGraph.addVertex(2);
    myGraph.addVertex(3);
    myGraph.addEdge(1, 2);
    myGraph.addEdge(1, 3);
    myGraph.addEdge(2, 3);
    myGraph.removeVertex(3);
    myGraph.printGraph();
    myGraph.getVertices();
    myGraph.getEdges(1);

    return 0;
}